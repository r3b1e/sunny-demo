#include<stdio.h>
#include<stdlib.h>
struct Stack
{
    /* data */
    int data;
    int i;
    struct Stack *next;
};
struct Stack *head = NULL;
// struct Stack *createstack (){
// struct Stack *node = (struct Stack *)malloc(sizeof(struct Stack));
// node->i = 0;
// return node;
// }
// int IsEmpty(){
// return (head->i == -1);
// }
void push(){
    int val;
    struct Stack *node = (struct Stack *)malloc(sizeof(struct Stack));
    printf("\nEnter value to be push : ");
    scanf("%d", &val);
    node->data = val;
    if(head == NULL){
        head = node;
        head->next = NULL;
    }
    else{
    node->next = head;
    head = node;
    }
    printf("\nElement Pushed Sucessfully");
}
void pop(){
    if(head == NULL){
        printf("\nStack UnderFlow - There is no element to be poped");
        return;
    }
    int ext;
    struct Stack *temp = head;
    head = head->next;
    ext = temp->data;
    free(temp);
    printf("%d", ext);
}
void display(){
    struct Stack *temp = head;
    printf("\nElement in the Stack : ");
    while(temp !=NULL){
        int val = temp->data;
    printf("%d ", val);
    temp = temp->next;
    }
}

int main(){
    
    int choose;
    while(1){
    printf("\n1 - push an element\n2 - pop an element\n2 - Display all element\n4 - Exit");
    printf("\nEnter ur Choose:)");
    scanf("%d", &choose);
    switch(choose){
       case 1 : push();
       break;
       case 2 : pop();
       break;
       case 3 : display();
       break;
       case 4 : {
       printf("Exiting...");
       return 0;}
       break;
       default : printf("Enter a valid no.");
       break;
    }
    }
    return 0;
}