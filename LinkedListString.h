#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Link list node */
struct node
{
        char data[40];
        struct node* next;
};

void push(struct node** head_ref, char* new_data);
void printList(struct node *head);
int listCount(struct node *head);
void reverseList(struct node** head_ref);
void listAllDelete(struct node **currP);
void deleteElement(struct node **currP, char *value);
//void insertElement(struct node **currP, char* value);
//void sortLinkedList(struct node** currP);
//void swapData(struct node* nOne, struct node* nTwo);