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
        MergeSort(arr, low, mid);      // is function call se hum first half ko aur bhi divide krre
        MergeSort(arr, mid + 1, high); // is function call ki help se hum secod half ko divide krre

        Merge(arr, low, mid, high); // yo function call sabse phele 2 element ko sort krra fir 4 element ko fir 8 ko.....
    }
}
int Merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1; // first half ka array banane ke liye size calculate kia
    int n2 = right - mid;    // second half ka array banane ke liye size calculate kia
    int l1[n1], l2[n2];      // yha bhi dono array initialize kre ....inko hum L and R naam bhi bna sake vo sahi option hai l1 aur l2 thodi se confusion krdega
    for (int j = 0; j < n1; j++)
    {
        l1[j] = arr[left + j]; // is puure for loop se first half ki value l1(L) me daali
    }
    for (int j = 0; j < n2; j++)
    {
        l2[j] = arr[mid + 1 + j]; // is loop se socnd half ki value l2(R)me
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) // is loop se hum dono halfs ko tab tak traverse krenge jab tak ki dono puure traverse ni ho jaate
    {
        if (l1[i] <= l2[j])
        {
            arr[k] = l1[i]; // is if aur else se humne jo original array se usme upate kra
            i++;            // matlab agar l1 ka phela element l2 ke phele element se chota hai to usko original waale me add krdia
        }
        else
        {
            arr[k] = l2[j]; // isme vise versa
            j++;
        }
        k++;
    }
    while (i < n1) // is loop se bache hue saare element l1 ke original waale me add kre
    {
        arr[k] = l1[i];
        i++;
        k++;
    }
    while (j < n2) // aur is loop se l2 ke bache hue element original waale me add kre
    {
        arr[k] = l2[j];
        j++;
        k++;
    }
}