#include<stdio.h>
#include<stdlib.h>
#define MAX 3
int Q[MAX];
int Rear,Front;
void Qinsert();
void Qdelete();
void Qdisplay();
void main()
{
    int choice;
    Rear=-1;Front =-1;
    while(1)
    {
        printf("Basic operations of queues\n");
        printf("\n 1:Insertion in queues");
        printf("\n 2:Deletion in queues");
        printf("\n 3:Display contents of queue");
        printf("\n 4:Exit");
        printf("\n Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:Qinsert(); break;
            case 2:Qdelete(); break;
            case 3:Qdisplay(); break;
            default: exit(0);
        }

    }
}
void Qinsert()
{
    if(Rear==MAX-1)
        printf("Queue Overflow\n");
    else
    {
        if(Rear==-1)
        {
            Front=0;
        }
        printf("\n Enter the item to be inserted:");
        scanf("%d",&Q[++Rear]);

    }
}
void Qdelete()
{
    if(Front==-1)
        printf("\n Queue is empty");
    else
    {
        printf("\n Deleted item is %d\n",Q[Front++]);
        if(Front>Rear)
            Front=Rear=-1;
    }
}
void Qdisplay()
{
    int i;
    if(Front==-1)
        printf("\n Queue is empty\n");
    else
    {
        printf("\n Queue element are:\n");
        for(i=Front;i<=Rear;i++)
            printf("%d \t",Q[i]);
    }
}
