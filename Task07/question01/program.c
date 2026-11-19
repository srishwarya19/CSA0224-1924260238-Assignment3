#include <stdio.h>

int main()
{
    int count[13] = {0};
    int candidate[12];
    int candidates, votes, valid = 0, invalid = 0;
    int i, j, temp, tie = 0;

    printf("Enter number of candidates: ");
    scanf("%d", &candidates);

    if (candidates < 1 || candidates > 12)
        return 1;

    printf("Enter number of votes: ");
    scanf("%d", &votes);

    if (votes < 0 || votes > 500000)
        return 1;

    printf("Enter votes:\n");

    for (i = 0; i < votes; i++) {
        int v;
        scanf("%d", &v);

        if (v >= 1 && v <= candidates) {
            count[v]++;
            valid++;
        }
        else {
            invalid++;
        }
    }

    for (i = 0; i < candidates; i++)
        candidate[i] = i + 1;

    for (i = 0; i < candidates - 1; i++) {
        for (j = 0; j < candidates - 1 - i; j++) {
            if (count[candidate[j]] <
                count[candidate[j + 1]]) {

                temp = candidate[j];
                candidate[j] = candidate[j + 1];
                candidate[j + 1] = temp;
            }
        }
    }

    printf("\nValid Votes: %d\n", valid);
    printf("Invalid Votes: %d\n", invalid);

    printf("\nVotes in Descending Order:\n");

    for (i = 0; i < candidates; i++) {
        printf("Candidate %d: %d votes\n",
               candidate[i], count[candidate[i]]);
    }

    for (i = 1; i < candidates; i++) {
        if (count[candidate[i]] == count[candidate[0]])
            tie = 1;
        else
            break;
    }

    if (tie)
        printf("Result: Tie\n");
    else
        printf("Winner: Candidate %d\n", candidate[0]);

    return 0;
}
