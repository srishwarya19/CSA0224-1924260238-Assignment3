#include <stdio.h>

int steps;

int linear_search(int a[], int n, int key)
{
    int i;
    steps = 0;

    for (i = 0; i < n; i++) {
        steps++;
        if (a[i] == key)
            return i;
    }
    return -1;
}

int binary_search(int a[], int n, int key)
{
    int low = 0, high = n - 1, mid;
    steps = 0;

    while (low <= high) {
        mid = low + (high - low) / 2;
        steps++;

        if (a[mid] == key)
            return mid;
        else if (a[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main()
{
    int a[] = {1021, 1048, 1103, 1190, 1222,
               1305, 1377, 1402, 1460, 1533};
    int keys[] = {1021, 1305, 1533, 1400};
    int i, pos;

    for (i = 0; i < 4; i++) {
        pos = binary_search(a, 10, keys[i]);
        printf("Book %d -> index %d, comparisons = %d\n",
               keys[i], pos, steps);
    }

    return 0;
}
