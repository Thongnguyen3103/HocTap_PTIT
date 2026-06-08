#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        int N, M;
        scanf("%d %d", &N, &M);

        int matrix[N][M];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                scanf("%d", &matrix[i][j]);
            }
        }

        printf("Test %d:\n", t);
        for (int i = 1; i < N; i++) {
            for (int j = 1; j < M; j++) {
                printf("%d ", matrix[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}

