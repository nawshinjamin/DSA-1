#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int element;
   struct node *next;
    struct node *prev;
} node;

typedef struct
{
    node *head;
    node *tail;
    int size;
    int cur;
} linkedList;

void init(linkedList *list)
{
    list->head = list->tail = NULL;
    list->size = 0;
    list->cur = 0;
}

void free_list(linkedList *list)
{
    node *p = list->head;
    while (p)
    {
        node *n = p->next;
        free(p);
        p = n;
    }
    init(list);
}

void print(linkedList *list)
{
    if (list->size == 0)
    {
        printf("[ . ]\n");
        return;
    }
    printf("[ ");
    if (list->cur == 0)
        printf("| ");
    node *p = list->head;
    int idx = 0;
    while (p)
    {
        printf("%d", p->element);
        if (idx == list->cur - 1)
            printf("| ");
        else
            printf(" ");
        p = p->next;
        idx++;
    }
    printf("]\n");
}



void insert(int item, linkedList *list)
{
    node *n = (node *)malloc(sizeof(node));
    n->element = item;
    n->next = n->prev = NULL;

    if (list->size == 0)
    {
        list->head = list->tail = n;
    }
    else if (list->cur == 0)
    {
        n->next = list->head;
        list->head->prev = n;
        list->head = n;
    }
    else if (list->cur == list->size)
    {
        n->prev = list->tail;
        list->tail->next = n;
        list->tail = n;
    }
    else
    {
        node *at = list->head;
        for (int i = 0; i < list->cur; i++)
            at = at->next;
        n->next = at;
        n->prev = at->prev;
        if (at->prev)
            at->prev->next = n;
        at->prev = n;
    }
    list->cur++;
    list->size++;
}

int delete_cur(linkedList *list)
{
    if (list->size == 0)
        return -1;
    int idx = (list->cur == 0) ? 0 : list->cur - 1;
    node *rem = list->head;
    for (int i = 0; i < idx; i++)
        rem = rem->next;
    int removed = rem->element;

    if (rem->prev)
        rem->prev->next = rem->next;
    else
        list->head = rem->next;
    if (rem->next)
        rem->next->prev = rem->prev;
    else
        list->tail = rem->prev;

    free(rem);
    list->size--;

    if (list->cur > list->size)
        list->cur = list->size;

    return removed;
}

void append(int item, linkedList *list)
{
    int old = list->cur;
    list->cur = list->size;
    insert(item, list);
    if (list->size == 1)
        list->cur = 1;
    else
        list->cur = old;
}

int size(linkedList *list)
{
    return list->size;
}

void prev(int n, linkedList *list)
{
    list->cur -= n;
    if (list->cur < 0)
        list->cur = 0;
}

void next(int n, linkedList *list)
{
    list->cur += n;
    if (list->cur > list->size)
        list->cur = list->size;
}

int is_present(int n, linkedList *list)
{
    node *p = list->head;
    while (p)
    {
        if (p->element == n)
            return 1;
        p = p->next;
    }
    return 0;
}

void clear(linkedList *list)
{
    free_list(list);
    init(list);
}

int delete_item(int item, linkedList *list)
{
    node *p = list->head;
    int idx = 0;
    while (p)
    {
        if (p->element == item)
        {
            list->cur = idx + 1;
            return delete_cur(list);
        }
        p = p->next;
        idx++;
    }
    printf("%d not found\n", item);
    return -1;
}

void swap_ind(int ind1, int ind2, linkedList *list)
{
    if (ind1 < 0 || ind2 < 0 || ind1 >= list->size || ind2 >= list->size)
        return;
    if (ind1 == ind2)
    {
        print(list);
        return;
    }
    node *a = list->head;
    for (int i = 0; i < ind1; i++)
        a = a->next;
    node *b = list->head;
    for (int i = 0; i < ind2; i++)
        b = b->next;
    int t = a->element;
    a->element = b->element;
    b->element = t;
    print(list);
}

int search(int item, linkedList *list)
{
    node *p = list->head;
    int idx = 0;
    while (p)
    {
        if (p->element == item)
        {
            list->cur = idx + 1;
            print(list);
            return idx;
        }
        p = p->next;
        idx++;
    }
    return -1;
}

int find(int ind, linkedList *list)
{
    if (ind < 0 || ind >= list->size)
        return -1;
    list->cur = ind + 1;
    print(list);
    node *n = list->head;
    for (int i = 0; i < ind; i++)
        n = n->next;
    return n->element;
}

int update(int ind, int value, linkedList *list)
{
    if (ind < 0 || ind >= list->size)
        return -1;
    node *n = list->head;
    for (int i = 0; i < ind; i++)
        n = n->next;
    int old = n->element;
    n->element = value;
    list->cur = ind + 1;
    print(list);
    return old;
}

int trim(linkedList *list)
{
    if (list->size == 0)
        return -1;
    node *rem = list->tail;
    int removed = rem->element;

    if (rem->prev)
    {
        rem->prev->next = NULL;
        list->tail = rem->prev;
    }
    else
    {
        list->head = list->tail = NULL;
    }
    free(rem);
    list->size--;

    if (list->size == 0)
        list->cur = 0;
    else if (list->cur > list->size)
        list->cur = list->size;

    return removed;
}

void reverse(linkedList *list)
{
    node *p = list->head;
    while (p)
    {
        node *nxt = p->next;
        node *prv = p->prev;
        p->next = prv;
        p->prev = nxt;
        p = nxt;
    }
    node *tmp = list->head;
    list->head = list->tail;
    list->tail = tmp;
}