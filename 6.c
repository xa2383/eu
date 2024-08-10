#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *leftChild;
    struct node *rightChild;
};
struct node *root = NULL;
void insert(int data)
{
    struct node *tempNode = (struct node *)malloc(sizeof(struct node));
    struct node *current;
    struct node *parent;
    tempNode->data = data;
    tempNode->leftChild = NULL;
    tempNode->rightChild = NULL;

    // if tree is empty
    if (root == NULL)
    {
        root = tempNode;
    }
    else
    {
        current = root;
        parent = NULL;
        while (1)
        {
            parent = current;

            // go to left of the tree
            if (data < parent->data)
            {
                current = current->leftChild;

                // insert to the left
                if (current == NULL)
                {
                    parent->leftChild = tempNode;
                    return;
                }
            } // go to right of the tree
            else
            {
                current = current->rightChild;

                // insert to the right
                if (current == NULL)
                {
                    parent->rightChild = tempNode;
                    return;
                }
            }
        }
    }
}

void inorder_traversal(struct node *root)
{
    if (root != NULL)
    {
        inorder_traversal(root->leftChild);
        printf("%d ", root->data);
        inorder_traversal(root->rightChild);
    }
}
void preorder_traversal(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder_traversal(root->leftChild);
        preorder_traversal(root->rightChild);
    }
}
void postorder_traversal(struct node *root)
{
    if (root != NULL)
    {
        postorder_traversal(root->leftChild);
        postorder_traversal(root->rightChild);
        printf("%d ", root->data);
    }
}
int main()
{
    int i, n, array[10];
    printf("enter n \n");
    scanf("%d", &n);
    printf("enter array \n");
    for (i = 0; i < n; i++)
        scanf("%d", &array[i]);
    for (i = 0; i < n; i++)
        insert(array[i]);
    printf("\nInorder traversal: ");
    inorder_traversal(root);
    printf("\n");
    printf("\nPreorder traversal: ");
    preorder_traversal(root);
    printf("\n");
    printf("\nPostorder traversal: ");
    postorder_traversal(root);
    return 0;
}
