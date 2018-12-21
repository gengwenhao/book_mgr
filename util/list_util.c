#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list_util.h"


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
BookInfo *create_book_node() {
    BookInfo *info = (BookInfo *) malloc(sizeof(BookInfo));
    info->next = NULL;
    return info;
}

/* 获得新结点并赋值 */
BookInfo *get_new_node(const char *book_no,
                       const char *book_isbn,
                       const char *book_name,
                       const char *writer,
                       const char *price,
                       const char *introduction,
                       int is_borrowed) {
    BookInfo *new_node = create_book_node();
    strcpy(new_node->book_no, book_no);
    strcpy(new_node->book_isbn, book_isbn);
    strcpy(new_node->book_name, book_name);
    strcpy(new_node->writer, writer);
    strcpy(new_node->price, price);
    strcpy(new_node->introduction, introduction);
    new_node->is_borrowed = is_borrowed;

    return new_node;
}

/* 添加图书信息 */
int add_book_lst_item(BookInfo *head, const char *book_no, const char *book_isbn, const char *book_name,
                      const char *writer, const char *price, const char *introduction, int is_borrowed) {
    if (NULL == head) {
        return -1;
    }

    BookInfo *new_node = get_new_node(book_no, book_isbn, book_name, writer, price, introduction, is_borrowed);
    new_node->next = head->next;
    head->next = new_node;

    return 0;
}

/* 删除图书信息 */
void remove_book_item_by_book_no(BookInfo *head, const char *book_no) {
    if (NULL == head) {
        printf("head is None)");
        return;
    }

    BookInfo *tmp = head;
    while (tmp->next) {
        if (!strcmp(tmp->next->book_no, book_no)) {
            break;
        }
        tmp = tmp->next;
    }

    BookInfo *free_p = tmp->next;
    tmp->next = tmp->next->next;
    free(free_p);
}

/* 打印图书信息 */
void print_book_lst(BookInfo *head) {
    if (NULL == head) {
        printf("head is None");
        return;
    }

    if (NULL == head->next) {
        printf("book lst is empty");
        return;
    }

    BookInfo *tmp = head->next;
    while (tmp) {
        printf("%s ", tmp->book_no);
        tmp = tmp->next;
    }
}

/* 释放lst */
void destroy_lst(BookInfo *head) {
    if (NULL == head) {
        return;
    }

    BookInfo *tmp = head, *free_p;
    while (tmp->next) {
        free_p = tmp;
        tmp = tmp->next;
        free(free_p);
    }
}
