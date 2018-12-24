#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ui/menu.h"
#include "model/book_model.h"

int main(int argc, char *argv[]) {
    /* 初始化 */
    init();

    /* 从文件中读取 */
    load(NULL, NULL, NULL);

    /* 菜单显示 */
    show_menu();

    /* 保存到文件中 */
    save(NULL, NULL, NULL);

    /* 释放 */
    destroy();
    return 0;
}


