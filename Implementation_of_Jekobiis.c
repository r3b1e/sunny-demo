#include<stdio.h>
#include<stdlib.h>
struct Node{
    int key;
    struct Node *next;
};
int main(){
 int n;
 printf("Enter No. of player");
 scanf("%d", &n);
 int k;
 printf("Enter value of k");
 scanf("%d", &k);
struct Node *st = (struct Node *)malloc(sizeof(struct Node));
st->key = 1;
struct Node *ptr = st;
struct Node *temp;
 for(int i=2;i<=n;i++){
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->key = i;
    temp->next = st;
    ptr->next = temp;
    ptr = temp;
 }
 temp = st->next;
 while(temp != st){
    printf("%d ", temp->key);
    temp=temp->next;
 }
 while(st != st->next){
    for(int j=1;j<k;j++){
       st = st->next;
    }
  struct Node *toDelete = st->next;
      

        printf("\nDeleted Player ID: %d", toDelete->key);
        st->next = toDelete->next; // Bypass the `k-th` player.
        free(toDelete);            // Free the memory of the deleted player.
        
 }
 printf("\n**The winner is %d**", st->key);
}
