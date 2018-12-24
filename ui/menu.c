#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "menu.h"
#include "../model/book_model.h"

/* ��ȡ��ǰʱ�� */
char *get_time() {
    /* ָ������-�ַ��� */
    char *wday[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    time_t timep;
    struct tm *p;
    time(&timep);
    /* ��ȡ��ǰʱ�� */
    p = localtime(&timep);

    char *time_str = malloc(sizeof(char) * 100);
    sprintf(time_str, "%d��%d��%d�� %s %d:%d", (1900 + p->tm_year), (1 + p->tm_mon), p->tm_mday, wday[p->tm_wday],
            p->tm_hour,
            p->tm_min);

    return time_str;
}

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

    /* ���ҵ����鼮��Ϣ */
    BookInfo *find_info = NULL;

    switch (sel_id) {
        case 1:
            system("cls");
            /* �����ÿ� */
            memset(book_no, 0, sizeof(book_no));
            memset(book_name, 0, sizeof(book_name));
            memset(type, 0, sizeof(type));

            /* ������Ϣ */
            printf("�����鼮��ţ�\n");
            scanf("%s", book_no);
            printf("�����鼮���ƣ�\n");
            scanf("%s", book_name);
            printf("�����鼮���ͣ�\n");
            scanf("%s", type);

            /* ���ͼ����Ϣ */
            if (add_book_detail(book_no, book_name, type)) {
                system("cls");
                printf("������:ͼ�����:%s ͼ������:%s ͼ�����:%s\n", book_no, book_name, type);
            } else {
                system("cls");
                printf("ͼ�����ʧ��!\n");
            }

            break;
        case 2:
            system("cls");
            /* �����ÿ� */
            memset(book_no, 0, sizeof(book_name));
            find_info = NULL;
            printf("����Ҫ�޸ĵ��鼮���:\n");

            /* ������Ϣ */
            scanf("%s", book_no);

            /* ����ͼ����Ϣ */
            find_info = search_book_info(NULL, book_no);
            if (NULL == find_info) {
                printf("δ�ҵ�ͼ����Ϣ\n");
                break;
            }

            /* ������Ϣ */
            printf("�����鼮�����ƣ�\n");
            scanf("%s", book_name);

            /* ��ֵ */
            strcpy(find_info->book_name, book_name);

            /* ��ʾ������ */
            system("cls");
            printf("�޸����:ͼ�����:%s ͼ������:%s ͼ�����:%s\n",
                   find_info->book_no,
                   find_info->book_name,
                   find_info->type);
            break;
        case 3:
            system("cls");
            /* �����ÿ� */
            memset(book_no, 0, sizeof(book_no));
            find_info = NULL;
            printf("����Ҫ�޸����͵��鼮���:\n");

            /* ������Ϣ */
            scanf("%s", book_no);

            /* ����ͼ����Ϣ */
            find_info = search_book_info(NULL, book_no);
            if (NULL == find_info) {
                printf("δ�ҵ�ͼ����Ϣ\n");
                break;
            }

            /* ������Ϣ */
            printf("�����鼮�����ͣ�\n");
            scanf("%s", type);

            /* ��ֵ */
            strcpy(find_info->type, type);

            /* ��ʾ������ */
            system("cls");
            printf("�޸����:ͼ�����:%s ͼ������:%s ͼ�����:%s\n",
                   find_info->book_no,
                   find_info->book_name,
                   find_info->type);
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

    /* �������ݶ��� */
    char reader_no[32] = {0}, reader_name[32] = {0};
    ReaderInfo *find_info = NULL;
    BorrowedRecord *find_record_info = NULL;

    switch (sel_id) {
        case 1:
            system("cls");
            /* ���������Ϣ */
            printf("�������ID��\n");
            scanf("%s", reader_no);
            printf("�������������\n");
            scanf("%s", reader_name);

            /* �����Ա��Ϣ */
            if (add_reader_detail(reader_no, reader_name)) {
                system("cls");
                printf("������:��Ա����:%s ��ԱID:%s\n", reader_name, reader_no);
            } else {
                system("cls");
                printf("��Ա���ʧ��!\n");
            }

            break;
        case 2:
            /* �����ÿ� */
            memset(reader_no, 0, sizeof(reader_no));
            memset(reader_name, 0, sizeof(reader_name));
            find_info = NULL;
            printf("����Ҫ�޸ĵ���ԱID:\n");

            /* ������Ϣ */
            scanf("%s", reader_no);

            /* ������Ա��Ϣ */
            system("cls");
            find_info = search_reader_info(NULL, reader_no);
            if (NULL == find_info) {
                printf("δ�ҵ�����Ա��Ϣ\n");
                break;
            }

            /* ������Ϣ */
            printf("�������µ�������\n");
            scanf("%s", reader_name);

            /* ��ֵ */
            strcpy(find_info->reader_name, reader_name);

            /* ��ʾ������ */
            system("cls");
            printf("�޸����:����ID:%s ����:%s\n",
                   find_info->reader_no,
                   find_info->reader_name);
            break;
        case 3:
            system("cls");
            /* �����ÿ� */
            memset(reader_no, 0, sizeof(reader_no));
            find_record_info = NULL;

            /* ���� */
            printf("����Ҫ�鿴��¼��ԱID:\n");
            scanf("%s", reader_no);

            /* ��ӡ��� */
            system("cls");
            int count = print_record_info(reader_no);
            printf("=========================================%d����¼===========================================\n", count);
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

    /* �������ݶ��� */
    char time[32] = {0}, book_no[16] = {0}, reader_no[16] = {0}, msg[32] = {0};
    BorrowedRecord *find_info = NULL;
    BookInfo *find_book_info = NULL;
    ReaderInfo *find_reader_info = NULL;

    switch (sel_id) {
        case 1:
            system("cls");

            /* �����ÿ� */
            memset(time, 0, sizeof(time));
            memset(book_no, 0, sizeof(book_no));
            memset(reader_no, 0, sizeof(reader_no));
            memset(msg, 0, sizeof(msg));
            find_info = NULL;

            /* ����ͼ������ */
            printf("����Ҫ��ͼ��ID��\n");
            scanf("%s", book_no);
            printf("�������ID��\n");
            scanf("%s", reader_no);
            printf("�������ԣ�\n");
            scanf("%s", msg);

            /* ���ʱ�� */
            char *time_str = get_time();

            /* �����Ա��Ϣ */
            if (add_record_detail(time_str, reader_no, book_no, msg)) {
                free(time_str);
                system("cls");

                /* ����ͼ�����Ա */
                find_book_info = search_book_info(NULL, book_no);
                find_reader_info = search_reader_info(NULL, reader_no);
                if (NULL == find_book_info || NULL == find_reader_info) {
                    printf("����ʧ��!\n");
                    return;
                }

                /* ��ӡ������Ϣ */
                printf("������ɣ�ʱ��:%s ��ԱID:%s ��Ա����:%s ͼ�����:%s ͼ������:%s\n",
                       time,
                       find_reader_info->reader_no,
                       find_reader_info->reader_name,
                       find_book_info->book_no,
                       find_book_info->book_name);
            } else {
                system("cls");
                printf("��Ա���ʧ��!\n");
            }
            break;
        case 2:
            system("cls");

            /* �����ÿ� */
            memset(book_no, 0, sizeof(book_no));
            memset(reader_no, 0, sizeof(reader_no));
            find_info = NULL;
            find_book_info = NULL;
            find_reader_info = NULL;

            /* ����ͼ������ */
            printf("����Ҫ��ͼ��ID��\n");
            scanf("%s", book_no);
            printf("���������ԱID��\n");
            scanf("%s", reader_no);

            /* ���ҽ����¼ */
            find_info = search_record_info(reader_no, book_no);
            if (NULL == find_info) {
                printf("�����¼δ�ҵ���\n");
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
            /* �����ÿ� */
            memset(book_no, 0, sizeof(book_no));

            /* ������Ϣ */
            printf("�����鼮���:\n");
            scanf("%s", book_no);

            /* ��ѯ�鼮 */
            BookInfo *book_info = search_book_info(NULL, book_no);
            if (NULL == book_info) {
                system("cls");
                printf("�鼮δ�ҵ�!\n");
            } else {
                system("cls");
                printf("���ҵ��鼮��Ϣ: ����:%s ���:%s ���:%s ����״̬:%s",
                       book_info->book_name,
                       book_info->book_no,
                       book_info->type,
                       book_info->status == HAS_LENT ? "���\n" : "δ���\n");
            }

            break;
        case 2:
            /* �����ÿ� */
            memset(reader_no, 0, sizeof(reader_no));

            /* ������Ϣ */
            printf("�������ID:\n");
            scanf("%s", reader_no);

            /* ��ѯ��Ա */
            ReaderInfo *reader_info = search_reader_info(NULL, reader_no);
            if (NULL == reader_info) {
                system("cls");
                printf("����Ա��Ϣδ�ҵ�!\n");
            } else {
                system("cls");
                printf("���ҵ���Ա��Ϣ: ����:%s ID:%s\n",
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
