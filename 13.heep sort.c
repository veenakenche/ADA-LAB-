#include <stdio.h>
#include <time.h>

void heapify(int a[], int n, int i) {
    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;
    int temp;

    if (left <= n && a[left] > a[largest])
        largest = left;

    if (right <= n && a[right] > a[largest])
        largest = right;

    if (largest != i) {
        temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;
        heapify(a, n, largest);
    }
}

void buildHeap(int a[], int n) {
    for (int i = n/2; i >= 1; i--)
        heapify(a, n, i);
}

void heapSort(int a[], int n) {
    int temp;
    buildHeap(a, n);
    for (int i = n; i >= 2; i--) {
        temp = a[1];
        a[1] = a[i];
        a[i] = temp;
        heapify(a, i - 1, 1);
    }
}

int main() {
    int a[20], n, i, ch = 1;
    clock_t start, end;
    double time_taken;

    while (ch) {
        printf("\nEnter the number of elements to sort: ");
        scanf("%d", &n);

        printf("Enter the elements to sort:\n");
        for (i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }

        start = clock();
        heapSort(a, n);
        end = clock();

        printf("The sorted list of elements is:\n");
        for (i = 1; i <= n; i++) {
            printf("%d ", a[i]);
        }

        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("\nTime taken: %lf seconds\n", time_taken);

        printf("Do you wish to run again? (1 for Yes / 0 for No): ");
        scanf("%d", &ch);
    }

    return 0;
}
