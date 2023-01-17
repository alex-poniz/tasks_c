//#include <QCoreApplication>
#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node *next;
    int val;
};


struct Node* createReverseList(const int count)
{
    if (count < 1)
        return NULL;

    struct Node*  list = (struct Node *)malloc(sizeof(struct Node));
    list->next = NULL;
    list->val = 0;


    for (int i = 1; i < count; i++) {
        struct Node*  element = (struct Node *)malloc(sizeof(struct Node));
        element->next = list;
        element->val = i;

        list = element;
    }

    return list;
}

struct Node* createList(const int count)
{
    if (count < 1)
        return NULL;

    struct Node*  list = (struct Node *)malloc(sizeof(struct Node));
    list->next = NULL;
    list->val = 0;

    struct Node* lastElement = list;


    for (int i = 1; i < count; i++) {
        struct Node*  element = (struct Node *)malloc(sizeof(struct Node));
        element->next = NULL;
        element->val = i;

        lastElement->next = element;
        lastElement = element;
    }

    return list;
}

void deleteList(struct Node *list)
{
    while (list != NULL) {
        struct Node *tmp = list;
        list = list->next;
        free(tmp);
    }
}

void printList(const struct Node *list)
{
    while (list != NULL) {
        printf("%i ", list->val);
        list = list->next;
    }

    printf("\n");
}

struct Node* reverseList(struct Node *list){
    if (!list)
        return NULL;

    struct Node *reverse = list;
    struct Node *tmp = list->next;
    reverse->next = NULL;
    list = tmp;

    while (list != NULL) {
        printf("list %p, reverse %p\n", list, reverse);
        tmp = list->next;
        list->next = reverse;
        reverse = list;
        if (tmp)
            list = tmp;
        else
            break;
    }

    return reverse;
}

int main(int argc, char *argv[])
{
    struct Node *list = createList(10);

    printList(list);

    list = reverseList(list);

    printList(list);

    deleteList(list);

    return(0);
}
