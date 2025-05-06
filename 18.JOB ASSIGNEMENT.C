#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

typedef struct Node {
    struct Node* parent;
    int pathCost;
    int cost;
    int workerID;
    int jobID;
    bool assigned[10];
} Node;

Node* createNode(int x, int y, bool assigned[], Node* parent, int n) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->workerID = x;
    node->jobID = y;
    node->parent = parent;
    node->pathCost = node->cost = 0;
    for (int i = 0; i < n; i++) node->assigned[i] = assigned[i];
    return node;
}

int calculateCost(int costMat[10][10], int x, int y, bool assigned[], int n) {
    int cost = 0, available[10] = {1};
    for (int i = x + 1; i < n; i++) {
        int min = INT_MAX, minIndex = -1;
        for (int j = 0; j < n; j++) {
            if (!assigned[j] && available[j] && costMat[i][j] < min) {
                min = costMat[i][j];
                minIndex = j;
            }
        }
        cost += min;
        available[minIndex] = 0;
    }
    return cost;
}

int findMinCost(int costMat[10][10], int n) {
    Node* pq[100];
    int pqSize = 0;
    bool assigned[10] = {0};
    pq[pqSize++] = createNode(-1, -1, assigned, NULL, n);

    while (pqSize) {
        Node* min = pq[--pqSize];
        int i = min->workerID + 1;
        if (i == n) return min->cost;
        for (int j = 0; j < n; j++) {
            if (!min->assigned[j]) {
                Node* child = createNode(i, j, min->assigned, min, n);
                child->assigned[j] = 1;
                child->pathCost = min->pathCost + costMat[i][j];
                child->cost = child->pathCost + calculateCost(costMat, i, j, child->assigned, n);
                pq[pqSize++] = child;
            }
        }
    }
    return -1;
}

int main() {
    int costMat[10][10] = {
        {9, 2, 7, 8},
        {6, 4, 3, 7},
        {5, 8, 1, 8},
        {7, 6, 9, 4}
    };
    printf("%d", findMinCost(costMat, 4));
    return 0;
}
