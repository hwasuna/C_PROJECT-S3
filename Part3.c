//
// Created by tideu on 06/12/2023.
//

#include "Part3.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* scanString(void) {
    char buffer[256];
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0'; // Remove trailing newline character

    return strdup(buffer);
}



contact* Create_contact(char* FirstName, char* LastName)
{
    contact* newContact = (contact*)malloc(sizeof(contact));

    if (newContact != NULL) {
        newContact->FirstName = strdup(FirstName);
        newContact->LastName = strdup(LastName);

//        // Check for allocation errors
//        if (newContact->FirstName == NULL || newContact->LastName == NULL) {
//            free(newContact->FirstName);
//            free(newContact->LastName);
//            free(newContact);
//            return NULL;
//        }
    }

    return newContact;
}
appointment* Create_Appointment(int day,int month,int year,int hour_begin,int minute_begin,int hour_end,int minute_end,char* purpose)
{
    appointment* newAppointment = (appointment*)malloc(sizeof(appointment));

    if (newAppointment != NULL) {
        newAppointment->day = day;
        newAppointment->month = month;
        newAppointment->year = year;
        newAppointment->hour_begin = hour_begin;
        newAppointment->minute_begin = minute_begin;
        newAppointment->hour_end = hour_end;
        newAppointment->minute_end = minute_end;
        newAppointment->purpose = strdup(purpose);
//
//        // Check for allocation errors
//        if (newAppointment->purpose == NULL) {
//            free(newAppointment->purpose);
//            free(newAppointment);
//            return NULL;
//        }
    }

    return newAppointment;
}

Calendar_entry* Create_CalendarEntry(contact contact, appointment appointment)
{
    Calendar_entry* newEntry = (Calendar_entry*)malloc(sizeof(Calendar_entry));

    if (newEntry != NULL) {
        newEntry->contact = contact;
        newEntry->appointment = appointment;
        newEntry->next = NULL;
    }

    return newEntry;
}

void Display_entry(Calendar_entry* entry)
{
    printf("Contact: %s %s\n", entry->contact.FirstName, entry->contact.LastName);
    printf("Appointment Date: %d-%02d-%02d\n", entry->appointment.year, entry->appointment.month, entry->appointment.day);
    printf("Appointment Time: %02d:%02d - %02d:%02d\n", entry->appointment.hour_begin, entry->appointment.minute_begin,
           entry->appointment.hour_end, entry->appointment.minute_end);
    printf("Purpose: %s\n", entry->appointment.purpose);
}

