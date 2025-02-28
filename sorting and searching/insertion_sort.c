#include <stdio.h>
int insertion_sort(int arr[], int n);
int swap(int *a, int *b);
int main()
{
    int n;
    printf("enter the size of Array; ");
    scanf("%d", &n);
    int array[n];
    for (int i = 0; i < n; i++)
    {
        printf("enter %d element of array;", i + 1);
        scanf("%d", &array[i]);
    }
    insertion_sort(array, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    return 0;
}

int insertion_sort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[i])
            {
                swap(&arr[j], &arr[i]);
            }
        }
    }
}

int swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}