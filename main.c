#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ui/menu.h"
#include "model/book_model.h"

void run() {
    /* ��ʼ�� */
    init();

    /* ���ļ��ж�ȡ */
    load(NULL, NULL, NULL);

    /* �˵���ʾ */
    show_menu();

    /* ���浽�ļ��� */
    save(NULL, NULL, NULL);

    /* �ͷ� */
    destroy();
}

int main(int argc, char *argv[]) {
    run();

    return 0;
}


