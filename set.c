//
// Created by Hawa Ajroud on 26/10/2023.
//


#include "set.h"
#include <stdio.h>
#include "stdlib.h"

///////level cells
// Create_cell
// param : int value,  int level
// output : pointer to the cell
t_d_cell* Create_cell(int value, int level)
{
    t_d_cell* cell = (t_d_cell*)malloc(sizeof(t_d_cell));
    cell->value = value;
    //cell->next = (t_d_cell*)malloc(nb * sizeof(t_d_cell));
    cell->next=NULL;
//    for (int i = 0; i < nb; i++)
//    {
//        cell->next[i].next = NULL;
//    }
    return cell;
}

///////level lists
// Create_empty_lev_list
// param : int max_level
// output : t_d_list
t_d_list Create_emp_list(int max_level)
{
    t_d_list list;
    list.max_level = max_level;
    list.head = (t_d_cell**)malloc(max_level * sizeof(t_d_cell*));


    for (int i = 0; i < max_level; i++)
    {
        list.head[i] = NULL;
    }
    return list;
}

//Insert_Head
// param : t_d_list* list, int  value, int level
// output : void
void Insert_Head(t_d_list* list, int level , int  value)
{
    if (level >= 0 && level <= list->max_level) {

        for (int i = 0; i < level; i++) {
            t_d_cell* new_cell = Create_cell(value, level);
            new_cell->next = list->head[i];
            list->head[i] = new_cell;
        }
    } else {
        printf("Niveau invalide insert\n");
    }
}

// Display_level
// param : t_d_list list, int level
// output : void
void Display_level(t_d_list list, int level)
{
    if (level >= 0 && level <= list.max_level) {
        printf("[list_head_%d @-] --> ", level);
        t_d_cell* temp = list.head[level];
        while (temp != NULL) {
            printf("[%d|@-] --> ", temp->value);
            temp = temp->next;
        }
        printf("NULL\n");
    } else {
        printf("Niveau invalide display\n");
    }
}


//
//// Display_align
//// param :  t_d_list list
//// output : void
//void Display_align(t_d_list list);



// Insert_list
// param : t_d_list* list, int  value, int level
// output : void
// ATTENTION TO THE ORDER OF THE INSERTION = MUST STAY A SORTED LIST
void Insert_list(t_d_list* list, int  value, int level)
{
    if (level >= 0 && level <= list->max_level) {
        for (int curr_level = 0; curr_level < level; curr_level++) {
            t_d_cell* new_cell = Create_cell(value, level);

            t_d_cell* temp = list->head[curr_level];
            t_d_cell* prev = NULL;

            while (temp != NULL && temp->value <= value) { //loop until the value inserted is bigger than the list's values
                prev = temp;
                temp = temp->next;
            }

            if (prev == NULL) // Insert at the beginning of the list at this level
            {
                Insert_Head(list, level, value);
            }
            else // Insert after 'prev' and before 'temp'
            {
                new_cell->next = temp;
                prev->next = new_cell;
            }
            break;
        }
    }
    else //problem of level of the inserted cell
    {
        printf("The level indicated isn't in the list's range\n");
    }
}

// Display_all
// param : t_d_list list
// output : void
void Display_all(t_d_list list)
{
    for(int i = 0; i<list.max_level; i++)
    {
        Display_level(list, i);
    }
}