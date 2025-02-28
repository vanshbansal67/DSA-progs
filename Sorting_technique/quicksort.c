#include <stdio.h>
int quick(int array[], int low, int high);
int display(int array[], int size);
int partition(int array[], int low, int high);
int swap(int *a, int *b);
int main()
{

    int n;
    printf("enter the size of array; ");
    scanf("%d", &n);
    int array[n];
    for (int i = 0; i < n; i++)
    {
        printf("enter the %d element;", i + 1);
        scanf("%d", &array[i]);
    }
    printf("the array you created\n");
    display(array, n);

    quick(array, 0, n - 1);
    printf("sorted array\n");
    display(array, n);
    return 0;
}

int swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;

    *b = temp;
}
int display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int quick(int array[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(array, low, high);

        quick(array, low, pi - 1);
        quick(array, pi + 1, high);
    }
}

int partition(int array[], int low, int high)
{
    int pivot = array[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return i + 1;
}