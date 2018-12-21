#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "util.h"

/* 把book_list写入文件 */
int save(BookInfo *list, int list_count, const char *file_name) {
    FILE *fp = fopen(file_name, "w");
    if (NULL == fp) {
        printf("load file error");
        return -1;
    }

    fwrite(list, sizeof(BookInfo), (size_t) list_count, fp);

    fclose(fp);
    return 0;
}

/* 读取文件转换为book_list结构体 */
int load(BookInfo *list, const char *file_name) {
    FILE *fp = fopen(file_name, "r");
    if (NULL == fp) {
        printf("load file error\n");
        return -1;
    }

    int read_count = 0, len = 0;
    while (1) {
        // once an info
        read_count = fread(&list[len++], sizeof(BookInfo), 1, fp);
        if (!read_count) {
            break;
        }
    }

    fclose(fp);
    return len;
}

/* 初始化book_list */
BookInfo *init_book_list() {
    BookInfo *head = (BookInfo *) malloc(sizeof(BookInfo));
    return head;
}
