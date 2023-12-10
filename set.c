//
// Created by Hawa Ajroud on 26/10/2023.
//

#include "set.h"
#include <stdio.h>
#include "stdlib.h"
#include <math.h>

///////level cells
// fct : Create_cell
// param : int value, int level
// output : pointer to cell
t_d_cell* Create_cell(int value, int levels) {
//    Dynamic allocation of newCell and "next" field
    t_d_cell* newCell = (t_d_cell*)malloc(sizeof(t_d_cell));
    newCell->value = value;
    newCell->next = (t_d_cell**)malloc(sizeof(t_d_cell*) * levels);

//    Set the different level's "next" to NULL
    for (int i = 0; i < levels; ++i)
    {
        newCell->next[i] = NULL;
    }
    return newCell;
}


///////level lists
// Create_empty_lev_list
// param : int max_level
// output : t_d_list
t_d_list* Create_emp_list(int maxLevel) {
//    Check if the level asked is allowed
    if (maxLevel<=0)
    {
        printf("Error with level asked. Please enter a positive value\n");
        return NULL;
    }
//    Dynamic allocation for the list and it's head
    t_d_list* newList = (t_d_list*)malloc(sizeof(t_d_list));
    newList->head = (t_d_cell**)malloc(sizeof(t_d_cell*) * (maxLevel + 1));
    newList->max_level = maxLevel;

//    Create the head for each level
    for (int i = 0; i < maxLevel; ++i) {
        newList->head[i] = NULL;
    }

    return newList;
}

//Insert_Head
// param : t_d_list* list, int  value, int level
// output : void
void Insert_Head(t_d_list* list, int value, int levels) {
//    Create the cell to insert
    t_d_cell* newCell = Create_cell(value, levels);

//    Error message
    if (newCell == NULL) {
        printf("Error creating cell. Memory allocation failed.\n");
        return;
    }

//    Insert the cell at the head (no regard for the order)
    for (int i = 0; i < levels; i++) {
        newCell->next[i] = list->head[i];
        list->head[i] = newCell;
    }
}

// Display_level
// param : t_d_list list, int level
// output : void
void Display_level(t_d_list* list, int level) {
//    Check if the level is right (in the bounds)
    if (level >= 0 && level < list->max_level) {
        printf("[list_head_%d @-] --> ", level);
//        Create a temporary cell to browse the list
        t_d_cell* temp = list->head[level];
//        Display each cell until the last
        while (temp != NULL) {
            printf("[ %d|@-] --> ", temp->value);
            temp = temp->next[level];
        }
//        Display the last cell's pointer to NULL
        printf("NULL\n");
//        If the level asked isn't right = display an error message
    } else {
        printf("Invalid level display\n");
    }
}


int get_lenght_int(int a)
{
    int add=0;
    if (a<0)
    {
        add=1;
        a=-a;
    }
    else if (a==0)
    {
        return 0;
    }
    return add+(int)log10((double )a);
}

////// Display_align
////// param : t_d_list list
////// output : void
void Display_align(t_d_list *list) // Display level list function, it takes 1 parameter : the address of the level list [my_t_d_list]
{
    if (list->max_level == 0) // Check if the level list is not created ?
    {
        printf("The level list is empty\n"); // Display it's impossible to display a none created level list
    }
    else
    {
        t_d_cell *temp_ptr; // Initialize a temporary pointer which points to [t_d_cell] structure
        for (int i = 0; i < list->max_level; i++)  // Iterate [max_level] times to print all the different levels of the [t_d_list]
        {
            temp_ptr = list->head[i]; // temporary pointer get the address of the first byte memory block allocated for [t_d_cell]
            t_d_cell *temp_shr = list->head[0];
            printf("[list head_%d @-]", i); // print the different level one by one starting from 0
            do
            {
                while ( temp_ptr != temp_shr)
                {
                    printf("-----------");
                    for (int j=0; j<get_lenght_int(temp_shr->value);j++){
                        printf("-");
                    }
                    temp_shr=temp_shr->next[0];
                }
                printf("--> [ %d|@-]", temp_ptr->value); // display the value of each cell on every level
                temp_ptr = temp_ptr->next[i];
                temp_shr = temp_shr->next[0];
            }
            while (temp_ptr != NULL); // while the temporary pointer don't point to NULL on each level to display from head to tail

            while ( temp_ptr != temp_shr)
            {
                printf("-----------");
                for (int j=0; j<get_lenght_int(temp_shr->value);j++){
                    printf("-");
                }
                temp_shr=temp_shr->next[0];
            }
            printf("----> NULL\n"); // display the end of each level
        }
    }
    return;
}


