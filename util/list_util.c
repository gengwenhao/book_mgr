#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list_util.h"


typedef enum BOOK_STATUS {
    HAS_LENT,
    HAS_NOT_LENT,
} BOOK_STATUS;

/* 图书信息结构定义 */
typedef struct BookInfo {
    /* 书籍序号 */
    char book_no[16];

    /* 书籍名称 */
    char book_name[16];

    /* 书籍ID */
    char type[16];

    /* 书籍借阅状态 */
    BOOK_STATUS status;
    struct BookInfo *next;
} BookInfo;

/* 读者信息 */
typedef struct ReaderInfo {
    /* 读者卡号 */
    char reader_no[32];

    /* 读者姓名 */
    char name[32];
} ReaderInfo;

/* 借阅历史 */
typedef struct BorrowedRecord {
    /* 借阅时间 */
    char time[32];

    /* 借阅读者 */
    char reader_no;

    /* 借阅书籍 */
    char book_no;

    /* 借阅信息 */
    char msg[32];
} BorrowedRecord;
