#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

/* 显示书籍管理菜单 */
void show_book_mgr_menu() {
    printf("============书籍管理===========\n");
    printf("==========1.新增书籍===========\n");
    printf("==========2.信息维护===========\n");
    printf("==========3.类别管理===========\n");
    printf("==========4.返回上级===========\n");

    int sel_id = -1;
    scanf("%d", &sel_id);

    switch (sel_id) {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        default:
            return;
    }

    show_book_mgr_menu();
}

/* 显示读者管理菜单 */
void show_reader_mgr_menu() {
    printf("============读者管理===========\n");
    printf("==========1.新增读者===========\n");
    printf("==========2.信息维护===========\n");
    printf("==========3.借阅历史查看=======\n");
    printf("==========4.返回上级===========\n");

    int sel_id = -1;
    scanf("%d", &sel_id);

    switch (sel_id) {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        default:
            return;
    }

    show_reader_mgr_menu();
}

/* 显示借阅管理菜单 */
void show_lead_mgr_menu() {
    printf("==========借阅管理==========\n");
    char borrow_book_name[32] = {0};

    printf("输入要借阅图书:\n");
    scanf("%s", borrow_book_name);

    printf("OK");
    getchar();
    getchar();
}

/* 显示查看菜单 */
void show_search_menu() {
    printf("============查看===========\n");
    printf("==========1.书籍信息查询===========\n");
    printf("==========2.读者信息查询===========\n");
    printf("==========3.借阅信息查询=======\n");
    printf("==========4.返回上级===========\n");

    int sel_id = -1;
    scanf("%d", &sel_id);

    switch (sel_id) {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        default:
            return;
    }

    show_search_menu();
}

/* 显示主菜单 */
void show_menu() {
    printf("请选择序号:\n"
           "1.========== 书籍管理 ==========\n"
           "2.========== 读者管理 ==========\n"
           "3.========== 借阅管理 ==========\n"
           "4.==========   查看  ==========\n"
           "5.==========   退出  ========\n:");

    int sel_id = -1;
    scanf("%d", &sel_id);

    switch (sel_id) {
        case 1:
            system("cls");
            show_book_mgr_menu();
            break;
        case 2:
            system("cls");
            show_reader_mgr_menu();
            break;
        case 3:
            system("cls");
            show_lead_mgr_menu();
            break;
        case 4:
            system("cls");
            show_search_menu();
            break;
        default:
            return;
    }
    system("cls");

    /* 尾递归 */
    show_menu();
}
