#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

/* ��ʾ�鼮����˵� */
void show_book_mgr_menu(){
    printf("==========�鼮����ҳ��==========\n");
}
/* ��ʾ���߹���˵� */

void show_reader_mgr_menu(){
    printf("==========���߹���==========\n");
}
/* ��ʾ���Ĺ���˵� */

void show_lead_mgr_menu(){
    printf("==========���Ĺ���==========\n");
}
/* ��ʾ�鿴�˵� */

void show_search_menu(){
    printf("============�鿴===========\n");
}

/* ��ʾ�˵� */
void show_menu(){
    printf("��ѡ�����:\n"
           "1.==========�鼮����==========\n"
           "2.==========���߹���==========\n"
           "3.==========���Ĺ���==========\n"
           "4.============�鿴===========\n:");

    int choice_id = -1;
    scanf("%d", &choice_id);
    switch (choice_id) {
        case 1:
            system("cls");
            printf("==�鼮����==\n");
            show_book_mgr_menu();
            break;
        case 2:
            system("cls");
            printf("==���߹���==\n");
            show_reader_mgr_menu();
            break;
        case 3:
            system("cls");
            printf("==���Ĺ���==\n");
            show_lead_mgr_menu();
            break;
        case 4:
            system("cls");
            printf("==�鿴==\n");
            show_search_menu();
            break;
        default:
            return;
    }

    system("cls");

    /* β�ݹ� */
    show_menu();
}