// Insert_list
// param : t_d_list* list, int value, int  level
// output : void
void Insert_list(t_d_list* list, int value, int levels) {
//    Create the new cell to insert
    t_d_cell* newCell = Create_cell(value, levels);

//    Check if the creation was done correctly
    if (newCell == NULL) {
        printf("Error creating cell. Memory allocation failed.\n");
        return;
    }

    // Start at the highest level
    int i = levels - 1;

//    Repeat the iteration for every level (from starting level to the lowest level)
    while (i >= 0) {
//        Create 2 temporary cells to browse the list
        t_d_cell* current = list->head[i];
        t_d_cell* prev = NULL;

//      Find the correct position (ascending order) to insert the new cell at the current level
        while (current != NULL && current->value < value) {
            prev = current;
            current = current->next[i];
        }

        // Insert the new cell at the chosen position
        if (prev == NULL) {
            // Insert at the head
            newCell->next[i] = list->head[i];
            list->head[i] = newCell;

        } else {
            // Insert in the beginning/ end of the list
            newCell->next[i] = current;
            prev->next[i] = newCell;
        }

        // Move to the next level
        i--;
    }
}



// Display_all
// param : t_d_list list
// output : void
void Display_all(t_d_list* list) {
//    For every level = display level by level
    for (int i = 0; i < list->max_level; i++) {
        Display_level(list, i);
    }
}


////////Part 2/////////

// Level_list_P2
// param : int n
// output : t_d_list* list
t_d_list * Level_list_P2(int n)
{
//    Specify the number of cells of the list (2^n-1)
    int size = (long )(pow(2, n) - 1);

//    Dynamic allocation of the levels (depends on n) with an
    int *levels = (int *)malloc(size * sizeof(int));

//    Set every cell (= future level value) to 1 as a default value
    for (int i = 0; i < size; i++) {
        levels[i] = 1;
    }
//    Increment the value of the cells depending on the given sequence
    for (int step = 2; step <= size; step *= 2) {
        for (int i = step - 1; i < size; i += step) {
            levels[i] += 1;
        }
    }
//    Creation of the level list of level given by the precedent array
    t_d_list* new_list = Create_emp_list(n);
    for(int i = 0; i<size; i++)
    {
//        Insert cells with the value and level size given by the array
        Insert_list(new_list, i+1, levels[i]);
    }
//    Free the dynamic allocation of the array
    free(levels);
    return new_list;
}


// Search_lvl_0
// param : t_d_list list, int value
// output : int
int Search_lvl_0(t_d_list list, int value)
{
//    Create a temporary cell at level 0
    t_d_cell* temp = list.head[0];
//    a place variable to keep the position of the value
    int place = 1;

//    Browse the list until the end while the value is not found
    while (temp != NULL && temp->value != value) {
        temp = temp->next[0];
        place++;
    }

//    If the value was  found, return the position of the cell, else -1 (an unreachable value for the list)
    if (temp != NULL && temp->value == value) {
        return place;
    } else {
        return -1;  // Returning -1 to indicate that the value was not found
    }
}

// Search_lvl_max
// param : t_d_list* list, int value
// output : int
int Search_lvl_max(t_d_list *list, int value) {
//    Check if the list is null or has an invalid max_level
    if (list == NULL || list->max_level <= 0)
    {
        return 0;
    }

//    Start the search at level max
    int level = list->max_level-1;
    t_d_cell* temp = list->head[level];
    t_d_cell* bound = temp;

//    For every level (we descend from highest to lowest level) until the value is found
    while((level >= 0) && (temp->value != value))
    {
//        if the value is higher than the current value, descend of one level and add to the bound
        if (temp->value <= value)
        {
            bound = temp;
            level-= 1;
            temp = bound ->next[level];
        }
        else
        {
            // If the value is lower than the current value, move to the previous bound or head if at the beginning
            if (temp == list->head[level])
            {
                level-=1;
                bound = list->head[level];
                temp = bound ;
            }
            else
            {
                temp = bound ;
                level-=1;
                temp = temp->next[level];
            }
        }
    }
    // If the level is valid, the value is found : return 1, else return 0
    if (level >= 0)
    {
        return 1;
    }
    return 0;
}