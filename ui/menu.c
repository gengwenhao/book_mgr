#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

/* ��ʾ�鼮����˵� */
void show_book_mgr_menu() {
    printf("============�鼮����===========\n");
    printf("==========1.�����鼮===========\n");
    printf("==========2.��Ϣά��===========\n");
    printf("==========3.������===========\n");
    printf("==========4.�����ϼ�===========\n");

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

/* ��ʾ���߹���˵� */
void show_reader_mgr_menu() {
    printf("============���߹���===========\n");
    printf("==========1.��������===========\n");
    printf("==========2.��Ϣά��===========\n");
    printf("==========3.������ʷ�鿴=======\n");
    printf("==========4.�����ϼ�===========\n");

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

/* ��ʾ���Ĺ���˵� */
void show_lead_mgr_menu() {
    printf("==========���Ĺ���==========\n");
    char borrow_book_name[32] = {0};

    printf("����Ҫ����ͼ��:\n");
    scanf("%s", borrow_book_name);

    printf("OK");
    getchar();
    getchar();
}

/* ��ʾ�鿴�˵� */
void show_search_menu() {
    printf("============�鿴===========\n");
    printf("==========1.�鼮��Ϣ��ѯ===========\n");
    printf("==========2.������Ϣ��ѯ===========\n");
    printf("==========3.������Ϣ��ѯ=======\n");
    printf("==========4.�����ϼ�===========\n");

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

/* ��ʾ���˵� */
void show_menu() {
    printf("��ѡ�����:\n"
           "1.========== �鼮���� ==========\n"
           "2.========== ���߹��� ==========\n"
           "3.========== ���Ĺ��� ==========\n"
           "4.==========   �鿴  ==========\n"
           "5.==========   �˳�  ========\n:");

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

    /* β�ݹ� */
    show_menu();
}
