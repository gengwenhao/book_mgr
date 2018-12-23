#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ui/menu.h"
#include "model/book_model.h"

int main(int argc, char *argv[]) {
    /* 初始化 */
    init();

    /* 菜单显示 */
    show_menu();

    /* 释放 */
    destroy();
    return 0;
}


