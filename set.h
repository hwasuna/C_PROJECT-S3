#ifndef TEST_PROJET_SET_H
#define TEST_PROJET_SET_H
//
// Created by Hawa Ajroud on 26/10/2023.
//


//Cell
typedef struct s_d_cell {
    int value;
    struct s_d_cell** next;
    struct s_d_cell** prec;
} t_d_cell;

typedef struct s_d_list {
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
t_d_list* Create_emp_list(int maxLevel);


//Insert_Head
// param : t_d_list* list, int level, int  value
// output : void
void Insert_Head(t_d_list* list, int value, int levels);

// Display_level
// param : t_d_list list, int level
// output : void
void Display_level(t_d_list* list, int level);

// Display_align
// param :  t_d_list list
// output : void
void Display_align(t_d_list list);

// Insert_list
// param : t_d_list* list, int  level, int value
// output : void
// ATTENTION TO THE ORDER OF THE INSERTION = MUST STAY A SORTED LIST
void Insert_list(t_d_list* list, int value, int levels) ;

// Display_all
// param : t_d_list list
// output : void
void Display_all(t_d_list* list);


/////Part 2//////
t_d_list * Level_list_P4(int n);

// Search_lvl_0
// param : t_d_list list, int value
// output : int
int Search_lvl_0(t_d_list list, int value);

// Search_lvl_max
// param : t_d_list* list, int value, int bound
// output : int
int Search_lvl_max(t_d_list* list, int value);

#endif //TEST_PROJET_SET_H