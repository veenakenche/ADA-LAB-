#include <stdio.h>
#include <limits.h>
#include <string.h>

#define MAX_N 15

int n, cost[MAX_N][MAX_N], dp[1 << MAX_N][MAX_N];

int tsp(int mask, int pos) {
    if (mask == (1 << n) - 1) return cost[pos][0];
    if (dp[mask][pos] != -1) return dp[mask][pos];
    int ans = INT_MAX;
    for (int next = 0; next < n; next++)
        if (!(mask & (1 << next)))
            ans = ans < cost[pos][next] + tsp(mask | (1 << next), next) ? ans : cost[pos][next] + tsp(mask | (1 << next), next);
    return dp[mask][pos] = ans;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);
    memset(dp, -1, sizeof(dp));
    printf("%d\n", tsp(1, 0));
    return 0;
}
