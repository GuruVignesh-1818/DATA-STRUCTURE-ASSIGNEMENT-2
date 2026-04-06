#include <stdio.h>

int main() {
    int arr[] = {4, 5, 2, 10, 8};  // Input array
    int n = 5;                     // Size of array
    int i, j;

    // Loop through each element
    for(i = 0; i < n; i++) {

        int found = 0;  // Flag to check if next greater found

        // Check elements to the right
        for(j = i + 1; j < n; j++) {

            // If greater element found
            if(arr[j] > arr[i]) {
                printf("%d -> %d\n", arr[i], arr[j]);
                found = 1;
                break;
            }
        }

        // If no greater element found
        if(!found)
            printf("%d -> -1\n", arr[i]);
    }

    return 0;
}