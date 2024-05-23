#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdbool.h>

typedef struct data {
    int array_size;
    int arr[10];
} data_t;

data_t d1;

void swap(int* xp, int* yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}


void* bubbleSort(void* param) {
    int i, j;
    data_t *d2;
    d2 = (data_t*)param;
    
    bool swapped;
    for (i = 0; i < d2->array_size - 1; i++) {
        swapped = false;
        for (j = 0; j < d2->array_size - i - 1; j++) {
            if (d2->arr[j] > d2->arr[j + 1]) {
                swap(&d2->arr[j], &d2->arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
    return NULL;
}

int main() {
    int ret = 0, i = 0;
    d1.array_size = 10;
    
    
    int tempArr[10] = {12, 3, 45, 1, 2, 89, 87, 78, 5, 0};
    for (i = 0; i < 10; i++) {
        d1.arr[i] = tempArr[i];
    }
    
    pthread_t th;
    ret = pthread_create(&th, NULL, bubbleSort, &d1);
    if (ret != 0) {
        fprintf(stderr, "Error - pthread_create() return code: %d\n", ret);
        return 1;
    }
    pthread_join(th, NULL);
    
    printf("The sorted array\n");
    for (i = 0; i < d1.array_size; i++)
        printf("%d ", d1.arr[i]);
    printf("\r\n");
    
    return 0;
}

