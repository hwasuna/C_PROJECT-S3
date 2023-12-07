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
//    Dynamic allocation of newCell and "next" and "prec" fields
    t_d_cell* newCell = (t_d_cell*)malloc(sizeof(t_d_cell));
    newCell->value = value;
    newCell->next = (t_d_cell**)malloc(sizeof(t_d_cell*) * levels);
    newCell->prec = (t_d_cell**)malloc(sizeof(t_d_cell*) * levels);

    for (int i = 0; i < levels; ++i)
    {
        newCell->next[i] = NULL;
        // Set prec pointers to the previous level cells
        if (i > 0)
        {
            newCell->prec[i] = newCell->prec[i - 1];
        }
        else
        {
            newCell->prec[i] = NULL;
        }
    }
    return newCell;
}


///////level lists
// Create_empty_lev_list
// param : int max_level
// output : t_d_list
t_d_list* Create_emp_list(int maxLevel) {
    t_d_list* newList = (t_d_list*)malloc(sizeof(t_d_list));
    newList->head = (t_d_cell**)malloc(sizeof(t_d_cell*) * (maxLevel + 1));
    newList->max_level = maxLevel;

    for (int i = 0; i < maxLevel; ++i) {
        newList->head[i] = NULL;
    }

    return newList;
}

//Insert_Head
// param : t_d_list* list, int  value, int level
// output : void
void Insert_Head(t_d_list* list, int value, int levels) {
    t_d_cell* newCell = Create_cell(value, levels);

    if (newCell == NULL) {
        printf("Error creating cell. Memory allocation failed.\n");
        return;
    }

    for (int i = 0; i < levels; i++) {
        newCell->next[i] = list->head[i];
        list->head[i] = newCell;
        if (i>0)
        {
            newCell->prec[i] = newCell->prec[i-1];
        }
    }
}

// Display_level
// param : t_d_list list, int level
// output : void
void Display_level(t_d_list* list, int level) {
    if (level >= 0 && level < list->max_level) {
        printf("[list_head_%d @-] --> ", level);
        t_d_cell* temp = list->head[level];
        while (temp != NULL) {
            printf("[%d|@-] --> ", temp->value);
            temp = temp->next[level];
        }
        printf("NULL\n");
    } else {
        printf("Invalid level display\n");
    }
}



////// Display_align
////// param : t_d_list list
////// output : void
//void Display_align(t_d_list list)
//{
//    for (int level = 0; level < list.max_level; level++) {
//        printf("[list_head_%d @-] ", level);
//        t_d_cell* temp = list.head[level];
//
//        // Create an array to keep track of the positions for each level
//        int positions[level + 1];
//
//        for (int i = 0; i <= level; i++) {
//            positions[i] = 0; // Initialize positions to 0
//        }
//
//        // Iterate through the elements and display them with alignment
//        while (temp != NULL) {
//            // Print spaces to align with the previous level
//            for (int i = 0; i < positions[level]; i++) {
//                printf("-------");
//            }
//
//            // Print the current element and update the position
//            printf("-->[%d|@-] ", temp->value);
//            positions[level]++;
//
//            // Move to the next level and update the positions array
//            for (int i = level - 1; i >= 0; i--) {
//                if (temp->next == NULL || temp->next->value > list.head[i]->value) {
//                    printf("----------");
//                } else {
//                    printf("--> ");
//                }
//                positions[i]++;
//            }
//            temp = temp->next;
//        }
//        printf("NULL\n");
//    }
//}



// Insert_list
// param : t_d_list* list, int  level, int value
// output : void
// ATTENTION TO THE ORDER OF THE INSERTION = MUST STAY A SORTED LIST
void Insert_list(t_d_list* list, int value, int levels) {
    t_d_cell* newCell = Create_cell(value, levels);

    if (newCell == NULL) {
        printf("Error creating cell. Memory allocation failed.\n");
        return;
    }

    // Start at the highest level
    int i = levels - 1;

    while (i >= 0) {
        t_d_cell* current = list->head[i];
        t_d_cell* prev = NULL;

        // Find the correct position to insert the new cell at the current level
        while (current != NULL && current->value < value) {
            prev = current;
            current = current->next[i];
        }

        // Insert the new cell at the correct position
        if (prev == NULL) {
            // Insert at the beginning
            newCell->next[i] = list->head[i];
            list->head[i] = newCell;

        } else {
            // Insert after the last cell at the level with a lower value
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
    for (int i = 0; i < list->max_level; i++) {
        Display_level(list, i);
    }
}


////////Part 2/////////

t_d_list * Level_list_P4(int n)
{
    int size = (long )(pow(2, n) - 1);

    int *levels = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        levels[i] = 1;
    }
    for (int step = 2; step <= size; step *= 2) {
        for (int i = step - 1; i < size; i += step) {
            levels[i] += 1;
        }
    }
    t_d_list* new_list = Create_emp_list(n);
    for(int i = 0; i<size; i++)
    {
        Insert_list(new_list, i+1, levels[i]);
    }
    free(levels);
    return new_list;
}


// Search_lvl_0
// param : t_d_list list, int value
// output : int
int Search_lvl_0(t_d_list list, int value)
{
    t_d_cell* temp = list.head[0];
    int place = 1;

    while (temp != NULL && temp->value != value) {
        temp = temp->next[0];
        place++;
    }

    if (temp != NULL && temp->value == value) {
//        printf("Value %d found at level 0, position %d\n", value, place);
        return place;
    } else {
//        printf("Value %d not found\n", value);
        return -1;  // Returning -1 to indicate that the value was not found
    }
}

// Search_lvl_max
// param : t_d_list* list, int value
// output : int
int Search_lvl_max(t_d_list *list, int value) {
    if (list == NULL || list->max_level <= 0)
    {
        return 0;
    }

    int level = list->max_level-1;
    t_d_cell* temp = list->head[level];
    t_d_cell* bound = temp;

    while((level >= 0) && (temp->value != value))
    {
        if (temp->value <= value)
        {
            bound = temp;
            level-= 1;
            temp = bound ->next[level];
        }
        else
        {
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
    if(level >= 0)
    {
        return 1;
    }
    return 0;
}