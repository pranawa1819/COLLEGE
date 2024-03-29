#include <stdio.h>

int main() {
    int n, m, i, j, k;
    n = 5; // Change the size to 5
    m = 4;
    int alloc[5][4] = {
        {0, 1, 1, 0},
        {1, 2, 3, 1},
        {1, 3, 6, 5},
        {0, 6, 3, 2},
        {0, 0, 1, 4}
    };
    int max[5][4] = {
        {0, 2, 1, 0},
        {1, 6, 5, 2},
        {2, 3, 6, 6},
        {0, 6, 5, 2},
        {0, 6, 5, 6}
    };
    int avail[4] = {1, 5, 2, 0};
    int f[n], ans[n], ind = 0;
    for (k = 0; k < n; k++)
        f[k] = 0;
    int need[n][m];
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    int y = 0;
    for (k = 0; k < 4; k++) {
        for (i = 0; i < n; i++) {
            if (f[i] == 0) {
                int flag = 0;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]) {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0) {
                    ans[ind++] = i;
                    for (y = 0; y < m; y++)
                        avail[y] += alloc[i][y];
                    f[i] = 1;
                }
            }
        }
    }
    int safe = 1;
    for (i = 0; i < n; i++) {
        if (f[i] == 0) {
            safe = 0;
            printf("The following system is not safe");
            break;
        }
    }
    if (safe == 1) {
        printf("Following is the SAFE Sequence\n");
        for (i = 0; i < n - 1; i++)
            printf("P%d ->", ans[i]);
        printf(" P%d", ans[n - 1]); // Corrected index
    }
    printf("\n");
    return 0;
}
