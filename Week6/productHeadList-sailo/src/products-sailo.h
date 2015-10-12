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

struct product_list {
    struct product *head;
    // could have other list specific elements, like length of the list, last update time, etc.
    };

void init_list(struct product_list *list);
struct product *add_product(struct product_list *start, const char *title, const char *code,
        int stock, double price);
struct product *find_product(struct product_list *start, const char *code);
int remove_product(struct product_list *start, const char *code);
int delete_list(struct product_list *start);

#endif
