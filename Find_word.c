#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{
    srand(time(0));

    FILE *file = fopen("notes.txt", "r");

    if (file == NULL)
    {
        printf("This couldn't be opened.");
        return 1;
    }

    char word[20];
    int count = 0;

    while (fgets(word, 20, file) != NULL)
    {
        count++;
    }

    rewind(file);

    int random_index = rand() % count;

    for (int i = 0; i <= random_index; i++)
    {
        fgets(word, 20, file);
    }

    printf("%s", word);

    int n = strlen(word);

    if (word[n - 1] == '\n')
    {
        word[n - 1] = '\0';
    }

    n = strlen(word);

    char word_copy[n];

    printf("Hidden word: ");

    for (int i = 0; i < n; i++)
    {
        word_copy[i] = '_';
        printf("%c ", word_copy[i]);
    }

    printf("\n");

    int opened = n;

    for (int j = 0; j < n + 2; j++)
    {
        char letter;

        printf("Attempts %d\nEnter a letter: ", j + 1);
        scanf(" %c", &letter);

        for (int k = 0; k < n; k++)
        {
            if (word[k] == letter)
            {
                if (word_copy[k] == '_')
                {
                    opened--;
                    word_copy[k] = letter;
                }
            }
        }

        printf("\nHidden word: ");

        for (int i = 0; i < n; i++)
        {
            printf("%c ", word_copy[i]);
        }

        printf("\n");

        if (opened == 0)
        {
            printf("You won!");
            return 0;
        }
    }

    printf("You lost. Try again!");

    return 0;
}