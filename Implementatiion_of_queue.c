#include<stdio.h>
#include<stdlib.h>
struct Queue{
    int data;
    struct Queue *next;
}*front = NULL, *rare = NULL;
void Enque(int value){
    struct Queue *node = (struct Queue *)malloc(sizeof(struct Queue));
    node->data = value;
    node->next = NULL;
    if(front == NULL){
    front = rare = node;
    return;
    }
    front->next = node;
    front = node;
}
void deque(){
    if(rare == NULL){
        printf("Queue Underflow");
        return;
    }
    struct Queue *temp = rare;
    rare = rare->next;
    free(temp);
}
void Display(){
    struct Queue *temp = rare;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
int main(){
    int choose;
while(1){
    printf("1. enQue\n2. deQue\n3. disPlay\n4. exit");
    printf("Enter Your Choose :)");
    scanf("%d", &choose);
    switch(choose){
        case 1 : {int val;
        printf("\nEnter Value to Enque Into Queue : ");
        scanf("%d", &val);
        Enque(val);
        }
        break;
        case 2 : {
            printf("\nthe element is poped");
            deque();
        }
        break;
        case 3 : {
            printf("\nElement are : ");
            Display();
        }
        break;
        case 4 : exit(0);
        default : printf("wrong choose");
        break;
    }

}
return 0;
}