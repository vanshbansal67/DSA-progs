#include <stdio.h>
int bubble_sort(int arr[], int n);
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
    bubble_sort(array, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    return 0;
}

int bubble_sort(int arr[], int n)
{
    for (int j = 0; j < n - 1; j++) // n-1 isliye lia kyuki humko array ke i+1 waale se comparison karna hai
    {
        for (int i = 0; i < n - j - 1; i++) /*n-j-1 isliye kia kyuki ek loop complete
                                                hone par jo sabse bada element hai vo last me pahuch
                                                 chuka hota hai to usko wapis se compare karne
                                                 ki jarurat nahi hai...*/
        {
            if (arr[i] > arr[i + 1])
            {
                swap(&arr[i], &arr[i + 1]);
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