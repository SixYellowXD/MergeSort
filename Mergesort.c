#include <stdio.h>

#define MAX_SIZE 50

int bilangan[MAX_SIZE];

void merge(int kiri, int tengah, int kanan) {
    int h, i, j, b[MAX_SIZE], k;
    h = kiri;
    i = kiri;
    j = tengah + 1;

    while ((h <= tengah) && (j <= kanan)) {
        if (bilangan[h] <= bilangan[j]) {
            b[i] = bilangan[h];
            h++;
        } else {
            b[i] = bilangan[j];
            j++;
        }
        i++;
    }

    if (h > tengah) {
        for (k = j; k <= kanan; k++) {
            b[i] = bilangan[k];
            i++;
        }
    } else {
        for (k = h; k <= tengah; k++) {
            b[i] = bilangan[k];
            i++;
        }
    }

    for (k = kiri; k <= kanan; k++)
        bilangan[k] = b[k];
}

void merge_sort(int kiri, int kanan) {
    int tengah;
    if (kiri < kanan) {
        tengah = (kiri + kanan) / 2;
        merge_sort(kiri, tengah);
        merge_sort(tengah + 1, kanan);
        merge(kiri, tengah, kanan);
    }
}

int main() {
    int n, i;
    printf("Masukkan jumlah bilangan: ");
    scanf("%d", &n);

    printf("Masukkan bilangan:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &bilangan[i]);
    }

    merge_sort(0, n - 1);

    printf("Bilangan setelah diurutkan:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", bilangan[i]);
    }
    printf("\n");

    return 0;
}
