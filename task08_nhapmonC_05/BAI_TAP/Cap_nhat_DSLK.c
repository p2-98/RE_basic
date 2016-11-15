#include <stdio.h>
#include <stdlib.h>

struct node {
   int data;
   struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;

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

void display() {
   struct node *ptr = head;

   printf("\n[head] =>");
   while(ptr != NULL) {
      printf(" %d =>",ptr->data);
      ptr = ptr->next;
   }

   printf(" [null]\n");
}

void update_data(int old, int new1) {
   int pos = 0;
   
   if(head==NULL) {
      printf("Danh sach lien ket chua duoc khoi tao");
      return;
   } 

   current = head;
   while(current->next!=NULL) {
      if(current->data == old) {
         current->data = new1;
         printf("\nTim thay %d tai vi tri %d, duoc thay the voi %d\n", old, pos, new1);
         return;
      }
      current = current->next;
      pos++;
   }
   printf("%d khong ton tai trong list\n", old);
}


int main() {
   int n, a, b, tmp;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		{
			scanf("%d", &tmp);
			insert(tmp);
		}
   display();
   printf("Nhap so can thay the va duoc thay the boi so: ");
   scanf("%d %d",&a, &b);
   update_data(a, b);
   display();
   
   return 0;
}
/* Cập nhật và thay thế một số trong danh sách liên kết
Input
5
1 2 3 6 4
Nhap so can thay the va duoc thay the boi so: 4 3
Output
[head] => 1 => 2 => 3 => 6 => 4 => [null]
Tim thay so 4 tai vi tri 3 duoc thay the voi 3
[head] => 1 => 2 => 3 => 6 => 3 => [null] */
