#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>

/*----------------------------------------------------------------------*/
int main(void)
{
    char *name, *letter, *next_letter;

    /* Get a name from the user */
    do
    {
        name = GetString();
    } 
    while (strcmp(name, "") == 0);

    letter = name;

    /* The first character in the name is always an initial */
    putchar(toupper(*letter));

    for (letter = name; *letter != '\0'; letter++) 
    {
        /* Any character following a space is an initial */
        next_letter = letter + 1;

        if (*letter == ' ' && *next_letter != '\0') 
        {
            putchar(toupper(*next_letter));
        }
    }

    printf("\n");

    free(name);

    return 0;
}
