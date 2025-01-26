#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_NAMES 18
#define NAME_LENGTH 50
#define GROUP_A_SIZE 8
#define GROUP_B_SIZE 10

// the shuffling function
void shuffle(char names[][NAME_LENGTH], int n)
{
    for (int i = n - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);

        char temp[NAME_LENGTH];
        strcpy(temp, names[i]);
        strcpy(names[i], names[j]);
        strcpy(names[j], temp);
    }
}

int main()
{
    char groupA[GROUP_A_SIZE][NAME_LENGTH];
    char groupB[GROUP_B_SIZE][NAME_LENGTH];

    printf("Enter names for Group A (8 names):\n");
    for (int i = 0; i < GROUP_A_SIZE; i++)
    {
        printf("Group A Name %d: ", i + 1);
        fgets(groupA[i], NAME_LENGTH, stdin);
        groupA[i][strcspn(groupA[i], "\n")] = '\0';
    }

    printf("\nEnter names for Group B (10 names):\n");
    for (int i = 0; i < GROUP_B_SIZE; i++)
    {
        printf("Group B Name %d: ", i + 1);
        fgets(groupB[i], NAME_LENGTH, stdin);
        groupB[i][strcspn(groupB[i], "\n")] = '\0';
    }

    srand(time(NULL));

    shuffle(groupA, GROUP_A_SIZE);
    shuffle(groupB, GROUP_B_SIZE);

    printf("\nChore Assignments:\n");
    printf("Bin: %s\n", groupB[0]);
    printf("Tank: %s, %s\n", groupA[0], groupB[1]);
    printf("Front yard and backyard (gutters too): %s, %s, %s, %s\n", groupA[1], groupA[2], groupB[2], groupB[3]);
    printf("Toilet A: %s, %s, %s\n", groupA[3], groupA[4], groupA[5]);
    printf("Toilet B: %s, %s, %s, %s\n", groupB[4], groupB[5], groupB[6], groupB[7]);
    printf("Pallor: %s, %s, %s, %s\n", groupA[6], groupA[7], groupB[8], groupB[9]);

    return 0;
}