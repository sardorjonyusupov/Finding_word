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

    char word[10];
    int count = 0;

    while (fgets(word, 10, file) != NULL)
    {
        count++;
    }

    rewind(file);

    int random_index = rand() % count;

    for (int i = 0; i <= random_index; i++)
    {
        fgets(word, 10, file);
    }

    printf("%s", word);

    int n = strlen(word);

    if (word[n - 1] == '\n')
    {
        word[n - 1] = '\0';
    }

    n = strlen(word);

    char word_copy[n];

    printf("Yashirin so'z: ");

    for (int i = 0; i < n; i++)
    {
        word_copy[i] = '_';
        printf("%c ", word_copy[i]);
    }

    printf("\n");

    int ochilgan = n;

    for (int j = 0; j < n + 2; j++)
    {
        char harf;

        printf("Urinishlar %d\nHarf kiriting: ", j + 1);
        scanf(" %c", &harf);

        for (int k = 0; k < n; k++)
        {
            if (word[k] == harf)
            {
                if (word_copy[k] == '_')
                {
                    ochilgan--;
                    word_copy[k] = harf;
                }
            }
        }

        printf("\nYashirin so'z: ");

        for (int i = 0; i < n; i++)
        {
            printf("%c ", word_copy[i]);
        }

        printf("\n");

        if (ochilgan == 0)
        {
            printf("Yutdingiz.");
            return 0;
        }
    }

    printf("Yutqazdingiz. Yana urib ko'ring");

    return 0;
}

