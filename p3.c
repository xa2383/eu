#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int **matrixmultiply(int **a, int r1, int c1, int **b, int r2, int c2)
{
    int **resultmatrix;
    int i, j, k, r, c;
    r = r1;
    c = c2;
    resultmatrix = (int **)malloc(sizeof(int *) * r);
    for (i = 0; i < r; i++)
        resultmatrix[i] = (int *)malloc(sizeof(int) * c);
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            resultmatrix[i][j] = 0;
            for (k = 0; k < c1; k++)
                resultmatrix[i][j] += a[i][k] * b[k][j];
        }
    }
    return resultmatrix;
}
void printmatrix(int **matrix, int r, int c)
{
    int i, j;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
            printf("%d", matrix[i][j]);
        printf("\n");
    }
}
int plaintexttociphertext (char plaintext[],int** matrix)
{
int len,**plaintextmatrix,**resultmatrix,i,j;
char * ciphertext;
len=strlen(plaintext);
ciphertext=(char*) malloc(sizeof(char)*1000);
plaintextmatrix=(int**)malloc(sizeof(int*)*len);
for(i=0;i<len;i++)
plaintextmatrix[i]=(int*)malloc(sizeof(int)*1);
for(i=0;i<len;i++)
for(j=0;j<1;j++)
plaintextmatrix[i][j]=plaintext[i]-'a';
resultmatrix=matrixmultiply(matrix,len,len,plaintextmatrix,len,1);
for(i=0;i<len;i++)
for(j=0;j<1;j++)
resultmatrix[i][j]%=26;
printf(" the cipher text is as follows:");
for(i=0;i<len;i++)
for(j=0;j<1;j++)
printf("%c",resultmatrix[i][j]+'a');
printf("\n");
}

int main()
{
    int len, i, j, **matrix;
    char plaintext[1000];
    printf(" enter the word to be encrypted:");
    scanf("%s", plaintext);
    len = strlen(plaintext);
    // allocating memory to matrix
    matrix = (int **)malloc(sizeof(int *) * len);
    for (i = 0; i < len; i++)
        matrix[i] = (int *)malloc(sizeof(int) * len);
printf(" enter matrix of %d by %d to be used in encryption process:\n",len,len);
for(i=0;i<len;i++)
for(j=0;j<len;j++)
scanf("%d",&matrix[i][j]);
plaintexttociphertext(plaintext,matrix);
return 0;
}