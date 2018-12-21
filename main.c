#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"
#include "menu.h"


/* Õº È–≈œ¢ */
BookInfo *g_lst = NULL;


int main(int argc, char *argv[]) {
    g_lst = init_book_list();
    //show_menu();


    free(g_lst);
    return 0;
}
