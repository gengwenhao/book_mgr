#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

/* 显示书籍管理菜单 */
void show_book_mgr_menu(){
    printf("==========书籍管理页面==========\n");
}
/* 显示读者管理菜单 */

void show_reader_mgr_menu(){
    printf("==========读者管理==========\n");
}
/* 显示借阅管理菜单 */

void show_lead_mgr_menu(){
    printf("==========借阅管理==========\n");
}
/* 显示查看菜单 */

void show_search_menu(){
    printf("============查看===========\n");
}

/* 显示菜单 */
void show_menu(){
    printf("请选择序号:\n"
           "1.==========书籍管理==========\n"
           "2.==========读者管理==========\n"
           "3.==========借阅管理==========\n"
           "4.============查看===========\n:");

    int choice_id = -1;
    scanf("%d", &choice_id);
    switch (choice_id) {
        case 1:
            system("cls");
            printf("==书籍管理==\n");
            show_book_mgr_menu();
            break;
        case 2:
            system("cls");
            printf("==读者管理==\n");
            show_reader_mgr_menu();
            break;
        case 3:
            system("cls");
            printf("==借阅管理==\n");
            show_lead_mgr_menu();
            break;
        case 4:
            system("cls");
            printf("==查看==\n");
            show_search_menu();
            break;
        default:
            return;
    }

    system("cls");

    /* 尾递归 */
    show_menu();
}

