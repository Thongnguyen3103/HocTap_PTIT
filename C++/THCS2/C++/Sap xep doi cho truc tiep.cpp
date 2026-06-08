#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int a[105];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int step = 1;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[i]) {
                // Ð?i ch?
                int tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
        
        printf("Buoc %d:", step++);
        for (int k = 0; k < n; k++) {
            printf(" %d", a[k]);
        }
        printf("\n");
    }

    return 0;
}

