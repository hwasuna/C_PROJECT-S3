//
// Created by tideu on 06/12/2023.
//

#include "Part3.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ctype.h"


char* scanString(void)
{
    char buffer[256];
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0';

    return strdup(buffer);
}

Contact* Create_contact(Calendar* calendar, char* FirstName, char* LastName)
{
    if (calendar == NULL)
    {
        printf("Invalid calendar\n");
        return NULL;
    }

    // Allocate memory for a new contact
    Contact* newContact = (Contact*)malloc(sizeof(Contact));

    // Allocate memory for the first and last names
    newContact->FirstName = strdup(FirstName);
    newContact->LastName = strdup(LastName);

    // Initialize other fields
    newContact->appointments = NULL;
    newContact->next = NULL;

    // Insert the new contact into the calendar
    InsertSorted(calendar, newContact);

    printf("Contact created and added to the calendar\n");

    // Return the created contact
    return newContact;
}

Calendar* Create_Emp_Calendar(int max_level)
{
    // Allocate memory for a Calendar structure
    Calendar* new_calendar = malloc(sizeof(Calendar));

    // Allocate memory for the head array
    new_calendar->head = (Contact**)malloc(sizeof(Contact*) * (max_level + 1));

    // Initialize all head pointers to NULL
    for (int i = 0; i <= max_level; i++)
    {
        new_calendar->head[i] = NULL;
    }
    new_calendar->max_level = max_level;

    // Return the created calendar
    return new_calendar;
}


// Function to compare two strings
int strcasecmp_lower(const char* str1, const char* str2)
{
    while (*str1 && *str2)
    {
        int diff = tolower((unsigned char)*str1) - tolower((unsigned char)*str2);
        if (diff)
        {
            return diff;
        }
        ++str1;
        ++str2;
    }
    return tolower((unsigned char)*str1) - tolower((unsigned char)*str2);
}

//Insert the contact in the list (supposed to be alphabetic but doesn't work)
void InsertSorted(Calendar* calendar, Contact* newContact)
{
    // Check for empty calendar or invalid contact
    if (calendar == NULL || newContact == NULL)
    {
        printf("Invalid calendar or contact\n");
        return;
    }

    // Find the appropriate level for insertion
    int level = 3;
    Contact* currentHead = calendar->head[level];
    Contact* previous = NULL;

    // Traverse the levels until the correct position is found
    while (level >= 0)
    {
        // Check if the current level is empty or if the new contact should be inserted
        if (currentHead == NULL || strcasecmp_lower(currentHead->LastName, newContact->LastName) >= 0)
        {
            break;
        }

        // Move to the next node in the current level
        previous = currentHead;
        currentHead = currentHead->next;
        level--;
    }

    // Create a copy of the new contact
    Contact* insertedContact = malloc(sizeof(Contact));
    memcpy(insertedContact, newContact, sizeof(Contact));

    // Insert the contact at the position
    if (previous == NULL)
    {
        // Insert at the beginning of the list
        insertedContact->next = calendar->head[level];
        calendar->head[level] = insertedContact;
    }
    else
    {
        // Insert after the previous node
        insertedContact->next = currentHead;
        previous->next = insertedContact;
    }

}

//Create an appointment to a given contact
void createAppointment(Contact* contact, Date date, Time startTime, Time endTime, char* purpose)
{
    // Check if the contact is valid
    if (contact == NULL)
    {
        printf("Invalid contact\n");
        return;
    }

    // Create a new appointment
    Appointment* newAppointment = (Appointment*)malloc(sizeof(Appointment));

    // Check if memory allocation was successful
    if (newAppointment == NULL)
    {
        printf("Memory allocation failed for new appointment\n");
        return;
    }

    // Set the values for the new appointment
    newAppointment->date = date;
    newAppointment->startTime = startTime;
    newAppointment->endTime = endTime;

    // Allocate memory for the purpose and copy the string
    newAppointment->purpose = strdup(purpose);

    // Check if memory allocation was successful for the purpose
    if (newAppointment->purpose == NULL)
    {
        printf("Memory allocation failed for purpose\n");
        free(newAppointment);  // Free the allocated memory for the appointment
        return;
    }

    // Link the new appointment to the contact's list of appointments
    newAppointment->next = contact->appointments;
    contact->appointments = newAppointment;
}

void displayAppointments(Calendar* calendar, Contact* contact)
{
    if (calendar == NULL || contact == NULL)
    {
        printf("Invalid calendar or contact\n");
        return;
    }

    printf("Appointments for %s %s:\n", contact->FirstName, contact->LastName);

    // Iterate through the linked list of appointments for the contact
    Appointment* currentAppointment = contact->appointments;
    while (currentAppointment != NULL) {
        printf("Date: %02d/%02d/%04d\n", currentAppointment->date.day, currentAppointment->date.month, currentAppointment->date.year);
        printf("Time: %02d:%02d - %02d:%02d\n", currentAppointment->startTime.hour, currentAppointment->startTime.minute,currentAppointment->endTime.hour, currentAppointment->endTime.minute);
        printf("Purpose: %s\n", currentAppointment->purpose);
        printf("\n");

        // Move to the next appointment
        currentAppointment = currentAppointment->next;
    }
}

