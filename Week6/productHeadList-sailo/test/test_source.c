#include <check.h>
#include "tmc-check.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "../src/products.h"


int test_product(char *buf, struct product *pr, const char *title, const char *code,
        int stock, double price) {
    if (pr->title == title || pr->title == NULL) {
        sprintf(buf, "Memory for title string not dynamically allocated");
        return 0;
    }
    if (strcmp(pr->title, title)) {
        remove_nonascii(pr->title);
        sprintf(buf, "Incorrect title. You: \"%s\", expected: \"%s\"",
                pr->title, title);
        return 0;
    }

    if (strlen(pr->code) > 7) {
        sprintf(buf, "Code field is too long. Max. length is 7 characters (plus '\\0')");
        return 0;
    }
    char codebuf[8];
    strncpy(codebuf, code, 7);
    codebuf[7] = 0;

    if (strcmp(pr->code, codebuf)) {
        remove_nonascii(pr->code);
        sprintf(buf, "Incorrect code. You: \"%s\", expected: \"%s\"",
                pr->code, codebuf);
        return 0;
    }
    if (pr->stock != stock) {
        sprintf(buf, "Incorrect stock. You: %d, expected: %d",
                pr->stock, stock);
        return 0;
    }
    if (pr->price != price) {
        sprintf(buf, "Incorrect price. You: %lf, expected: %lf",
                pr->price, price);
        return 0;
    }
    return 1;
}


void release_list(struct product *p)
{
    while (p) {
        struct product *prev = p;
        p = p->next;
        free(prev->title);
        free(prev);
    }
}


START_TEST(test_add_product)
{
    int i;
    struct product_list list;
    struct product *l, *ptr1, *ptr2;
    struct product *other = NULL;
    const int len = 4;
    char buf[200];
    buf[0] = 0;

    char *titles[] = {"Floppy disk", "USB stick", "Something with quite long name", "Laptop"};
    char *codes[] = {"0000", "1234567", "4444444", "1111"};
    int stocks[] = {1, 2, 3, 4};
    double prices[] = {0.1, 1, 10, 100};    
    
    init_list(&list);
    l = add_product(&list, titles[0], codes[0], stocks[0], prices[0]);
    fail_unless(l != NULL, "Add_product returned NULL when trying to add value.\n");

    for (i = 1; i < len; i++) {
        ptr1 = add_product(&list, titles[i], codes[i], stocks[i], prices[i]);
        if (!ptr1) {
            release_list(list.head);
            list.head = NULL;
            fail("Add_product returned NULL when trying to add multiple values.\n");
        }

        if (!test_product(buf, ptr1, titles[i], codes[i], stocks[i], prices[i])) {
            release_list(list.head);
            list.head = NULL;
            fail("Add_product added list item has invalid content: %s", buf);
        }
        if (ptr1->next) {
            release_list(list.head);
            list.head=NULL;
            fail("Add_product: The next pointer should be NULL in the new list item.\n");
        }
    }

    ptr2 = list.head;
    for (i = 0; i < len; i++) {
        if (i < len - 1 && ptr2->next == NULL) {
            release_list(list.head);
            fail("[Task 3.5.a] Item nr. %d incorrectly has NULL as next pointer\n",
                    i+1);
        }
        if (strcmp(ptr2->code, codes[i])) {
            release_list(list.head);
            fail("[Task 3.5.a] Item nr. #d has code '%s', should be '%s'\n",
                    i+1, ptr2->code, codes[i]);
        }
        ptr2 = ptr2->next;
    }

    release_list(list.head);
}
END_TEST


int add_product_exists()
{

    struct product_list apu;
    init_list(&apu);

    struct product *l;
    l = add_product(&apu, "a", "b", 1, 2);
    if (l) {
      free(l->title);
        free(l);
        return 1;
    } else {
        return 0;
    }
}


START_TEST(test_find_product)
{
    const int len = 4;
    struct product *l, *ptr;

    struct product_list list;
    init_list(&list);

    fail_unless(add_product_exists(), "Implement add_product first!\n");

    char *titles[] = {"Floppy disk", "USB stick", "Something with quite long name", "Laptop"};
    char *codes[] = {"0000", "1234567", "4444444", "1111"};
    int stocks[] = {1, 2, 3, 4};
    double prices[] = {0.1, 1, 10, 100};    
    
    l = add_product(&list, titles[0], codes[0], stocks[0], prices[0]);
    for (int i = 1; i < len; i++) {
        add_product(&list, titles[i], codes[i], stocks[i], prices[i]);
    }
    
    int findidx;
    for (int i = 0; i < 3; i++) {
        findidx = rand() % len;

        ptr = find_product(&list, codes[findidx]);
        if (!ptr) {
            release_list(list.head);
            fail("Find_product did not find code '%s', as it should have. Returned NULL\n",
                    codes[findidx]);
        }
        if (strcmp(ptr->code, codes[findidx])) {
            char buf[100];
            sprintf(buf, "Find_product for code '%s' returned item with code '%s'",
                    codes[findidx], ptr->code);
            release_list(list.head);
            fail("%s", buf);
        }
    }

    ptr = find_product(&list, "ABCD");
    if (ptr) {
        release_list(list.head);
        fail("Find_product for non-existing code 'ABCD' should return NULL");
    }
    
    release_list(list.head);
}
END_TEST

