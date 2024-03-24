#include <stdio.h>

int sortcountsplitinv(int left[], int right[], int a[], int nl, int nr) {
    int count = 0;

    int i = 0, j = 0, k = 0;

    while (i < nl && j < nr) {
        if (left[i] <= right[j]) {
            a[k] = left[i];
            i++;
        }
        else {
            a[k] = right[j];
            j++;
            count += (nl - i);
        }
        k++;
    }

    while (i < nl) {
        a[k] = left[i];
        i++;
        k++;
    }

    while (j < nr) {

    while (j < nr) {
        a[k] = right[j];
        j++;
        k++;
    }
        a[k] = right[j];
        j++;
        k++;
    }

    return count;
}

int sortcount(int a[], int n) {
    if (n == 1)
        return 0;
        
    int mid = n / 2;
    int left[mid];
    int right[n - mid];

    for (int i = 0; i < mid; i++)
        left[i] = a[i];

    for (int i = mid; i < n; i++)
        right[i - mid] = a[i];

    int x = sortcount(left, mid);
    int y = sortcount(right, n - mid);
    int z = sortcountsplitinv(left, right, a, mid, n - mid);

    return x + y + z;
}

int main() {
    printf("Enter the number of elements in the array: ");
    int n;
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int count = sortcount(a, n);

    printf("There are %d inversions\n", count);
}