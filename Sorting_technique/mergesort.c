#include <stdio.h>
int Display(int arr[], int n);
int MergeSort(int arr[], int low, int high);

int Merge(int arr[], int left, int mid, int right);

int main()
{
    int n;
    printf("ENTER THE size of array ; ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("enter %d element of arrar;", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("the array you entered\n");
    Display(arr, n);
    MergeSort(arr, 0, n - 1);
    printf("array after sorted\n");
    Display(arr, n);
    return 0;
}

int Display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int MergeSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;
        MergeSort(arr, low, mid);
        MergeSort(arr, mid + 1, high);

        Merge(arr, low, mid, high);
    }
}
int Merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int l1[n1], l2[n2];
    for (int j = 0; j < n1; j++)
    {
        l1[j] = arr[left + j];
    }
    for (int j = 0; j < n2; j++)
    {
        l2[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (l1[i] <= l2[j])
        {
            arr[k] = l1[i];
            i++;
        }
        else
        {
            arr[k] = l2[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = l1[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = l2[j];
        j++;
        k++;
    }
}