int compare_list(struct product *l, const char **codes ,int len)
{
    struct product *ptr;
    int i;
    ptr = l;
    for (i = 0; i < len; i++) {
	if (!ptr) return 1;
        if (strcmp(ptr->code, codes[i])) {
            return i;
        }
        ptr = ptr->next;
    }
    return -1;
}


void print_list(char *buf, struct product *l)
{
    char buf2[10];
    int count = 15;
    sprintf(buf, "{ ");
    while (l && count--) {
        sprintf(buf2, "%s ", l->code);
        strcat(buf, buf2);
        l = l->next;
    }
    strcat(buf, "}");
}

START_TEST(test_remove_product)
{

    struct product_list list;
    init_list(&list);

    const int len = 4;
    int fail = 0;
    struct product *l, *retl;
    int ret_count;

    fail_unless(add_product_exists(), "Remove_product: Implement add_product first!\n");

    char *titles[] = {"Floppy disk", "USB stick", "Something with quite long name", "Laptop"};
    const char *codes[] = {"0000", "1234567", "4444444", "1111"};
    int stocks[] = {1, 2, 3, 4};
    double prices[] = {0.1, 1, 10, 100};

    const char *codes2[] = {"0000", "1234567", "1111"};
    const char *codes3[] = {"1234567", "1111"};

    l = add_product(&list, titles[0], codes[0], stocks[0], prices[0]);
    for (int i = 1; i < len; i++) {
        add_product(&list, titles[i], codes[i], stocks[i], prices[i]);
    }

    ret_count = remove_product(&list, "ABCD");
    if (ret_count != 0) {
	    release_list(list.head);
	    fail("Remove_poduct: Return value should be 0 when trying to remove non-existent code 'ABCD'");
    }

    char buf[100];
    fail = compare_list(list.head, codes, len);
    print_list(buf, list.head);
    if (fail != -1) {
	    release_list(list.head);
	    fail("Remove_product: Trying to remove nonexistent item modified the linked list. Current list: %s.",
                    buf);
    }

    ret_count = remove_product(&list, "4444444");
    if (ret_count !=1) {
	    release_list(list.head);
	    fail("Remove_product: Return value should be 1 when removing an existent code '4444444'");
            };

    print_list(buf, list.head);

    fail = compare_list(list.head, codes2, len - 1);
    if (fail != -1) {
        release_list(list.head);
        fail("Remove_product: Incorrect list after removing \"4444444\". Current list: %s",
            buf);
    }

    ret_count = remove_product(&list, "0000");
    print_list(buf, list.head);
    fail = compare_list(list.head, codes3, len - 2);
    if (fail != -1) {
        release_list(list.head);
        fail("Remove_product: Incorrect list after removing \"4444444\" and \"0000\". Current list: %s",
            buf);
    }

    release_list(list.head);
}
END_TEST


START_TEST(test_delete_list)
{
    const int len = 4;
    struct product *l;

    struct product_list list;
    init_list(&list);

    fail_unless(add_product_exists(), "Delete_list: Implement add_product first!\n");

    char *titles[] = {"Floppy disk", "USB stick", "Something with quite long name", "Laptop"};    
    const char *codes[] = {"0000", "1234567", "4444444", "1111"};
    int stocks[] = {1, 2, 3, 4};
    double prices[] = {0.1, 1, 10, 100};

    l = add_product(&list, titles[0], codes[0], stocks[0], prices[0]);
    for (int i = 1; i < len; i++) {
        add_product(&list, titles[i], codes[i], stocks[i], prices[i]);
    }

    int ret = delete_list(&list);
    if (!ret) {
        release_list(list.head);
        fail("delete_list should return 1 after properly implemented\n");
    }
}
END_TEST


int main(int argc, const char *argv[])
{

    srand((unsigned)time(NULL));
    Suite *s = suite_create("ListWithHead");

    tmc_register_test(s, test_add_product, "head_additem");
    tmc_register_test(s, test_find_product, "head_finditem");
    tmc_register_test(s, test_remove_product, "head_removeitem");
    tmc_register_test(s, test_delete_list, "head_deletelist");

    return tmc_run_tests(argc, argv, s);
}
