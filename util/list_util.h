//
// Created by gengw on 2018/12/20.
//

#ifndef BOOK_MGR_20181220_UTIL_H
#define BOOK_MGR_20181220_UTIL_H

/* 图书信息结构定义 */
typedef struct BookInfo {
    char book_no[16];
    char book_isbn[16];
    char book_name[16];
    char writer[16];
    char price[16];
    char introduction[16];
    int is_borrowed;
    struct BookInfo *next;
} BookInfo;

BookInfo *init_book_lst();

BookInfo *create_book_node();

/* 获得新结点并赋值 */
BookInfo *get_new_node(const char *book_no,
                       const char *book_isbn,
                       const char *book_name,
                       const char *writer,
                       const char *price,
                       const char *introduction,
                       int is_borrowed);


int add_book_lst_item(BookInfo *head,
                      const char *book_no,
                      const char *book_isbn,
                      const char *book_name,
                      const char *writer,
                      const char *price,
                      const char *introduction,
                      int is_borrowed);

void remove_book_item_by_book_no(BookInfo *head, const char *book_no);

void print_book_lst(BookInfo *head);


void destroy_lst(BookInfo *head);

#endif //BOOK_MGR_20181220_UTIL_H
