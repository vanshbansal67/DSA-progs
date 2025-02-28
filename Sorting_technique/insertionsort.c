#include <stdio.h>
int display(int array[], int n);
int Insertionsort(int arr[], int size);

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
    printf("the array you entered\n");
    display(arr, n);
    Insertionsort(arr, n);
    printf("the array after sorting\n");
    display(arr, n);
    return 0;
}

int display(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int Insertionsort(int arr[], int size)
{
    int key, j;
    for (int i = 1; i < size; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && key < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}