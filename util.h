//
// Created by gengw on 2018/12/20.
//

#ifndef BOOK_MGR_20181220_UTIL_H
#define BOOK_MGR_20181220_UTIL_H

/* 图书信息结构定义 */
typedef struct BookInfo{
    char book_no[16];
    char book_isbn[16];
    char book_name[16];
    char writer[16];
    char address[16];
    char press[16];
    char press_time[16];
    char price[16];
    char introduction[16];
    int is_borrowed;
}BookInfo;

int save(BookInfo* list, int list_count, const char* file_name);
int load(BookInfo* list, const char* file_name);
BookInfo* init_book_list(int len);
BookInfo* modify_book_list_len(BookInfo* list, int new_len);

#endif //BOOK_MGR_20181220_UTIL_H
