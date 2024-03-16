#include <stdio.h>


void merge(int arr[], int l, int m, int r)
{
    int temp[r+l+1];
    int n1 = l;

    int n2 = m+1;
    int k = 0;
    


    while(n1 <= m && n2 <= r)
    {
        if(arr[n1] <= arr[n2])
        {
            temp[k] = arr[n1];
            n1++;
            k++;
        }
        else
        {
            temp[k++] = arr[n2];
            n2++;
        }
    }

    while(n1 <= m)
    {
        temp[k] = arr[n1];
        n1++;
        k++;
    }

    while(n2 <= r)
    {
        temp[k] = arr[n2];
        n2++;
        k++;
    }

    for(int i = 0; i < k; i++)
    {
        arr[i+l] = temp[i];
    }

    // for(int i = 0; i <= r; i++)
    // {
    //     printf("%d ", arr[i]);
    // }

}

void mergeSort(int arr[], int l, int r)
{
    if(l < r)
    {
        int m = (l + r)/ 2;

        mergeSort(arr, l, m);

        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int main()
{
    int arr[] = {5, 1, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Array: ");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    mergeSort(arr, 0, n - 1);

    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}