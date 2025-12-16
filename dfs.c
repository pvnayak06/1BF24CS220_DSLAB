#include <stdio.h>

int a[20][20], visited[20], n, count = 0;

void dfs(int v) {
    int i;
    visited[v] = 1;
    count++;
    
    for (i = 0; i < n; i++) {
        if (a[v][i] == 1 && visited[i] == 0) {
            dfs(i);
        }
    }
}

int main() {
    int i, j;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("\nEnter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for (i = 0; i < n; i++)
        visited[i] = 0;

    dfs(0);

    if (count == n) {
        printf("\nThe graph is Connected.\n");
    } else {
        printf("\nThe graph is NOT Connected.\n");
    }

    return 0;
}