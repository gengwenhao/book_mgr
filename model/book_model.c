#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "book_model.h"

static BookInfo *book_lst = NULL;
static ReaderInfo *reader_lst = NULL;
static BorrowedRecord *record_lst = NULL;

/* 初始化 */
void init() {
    book_lst = (BookInfo *) malloc(sizeof(BookInfo));
    reader_lst = (ReaderInfo *) malloc(sizeof(ReaderInfo));
    record_lst = (BorrowedRecord *) malloc(sizeof(BorrowedRecord));

    book_lst->next = NULL;
    reader_lst->next = NULL;
    record_lst->next = NULL;
}

/* 释放 */
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

/*  图书操作 */
/* 添加图书 */
void add_book_info(BookInfo *book_info) {
    if (NULL == book_lst) {
        return;
    }

    book_info->next = book_lst->next;
    book_lst->next = book_info;
}

/* 根据详细信息添加图书 */
int add_book_detail(char *book_no, char *book_name, char *type) {
    /* 开辟空间 */
    BookInfo *book_info = malloc(sizeof(BookInfo));
    if (NULL == book_info) return 0;

    /* 初始化 */
    book_info->next = NULL;
    book_info->status = HAS_NOT_LENT;

    /* 赋值 */
    strcpy(book_info->book_no, book_no);
    strcpy(book_info->book_name, book_name);
    strcpy(book_info->type, type);

    /* 添加到列表 */
    add_book_info(book_info);

    return 1;
}

/* 查找图书 */
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

/* 读者操作 */
/* 添加读者 */
void add_reader_info(ReaderInfo *reader_info) {
    if (NULL == reader_lst) {
        return;
    }

    reader_info->next = reader_lst->next;
    reader_lst->next = reader_info;
}

/* 根据详细信息添加读者 */
void add_reader_detail(char *reader_no, char *reader_name) {
    /* 开辟空间 */
    ReaderInfo *reader_info = malloc(sizeof(ReaderInfo));

    /* 初始化 */
    reader_info->next = NULL;

    /* 赋值 */
    strcpy(reader_info->reader_no, reader_no);
    strcpy(reader_info->reader_name, reader_name);
}

/* 查找读者 */
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

        printf("not found reader_name: %s\n", reader_name);
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

        printf("not found reader_no: %s\n", reader_no);
        return NULL;
    }
}

/* 阅读记录操作 */
/* 阅读记录操作 */
void add_record_info(BorrowedRecord *record_info) {
    if (NULL == record_info) {
        return;
    }

    record_info->next = record_lst->next;
    record_lst->next = record_info;
}

/* 根据详细信息添加阅读记录 */
void add_record_detail(char *time, char *reader_no, char *book_no, char *msg) {
    /* 开辟空间 */
    BorrowedRecord *record_info = malloc(sizeof(BorrowedRecord));

    /* 初始化 */
    record_info->next = NULL;

    /* 赋值 */
    strcpy(record_info->time, time);
    strcpy(record_info->reader_no, reader_no);
    strcpy(record_info->book_no, book_no);
    strcpy(record_info->msg, msg);
}

/* 查找阅读记录 */
BorrowedRecord *search_record_info(char *reader_no, char *book_no) {
    if (NULL == record_lst) {
        printf("record_lst is NULL\n");
        return NULL;
    }

    if (NULL != reader_no) {
        BorrowedRecord *p = record_lst;

        while (p->next) {
            p = p->next;
            if (0 == strcmp(p->reader_no, reader_no)) {
                return p;
            }
        }

        printf("not found reader_no: %s\n", reader_no);
        return NULL;
    }

    if (NULL != book_no) {
        BorrowedRecord *p = record_lst;

        while (p->next) {
            p = p->next;
            if (0 == strcmp(p->book_no, book_no)) {
                return p;
            }
        }

        printf("not found book_no: %s\n", book_no);
        return NULL;
    }
}
