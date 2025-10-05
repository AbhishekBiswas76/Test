#include <stdio.h>
#include <stdlib.h>

// Selection Sort with Static Allocation
void selectionSortStatic(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        // Swap elements
        int temp = arr[minIdx];
        arr[minIdx] = arr[i];
        arr[i] = temp;
    }
}
// Function to print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
    // Static Allocation Example
    int i,n;
    int staticArr[10];
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    printf("Enter the elements: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&staticArr[i]);
    }
    printf("Static Allocation - Original array: ");
    printArray(staticArr, n);
    selectionSortStatic(staticArr, n);
    printf("Static Allocation - Sorted array: ");
    printArray(staticArr, n);
}