#include <stdio.h>
#include <string.h>

int main()
{
    char names[500][30], temp[30], key[30];
    int n, i, j, low, high, mid, found = 0;

    printf("Enter number of names: ");
    scanf("%d", &n);
    getchar();

    if (n < 1 || n > 500)
        return 1;

    for (i = 0; i < n; i++) {
        printf("Enter name %d: ", i + 1);
        fgets(names[i], 30, stdin);
        names[i][strcspn(names[i], "\n")] = '\0';
    }

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (strcmp(names[j], names[j + 1]) > 0) {
                strcpy(temp, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], temp);
            }
        }
    }

    printf("\nSorted Names:\n");

    for (i = 0; i < n; i++)
        printf("%s\n", names[i]);

    printf("\nDuplicate Names:\n");

    for (i = 1; i < n; i++) {
        if (strcmp(names[i], names[i - 1]) == 0)
            printf("%s\n", names[i]);
    }

    printf("\nEnter name to search: ");
    fgets(key, 30, stdin);
    key[strcspn(key, "\n")] = '\0';

    low = 0;
    high = n - 1;

    while (low <= high) {
        mid = low + (high - low) / 2;

        if (strcmp(names[mid], key) == 0) {
            found = 1;
            break;
        }
        else if (strcmp(names[mid], key) < 0)
            low = mid + 1;
        else
            high = mid - 1;
    }

    if (found)
        printf("Name Found at Index %d\n", mid);
    else
        printf("Name Not Found\n");

    return 0;
}
