#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int A[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    
    int k;
    scanf("%d", &k);
    
    k = k % n; 
    
    int B[n];
    for (int i = 0; i < n; i++) {
        B[(i + k) % n] = A[i];
    }
    
    for (int i = 0; i < n; i++) {
        printf("%d ", B[i]);
    }
    
    return 0;
}

