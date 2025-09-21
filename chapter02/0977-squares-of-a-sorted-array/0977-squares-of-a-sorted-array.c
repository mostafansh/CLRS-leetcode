/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>  // for malloc
#include <stdbool.h> // optional if using bool

int* sortedSquares(int* a, int n, int* returnSize) {
    // Allocate dynamic memory for result
    int* arr = (int*)malloc(n * sizeof(int));
    if (!arr) return NULL; // handle malloc failure

    int j = -1, i = 0;

    // Determine starting positions for two-pointer approach
    if (a[0] >= 0) {
        j = -1;
        i = 0;
    } else if (a[n - 1] <= 0) {
        j = n - 1;
        i = n;
    } else {
        for (int p = 0; p < n - 1; p++) {
            if (a[p] < 0 && a[p + 1] >= 0) {
                j = p;
                i = p + 1;
                break;
            }
        }
    }

    // Merge process: compare squares and build sorted array
    for (int cnt = 0; cnt < n; cnt++) {
        if (j < 0) {
            arr[cnt] = a[i] * a[i];
            i++;
        } else if (i >= n) {
            arr[cnt] = a[j] * a[j];
            j--;
        } else {
            if (-a[j] < a[i]) {
                arr[cnt] = a[j] * a[j];
                j--;
            } else {
                arr[cnt] = a[i] * a[i];
                i++;
            }
        }
    }

    *returnSize = n;
    return arr; // caller must call free(arr)
}
