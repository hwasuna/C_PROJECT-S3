//
// Created by Hawa Ajroud on 26/10/2023.
//

#ifndef C_PROJECT_S3_SET_H
#define C_PROJECT_S3_SET_H


//Cell
typedef struct s_d_cell
{
    int value;
    struct s_d_cell* next;
    //struct s_d_cell *down;
} t_d_cell;

//Level_list
typedef struct s_d_list
{
    t_d_cell* head;
    int max_level;
} t_d_list;


///////level cells
// Create_cell
// param : int value, int nb_levels
// output : pointer to the cell
t_d_cell* Create_cell (int, int);


///////level lists
// Create_empty_lev_list
// param : int max_nb_levels  (of list)
// output : level_list
t_d_list Create_empty_lev_list(int);


//Insert_Cell_Head_list
// param : t_d_list* list, int  value_cell, int level_cell
// output : void
void Insert_Cell_Head_list(t_d_list*, int, int);

// Display_cells_level
// param : int level, t_d_list list
// output : t_d_cell cells
void Display_cells_level(t_d_list , int);

// Display_levels_list_align_cells
// param : int level , t_d_list list
// output : t_d_cell cells (to align)
void Display_levels_list_align_cells(t_d_list , int);

// Insert_level_cell
// param : int level, t_d_cell cell_to_insert
// output : void
// ATTENTION TO THE ORDER OF THE INSERTION = MUST STAY A SORTED LIST
void Insert_level_cell(int, t_d_cell);

//For this last function, it is possible to make a 'simple' insertion at each level, starting
//from the beginning of the list, but it is possible to be more efficient - it's up to you
//to work out how.



#endif //C_PROJECT_S3_SET_H
