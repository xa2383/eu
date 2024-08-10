#include<stdio.h>
#include<malloc.h>
#define MAX 5

int main() {
    int stack[5], TOP = MAX, choice, TRUE = 1;
    while (TRUE) {
        choice = menu();
        switch(choice) {
            case 1:
                push(stack, &TOP);
                display(stack, TOP);
                break;
            case 2:
                pop(stack, &TOP);
                display(stack, TOP);
                break;
            case 3:
                display(stack, TOP);
                break;
            case 4:
            default:
                TRUE = 0;
                break;
        }
    }
    return 0;
}

int menu() {
    int choice;
    printf("\n");
    printf("1. Push operation\n");
    printf("2. Pop operation\n");
    printf("3. Display stack\n");
    printf("4. Exit\n");
    printf("Enter your choice:\n");
    scanf("%d", &choice);
    return choice;
}

void push(int stack[], int *p) {
    int data;
    if (*p == 0) {
        printf("Stack is full\n");
    } else {
        printf("Enter the data to be pushed:\n");
        scanf("%d", &data);
        *p = *p - 1;
        stack[*p] = data;
    }
}

void pop(int stack[], int *p) {
    if (*p == MAX) {
        printf("Stack is empty\n");
    } else {
        printf("Data deleted: %d\n", stack[*p]);
        *p = *p + 1;
    }
}

void display(int stack[], int top) {
    int i;
    printf("Elements of the stack are:\n");
    for (i = TOP; i < MAX; i++) {
        printf("%d\t", stack[i]);
    }
}