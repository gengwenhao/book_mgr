//
// Created by gengw on 2018/12/20.
//

#ifndef BOOK_MGR_20181220_UTIL_H
#define BOOK_MGR_20181220_UTIL_H

int test();

/* 保存 */
void save(char *book_db_name,
          char *reader_db_name,
          char *record_db_name);

/* 读取 */
void load(char *book_db_name,
          char *reader_db_name,
          char *record_db_name);

/* 初始化 */
void init();

/* 释放 */
void destroy();

/* 数据结构 */
/* 图书借阅状态 */
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

    /* 作者姓名 */
    char writer_name[16];

    /* 书籍ID */
    char type[16];

    /* 书籍借阅状态 */
    BOOK_STATUS status;
    struct BookInfo *next;
} BookInfo;

/* 图书存书数 */
typedef struct BookCount {
    int count;
    char book_name[32];
    struct BookCount *next;
} BookCount;

/* 读者信息 */
typedef struct ReaderInfo {
    /* 读者卡号 */
    char reader_no[32];

    /* 读者姓名 */
    char reader_name[32];
    struct ReaderInfo *next;
} ReaderInfo;

/* 借阅历史 */
typedef struct BorrowedRecord {
    /* 借阅时间 */
    char time[32];

    /* 借阅读者 */
    char reader_no[32];

    /* 借阅书籍 */
    char book_no[32];

    /* 借阅信息 */
    char msg[32];

    /* 失效 */
    int is_delete;
    struct BorrowedRecord *next;
} BorrowedRecord;

/* 操作
 * 添加图书 void add_book_info(BookInfo *book_info)
 * 根据详细信息添加图书 int add_book_detail(char *book_no, char *book_name, char *type, char *writer_name)
 * 通过作者姓名打印图书 print_book_info_by_writer_name
 * 查找图书 BookInfo *search_book_info(char *book_name, char *book_no)
 * 添加图书数量记录 void add_book_count_info(char *book_name)
 * 更新图书数量 void update_book_count(char *book_name)
 * 查找图书数量记录 BookCount *search_book_count_info(char *book_name)
 *
 * 添加读者 void add_reader_info(ReaderInfo *reader_info)
 * 根据详细信息添加读者 void add_reader_detail(char *reader_no, char *reader_name)
 * 查找读者 ReaderInfo *search_reader_info(char *reader_name, char *reader_no)
 *
 * 添加阅读记录 void add_record_info(BorrowedRecord *record_info)
 * 根据详细信息添加阅读记录 void add_record_detail(char *time, char *reader_no, char *book_no, char *msg)
 * 查找阅读记录 BorrowedRecord *search_record_info(char *reader_no, char *book_no)
 * 打印所有借阅记录信息 int print_all_record_info()
 * 打印读者阅读记录 int print_record_info(char *reader_no)
*/

/* 添加图书 */
void add_book_info(BookInfo *book_info);

/* 根据详细信息添加图书 */
int add_book_detail(char *book_no,
                    char *book_name,
                    char *type,
                    char *writer_name);

/* 通过作者姓名查找图书 */
void print_book_info_by_writer_name(char *writer_name);

/* 查找图书 */
BookInfo *search_book_info(char *book_name,
                           char *book_no);


/* 添加图书数量记录 */
void add_book_count_info(char *book_name, int count);

/* 更新图书数量 */
void update_book_count(char *book_name);

/* 查找图书数量记录 */
BookCount *search_book_count_info(char *book_name);

/* 添加读者 */
void add_reader_info(ReaderInfo *reader_info);

/* 根据详细信息添加读者 */
int add_reader_detail(char *reader_no,
                      char *reader_name);

/* 查找读者 */
ReaderInfo *search_reader_info(char *reader_name,
                               char *reader_no);

/* 添加阅读记录 */
void add_record_info(BorrowedRecord *record_info);

/* 根据详细信息添加借阅记录 */
int add_record_detail(char *time,
                      char *reader_no,
                      char *book_no,
                      char *msg);

/* 查找借阅记录 */
BorrowedRecord *search_record_info(char *reader_no,
                                   char *book_no);

/* 打印所有借阅记录信息 */
int print_all_record_info();

/* 打印读者阅读记录 */
int print_record_info(char *reader_no);

#endif //BOOK_MGR_20181220_UTIL_H
