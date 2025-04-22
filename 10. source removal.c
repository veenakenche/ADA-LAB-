#include <stdio.h>

int a[10][10], n, t[10], indegree[10];
int stack[10], top = -1;

void computeIndegree(int n, int a[][10]);
void tps_SourceRemoval(int n, int a[][10]);

int main() {
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    computeIndegree(n, a);
    tps_SourceRemoval(n, a);

    printf("Topological Sort Order: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", t[i]);
    }
    printf("\n");

    return 0;
}


void computeIndegree(int n, int a[][10]) {
    for (int i = 0; i < n; i++) {
        indegree[i] = 0;
        for (int j = 0; j < n; j++) {
            indegree[i] += a[j][i];
        }
    }
}


void tps_SourceRemoval(int n, int a[][10]) {
    int k = 0;

    
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            stack[++top] = i;
        }
    }

    while (top != -1) {
        int v = stack[top--];
        t[k++] = v;

        for (int i = 0; i < n; i++) {
            if (a[v][i] != 0) {
                indegree[i]--;
                if (indegree[i] == 0) {
                    stack[++top] = i;
                }
            }
        }
    }

    if (k < n) {
        printf("\nCycle detected! Topological sort not possible.\n");
        exit(0);
    }
}
