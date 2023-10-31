//
// Created by Hawa Ajroud on 26/10/2023.
//

#include "set.h"

int main() {
    t_d_list list = Create_emp_list(5);



    Insert_Head(&list,3,91);
    Insert_Head(&list,5,59 );
    Insert_Head(&list,1,59 );
    Insert_Head(&list,3,56 );
    Insert_Head(&list,5,32 );
    Insert_Head(&list,2,31 );
    Insert_Head(&list,1,25 );
    Insert_Head(&list,4,18 );

    Insert_list(&list,4,2);
    Display_all(list);

    return 0;
}
