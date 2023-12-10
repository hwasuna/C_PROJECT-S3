//
// Created by tideu on 06/12/2023.
//

#ifndef TEST_PROJET_PART3_H
#define TEST_PROJET_PART3_H



typedef struct {
    int day;
    int month;
    int year;
} Date;

// Structure for storing time
typedef struct {
    int hour;
    int minute;
} Time;

// Structure for storing appointment information
typedef struct Appointment{
    Date date;
    Time startTime;
    Time endTime;
    char* purpose;
    struct Appointment* next;
} Appointment;

typedef struct Contact{
    char* FirstName;
    char* LastName;
    Appointment* appointments;
    struct Contact** next;
} Contact;

typedef struct Calendar_entry {
    struct Contact** head;
    int max_level;
} Calendar;


Contact* Create_contact(Calendar* calendar, char* FirstName, char* LastName);
Calendar* Create_Emp_Calendar(int max_level);
void createAppointment(Contact* contact, Date date, Time startTime, Time endTime, char* purpose);
void displayAppointments(Calendar* calendar, Contact* contact);
void InsertSorted(Calendar* calendar, Contact* newContact);
Contact* Search_Contact(Calendar* calendar, char* Fname, char* Lname);

void Menu();

#endif //TEST_PROJET_PART3_H
