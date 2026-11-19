#include <stdio.h>

void bubble_sort(int a[], int n)
{
    int i, j, temp, flag;

    for (i = 0; i < n - 1; i++) {
        flag = 0;

        for (j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                flag = 1;
            }
        }

        if (flag == 0)
            break;
    }
}

void selection_sort(int a[], int n)
{
    int i, j, min, temp;

    for (i = 0; i < n - 1; i++) {
        min = i;

        for (j = i + 1; j < n; j++) {
            if (a[j] < a[min])
                min = j;
        }

        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}

void insertion_sort(int a[], int n)
{
    int i, j, key;

    for (i = 1; i < n; i++) {
        key = a[i];
        j = i - 1;

        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;
    }
}

void display(int a[], int n)
{
    int i;

    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");
}

int main()
{
    int a[] = {45, 12, 78, 23, 9, 56};
    int b[] = {45, 12, 78, 23, 9, 56};
    int c[] = {45, 12, 78, 23, 9, 56};

    bubble_sort(a, 6);
    printf("Bubble Sort: ");
    display(a, 6);

    selection_sort(b, 6);
    printf("Selection Sort: ");
    display(b, 6);

    insertion_sort(c, 6);
    printf("Insertion Sort: ");
    display(c, 6);

    return 0;
}
