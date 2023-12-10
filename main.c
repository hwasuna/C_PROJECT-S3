#include "set.h"
#include "stdio.h"
#include "timer.h"
#include "Part3.h"
#include <math.h>
#include "stdlib.h"


int main() {

//------------Part 1-----------------
////Create an empty list
    t_d_list *list = Create_emp_list(10);

////Insertion in the list at different levels
    Insert_Head(list, 3, 9);
    Insert_list(list, 5, 8);
    Insert_list(list, 4, 10);
    Insert_list(list, 2, 7);
    Insert_list(list, 2, 9);
    Insert_list(list, 4, 6);
    Insert_list(list, -1, 1);

    Display_aligned(list);
//Test of the insertion
//    Display_all(list);
//    Display_level(list, 5);

//------------Part 2-----------------

////Create the file to store the data (use absolute path)
//    FILE *log_file = fopen("C:C:\\Users\\tideu\\Documents\\travail\\Efrei_annee_1\\Data_structure\\log_1.txt", "w");
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
//    // Create a contact
//    contact* myContact = Create_contact("John", "Doe");
//
//    // Create an appointment
//    appointment* myAppointment = Create_Appointment(31, 12, 2023, 14, 30, 15, 30, "Meeting");
//
//    // Create a calendar entry
//    Calendar_entry* myEntry = Create_CalendarEntry(*myContact, *myAppointment);
//
//    Display_entry(myEntry);
//
//    return 0;
}