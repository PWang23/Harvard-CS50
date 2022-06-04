include <stdio.h>
include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}
node;

int main(void)
{
    //List of size
    node *list = NULL;

    node *n = malloc(sizeof(node));
    // error check eg. computer out of memory
    if (n == NULL)
    {
        return 1;
    }
    n->number = 1;
    n->next = NULL;
    
    //update list to point at new node
    list = n;

    n = malloc(sizeof(node));
    if (n == NULL)
    {
        free(list);
        return 1;
    }
    n->number = 2;
    n->next = NULL;
    
    //update list->next to point at new node
    list->next = n;

    n = malloc(sizeof(node));
    if (n == NULL)
    {
        //mind the sequence of those two free
        free(list->next);
        free(list);
        return 1;
    }
    n->number = 3;
    n->next = NULL;
    
    //update list->next to point at new node
    list->next->next = n;

    //print numbers
    for (node *tmp = list; tmp != NULL; tmp = tmp->next)
    {
        printf("%i\n", tmp->number);
    }

    //Free List
    while (list != NULL)
    {
        node *tmp = list->next
        free(list);
        list = tmp;
    }
    return 0;
}