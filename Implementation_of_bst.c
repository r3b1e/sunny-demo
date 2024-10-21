#include<stdio.h>
#include<stdlib.h>

struct bst{
    int val;
    struct bst *left;
    struct bst *right;
};
struct bst *newnode(int key){
   struct bst *temp = (struct bst *)malloc(sizeof(struct bst));
   temp->val = key;
   temp->left = NULL;
   temp->right = NULL;
   return temp;
}
struct bst * insert(struct bst *root, int val){
if(root == NULL){
   return newnode(val);
}
if(val<root->val){
root->left = insert(root->left, val);
}
else{
root->right = insert(root->right, val);
}
return root;
}
void preorder(struct bst *root){
    if(root == NULL){
        return;
    }
    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}
void inorder(struct bst *root){
    if(root == NULL){
        return;
    }
    
    preorder(root->left);
    printf("%d ", root->val);
    preorder(root->right);
   
}
void postorder(struct bst *root){
    if(root == NULL){
        return;
    }
    
    preorder(root->left);
    preorder(root->right);
    printf("%d ", root->val);
}
int main(){
    int choose;
    int n;
    printf("Enter value for Root Node : ");
    scanf("%d", &n);
    struct bst *root = newnode(n);
    while(1){
        printf("1. Insert\n2. Display\n3. exit");
        scanf("%d", &choose);
        switch(choose){
            case 1 : {
                int key;
                printf("Enter val to insert : ");
                scanf("%d", &key);
                struct bst *demo = insert(root, key);
            }
            break;
            case 2 : {
                printf("\n");
             preorder(root);
             printf("\n");
             inorder(root);
             printf("\n");
             postorder(root);
            }
            break;
            case 3 : exit(0);
            break;
            default : ("Enter a valid Number");
            break;
        }
    }
    return 0;

}