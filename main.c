#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"
#include "menu.h"

/* ��ʼ��¼����500�� */
#define INIT_LIST_LEN 500

/* ��ǰͼ����� */
int cur_lst_len = INIT_LIST_LEN;

/* ͼ����Ϣ */
BookInfo *g_lst = NULL;


int main(int argc, char *argv[]) {
    g_lst = init_book_list(INIT_LIST_LEN);
    //show_menu();


    free(g_lst);
    return 0;
}
