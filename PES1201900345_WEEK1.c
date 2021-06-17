#include <stdio.h>
#include <stdlib.h>

int seqsearch(int *arr, int n, int key) {
    int i;
    for(i=0; i<n; i++) {
        if(*(arr+i) == key)
        {
            return i;
        }
    }
    return -1;
}

int main(void) {
    int *arr;
    int key;
    int n;
    int res;
    int i;

    arr = (int *)malloc(n*sizeof(n));

    printf("Enter the size of the array");
    scanf("%d", &n);

    printf("Enter the elemenets of array");
    for(i=0; i<n; ++i) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to be searched");
    scanf("%d", &key);

    res = seqsearch(arr, n, key);
    printf("%d", res);

    free(arr);
    return 0;
}

