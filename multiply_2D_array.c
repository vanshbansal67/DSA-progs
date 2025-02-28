#include <stdio.h>
int multiplication(int r1, int c1, int r2, int c2);

int main()
{
    int r1, c1, r2, c2;
    printf("enter the no. of rows for first matrix: ");
    scanf("%d", &r1);
    printf("enter the no. of columns for first matrix: ");
    scanf("%d", &c1);
    int mar1[r1][c1];
    printf("enter the no. of rows for second matrix: ");
    scanf("%d", &r2);
    printf("enter the no. of columns for second matrix: ");
    scanf("%d", &c2);
    if (r2 != c1)
    {
        printf("multiplication not possible");
    }
    else
    {
        multiplication(r1, c1, r2, c2);
    }

    return 0;
}

int multiplication(int r1, int c1, int r2, int c2)
{
    int mar1[r1][c1];
    printf("******************************\n");

    printf("enter the elements for the first matrix:\n");
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            printf("enter the elements of first matrix for %d row; ", i + 1);
            scanf("%d", &mar1[i][j]);
        }
    }

    int mar2[r2][c2];
    printf("******************************\n");

    printf("enter the elements for the second matrix:\n");
    for (int i = 0; i < r2; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            printf("enter the elements of second matrix for %d row; ", i + 1);
            scanf("%d", &mar2[i][j]);
        }
    }
    printf("the matrix you entered are:\n");
    printf("******************************\n");
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            printf("%d ", mar1[i][j]);
        }
        printf("\n");
    }
    printf("the matrix you entered are:\n");

    printf("******************************\n");

    for (int i = 0; i < r2; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            printf("%d ", mar2[i][j]);
        }
        printf("\n");
    }
    int mar3[r1][c2];
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            mar3[i][j] = 0;
            for (int k = 0; k < c1; k++)
            {
                mar3[i][j] += mar1[i][k] * mar2[k][j];
            }
        }
    }
    printf("the resulting matrix after multiplication is:\n");
    printf("******************************\n");
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            printf("%d ", mar3[i][j]);
        }
        printf("\n");
    }
}