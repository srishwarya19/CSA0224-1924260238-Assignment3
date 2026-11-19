#include <stdio.h>

int merge(int a[], int na, int b[], int nb, int out[])
{
    int i = 0, j = 0, k = 0;

    while (i < na && j < nb) {
        if (a[i] >= b[j])
            out[k++] = a[i++];
        else
            out[k++] = b[j++];
    }

    while (i < na)
        out[k++] = a[i++];

    while (j < nb)
        out[k++] = b[j++];

    return k;
}

int main()
{
    int a[] = {98, 91, 85, 72};
    int b[] = {95, 91, 80};
    int out[7], n, i;

    n = merge(a, 4, b, 3, out);

    for (i = 0; i < n; i++)
        printf("%d ", out[i]);

    return 0;
}
