#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*----------------------------------------------------------------------*/
int getOffset(char *arg)
{
    int offset = 0;

    /* Get offset from user, and handle case where offset exceeds 26 */
    offset = atoi(arg);
    
    return (offset % 26);
}

/*----------------------------------------------------------------------*/
char *getMessage(void)
{
    char *message;

    /* Get message to encode from the user */
    do
    {
        message = GetString();
    }
    while (strcmp(message, "\0") == 0);

    return message;
}

/*----------------------------------------------------------------------*/
void printCipher(char *message, int offset)
{
    char *letter;

    for (letter = message; *letter; letter++) 
    {
        /* Find letter that's offset places after the current letter */
        if (islower(*letter)) 
        {
            *letter = (((*letter - 'a') + offset) % 26) + 'a'; 
        }
        else if (isupper(*letter)) 
        {
            *letter = (((*letter - 'A') + offset) % 26) + 'A'; 
        }

        putchar(*letter);
    }

    printf("\n");
}

/*----------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
    int offset;
    char *message;

    if (argc == 2)
    {
        offset = getOffset(argv[1]);
        message = getMessage();
        printCipher(message, offset);
        free(message);
        return 0;
    }
    else
    {
        printf("Usage: %s offset\n", argv[0]);
        return 1;
    }
}

