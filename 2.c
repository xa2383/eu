#include <stdio.h>
#include <stdlib.h>
#define MAX 10

// Function declarations (prototypes)
void push(int stack[], int *p, int data);
int pop(int stack[], int *p);

int main()
{
    int stack[MAX], TOP = MAX, data1, data2, res, i;
    char postfix[20];
    
    printf("Enter postfix expression\n");
    scanf("%s", postfix);
    
    for (i = 0; postfix[i] != '\0'; i++)
    {
        switch (postfix[i])
        {
        case '+':
            data1 = pop(stack, &TOP);
            data2 = pop(stack, &TOP);
            res = data1 + data2;
            push(stack, &TOP, res);
            break;
        case '-':
            data1 = pop(stack, &TOP);
            data2 = pop(stack, &TOP);
            res = data1 - data2;
            push(stack, &TOP, res);
            break;
        case '*':
            data1 = pop(stack, &TOP);
            data2 = pop(stack, &TOP);
            res = data1 * data2;
            push(stack, &TOP, res);
            break;
        case '/':
            data2 = pop(stack, &TOP);
            data1 = pop(stack, &TOP);
            res = data1 / data2;
            push(stack, &TOP, res);
            break;
        default:
            push(stack, &TOP, postfix[i] - '0');
        }
    }
    
    res = pop(stack, &TOP);
    printf("Result of computation: %d\n", res);  // Changed 'x' to 'res'
    return 0;
}

void push(int stack[], int *p, int data)
{
    *p = *p - 1;
    stack[*p] = data;
}

int pop(int stack[], int *p)
{
    int data;
    data = stack[*p];
    *p = *p + 1;
    return (data);
}
