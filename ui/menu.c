#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "../model/book_model.h"

/* ��ʾ�鼮����˵� */
void show_book_mgr_menu() {
    printf("============�鼮����===========\n");
    printf("==========1.�����鼮===========\n");
    printf("==========2.��Ϣά��===========\n");
    printf("==========3.������===========\n");
    printf("==========4.�����ϼ�===========\n");

    int sel_id = -1;
    scanf("%d", &sel_id);

    /* �鼮��ţ����ƣ���� */
    char book_no[16], book_name[16], type[16];

    switch (sel_id) {
        case 1:
            printf("�����鼮��ţ�\n");
            scanf("%s", book_no);
            printf("�����鼮���ƣ�\n");
            scanf("%s", book_name);
            printf("�����鼮���ͣ�\n");
            scanf("%s", type);
            if (add_book_detail(book_no, book_name, type)) {
                printf("������:ͼ�����:%s ͼ������:%s ͼ�����:%s\n", book_no, book_name, type);
            } else {
                printf("ͼ�����ʧ��!\n");
            }
            break;
        case 2:
            memset(book_no, 0, sizeof(book_name));
            printf("����Ҫ�޸ĵ��鼮���:\n");
            scanf("%s", book_no);

            /* ����ͼ����Ϣ */
            BookInfo *book_info = search_book_info(NULL, book_no);
            if (NULL == book_info) {
                printf("δ�ҵ�ͼ����Ϣ\n");
                break;
            }

            /* ������Ϣ */
            printf("�����鼮�����ƣ�\n");
            scanf("%s", book_name);
            printf("�����鼮�����ͣ�\n");
            scanf("%s", type);
            strcpy(book_info->book_name, book_name);
            strcpy(book_info->book_no, book_no);
            printf("�޸����:ͼ�����:%s ͼ������:%s ͼ�����:%s\n",
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
    printf("========== 1.���� =========\n");
    printf("========== 2.���� =========\n");
    printf("======== 3.�����ϼ� ========\n");

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

/* ��ʾ�鿴�˵� */
void show_search_menu() {
    printf("============�鿴===========\n");
    printf("==========1.�鼮��Ϣ��ѯ===========\n");
    printf("==========2.������Ϣ��ѯ===========\n");
    printf("==========3.������Ϣ��ѯ=======\n");
    printf("==========4.�����ϼ�===========\n");

    int sel_id = -1;
    scanf("%d", &sel_id);

    /* ������Ϣ�洢 */
    char book_no[16] = {0}, book_name[16] = {0}, reader_no[16] = {0};

    switch (sel_id) {
        case 1:
            memset(book_no, 0, sizeof(book_no));
            memset(book_name, 0, sizeof(book_name));

            printf("�����鼮���:\n");
            scanf("%d", book_no);

            /* ��ѯ�鼮 */
            BookInfo *book_info = search_book_info(NULL, book_no);
            if (NULL == book_info) {
                system("cls");
                printf("�鼮δ�ҵ�!\n");
                break;
            } else {
                printf("�鼮��Ϣ: ����:%s ���:%s ���:%s ����״̬:%s",
                       book_info->book_name,
                       book_info->book_no,
                       book_info->type,
                       book_info->status == HAS_LENT ? "���\n" : "δ���\n");
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
