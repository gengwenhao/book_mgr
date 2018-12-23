#include <stdlib.h>
#include <string.h>
#include "book_model.h"

//
// Created by gengw on 2018/12/23.
//
int test() {
    //show_menu();
    init();

    /* test book_info*/
    BookInfo *book_info = malloc(sizeof(BookInfo));
    strcpy(book_info->book_name, "计算机组成原理");
    strcpy(book_info->book_no, "001");
    add_book_info(book_info);
    BookInfo *find_info1 = search_book_info("计算机组成原理", NULL);
    BookInfo *find_info2 = search_book_info(NULL, "001");

    /* test reader_info */
    ReaderInfo *reader_info = malloc(sizeof(ReaderInfo));
    strcpy(reader_info->reader_name, "耿文浩");
    strcpy(reader_info->reader_no, "2018539221");
    add_reader_info(reader_info);
    ReaderInfo *find_info3 = search_reader_info("耿文浩", NULL);
    ReaderInfo *find_info4 = search_reader_info(NULL, "2018539221");

    /* test record_info */
    BorrowedRecord *record_info = malloc(sizeof(BorrowedRecord));
    strcpy(record_info->reader_no, "2018539221");
    strcpy(record_info->book_no, "001");
    add_record_info(record_info);
    BorrowedRecord *find_info5 = search_record_info("2018539221", NULL);
    BorrowedRecord *find_info6 = search_record_info(NULL, "001");

    free(book_info);
    free(reader_info);
    free(record_info);

    destroy();
    return 0;
}
