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

int Insertionsort(int arr[], int size) // selection sort me aur isme ye parameters same hai function call me
{
    int key, j;
    for (int i = 1; i < size; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && key < arr[j]) // while loop isliye lagaya kyuki hume key se phele se saare element compare krne uske liye(j>=0) lagaya aur saath ki saath ye bhi compare krlia ki key se phele ka koi element bda to ni hai
        // agar key se phele ka koi element bada hua
        {
            arr[j + 1] = arr[j]; // to hume key ke andar us value ko daalna hai
            j--;                 // aur fir j ku ghataya isliye hai ki kahi usse chota bhi koi element to ni hai
        }
        arr[j + 1] = key; // aur jab while loop false hoega to is condition ki help se hum key ko uski original jangeh pe set krdenge
    }
}