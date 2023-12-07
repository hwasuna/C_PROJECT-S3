//
// Created by tideu on 06/12/2023.
//

#ifndef TEST_PROJET_PART3_H
#define TEST_PROJET_PART3_H

typedef struct {
    char* FirstName;
    char* LastName;
}contact;

typedef struct {
    int day;
    int month;
    int year;
    int hour_begin;
    int minute_begin;
    int hour_end;
    int minute_end;
    char* purpose;
}appointment;

typedef struct Calendar_entry {
    contact contact;
    appointment appointment;
    struct Calendar_entry* next;
} Calendar_entry;

char* scanString(void);

contact* Create_contact(char* FirstName, char* LastName);
appointment* Create_Appointment(int day,int month,int year,int hour_begin,int minute_begin,int hour_end,int minute_end,char* purpose);
Calendar_entry* Create_CalendarEntry(contact contact, appointment appointment);
void Display_entry(Calendar_entry* entry);

#endif //TEST_PROJET_PART3_H
