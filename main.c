#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"
#include "menu.h"

/* 初始记录条数500条 */
#define INIT_LIST_LEN 500

/* 当前图书个数 */
int cur_lst_len = INIT_LIST_LEN;

/* 图书信息 */
BookInfo *g_lst = NULL;


int main(int argc, char *argv[]) {
    g_lst = init_book_list(INIT_LIST_LEN);
    //show_menu();


    free(g_lst);
    return 0;
}
