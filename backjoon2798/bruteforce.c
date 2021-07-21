#include <stdio.h>

int main(void) {
    int N, M;

    scanf("%d", &N);
    scanf("%d", &M);
    int i, j, k;
    int sum = 0;
    int max = 0;
    int *num;

    num = (int*)malloc(N * sizeof(int));
    for (i = 0; i < N; i++) {
        scanf("%d", &num[i]);
    }

    for (i = 0; i < N - 2; i++) {
        for (j = i + 1; j < N - 1; j++) {
            for (k = j + 1; k < N; k++) {
                sum = num[i] + num[j] + num[k];
                if (sum <= M && sum > max)
                    max = sum;
            }
        }
    }


    printf("%d", max);
    return 0;
}