#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *leftchild;
    struct node *rightchild;
};
struct node *root=NULL;
void insert(int data)
{
    struct node *tempNode=(struct node*)malloc(sizeof(struct node));
    struct node *current;
    struct node *parent;
    tempNode->data=data;
    tempNode->leftchild=NULL;
    tempNode->rightchild=NULL;
    if(root == NULL)
    {
        root=tempNode;
    }
    else
    {
        current=root;
        parent=NULL;
        while(1)
        {
            parent=current;
            if(data<parent->data)
            {
                current=current->leftchild;
                if(current==NULL)
                {
                    parent->leftchild=tempNode;
                    return;
                }
            }
            else
            {
                current=current->rightchild;
                if(current==NULL)
                {
                    parent->rightchild=tempNode;
                    return;
                }
            }

        }
    }
}
void inorder_traversal(struct node *root)
{
    if(root!=NULL)
    {
        inorder_traversal(root->leftchild);
        printf("%d \t",root->data);
        inorder_traversal(root->rightchild);
    }
}
void preorder_traversal(struct node *root)
{
    if(root!=NULL)
    {
        printf("%d \t",root->data);
        preorder_traversal(root->leftchild);
        preorder_traversal(root->rightchild);
    }
}
void postorder_traversal(struct node *root)
{
    if(root!=NULL)
    {
        postorder_traversal(root->leftchild);
        postorder_traversal(root->rightchild);
        printf("%d \t",root->data);
    }
}
int main()
{
    int i,n,array[10];
    printf("Enter n \n");
    scanf("%d",&n);
    printf("Enter array\n");
    for(i=0;i<n;i++)
        scanf("%d",&array[i]);
    for(i=0;i<n;i++)
        insert(array[i]);
    printf("\n Inorder traversal:");
    inorder_traversal(root);
    printf("\n");
    printf("\n Preorder traversal:");
    preorder_traversal(root);
    printf("\n");
    printf("\n Postorder traversal:");
    postorder_traversal(root);
    return 0;
}
