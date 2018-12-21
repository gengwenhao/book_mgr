#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util/list_util.h"

/* Õº È–≈œ¢ */
BookInfo *g_lst = NULL;


int main(int argc, char *argv[]) {
    g_lst = create_book_node();
    add_book_lst_item(g_lst, "gengwenhao0", "Python", "PY", "", "", "", 0);
    add_book_lst_item(g_lst, "gengwenhao1", "Python", "PY", "", "", "", 0);
    find_book_item_by_book_name(g_lst, "PY");

    return 0;
}


