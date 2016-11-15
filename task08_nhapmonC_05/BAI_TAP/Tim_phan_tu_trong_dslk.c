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

void find_data(int item) {
   int pos = 0;
   
   if(head==NULL) {
      printf("Danh sach lien ket chua duoc khoi tao");
      return;
   } 

   current = head;
   while(current->next!=NULL) {
      if(current->data == item) {
         printf("Tim thay %d tai vi tri %d\n", item, pos);
         return;
      }
      current = current->next;
      pos++;
   }
   printf("%d khong ton tai trong list", item);
}
int main() {
	int n, fNum, tmp;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		{
			scanf("%d", &tmp);
			insert(tmp);
		}
	printf("Nhap so can tim: ");
	scanf("%d",&fNum);
	find_data(fNum);   
    return 0;
}
/* Tìm phần tử trong danh sách liên kết
input
5
2 4 5 6 8
Nhap so can tim: 5
output
Tim thay so 5 tai vay tri 2*/
