#include <stdio.h> //Cert might not be able.
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 9
#define MAX_NAME_LENGTH 50

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s candidate1 candidate2 ... (up to %d candidates)\n", argv[0], MAX_CANDIDATES);
        return 1;
    }

    int num_candidates = argc - 1;
    if (num_candidates > MAX_CANDIDATES) {
        printf("Exceeded maximum number of candidates (%d)\n", MAX_CANDIDATES);
        return 1;
    }

    char **candidates = (char **)malloc(num_candidates * sizeof(char *));
    int *votes = (int *)malloc(num_candidates * sizeof(int));
    if (candidates == NULL || votes == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Copy candidate names and initialize votes to 0
    for (int i = 0; i < num_candidates; i++) {
        candidates[i] = (char *)malloc((strlen(argv[i + 1]) + 1) * sizeof(char));
        if (candidates[i] == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }
        strcpy(candidates[i], argv[i + 1]);
        votes[i] = 0;
    }

    int num_voters;
    printf("Number of voters: ");
    scanf("%d", &num_voters);

    if (num_voters <= 0) {
        printf("Invalid number of voters\n");
        return 1;
    }


    for (int i = 0; i < num_voters; i++) {
        printf("Vote: ");
        char candidate_name[MAX_NAME_LENGTH];
        scanf("%s", candidate_name);

        int found = 0;
        for (int j = 0; j < num_candidates; j++) {
            if (strcmp(candidate_name, candidates[j]) == 0) {
                votes[j]++;
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("Invalid candidate");
        }
    }

    // Find the candidate with the most votes
    int max_votes = 0;
    char *winner = NULL;
    for (int i = 0; i < num_candidates; i++) {
        if (votes[i] > max_votes) {
            max_votes = votes[i];
            winner = candidates[i];
        }
    }

    if (winner != NULL) {
        printf("%s\n", winner);
    } else {
        printf("No votes were cast\n");
    }

    // Free allocated memory
    for (int i = 0; i < num_candidates; i++) {
        free(candidates[i]);
    }
    free(candidates);
    free(votes);

    return 0;
}
