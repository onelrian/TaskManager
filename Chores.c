#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_NAMES 18
#define NAME_LENGTH 50

// the shuffling function

void shuffle(char names[NUM_NAMES][NAME_LENGTH], int n)
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
    char names[NUM_NAMES][NAME_LENGTH];

    printf("Enter 18 names:\n");
    for (int i = 0; i < NUM_NAMES; i++)
    {
        printf("Name %d: ", i + 1);
        fgets(names[i], NAME_LENGTH, stdin);
        // remove the newline character from fgets
        names[i][strcspn(names[i], "\n")] = '\0';
    }

    srand(time(NULL));

    shuffle(names, NUM_NAMES);
    shuffle(names, NUM_NAMES);

    printf("\nChore Assignments:\n");
    printf("Bin: %s\n", names[0]);
    printf("Tank: %s, %s\n", names[1], names[2]);
    printf("Front yard and backyard (gutters too): %s, %s, %s, %s\n", names[3], names[4], names[5], names[6]);
    printf("Toilets and corridor: %s, %s, %s, %s, %s, %s\n", names[7], names[8], names[9], names[10], names[11], names[12]);
    printf("Pallor: %s, %s, %s, %s, %s\n", names[13], names[14], names[15], names[16], names[17]);

    return 0;
}