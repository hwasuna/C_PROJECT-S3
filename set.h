
#ifndef TEST_PROJET_SET_H
#define TEST_PROJET_SET_H
//
// Created by Hawa Ajroud on 26/10/2023.
//

//Cell
typedef struct s_d_cell
{
    int value;
    struct s_d_cell* next;
} t_d_cell;

//Level_list
typedef struct s_d_list
{
    t_d_cell** head;
    int max_level;
} t_d_list;


///////level cells
// Create_cell
// param : int value, int level
// output : t_d_cell*
t_d_cell* Create_cell (int value, int level);



///////level lists
// Create_empty_lev_list
// param : int max_level
// output : t_d_list
t_d_list Create_emp_list(int max_level);


//Insert_Head
// param : t_d_list* list, int level, int  value
// output : void
void Insert_Head(t_d_list* list, int level, int  value);

// Display_level
// param : t_d_list list, int level
// output : void
void Display_level(t_d_list list, int level);

// Display_align
// param :  t_d_list list
// output : void
void Display_align(t_d_list list);

// Insert_list
// param : t_d_list* list, int  value, int level
// output : void
// ATTENTION TO THE ORDER OF THE INSERTION = MUST STAY A SORTED LIST
void Insert_list(t_d_list* list, int  value, int level);

// Display_all
// param : t_d_list list
// output : void
void Display_all(t_d_list list);


//For this last function, it is possible to make a 'simple' insertion at each level, starting
//from the beginning of the list, but it is possible to be more efficient - it's up to you
//to work out how.


#endif //TEST_PROJET_SET_H
