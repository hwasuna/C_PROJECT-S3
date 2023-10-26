//
// Created by Hawa Ajroud on 26/10/2023.
//


#include "set.h"
#include <stdio.h>
#include "stdlib.h"

///////level cells
// Create_cell
// param :value, nb_levels
// output : pointer to the cell
t_d_cell* Create_cell(int value, int nb)
{
    t_d_cell* cell = (t_d_cell*)malloc(sizeof(t_d_cell));
    cell->value = value;
    cell->next = (t_d_cell*)malloc(nb * sizeof(t_d_cell));

    for (int i = 0; i < nb; i++)
    {
        cell->next[i].next = NULL;
    }
    return cell;
}

///////level lists
// Create_empty_lev_list
// param : int max_nb_levels  (of list)
// output : level_list
t_d_list Create_empty_lev_list(int levels)
{
    t_d_list* list = (t_d_list*)malloc(sizeof(t_d_list));
    list->max_level = levels;
    list->head = (t_d_cell*)malloc(levels * sizeof(t_d_cell));

    t_d_cell* temp = list->head;
    for (int i = 0; i < levels; i++)
    {
        temp[i].next = NULL;
    }
    return *list;
}

//Insert_Cell_Head_list
// param : t_d_list* list, int  value_cell, int level_cell
// output : void
void Insert_Cell_Head_list(t_d_list* list, int num_levels,  int value_cell)
{
    t_d_cell* new_cell = Create_cell(value_cell, num_levels);

    if (num_levels <= list->max_level) {
        for (int i = 0; i < num_levels; i++) {
            // Insert the new cell at the head of the current level
            new_cell->next[i] = list->head[i];
            list->head[i] = *new_cell;
        }
    }
}

// Display_cells_level
// param : t_d_list list, int level
// output : void
void Display_cells_level(t_d_list list, int level) {
    if (level < 0 || level > list.max_level) {
        printf("[list_head_%d @-]-->NULL\n", level);
        return;
    }

    if (list.head[level].next == NULL) {
        printf("[list_head_%d @-]-->NULL\n", level);
    } else {
        t_d_cell* temp = &list.head[level];
        printf("[list_head_%d @-]", level);
        while (temp->next != NULL) {
            printf("-->[ %d|@-]", temp->value);
            temp = temp->next;
        }
        printf("-->NULL\n");
    }
}

#include "set.h"