Contact* Search_Contact(Calendar* calendar, char* Fname, char* Lname)
{
    // Check for invalid calendar or names
    if (calendar == NULL || Fname == NULL || Lname == NULL)
    {
        printf("Invalid calendar or names\n");
        return NULL;
    }

    int level = 3;
    Contact* contact = calendar->head[level];

    // Iterate through the levels until the correct position is found
    while (level >= 0)
    {
        // Check if the current level is empty or if contact is found
        while (contact != NULL) {
            if (strcasecmp_lower(contact->LastName, Lname) == 0 && strcasecmp_lower(contact->FirstName, Fname) == 0)
            {
                // Contact found, return the contact
                printf("Contact %s %s present in the calendar\n\n", contact->FirstName, contact->LastName);
                return contact;
            }
            contact = contact->next;
        }

        --level;
        if (level >= 0)
        {
            contact = calendar->head[level];
        }
    }

    // Contact not found
    printf("Contact not found\n");
    return NULL;
}

void Menu() {
    int val = 0;
    Calendar* calendar = Create_Emp_Calendar(4);

    while (val != 9) {
        printf("Type the number associated with the wanted action\n");
        printf("1. Search for a contact\n");
        printf("2. View a contact's appointments\n");
        printf("3. Create a contact\n");
        printf("4. Create an appointment for a contact\n");
        printf("5. Delete an appointment (not available)\n");
        printf("6. Save the file of all appointments (not available)\n");
        printf("7. Loading an appointment file (not available)\n");
        printf("8. Provide the calculation times for inserting a new contact (not available)\n");
        printf("9. Stop the execution\n");

        scanf("%d", &val);

        switch (val) {
            case 1: {
                char *Fname = (char *) malloc(50 * sizeof(char));
                char *Lname = (char *) malloc(50 * sizeof(char));
                printf("Enter the Firstname\n");
                scanf("%s", Fname);
                printf("Enter the Lastname\n ");
                scanf("%s", Lname);
                Search_Contact(calendar, Fname, Lname);

                break;
            }
            case 2: {
                char *Fname = (char *) malloc(50 * sizeof(char));
                char *Lname = (char *) malloc(50 * sizeof(char));
                printf("Enter the Firstname\n");
                scanf("%s", Fname);
                printf("Enter the Lastname\n ");
                scanf("%s", Lname);
                Contact* existingContact = Search_Contact(calendar, Fname, Lname);


                displayAppointments(calendar, existingContact);
                break;
            }
            case 3: {
                char *Fname = (char *) malloc(50 * sizeof(char));
                char *Lname = (char *) malloc(50 * sizeof(char));
                printf("Enter the Firstname\n");
                scanf("%s", Fname);
                printf("Enter the Lastname\n ");
                scanf("%s", Lname);

                Create_contact(calendar, Fname, Lname);

                free(Fname);
                free(Lname);
                break;
            }
            case 4: {
                char *Fname = (char *) malloc(50 * sizeof(char));
                char *Lname = (char *) malloc(50 * sizeof(char));
                printf("Enter the First and Last name\n");
                scanf("%s %s", Fname, Lname);

                Contact* existingContact = Search_Contact(calendar, Fname, Lname);

                if (existingContact == NULL) {
                    // Contact doesn't exist, create a new one
                    Create_contact(calendar, Fname, Lname);
                }

                printf("\nDate of the appointment (dd mm yyyy): ");
                Date appointmentDate;
                scanf("%d %d %d", &appointmentDate.day, &appointmentDate.month, &appointmentDate.year);

                printf("Start time of the appointment (hh mm): ");
                Time startTime;
                scanf("%d %d", &startTime.hour, &startTime.minute);

                printf("End time of the appointment (hh mm): ");
                Time endTime;
                scanf("%d %d", &endTime.hour, &endTime.minute);

                char purpose[100];
                printf("Purpose of the appointment: ");
                scanf("%s", purpose);

                // Create an appointment for the existing or newly created contact
                createAppointment(existingContact,appointmentDate, startTime, endTime, purpose);

                free(Fname);
                free(Lname);
                break;
            }
            case 5: {
                // TODO: Implement Delete_Appointment();
                break;
            }
            case 6: {
                // TODO: Implement Save_Appointments();
                break;
            }
            case 7: {
                // TODO: Implement Load_Appointments();
                break;
            }
            case 8: {
                // TODO: Implement Calculate_Insertion_Times();
                break;
            }
            case 9: {
                // Free the allocated memory for the calendar before stopping the execution
                // Free_Calendar(calendar);
                break;
            }
            default:
                printf("Unknown command\n");
        }
    }
}
