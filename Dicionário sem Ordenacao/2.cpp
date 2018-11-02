#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
 
struct lnode {
 int data;
 struct lnode *next;
} *head, *visit;
 
/* add a new entry to the linked list */
void llist_add(struct lnode **q, int num);
/* preform a bubble sort on the linked list */
void llist_bubble_sort(void);
/* print the entire linked list */
void llist_print(void);
 
int main(void) {
 /* linked list */
 struct lnode *newnode = NULL;
 int i = 0,num,a[20]; /* a general counter */
 printf("----------------------------------------------------------------------\n");
 printf("-------------------made by C code champ ------------------------------\n");
 printf("----------------------------------------------------------------------\n");
 printf("\n\n\t BUBBLE SORT ALGORITHM USING LINKED LIST\n");   
 printf("\nEnter the number of elements : ");
 scanf("%d",&num);
 /* load some random values into the linked list */
 printf("\nEnter the elements to be sorted : \n");
 for(i = 0; i < num; i++) {
  scanf("%d",&a[i]);
  llist_add(&newnode, a[i]);
 }
 
 head = newnode;
 printf("\nList of input elements :\n");
 llist_print();
 printf("\n\nSorted List of elements by bubble sort :\n");
 llist_bubble_sort();
 llist_print();
 getch();
 return 0;
}
 
/* adds a node at the end of a linked list */
void llist_add(struct lnode **q, int num) {
 struct lnode *tmp;
 
 tmp = *q;
 
 /* if the list is empty, create first node */
 if(*q == NULL) {
  *q = malloc(sizeof(struct lnode*));
   tmp = *q;
 } else {
  /* go to last node */
  while(tmp->next != NULL)
   tmp = tmp->next;
 
   /* add node at the end */
   tmp->next = malloc(sizeof(struct lnode));
   tmp = tmp->next;
 }
 
 /* assign data to the last node */
 tmp->data = num;
 tmp->next = NULL;
}
 
/* print the entire linked list */
void llist_print(void) {
 visit = head;
 
 while(visit != NULL) {
  printf("%d\t", visit->data);
  visit = visit->next;
 }
 printf("\n");
}
 
/* preform a bubble sort on the linked list */
void llist_bubble_sort(void) {
 struct lnode *a = NULL;
 struct lnode *b = NULL;
 struct lnode *c = NULL;
 struct lnode *e = NULL;
 struct lnode *tmp = NULL;
 
 /*
 // the `c' node precedes the `a' and `e' node
 // pointing up the node to which the comparisons
 // are being made.
 */
 while(e != head->next) {
 c = a = head;
 b = a->next;
  while(a != e) {
   if(a->data > b->data) {
    if(a == head) {
     tmp = b -> next;
     b->next = a;
     a->next = tmp;
     head = b;
     c = b;
    } else {
     tmp = b->next;
     b->next = a;
     a->next = tmp;
     c->next = b;
     c = b;
    }
   } else {
    c = a;
    a = a->next;
   }
   b = a->next;
   if(b == e)
    e = a;
  }
 }
}

