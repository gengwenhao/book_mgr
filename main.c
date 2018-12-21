#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util/list_util.h"

/* Õº È–≈œ¢ */
BookInfo *g_lst = NULL;

void destroy_lst(BookInfo *pInfo);

int main(int argc, char *argv[]) {
    g_lst = create_book_node();
    add_book_lst_item(g_lst, "gengwenhao0", "", "", "", "", "", 0);
    add_book_lst_item(g_lst, "gengwenhao1", "", "", "", "", "", 0);
    add_book_lst_item(g_lst, "gengwenhao2", "", "", "", "", "", 0);
    add_book_lst_item(g_lst, "gengwenhao3", "", "", "", "", "", 0);
    

    return 0;
}


