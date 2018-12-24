#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "book_model.h"

static BookInfo *book_lst = NULL;
static ReaderInfo *reader_lst = NULL;
static BorrowedRecord *record_lst = NULL;

/* ��ʼ�� */
void init() {
    book_lst = (BookInfo *) malloc(sizeof(BookInfo));
    reader_lst = (ReaderInfo *) malloc(sizeof(ReaderInfo));
    record_lst = (BorrowedRecord *) malloc(sizeof(BorrowedRecord));

    book_lst->next = NULL;
    reader_lst->next = NULL;
    record_lst->next = NULL;
}

/* ���� */
void save(char *book_db_name, char *reader_db_name, char *record_db_name) {
    BookInfo *book_p = book_lst;
    ReaderInfo *reader_p = reader_lst;
    BorrowedRecord *record_p = record_lst;

    if (NULL == book_db_name) {
        book_db_name = "book.db";
    }
    if (NULL == reader_db_name) {
        reader_db_name = "reader.db";
    }
    if (NULL == record_db_name) {
        record_db_name = "record.db";
    }

    FILE *fp_book = fopen(book_db_name, "w");
    FILE *fp_reader = fopen(reader_db_name, "w");
    FILE *fp_record = fopen(record_db_name, "w");
    if (NULL == fp_book || NULL == fp_reader || NULL == fp_record) {
        printf("load file error��\n");
    }

    while (book_p->next) {
        book_p = book_p->next;
        fwrite(book_p, sizeof(BookInfo), 1, fp_book);
    }

    while (reader_p->next) {
        reader_p = reader_p->next;
        fwrite(reader_p, sizeof(ReaderInfo), 1, fp_reader);
    }

    while (record_p->next) {
        record_p = record_p->next;
        fwrite(record_p, sizeof(BorrowedRecord), 1, fp_record);
    }

    fclose(fp_book);
    fclose(fp_reader);
    fclose(fp_record);
}

/* ��ȡ */
void load(char *book_db_name, char *reader_db_name, char *record_db_name) {
    if (NULL == book_lst || NULL == reader_lst || NULL == record_lst) {
        printf("lst not init");
    }

    if (NULL == book_db_name) {
        book_db_name = "book.db";
    }
    if (NULL == reader_db_name) {
        reader_db_name = "reader.db";
    }
    if (NULL == record_db_name) {
        record_db_name = "record.db";
    }

    FILE *fp_book = fopen(book_db_name, "r");
    FILE *fp_reader = fopen(reader_db_name, "r");
    FILE *fp_record = fopen(record_db_name, "r");
    if (NULL == fp_book || NULL == fp_reader || NULL == fp_record) {
        printf("load file error��\n");
    }

    while (book_lst->next) {
        book_lst = book_lst->next;
        fread(book_lst, sizeof(BookInfo), 1, fp_book);
    }

    while (reader_lst->next) {
        reader_lst = reader_lst->next;
        fwrite(reader_lst, sizeof(ReaderInfo), 1, fp_reader);
    }

    while (record_lst->next) {
        record_lst = record_lst->next;
        fwrite(record_lst, sizeof(BorrowedRecord), 1, fp_record);
    }

    fclose(fp_book);
    fclose(fp_reader);
    fclose(fp_record);
}

/* �ͷ� */
void destroy() {
    BookInfo *book_p = book_lst;
    if (NULL != book_p) {
        while (book_p->next) {
            BookInfo *next_p = book_p->next;
            free(book_p);
            book_p = next_p;
        }
    }

    ReaderInfo *reader_p = reader_lst;
    if (NULL != reader_p) {
        while (reader_p->next) {
            ReaderInfo *next_p = reader_p->next;
            free(reader_p);
            reader_p = next_p;
        }
    }

    BorrowedRecord *record_p = record_lst;
    if (NULL != record_p) {
        while (record_p->next) {
            BorrowedRecord *next_p = record_p->next;
            free(record_p);
            record_p = next_p;
        }
    }
}

/*  ͼ����� */
/* ���ͼ�� */
void add_book_info(BookInfo *book_info) {
    if (NULL == book_lst) {
        return;
    }

    book_info->next = book_lst->next;
    book_lst->next = book_info;
}

/* ������ϸ��Ϣ���ͼ�� */
int add_book_detail(char *book_no, char *book_name, char *type) {
    /* ���ٿռ� */
    BookInfo *book_info = malloc(sizeof(BookInfo));
    if (NULL == book_info) return 0;

    /* ��ʼ�� */
    book_info->next = NULL;
    book_info->status = HAS_NOT_LENT;

    /* ��ֵ */
    strcpy(book_info->book_no, book_no);
    strcpy(book_info->book_name, book_name);
    strcpy(book_info->type, type);

    /* ��ӵ����� */
    add_book_info(book_info);

    return 1;
}

/* ����ͼ�� */
BookInfo *search_book_info(char *book_name, char *book_no) {
    if (NULL == book_lst) {
        printf("book_lst is NULL\n");
        return NULL;
    }

    if (NULL != book_name) {
        BookInfo *p = book_lst;

        while (p->next) {
            p = p->next;
            if (0 == strncmp(p->book_name, book_name, strlen(book_name))) {
                return p;
            }
        }

        printf("not found book_name: %s\n", book_name);
        return NULL;
    }

    if (NULL != book_no) {
        BookInfo *p = book_lst;

        while (p->next) {
            p = p->next;
            if (0 == strncmp(p->book_no, book_no, strlen(book_no))) {
                return p;
            }
        }

        printf("not found book_no: %s\n", book_no);
        return NULL;
    }
}

