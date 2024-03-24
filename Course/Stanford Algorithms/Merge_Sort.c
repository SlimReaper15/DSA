#include <stdio.h>

void merge(int left[], int right[], int a[], int nl, int nr) {
    int i = 0, j = 0, k = 0;
    
    while (i < nl && j < nr) {
        if (left[i] <= right[j]) {
            a[k] = left[i];
            i++;
        }
        else {
            a[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < nl) {
        a[k] = left[i];
        i++;
        k++;
    }

    while (j < nr) {
        a[k] = right[j];
        j++;
        k++;
    }
}

void mergesort(int a[], int n) {
    if (n < 2)
        return;

    int mid = n / 2;
    int left[mid];
    int right[n - mid];

    for (int i = 0; i < mid; i++)
        left[i] = a[i];
    
    for (int i = mid; i < n; i++)
        right[i - mid] = a[i];
    
    mergesort(left, mid);
    mergesort(right, n - mid);
    merge(left, right, a, mid, n - mid);
}

int main() {
    printf("Enter the number of elements in the array: ");
    int n;
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    
    mergesort(a, n);

    printf("Sorted array: ");
    
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    
    printf("\n");
}