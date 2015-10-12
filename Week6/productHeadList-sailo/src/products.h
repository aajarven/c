#ifndef AALTO_CSUM14_35
#define AALTO_CSUM14_35

// Single product in inventory
struct product {
    char *title;  // Name of the product
    char code[8]; // Max. 7 characters of product ID
    int stock;  // Current stock (number of units)
    double price;  // Price of a single unit
    struct product *next; // pointer to next item in linked list
};

void init_list (struct product_list *list);

struct product_list {
    struct product *head;
    // could have other list specific elements, like length of the list, last update time, etc
};

struct product *add_product(struct product *start, const char *title, const char *code,
        int stock, double price);
struct product *find_product(struct product *start, const char *code);
struct product *remove_product(struct product *start, const char *code);
int delete_list(struct product *start);

void init_product(struct product *pr, const char *title, const char *code, int stock, double price, struct product *next);

#endif
