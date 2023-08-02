#include <stdio.h>
#include <stdlib.h>


void merge(int arr[], int left, int middle, int right) {
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[middle + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        merge(arr, left, middle, right);
    }
}

int main() {
    int numMobileNumbers;

    printf("Enter the number of mobile numbers in the contact list: ");
    scanf("%d", &numMobileNumbers);

    int* mobileNumbers = (int*)malloc(numMobileNumbers * sizeof(int));

    printf("Enter the mobile numbers in the contact list:\n");
    for (int i = 0; i < numMobileNumbers; i++) {
        scanf("%d", &mobileNumbers[i]);
    }

  
    mergeSort(mobileNumbers, 0, numMobileNumbers - 1);

    printf("\nSorted mobile numbers in the contact list:\n");
    for (int i = 0; i < numMobileNumbers; i++) {
        printf("%d\n", mobileNumbers[i]);
    }

    free(mobileNumbers); // Free memory for the array of mobile numbers
    return 0;
}
