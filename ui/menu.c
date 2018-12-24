#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "menu.h"
#include "../model/book_model.h"

/* 获取当前时间 */
char *get_time() {
    /* 指针数组-字符串 */
    char *wday[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    time_t timep;
    struct tm *p;
    time(&timep);
    /* 获取当前时间 */
    p = localtime(&timep);

    char *time_str = malloc(sizeof(char) * 100);
    sprintf(time_str, "%d年%d月%d日 %s %d:%d", (1900 + p->tm_year), (1 + p->tm_mon), p->tm_mday, wday[p->tm_wday],
            p->tm_hour,
            p->tm_min);

    return time_str;
}

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

    /* 查找到的书籍信息 */
    BookInfo *find_info = NULL;

    switch (sel_id) {
        case 1:
            system("cls");
            /* 数组置空 */
            memset(book_no, 0, sizeof(book_no));
            memset(book_name, 0, sizeof(book_name));
            memset(type, 0, sizeof(type));

            /* 输入信息 */
            printf("输入书籍序号：\n");
            scanf("%s", book_no);
            printf("输入书籍名称：\n");
            scanf("%s", book_name);
            printf("输入书籍类型：\n");
            scanf("%s", type);

            /* 添加图书信息 */
            if (add_book_detail(book_no, book_name, type)) {
                system("cls");
                printf("添加完成:图书序号:%s 图书名称:%s 图书类别:%s\n", book_no, book_name, type);
            } else {
                system("cls");
                printf("图书添加失败!\n");
            }

            break;
        case 2:
            system("cls");
            /* 数组置空 */
            memset(book_no, 0, sizeof(book_name));
            find_info = NULL;
            printf("输入要修改的书籍序号:\n");

            /* 输入信息 */
            scanf("%s", book_no);

            /* 查找图书信息 */
            find_info = search_book_info(NULL, book_no);
            if (NULL == find_info) {
                printf("未找到图书信息\n");
                break;
            }

            /* 更新信息 */
            printf("输入书籍新名称：\n");
            scanf("%s", book_name);

            /* 赋值 */
            strcpy(find_info->book_name, book_name);

            /* 显示新数据 */
            system("cls");
            printf("修改完成:图书序号:%s 图书名称:%s 图书类别:%s\n",
                   find_info->book_no,
                   find_info->book_name,
                   find_info->type);
            break;
        case 3:
            system("cls");
            /* 数组置空 */
            memset(book_no, 0, sizeof(book_no));
            find_info = NULL;
            printf("输入要修改类型的书籍序号:\n");

            /* 输入信息 */
            scanf("%s", book_no);

            /* 查找图书信息 */
            find_info = search_book_info(NULL, book_no);
            if (NULL == find_info) {
                printf("未找到图书信息\n");
                break;
            }

            /* 更新信息 */
            printf("输入书籍新类型：\n");
            scanf("%s", type);

            /* 赋值 */
            strcpy(find_info->type, type);

            /* 显示新数据 */
            system("cls");
            printf("修改完成:图书序号:%s 图书名称:%s 图书类别:%s\n",
                   find_info->book_no,
                   find_info->book_name,
                   find_info->type);
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

    /* 输入数据定义 */
    char reader_no[32] = {0}, reader_name[32] = {0};
    ReaderInfo *find_info = NULL;
    BorrowedRecord *find_record_info = NULL;

    switch (sel_id) {
        case 1:
            system("cls");
            /* 输入读者信息 */
            printf("输入读者ID：\n");
            scanf("%s", reader_no);
            printf("输入读者姓名：\n");
            scanf("%s", reader_name);

            /* 添加人员信息 */
            if (add_reader_detail(reader_no, reader_name)) {
                system("cls");
                printf("添加完成:人员姓名:%s 人员ID:%s\n", reader_name, reader_no);
            } else {
                system("cls");
                printf("人员添加失败!\n");
            }

            break;
        case 2:
            /* 数组置空 */
            memset(reader_no, 0, sizeof(reader_no));
            memset(reader_name, 0, sizeof(reader_name));
            find_info = NULL;
            printf("输入要修改的人员ID:\n");

            /* 输入信息 */
            scanf("%s", reader_no);

            /* 查找人员信息 */
            system("cls");
            find_info = search_reader_info(NULL, reader_no);
            if (NULL == find_info) {
                printf("未找到该人员信息\n");
                break;
            }

            /* 更新信息 */
            printf("请输入新的姓名：\n");
            scanf("%s", reader_name);

            /* 赋值 */
            strcpy(find_info->reader_name, reader_name);

            /* 显示新数据 */
            system("cls");
            printf("修改完成:读者ID:%s 姓名:%s\n",
                   find_info->reader_no,
                   find_info->reader_name);
            break;
        case 3:
            system("cls");
            /* 数组置空 */
            memset(reader_no, 0, sizeof(reader_no));
            find_record_info = NULL;

            /* 输入 */
            printf("输入要查看记录人员ID:\n");
            scanf("%s", reader_no);

            /* 打印结果 */
            system("cls");
            int count = print_record_info(reader_no);
            printf("=========================================%d条记录===========================================\n", count);
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

    /* 输入数据定义 */
    char time[32] = {0}, book_no[16] = {0}, reader_no[16] = {0}, msg[32] = {0};
    BorrowedRecord *find_info = NULL;
    BookInfo *find_book_info = NULL;
    ReaderInfo *find_reader_info = NULL;

    switch (sel_id) {
        case 1:
            system("cls");

            /* 数组置空 */
            memset(time, 0, sizeof(time));
            memset(book_no, 0, sizeof(book_no));
            memset(reader_no, 0, sizeof(reader_no));
            memset(msg, 0, sizeof(msg));
            find_info = NULL;

            /* 输入图书名称 */
            printf("输入要借图书ID：\n");
            scanf("%s", book_no);
            printf("输入读者ID：\n");
            scanf("%s", reader_no);
            printf("输入留言：\n");
            scanf("%s", msg);

            /* 添加时间 */
            char *time_str = get_time();

            /* 添加人员信息 */
            if (add_record_detail(time_str, reader_no, book_no, msg)) {
                free(time_str);
                system("cls");

                /* 查找图书和人员 */
                find_book_info = search_book_info(NULL, book_no);
                find_reader_info = search_reader_info(NULL, reader_no);
                if (NULL == find_book_info || NULL == find_reader_info) {
                    printf("借阅失败!\n");
                    return;
                }

                /* 打印借阅信息 */
                printf("借书完成！时间:%s 人员ID:%s 人员姓名:%s 图书序号:%s 图书姓名:%s\n",
                       time,
                       find_reader_info->reader_no,
                       find_reader_info->reader_name,
                       find_book_info->book_no,
                       find_book_info->book_name);
            } else {
                system("cls");
                printf("人员添加失败!\n");
            }
            break;
        case 2:
            system("cls");

            /* 数组置空 */
            memset(book_no, 0, sizeof(book_no));
            memset(reader_no, 0, sizeof(reader_no));
            find_info = NULL;
            find_book_info = NULL;
            find_reader_info = NULL;

            /* 输入图书名称 */
            printf("输入要还图书ID：\n");
            scanf("%s", book_no);
            printf("输入借书人员ID：\n");
            scanf("%s", reader_no);

            /* 查找借书记录 */
            find_info = search_record_info(reader_no, book_no);
            if (NULL == find_info) {
                printf("借书记录未找到！\n");
                return;
            }

            find_info->is_delete = 1;

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
            /* 数组置空 */
            memset(book_no, 0, sizeof(book_no));

            /* 输入信息 */
            printf("输入书籍序号:\n");
            scanf("%s", book_no);

            /* 查询书籍 */
            BookInfo *book_info = search_book_info(NULL, book_no);
            if (NULL == book_info) {
                system("cls");
                printf("书籍未找到!\n");
            } else {
                system("cls");
                printf("已找到书籍信息: 名称:%s 序号:%s 类别:%s 借阅状态:%s",
                       book_info->book_name,
                       book_info->book_no,
                       book_info->type,
                       book_info->status == HAS_LENT ? "借出\n" : "未借出\n");
            }

            break;
        case 2:
            /* 数组置空 */
            memset(reader_no, 0, sizeof(reader_no));

            /* 输入信息 */
            printf("输入读者ID:\n");
            scanf("%s", reader_no);

            /* 查询人员 */
            ReaderInfo *reader_info = search_reader_info(NULL, reader_no);
            if (NULL == reader_info) {
                system("cls");
                printf("该人员信息未找到!\n");
            } else {
                system("cls");
                printf("已找到人员信息: 姓名:%s ID:%s\n",
                       reader_info->reader_no,
                       reader_info->reader_name);
            }

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
