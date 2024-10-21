#include<stdio.h>
#include<stdlib.h>
int partition(int arr[], int st, int ed){
int pi = arr[ed];
int i = st-1;

for(int j = st;j<ed;j++){
    if(arr[j]<pi){
        i++;
        int temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
    }
    }
int temp = arr[ed];
        arr[ed] = arr[i+1];
        arr[i+1] = temp;
        return (i+1);
}
void quick(int st, int ed, int arr[]){
    if(st>=ed){
        return;
    }
    int mid = partition(arr, st, ed);
quick(st, mid-1, arr);
quick(mid+1, ed,arr);
}

int main(){
int arr[] = {7,5,4,6,9,2,3,5};
quick(0, 7, arr);
for(int i=0;i<=7;i++){
    printf("%d ", arr[i]);
}
return 0;
}