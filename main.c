#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ui/menu.h"
#include "model/book_model.h"

int main(int argc, char *argv[]) {
    /* ��ʼ�� */
    init();

    /* �˵���ʾ */
    show_menu();

    /* �ͷ� */
    destroy();
    return 0;
}


