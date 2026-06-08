#include <stdio.h>
#include <string.h>

int countWords(char s[]) {
    int count = 0;
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        
        if (s[i] != ' ' && (i == 0 || s[i-1] == ' ')) {
            count++;
        }
    }
    return count;
}

int main() {
    int T;
    scanf("%d", &T);
    getchar();

    for (int t = 0; t < T; t++) {
        char s[201];
        fgets(s, sizeof(s), stdin);

        size_t len = strlen(s);
        if (len > 0 && s[len - 1] == '\n') {
            s[len - 1] = '\0';
        }

        int result = countWords(s);
        printf("%d\n", result);
    }

    return 0;
}

