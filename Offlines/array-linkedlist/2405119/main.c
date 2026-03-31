#include <stdio.h>
//#include "arrayList.h"
 #include "linkedList.h"

int main()
{
    FILE *file = fopen("in.txt", "r");
    if (file == NULL)
    {
        return 1;
    }

    //arrayList list;
     linkedList list;
    init(&list);

    int func, param, param2;
    while (fscanf(file, "%d", &func) == 1 && func != 0)
    {
        if (func == 1 && fscanf(file, "%d", &param) == 1)
        {
            printf("Insert %d\n", param);
            insert(param, &list);
            print(&list);
        }
        else if (func == 2)
        {
            printf("Delete current item\n");
            int ret = delete_cur(&list);
            if (ret >= 0)
            {
                print(&list);
                printf("%d is deleted\n", ret);
            }
            else
                printf("List is empty\n");
        }
        else if (func == 3 && fscanf(file, "%d", &param) == 1)
        {
            printf("Append %d\n", param);
            append(param, &list);
            print(&list);
        }
        else if (func == 4)
        {
            int ret = size(&list);
            printf("Size of the list is %d\n", ret);
        }
        else if (func == 5 && fscanf(file, "%d", &param) == 1)
        {
            printf("Prev %d\n", param);
            prev(param, &list);
            print(&list);
        }
        else if (func == 6 && fscanf(file, "%d", &param) == 1)
        {
            printf("Next %d\n", param);
            next(param, &list);
            print(&list);
        }
        else if (func == 7 && fscanf(file, "%d", &param) == 1)
        {
            int ret = is_present(param, &list);
            if (ret)
            {
                printf("%d is present\n", param);
            }
            else
            {
                printf("%d is not present\n", param);
            }
             print(&list);
        }

        else if (func == 8)
        {
            printf("Clear list\n");
            clear(&list);
            print(&list);
        }
        else if (func == 9 && fscanf(file, "%d", &param) == 1)
        {
            printf("Delete %d\n", param);
            int ret = delete_item(param, &list);
            if (ret >= 0)
            {
                print(&list);
            }
        }
        else if (func == 10 && fscanf(file, "%d %d", &param, &param2) == 2)
        {
            printf("Swap index %d and %d\n", param, param2);
            swap_ind(param, param2, &list);
            print(&list);
        }
        else if (func == 11 && fscanf(file, "%d", &param) == 1)
        {
            printf("Search %d\n", param);
            int idx = search(param, &list);
            if (idx == -1)
                printf("%d is not found\n", param);
            else
                printf("%d is found at %d\n", param, idx);
                 print(&list);
        }
        else if (func == 12 && fscanf(file, "%d", &param) == 1)
        {
            printf("Find %d\n", param);
            int val = find(param, &list);
            if (val == -1)
                printf("%d is not a valid index\n", param);
            else
                printf("%d is found at %d\n", val, param);
                 print(&list);
        }
        else if (func == 13 && fscanf(file, "%d %d", &param, &param2) == 2)
        {
            printf("Update element at %d\n", param);
            int old = update(param, param2, &list);
            if (old == -1)
                printf("%d is not a valid index\n", param);
            else
                printf("%d is updated by %d\n", old, param2);
                 print(&list);
        }
        else if (func == 14)
        {
            printf("Trim\n");
            int removed = trim(&list);
            if (removed == -1)
                printf("List is empty\n");
            else
            {
                print(&list);
                printf("%d removed\n", removed);
            }
        }
        else if (func == 15)
        {
            printf("Reverse\n");
            reverse(&list);
            print(&list);
        }
    }

    return 0;
}