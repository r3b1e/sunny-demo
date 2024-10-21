#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int size;
    int *arr;
    int r;
    int f;
};

int isEmpty(struct Stack *s) {
    return s->r > s->f;
}

int isFull(struct Stack *s) {
    return s->f == s->size - 1;
}

void Enqueue(struct Stack *s, int val) {
    if (isFull(s)) {
        printf("It's Full\n");
    } else {
        if (s->r == -1) {
            s->r = 0;
        }
        s->f++;
        s->arr[s->f] = val;
    }
}

int Dequeue(struct Stack *s) {
    int a = -1;
    if (isEmpty(s)) {
        printf("It's Empty\n");
    } else {
        a = s->arr[s->r];
        s->r++;
        if (s->r > s->f) {
            s->r = s->f = -1;
        }
    }
    return a;
}

int main() {
    struct Stack q;
    q.size = 400;
    q.f = q.r = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));
    int i = 0;
    int visited[7] = {0, 0, 0, 0, 0, 0, 0};
    int a[7][7] = {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}
    };

    printf("%d", i);
    visited[i] = 1;
    Enqueue(&q, i);
    while (!isEmpty(&q)) {
        int node = Dequeue(&q);
        for (int j = 0; j < 7; j++) {
            if (a[node][j] == 1 && visited[j] == 0) {
                printf("%d", j);
                visited[j] = 1;
                Enqueue(&q, j);
            }
        }
    }
    return 0;
}
