#include <stdio.h>
#include <stdlib.h>

struct node {
   int data;
   struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;

void reverse_print(struct node *list) {
   if(list == NULL) {
      return;
   }
   reverse_print(list->next);
   printf("%d ",list->data);
   
}

void insert(int data) {
   struct node *link = (struct node*) malloc(sizeof(struct node));

   link->data = data;
   link->next = NULL;

   if(head==NULL) {
      head = link;
      return;
   }


   current = head;
   
   while(current->next!=NULL)
      current = current->next;
   
   current->next = link; 
}

int main() {
 int n, fNum, tmp;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		{
			scanf("%d", &tmp);
			insert(tmp);
		};
   reverse_print(head);
   return 0;
}
/* Đảo ngược danh sách liên kết
input
3
3 1 2
output
2 1 3
*/
