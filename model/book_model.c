#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "book_model.h"

static BookInfo *book_lst = NULL;
static ReaderInfo *reader_lst = NULL;
static BorrowedRecord *record_lst = NULL;
static BookCount *book_count_lst = NULL;

/* 初始化 */
void init() {
    book_lst = (BookInfo *) malloc(sizeof(BookInfo));
    reader_lst = (ReaderInfo *) malloc(sizeof(ReaderInfo));
    record_lst = (BorrowedRecord *) malloc(sizeof(BorrowedRecord));
    book_count_lst = (BookCount *) malloc(sizeof(BookCount));

    book_lst->next = NULL;
    reader_lst->next = NULL;
    record_lst->next = NULL;
    book_count_lst->next = NULL;
}

/* 保存 */
void save(char *book_db_name,
          char *reader_db_name,
          char *record_db_name) {
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
        printf("未读取到本地记录！\n");
        return;
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

/* 读取 */
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
        printf("未读取到完整的本地记录！\n");
    }

    while (1) {
        /* 创建空结点 */
        BookInfo *book_info = (BookInfo *) malloc(sizeof(BookInfo));

        /* 读取内容 */
        int count = fread(book_info, sizeof(BookInfo), 1, fp_book);

        /* 没有读到释放结点跳出循环 */
        if (count == 0) {
            free(book_info);
            break;
        }

        /* 添加到链表 */
        //update_book_count(book_info->book_name);
        add_book_info(book_info);
    }

    while (1) {
        /* 创建空结点 */
        ReaderInfo *reader_info = (ReaderInfo *) malloc(sizeof(ReaderInfo));

        /* 读取内容 */
        int count = fread(reader_info, sizeof(ReaderInfo), 1, fp_reader);

        /* 没有读到释放结点跳出循环 */
        if (count == 0) {
            free(reader_info);
            break;
        }

        /* 添加到链表 */
        add_reader_info(reader_info);
    }

    while (1) {
        /* 创建空结点 */
        BorrowedRecord *record_info = (BorrowedRecord *) malloc(sizeof(BorrowedRecord));

        /* 读取内容 */
        int count = fread(record_info, sizeof(BorrowedRecord), 1, fp_record);

        /* 没有读到释放结点跳出循环 */
        if (count == 0) {
            free(record_info);
            break;
        }

        /* 添加到链表 */
        add_record_info(record_info);
    }

    fclose(fp_book);
    fclose(fp_reader);
    fclose(fp_record);
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
int add_book_detail(char *book_no, char *book_name, char *type, char *writer_name) {
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
    strcpy(book_info->writer_name, writer_name);

    /* 添加到链表 */
    add_book_info(book_info);
    //update_book_count(book_name);

    return 1;
}

