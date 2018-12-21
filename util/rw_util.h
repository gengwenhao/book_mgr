//
// Created by gengw on 2018/12/21.
//

#ifndef BOOK_MGR_20181220_RW_UTIL_H
#define BOOK_MGR_20181220_RW_UTIL_H

#include "list_util.h"

/* 保存booklst */
int save(BookInfo *list, int list_count, const char *file_name);


/* 独处booklst */
int load(BookInfo *list, const char *file_name);

#endif //BOOK_MGR_20181220_RW_UTIL_H
