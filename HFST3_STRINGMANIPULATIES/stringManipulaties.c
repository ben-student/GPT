#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int str_length(char *str)
{

    int length;
    for (length = 0; str[length] != '\0'; length++)
        ; // We iterate trough every character in
    // the string and  check if it is the same as '\0'. This specifiyc character means it is
    // at the end of the string. While iterating over the string variable length increments
    // by each character. So once it hits the char '\0' it has iterated over all the characters
    //  and counted the number of chars in the string.

    return length;
}

char *str_cat(char *str_left, char *str_right)
{

    int str_left_length = str_length(str_left);
    int str_right_length = str_length(str_right);

    // printf("first string length : %d\n",str_left_length);
    // printf("right string length : %d\n",str_right_length);

    int length = str_left_length + str_right_length + 1; // both stringlengts +1 for the '\0'

    char *concat = (char *)calloc(str_left_length + str_right_length + 1, sizeof(char));

    for (int i = 0; i < str_left_length; i++)
    {
        concat[i] = str_left[i];
    }
    for (int i = 0; i < str_right_length; i++)
    {
        concat[i + str_left_length] = str_right[i];
    }

    return concat;
}


char **str_split(char *str, char *token)
{

    int strlen = str_length(str);
    printf("This is our string that we want to split : ");
    for (int i = 0; i < strlen; i++)
    {
        printf("%c", *(str + i));
    }
    printf("\n");
    printf("this is the token %c\n", *token);

    int amountOfSplits = 0; // iterate over the whole string to find all possible split tokens in the string
    for (int i = 0; i < strlen; i++)
    {
        if (*(str + i) == *token)
        {
            amountOfSplits++;
        }
    } // increment amountOfSplits at each token found.

    char **splittedString = (char **)calloc(amountOfSplits, sizeof(char *));
    // create memory for the array to return at end of function
    // This will depend of the amountOfSplits because each splitted string will be stored in this array

    int totalArrayLength = 0;
    int splitAtPosition = 0;
    int counter = 0;
    while (totalArrayLength < strlen)
    {
        char *str_token = (char *)calloc(strlen, sizeof(char)); // create a buffer char to pass each character from the
                                                                //  original string to our return array
        splitAtPosition = 0;
        while (*(str + totalArrayLength) != *token && (totalArrayLength < strlen))
        {
            *(str_token + splitAtPosition) = *(str + totalArrayLength);
            totalArrayLength++;
            splitAtPosition++;
            // printf("counter :  %d, totalArralenght : %d, splitAtPosition : %d \n", counter, totalArrayLength, splitAtPosition);
        }
        *(str_token + splitAtPosition) = '\0';

        *(splittedString + counter) = str_token;
        counter++;
        totalArrayLength++;
    }

    return splittedString;
}
