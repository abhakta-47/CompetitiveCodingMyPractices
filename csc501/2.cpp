// CPP code to search for element in a
// very large file using Multithreading
#include <math.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
// N size of array

// N number of threads to create

// int a[N] = {1, 5, 7, 10, 12, 14, 15, 18, 20, 22, 25, 27, 30, 64, 110, 220};
// int key = 202;
int N, n, key, limit;
float *a;
// Flag to indicate if key is found in a[]
// or not.
int f = 0;

int current_thread = 0;

// Linear search function which will
// run for all the threads
void *ThreadSearch(void *args) {
    int num = current_thread++, i;
    // printf("%d ", key);
    for (i = num * limit; i < min((num + 1) * limit, N); i++) {
        if (a[i] == key)
            f = 1;
    }
    return NULL;
}

// Driver Code
int main() {

    int i;
    printf("enter array size : ");
    scanf("%d", &N);
    printf("enter number of threads : ");
    scanf("%d", &n);
    limit = ceil((N * 1.0) / n);
    a = (float *)calloc(N, sizeof(float));
    for (i = 0; i < N; i++)
        scanf("%d", &a[i]);
    printf("enter key : ");
    scanf("%d", &key);

    pthread_t thread[n];

    for (int i = 0; i < n; i++) {
        pthread_create(&thread[i], NULL, ThreadSearch, (void *)NULL);
    }

    for (int i = 0; i < n; i++) {
        pthread_join(thread[i], NULL);
    }

    if (f == 1)
        printf("key found");
    else
        printf("key not found");
    return 0;
}
