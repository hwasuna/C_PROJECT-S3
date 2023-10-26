//
// Created by Hawa Ajroud on 26/10/2023.
//


///////level cells
// Create_cell
// param :value, nb_levels
// output : pointer to the cell
t_d_cell *Create_cell(int val, int nb)
{
    t_d_cell* cell;
    cell->value = val;
    cell->nb_levels = nb;
    cell->next = NULL;
    //cell->down ?? not sure if we implement it since we have nb
    return cell;
}

///////level lists
// Create_empty_lev_list
// param : int max_nb_levels  (of list)
// output : level_list
t_d_list Create_empty_lev_list(int levels)
{
    t_d_list list;
    list.max_level = levels;
    for (int i = 0; i < levels; i++) {
        list.head_[i] = NULL; // Initialize level's head to NULL
    }
    return list;
}

//Insert_Cell_Head_list
// param : t_d_list* list, int  value_cell, int level_cell
// output : void
void Insert_Cell_Head_list(t_d_list* list, int  value_cell, int level_cell)
{
    t_d_list *new_cell = Create_cell(value_cell, level_cell);
    for (int i = 0; i<level_cell; i++) {
        list->head_[i] = new_cell;
    }
}

// Display_cells_level
// param : int level, t_d_list list
// output : t_d_cell cells
void Display_cells_level(t_d_list list, int level) {
    if (level < 0 || level >= list.max_level) {
        printf("[list_head_%d @-]-->NULL\n", level);
        return;
    }

    if (list.head_[level] == NULL) {
        printf("[list_head_%d @-]-->NULL\n", level);
    }
    else
    {
        t_d_cell *temp=list.head_[level];
        printf("[list_head_%d @-]-->",level);
        while(temp->next != NULL)
        {
            printf("-->[ %d|@-]", temp->value);
            temp = temp->next;
        }
        printf("-->NULL\n");
    }
}


#include "set.h"
