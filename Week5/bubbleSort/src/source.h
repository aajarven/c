typedef int (*compare)(int first, int second);

int* bubble_sort(int* numbers, int count, compare comp);
int sorted_compare(int first, int second);
int reverse_compare(int first, int second);