/* ���߲��� */
/* ��Ӷ��� */
void add_reader_info(ReaderInfo *reader_info) {
    if (NULL == reader_lst) {
        return;
    }

    reader_info->next = reader_lst->next;
    reader_lst->next = reader_info;
}

/* ������ϸ��Ϣ��Ӷ��� */
int add_reader_detail(char *reader_no, char *reader_name) {
    /* ���ٿռ� */
    ReaderInfo *reader_info = malloc(sizeof(ReaderInfo));
    if (NULL == reader_info) return 0;

    /* ��ʼ�� */
    reader_info->next = NULL;

    /* ��ֵ */
    strcpy(reader_info->reader_no, reader_no);
    strcpy(reader_info->reader_name, reader_name);

    /* ��ӵ����� */
    add_reader_info(reader_info);

    return 1;
}

/* ���Ҷ��� */
ReaderInfo *search_reader_info(char *reader_name, char *reader_no) {
    if (NULL == reader_lst) {
        printf("reader_lst is NULL\n");
        return NULL;
    }

    if (NULL != reader_name) {
        ReaderInfo *p = reader_lst;

        while (p->next) {
            p = p->next;
            if (0 == strcmp(p->reader_name, reader_name)) {
                return p;
            }
        }

        return NULL;
    }

    if (NULL != reader_no) {
        ReaderInfo *p = reader_lst;

        while (p->next) {
            p = p->next;
            if (0 == strcmp(p->reader_no, reader_no)) {
                return p;
            }
        }

        return NULL;
    }
}

/* �Ķ���¼���� */
/* ����Ķ���¼ */
void add_record_info(BorrowedRecord *record_info) {
    if (NULL == record_info) {
        return;
    }

    record_info->next = record_lst->next;
    record_lst->next = record_info;
}

/* ������ϸ��Ϣ��ӽ��ļ�¼ */
int add_record_detail(char *time, char *reader_no, char *book_no, char *msg) {
    /* ���ٿռ� */
    BorrowedRecord *record_info = malloc(sizeof(BorrowedRecord));
    if (NULL == record_info) return 0;

    /* ��ʼ�� */
    record_info->next = NULL;
    record_info->is_delete = 0;

    /* ��ֵ */
    strcpy(record_info->time, time);
    strcpy(record_info->reader_no, reader_no);
    strcpy(record_info->book_no, book_no);
    strcpy(record_info->msg, msg);

    /* ��� */
    add_record_info(record_info);

    return 1;
}

/* �����Ķ���¼ */
BorrowedRecord *search_record_info(char *reader_no, char *book_no) {
    if (NULL == record_lst) {
        printf("record_lst is NULL\n");
        return NULL;
    }

    if (NULL != reader_no && NULL != book_no) {
        BorrowedRecord *p = record_lst;

        while (p->next) {
            p = p->next;
            if (0 == strcmp(p->reader_no, reader_no) && 0 == strcmp(p->book_no, book_no)) {
                return p;
            }
        }

        printf("not found record reader_no: %s book_no: %s\n", reader_no, book_no);
    }


    return NULL;
}

/* ��ӡ���н��ļ�¼��Ϣ */
int print_all_record_info() {
    int count = 0;
    BorrowedRecord *p = record_lst;
    BookInfo *find_book_info = NULL;
    ReaderInfo *find_reader_info = NULL;

    system("cls");

    while (p->next) {
        p = p->next;
        /* ����ͼ�����Ա */
        find_book_info = search_book_info(NULL, p->book_no);
        find_reader_info = search_reader_info(NULL, p->reader_no);

        /* ��ӡ������Ϣ */
        printf("ʱ��:%s ��ԱID:%s ��Ա����:%s ͼ�����:%s ͼ������:%s\n",
               p->time,
               find_reader_info->reader_no,
               find_reader_info->reader_name,
               find_book_info->book_no,
               find_book_info->book_name);

        ++count;
    }

    return count;
}

/* ��ӡ�����Ķ���¼ */
int print_record_info(char *reader_no) {
    int count = 0;

    if (NULL != reader_no) {
        BorrowedRecord *p = record_lst;
        BookInfo *find_book_info = NULL;
        ReaderInfo *find_reader_info = NULL;

        while (p->next) {
            p = p->next;
            if (0 == strcmp(p->reader_no, reader_no)) {
                /* ����ͼ�����Ա */
                find_book_info = search_book_info(NULL, p->book_no);
                find_reader_info = search_reader_info(NULL, p->reader_no);

                /* ��ӡ������Ϣ */
                printf("ʱ��:%s ��ԱID:%s ��Ա����:%s ͼ�����:%s ͼ������:%s\n",
                       p->time,
                       find_reader_info->reader_no,
                       find_reader_info->reader_name,
                       find_book_info->book_no,
                       find_book_info->book_name);

                ++count;
            }

        }
    }

    return count;
}
