#include <stdio.h>

int subset[100], n, target;

void sumOfSubsets(int set[], int i, int currentSum, int totalRemaining) {
    if (currentSum == target) {
        // Print subset
        printf("{ ");
        for (int j = 0; j < i; j++) {
            if (subset[j])
                printf("%d ", set[j]);
        }
        printf("}\n");
        return;
    }

    if (i == n || currentSum > target)
        return;

    // Include element
    subset[i] = 1;
    sumOfSubsets(set, i + 1, currentSum + set[i], totalRemaining - set[i]);

    // Exclude element
    subset[i] = 0;
    sumOfSubsets(set, i + 1, currentSum, totalRemaining - set[i]);
}

int main() {
    int set[100], total = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &set[i]);
        total += set[i];
    }

    printf("Enter target sum: ");
    scanf("%d", &target);

    sumOfSubsets(set, 0, 0, total);

    return 0;
}