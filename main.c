#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ui/menu.h"
#include "model/book_model.h"

int main(int argc, char *argv[]) {
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
    return 0;
}


