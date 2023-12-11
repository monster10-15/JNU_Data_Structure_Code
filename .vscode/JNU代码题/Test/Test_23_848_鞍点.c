void findSaddlePoints(int matrix[MAX][MAX], int m, int n) {
    for (int i = 0; i < m; i++) {
        int minRow = matrix[i][0], colIndex = 0;
        for (int j = 1; j < n; j++) {
            if (minRow > matrix[i][j]) {
                minRow = matrix[i][j];
                colIndex = j;
            }
        }
        int k;
        for (k = 0; k < m; k++)
            if (minRow < matrix[k][colIndex])
                break;
        if (k == m)
            printf("马鞍点是: %d\n", minRow);
    }
}
