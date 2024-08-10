#include <stdio.h>
#include <stdlib.h>
#define MAX 20
int main()
{
    // prototype of the functions used in the program
    int rank(char);
    char pop(char[], int *);
    void push(char[], int *, char);
    int TOP = MAX, i, j = 0;
    char stack[20], infix[20], postfix[20], c1, c2;
    printf("Enter infix expression\n");
    scanf("%s", infix);
    push(stack, &TOP, '\0');
    for (i = 0; infix[i] != '\0'; i++)
    {
        if (rank(stack[TOP]) < rank(infix[i]))
            push(stack, &TOP, infix[i]);
        else
        {
            while (rank(stack[TOP]) >= rank(infix[i]))
                postfix[j++] = pop(stack, &TOP);
            push(stack, &TOP, infix[i]);
        }
    }
    while (stack[TOP] != '\0') // pop out remaining character from stack
        postfix[j++] = pop(stack, &TOP);
    postfix[j] = '\0';
    printf("postfix expression is:%s", postfix);
    return 0;
}
int rank(char c)
{
    switch (c)
    {
    case '\0':
        return (0);
        break;
    case '+':
    case '-':
        return (1);
        break;
    case '*':
    case '/':
        return (2);
        break;
    default:
        return (3);
        break;
    }
}
void push(char stack[], int *p, char c)
{
    *p = *p - 1;
    stack[*p] = c;
}
char pop(char stack[], int *p)
{
    char c;
    c = stack[*p];
    *p = *p + 1;
    return (c);
}