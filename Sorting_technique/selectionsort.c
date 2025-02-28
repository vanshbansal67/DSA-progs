#include <stdio.h>
int selectionsort(int arr[], int n);

int swap(int *a, int *b);

int display(int arr[], int n);

int main()
{
    int n;
    printf("enter the size of array ; ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("enter the %d element of array ; ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("the array you entered ; \n");
    display(arr, n);
    selectionsort(arr, n);
    printf("the array after sorting ; \n");
    display(arr, n);
    return 0;
}

int swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int selectionsort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}