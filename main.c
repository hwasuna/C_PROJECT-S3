//
// Created by Hawa Ajroud on 26/10/2023.
//
#include "set.h"

int main() {
    t_d_list list = Create_empty_lev_list(5);
    for(int i =0; i<5; i++)
    {
        Display_cells_level(list, i);
    }


    Insert_Cell_Head_list(&list,4,18 );
    Insert_Cell_Head_list(&list,1,25 );
    Insert_Cell_Head_list(&list,1,31 );
    Insert_Cell_Head_list(&list,1,32 );
    Insert_Cell_Head_list(&list,5,56 );
    Insert_Cell_Head_list(&list,1,25 );
    Insert_Cell_Head_list(&list,3,8);
    Insert_Cell_Head_list(&list,1,2 );

    for(int i =0; i<5; i++)
    {
        Display_cells_level(list, i);
    }

    return 0;
}
