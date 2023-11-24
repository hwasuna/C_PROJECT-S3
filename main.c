//
// Created by Hawa Ajroud on 26/10/2023.
//

#include "set.h"
int main() {
    t_d_list* list = Create_emp_list(10);

    Insert_Head(list,3,9);
    Insert_list(list,5,8 );
    Insert_list(list,4,10 );
    Insert_list(list,2,7);
    Insert_list(list,2,9 );
    Insert_list(list,4,6 );
    Insert_list(list,2,9 );




    Display_all(list);
    //Search_element(&list, 3);

    return 0;
}
