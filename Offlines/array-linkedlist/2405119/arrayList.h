#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int *array;
    int cap;
    int size;
    int cur;
} arrayList;

void init(arrayList *list)
{
    list->cap = 2;
    list->size = 0;
    list->cur = 0;
    list->array = (int *)malloc(list->cap * sizeof(int));
}
void free_list(arrayList *list)
{
    free(list->array);
}

void increase_capacity(arrayList *list)
{
    int newCap = list->cap * 2;
    int *a = (int *)malloc(sizeof(int) * newCap);
    for (int i = 0; i < list->size; i++)
    {
        a[i] = list->array[i];
    }
    free(list->array);
    list->array = a;
    printf("Capacity increased from %d to %d\n", list->cap, newCap);
    list->cap = newCap;
}

void decrease_capacity(arrayList *list)
{
    if (list->cap <= 2)
        return;
    int newCap = list->cap / 2;
    if (newCap < 2)
        newCap = 2;
    int *a = (int *)malloc(sizeof(int) * newCap);
    for (int i = 0; i < list->size; i++)
    {
        a[i] = list->array[i];
    }
    free(list->array);
    list->array = a;
    printf("Capacity decreased from %d to %d\n", list->cap, newCap);
    list->cap = newCap;
}
void print(arrayList *list)
{
    if (list->size == 0)
    {
        printf("[ . ]\n");
        return;
    }
    printf("[ ");
    for (int i = 0; i < list->size; i++)
    {
        if (i == list->cur)
            printf("| ");
        printf("%d", list->array[i]);
        printf(" ");
    }
    if (list->cur == list->size)
    {
        printf("|");
    }
    printf("]\n");
}
void insert(int item, arrayList *list)
{
    if (list->size * 2 >= list->cap)
    {
        increase_capacity(list);
    }
    for (int i = list->size; i > list->cur; i--)
    {
        list->array[i] = list->array[i - 1];
    }
    list->array[list->cur] = item;
    list->cur++;
    list->size++;
}
int delete_cur(arrayList *list)
{
    if (list->size == 0)
        return -1;
    int idx;
    if (list->cur == 0)
        idx = 0;
    else
        idx = list->cur - 1;
    int removed = list->array[idx];

     for (int i = idx; i < list->size - 1; i++)
        list->array[i] = list->array[i + 1];
    
    list->size--;
    if (list->cur > list->size)
        list->cur = list->size;
    if (list->size < list->cap / 4)
        decrease_capacity(list);
    return removed;
}
void append(int item, arrayList *list)
{
   int old = list->cur;
    list->cur = list->size;   
    insert(item, list);

    if (list->size == 1)
        list->cur = 1;
    else
        list->cur = old;
}
int size(arrayList *list) {
     return list->size;
     }
void prev(int n, arrayList *list)
{
    list->cur -= n;
    if (list->cur < 0)
        list->cur = 0;
}
void next(int n, arrayList *list)
{
    list->cur += n;
    if (list->cur > list->size)
        list->cur = list->size;
}
int is_present(int n, arrayList *list)
{
    for (int i = 0; i < list->size; i++)
    {
        if (list->array[i] == n)
            return 1;
    }
    return 0;
}
void clear(arrayList *list)
{
    free(list->array);
    init(list);
}
int delete_item(int item, arrayList *list)
{
    for (int i = 0; i < list->size; i++)
    {
        if (list->array[i] == item)
        {
            list->cur = i + 1;
            return delete_cur(list);
        }
    }
    printf("%d not found\n", item);
    return -1;
}
void swap_ind(int ind1, int ind2, arrayList *list)
{
    if (ind1 < 0 || ind2 < 0 || ind1 >= list->size || ind2 >= list->size)
        return;
    int t = list->array[ind1];
    list->array[ind1] = list->array[ind2];
    list->array[ind2] = t;
    
}
int search(int item, arrayList *list)
{
    for (int i = 0; i < list->size; i++)
    {
        if (list->array[i] == item)
        {
            list->cur = i + 1;
            
            return i;
        }
    }
    return -1;
}
int find(int ind, arrayList *list)
{
    if (ind < 0 || ind >= list->size)
        return -1;
    list->cur = ind + 1;

    return list->array[ind];
}
int update(int ind, int value, arrayList *list)
{
    if (ind < 0 || ind >= list->size)
        return -1;
    int old = list->array[ind];
    list->array[ind] = value;
    list->cur = ind + 1;
    
    return old;
}
int trim(arrayList *list)
{
    if (list->size == 0)
        return -1;

    int removed = list->array[list->size - 1];
   
    list->size--;
if (list->size == 0) list->cur = 0;
else if (list->cur > list->size) list->cur = list->size;
if (list->size < list->cap / 4) decrease_capacity(list);
return removed;
   
   
}
void reverse(arrayList *list)
{
    int t;
    for (int i = 0; i < list->size / 2; i++)
    {
        t = list->array[i];
        list->array[i] = list->array[list->size - i - 1];
        list->array[list->size - i - 1] = t;
    }
    
}