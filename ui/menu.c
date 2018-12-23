#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "../model/book_model.h"

/* 显示书籍管理菜单 */
void show_book_mgr_menu() {
    printf("============书籍管理===========\n");
    printf("==========1.新增书籍===========\n");
    printf("==========2.信息维护===========\n");
    printf("==========3.类别管理===========\n");
    printf("==========4.返回上级===========\n");

    int sel_id = -1;
    scanf("%d", &sel_id);

    /* 书籍序号，名称，类别 */
    char book_no[16], book_name[16], type[16];

    switch (sel_id) {
        case 1:
            printf("输入书籍序号：\n");
            scanf("%s", book_no);
            printf("输入书籍名称：\n");
            scanf("%s", book_name);
            printf("输入书籍类型：\n");
            scanf("%s", type);
            if (add_book_detail(book_no, book_name, type)) {
                printf("添加完成:图书序号:%s 图书名称:%s 图书类别:%s\n", book_no, book_name, type);
            } else {
                printf("图书添加失败!\n");
            }
            break;
        case 2:
            memset(book_no, 0, sizeof(book_name));
            printf("输入要修改的书籍序号:\n");
            scanf("%s", book_no);

            /* 查找图书信息 */
            BookInfo *book_info = search_book_info(NULL, book_no);
            if (NULL == book_info) {
                printf("未找到图书信息\n");
                break;
            }

            /* 更新信息 */
            printf("输入书籍新名称：\n");
            scanf("%s", book_name);
            printf("输入书籍新类型：\n");
            scanf("%s", type);
            strcpy(book_info->book_name, book_name);
            strcpy(book_info->book_no, book_no);
            printf("修改完成:图书序号:%s 图书名称:%s 图书类别:%s\n",
                   book_info->book_no,
                   book_info->book_name,
                   book_info->type);
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
    printf("========== 1.借书 =========\n");
    printf("========== 2.还书 =========\n");
    printf("======== 3.返回上级 ========\n");

    int sel_id = 0;
    scanf("%d", &sel_id);

    switch (sel_id) {
        case 1:
            break;
        case 2:
            break;
        default:
            return;
    }

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

    /* 输入信息存储 */
    char book_no[16] = {0}, book_name[16] = {0}, reader_no[16] = {0};

    switch (sel_id) {
        case 1:
            memset(book_no, 0, sizeof(book_no));
            memset(book_name, 0, sizeof(book_name));

            printf("输入书籍序号:\n");
            scanf("%d", book_no);

            /* 查询书籍 */
            BookInfo *book_info = search_book_info(NULL, book_no);
            if (NULL == book_info) {
                system("cls");
                printf("书籍未找到!\n");
                break;
            } else {
                printf("书籍信息: 名称:%s 序号:%s 类别:%s 借阅状态:%s",
                       book_info->book_name,
                       book_info->book_no,
                       book_info->type,
                       book_info->status == HAS_LENT ? "借出\n" : "未借出\n");
            }
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
