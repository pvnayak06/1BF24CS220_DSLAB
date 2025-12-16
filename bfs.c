

int a[20][20], q[20], visited[20], n, i, j, f = 0, r = -1;

void bfs(int v) {
    for (i = 0; i < n; i++) {
        if (a[v][i] && !visited[i]) {
            q[++r] = i;
            visited[i] = 1;
        }
    }
    if (f <= r) {
        printf("%d ", q[f]);
        bfs(q[f++]);
    }
}

int main() {
    int v;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        visited[i] = 0;
    } 

    printf("\nEnter graph data in matrix form:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nEnter the starting vertex: ");
    scanf("%d", &v);

    printf("\nThe node which are reachable are:\n");
    visited[v] = 1;
    printf("%d ", v);
    
    bfs(v);
    
    return 0;
}