/* 通过作者姓名打印图书 */
void print_book_info_by_writer_name(char *writer_name) {
    if (NULL == book_lst) {
        printf("book_lst is NULL\n");
        return;
    }

    if (NULL != writer_name) {
        BookInfo *p = book_lst;

        while (p->next) {
            p = p->next;
            if (0 == strncmp(p->writer_name, writer_name, strlen(writer_name))) {
                printf("已找到书籍信息: 名称:%s 序号:%s 作者:%s 类别:%s 书籍数量:%d 借阅状态:%s",
                       p->book_name,
                       p->book_no,
                       p->writer_name,
                       p->type,
                       search_book_count_info(p->book_name)->count,
                       p->status == HAS_LENT ? "借出\n" : "未借出\n");
            }
        }

    }
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

/* 添加图书数量记录 */
void add_book_count_info(char *book_name, int count) {
    if (NULL == book_name) {
        return;
    }

    /* 创建空间 */
    BookCount *new_count_info = (BookCount *) malloc(sizeof(BookCount));

    /* 赋值 */
    new_count_info->count = count;
    strcpy(new_count_info->book_name, book_name);

    /* 添加结点 */
    new_count_info->next = book_count_lst->next;
    book_count_lst->next = new_count_info;
}

/* 添加图书数量 */
void update_book_count(char *book_name) {
    if (NULL == book_name || NULL == book_count_lst) {
        return;
    }

    BookCount *p = book_count_lst;

    /* 根据书名查找记录 */
    while (p->next) {
        p = p->next;
        if (0 == strncmp(p->book_name, book_name, strlen(book_name))) {
            p->count++;
            return;
        }
    }

    /* 未找到记录 */
    add_book_count_info(book_name, 1);
}

/* 查找图书数量记录 */
BookCount *search_book_count_info(char *book_name) {
    if (NULL == book_name) {
        printf("book_count_lst is NULL\n");
        return NULL;
    }

    if (NULL != book_name) {
        BookCount *p = book_count_lst;

        while (p->next) {
            p = p->next;
            if (0 == strncmp(p->book_name, book_name, strlen(book_name))) {
                return p;
            }
        }

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
int add_reader_detail(char *reader_no, char *reader_name) {
    /* 开辟空间 */
    ReaderInfo *reader_info = malloc(sizeof(ReaderInfo));
    if (NULL == reader_info) return 0;

    /* 初始化 */
    reader_info->next = NULL;

    /* 赋值 */
    strcpy(reader_info->reader_no, reader_no);
    strcpy(reader_info->reader_name, reader_name);

    /* 添加到链表 */
    add_reader_info(reader_info);

    return 1;
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

/* 借阅记录操作 */
/* 添加借阅记录 */
void add_record_info(BorrowedRecord *record_info) {
    if (NULL == record_info) {
        return;
    }

    record_info->next = record_lst->next;
    record_lst->next = record_info;
}

/* 根据详细信息添加借阅记录 */
int add_record_detail(char *time, char *reader_no, char *book_no, char *msg) {
    /* 开辟空间 */
    BorrowedRecord *record_info = malloc(sizeof(BorrowedRecord));
    if (NULL == record_info) return 0;

    /* 初始化 */
    record_info->next = NULL;
    record_info->is_delete = 0;

    /* 赋值 */
    strcpy(record_info->time, time);
    strcpy(record_info->reader_no, reader_no);
    strcpy(record_info->book_no, book_no);
    strcpy(record_info->msg, msg);

    /* 添加 */
    add_record_info(record_info);

    return 1;
}

/* 查找阅读记录 */
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

/* 打印所有借阅记录信息 */
int print_all_record_info() {
    int count = 0;
    BorrowedRecord *p = record_lst;
    BookInfo *find_book_info = NULL;
    ReaderInfo *find_reader_info = NULL;

    system("cls");

    while (p->next) {
        p = p->next;
        /* 查找图书和人员 */
        find_book_info = search_book_info(NULL, p->book_no);
        find_reader_info = search_reader_info(NULL, p->reader_no);

        /* 打印借阅信息 */
        printf("时间:%s 人员ID:%s 人员姓名:%s 图书序号:%s 图书姓名:%s 状态:%s\n",
               p->time,
               find_reader_info->reader_no,
               find_reader_info->reader_name,
               find_book_info->book_no,
               find_book_info->book_name,
               p->is_delete ? "已归还" : "未归还");

        ++count;
    }

    return count;
}

/* 打印读者阅读记录 */
int print_record_info(char *reader_no) {
    int count = 0;

    if (NULL != reader_no) {
        BorrowedRecord *p = record_lst;
        BookInfo *find_book_info = NULL;
        ReaderInfo *find_reader_info = NULL;

        while (p->next) {
            p = p->next;
            if (0 == strcmp(p->reader_no, reader_no)) {
                /* 查找图书和人员 */
                find_book_info = search_book_info(NULL, p->book_no);
                find_reader_info = search_reader_info(NULL, p->reader_no);

                /* 打印借阅信息 */
                printf("时间:%s 人员ID:%s 人员姓名:%s 图书序号:%s 图书姓名:%s 状态:%s\n",
                       p->time,
                       find_reader_info->reader_no,
                       find_reader_info->reader_name,
                       find_book_info->book_no,
                       find_book_info->book_name,
                       p->is_delete ? "已归还" : "未归还");

                ++count;
            }

        }
    }

    return count;
}
