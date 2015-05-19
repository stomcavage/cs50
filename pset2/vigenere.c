#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*----------------------------------------------------------------------*/
int argIsValid(char *arg)
{
    char *i;

    for (i = arg; *i; i++)
    {
        if (!isalpha(*i))
        {
            break;
        }
    }

    /* Pointer will be at the end of the string if all chars were valid */
    return *i == '\0';
}

/*----------------------------------------------------------------------*/
char *getMessage(void)
{
    char *message;

    /* Get the message to convert from the user */
    do
    {
        message = GetString();
    }
    while (strcmp(message, "\0") == 0);

    return message;
}

/*----------------------------------------------------------------------*/
void printCipher(char *message, char *keyword)
{
    char *i, *j;
    char offset;

    for (i = message, j = keyword; *i; i++) 
    {
        /* Offset case might not match message case */
        offset = islower(*j) ? *j - 'a' : *j - 'A';

        /* Convert the letter using current char in the keyword as offset */
        if (islower(*i))
        {
            *i = ((*i - 'a' + offset) % 26) + 'a'; 
            j++;
        }
        else if (isupper(*i))
        {
            *i = ((*i - 'A' + offset) % 26) + 'A'; 
            j++;
        }

        /* If we've reached the end of the keyword, cycle around */
        if (!(*j))
        {
            j = keyword;
        }

        putchar(*i);
    }

    printf("\n");
}

/*----------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
    char *keyword, *message;

    if (argc == 2 && argIsValid(argv[1]))
    {
        keyword = argv[1];
        message = getMessage();
        printCipher(message, keyword);
        free(message);
        return 0;
    }
    else
    {
        printf("Usage: %s <keyword>\n", argv[0]);
        return 1;
    }
}

