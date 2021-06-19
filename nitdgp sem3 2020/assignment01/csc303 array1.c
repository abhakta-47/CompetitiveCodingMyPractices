#include <stdio.h>

int Search(int arr[], int l, int r, int x)
{
    int mid = l + (r - l) / 2;
    if (r >= l)
    {

        // If the element is present at the middle
        // return current positon - middle
        if (arr[mid] == x)
            return mid;

        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x)
            return Search(arr, l, mid - 1, x);

        // Else the element can only be present
        // in right subarray
        return Search(arr, mid + 1, r, x);
    }

    // We reach here when element is not
    // present in array
    return -1;
}

int main()
{
    int n, i, a[100], s, r;
    printf("Enter number of elements : ");
    scanf("%d", &n);
    printf("Enter elements : ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter what to search : ");
    scanf("%d", &s);
    printf("Searching for %d ........\n", s);
    r = Search(a, 0, n - 1, s);
    if (r == -1)
        printf("Item not found !!!!\n");
    else
        printf("Item found in position : %d\n", r);
}