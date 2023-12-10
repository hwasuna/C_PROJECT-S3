#include "set.h"
#include "stdio.h"
#include "timer.h"
#include "Part3.h"
#include <math.h>
#include "stdlib.h"


void DisplayCalendar(Calendar* calendar) {
    if (calendar == NULL || calendar->head == NULL) {
        printf("Empty calendar\n");
        return;
    }

    printf("Calendar:\n");

    for (int level = 0; level < calendar->max_level ; ++level) {
        Contact* current = calendar->head[level];
        printf("Level %d: ", level);

        while (current != NULL) {
            printf("%s %s -> ", current->FirstName, current->LastName);
            current = current->next;
        }

        printf("NULL\n");
    }
}


int main() {

//------------Part 1-----------------
////Create an empty list
//    t_d_list *list = Create_emp_list(10);
//
//////Insertion in the list at different levels
//    Insert_Head(list, 3, 9);
//    Insert_list(list, 5, 8);
//    Insert_list(list, 4, 10);
//    Insert_list(list, 2, 7);
//    Insert_list(list, 2, 9);
//    Insert_list(list, 4, 6);
//    Insert_list(list, -1, 1);


//Test of the insertion
//    Display_align(list);
//    Display_all(list);
//    Display_level(list, 5);

//------------Part 2-----------------

////Create the file to store the data (use absolute path)
//    FILE *log_file = fopen("C:\\Users\\tideu\\Documents\\travail\\Efrei_annee_1\\Data_structure\\log_1.txt", "w");
//    char format[] = "%d\t%s\t%s\n";
//    int level;
//    char *time_lvl0;
//    char *time_all_levels;
//
//
////Test of the search functions at level max and level 0
//    ////////Test 100 000/////////
//
////  Chose to have a list going from 7 to 16 cells to test
//    for (int n = 7; n < 17; n++) {
////      Create the formated list
//        t_d_list *list_search = Level_list_P2(n);
//
//        printf("Test level 0\n");
//        startTimer();
////      Search for 100 000 repetitions the time taken to find a random value at level 0
//        for (int i = 0; i < 100000; i++) {
//            int value_search = rand() % ((int) pow(2, n) + 1);
//            Search_lvl_0(*list_search, value_search);
//        }
//        stopTimer();
//        displayTime();
//        time_lvl0 = getTimeAsString(); // Timer module function
//
//        printf("Test level max\n");
//        startTimer();
////      Search for 100 000 repetitions the time taken to find a random value at level max
//        for (int i = 0; i < 100000; i++) {
//            int value_search = rand() % ((int) pow(2, n) + 1);
//            Search_lvl_max(list_search, value_search);
//        }
//        stopTimer();
//        displayTime();
//        time_all_levels = getTimeAsString();
//        level = n;
//
//        fprintf(log_file, format, level, time_lvl0, time_all_levels);
//    }
//    fclose(log_file);



////-------------Part 3--------------

// Test Create_Emp_Calendar
//    Calendar* empCalendar = Create_Emp_Calendar(4);
//
//    // Test Create_contact and InsertSorted
//    Create_contact(empCalendar, "John", "flamel");
//    Create_contact(empCalendar, "Joli", "galluouin");
//    Create_contact(empCalendar, "Bob", "garnier");
//    Create_contact(empCalendar, "Charlie", "gartner");
//
//    // Display the calendar
//    DisplayCalendar(empCalendar);
//
//
//
//    Contact* sampleContact = Create_contact(empCalendar, "John", "Doe");
//
//    // Create sample appointments
//    Date date1 = {10, 12, 2023};
//    Time startTime1 = {14, 30};
//    Time endTime1 = {15, 30};
//    Appointment* appointment1 = createAppointment(date1, startTime1, endTime1, "Meeting with client");
//
//    Date date2 = {15, 12, 2023};
//    Time startTime2 = {10, 0};
//    Time endTime2 = {11, 0};
//    Appointment* appointment2 = createAppointment(date2, startTime2, endTime2, "Team meeting");
//
//    // Link appointments to the contact
//    sampleContact->appointments = appointment1;
//    appointment1->next = appointment2;
//
//    // Display appointments for the contact
//    displayAppointments(sampleContact);
//
//    // Free allocated memory (you should have a function to free the entire contact structure)
//    free(sampleContact->FirstName);
//    free(sampleContact->LastName);
//    free(sampleContact);
//    free(appointment1->purpose);
//    free(appointment1);
//    free(appointment2->purpose);
//    free(appointment2);
    Menu();

    return 0;


}