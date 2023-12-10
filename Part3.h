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

char* scanString(void);
//void toLowerCase(char* str);

Contact* Create_contact(Calendar* calendar, char* FirstName, char* LastName);
Calendar* Create_Emp_Calendar(int max_level);
void createAppointment(Contact* contact, Date date, Time startTime, Time endTime, char* purpose);
void displayAppointments(Calendar* calendar, Contact* contact);
//Calendar* Fill_Calendar(int, int);
void InsertSorted(Calendar* calendar, Contact* newContact);
//void Add_Contact(Calendar*, Calendar_cell* );
//Calendar_cell* create_calendar_cell(Contact contact, Appointment* appointment);
Contact* Search_Contact(Calendar* calendar, char* Fname, char* Lname);
//void Print_Calendar(Calendar* calendar);



void Menu();
//Calendar_entry* InsertSorted(Calendar_entry* head, Calendar_entry* newEntry);
//Contact* Create_contact(char* FirstName, char* LastName);
//Appointment* createAppointment(Contact* contact,Date date, Time startTime, Time endTime, char* purpose);
//void Display_entry(Calendar_entry* entry);

#endif //TEST_PROJET_PART3_H
