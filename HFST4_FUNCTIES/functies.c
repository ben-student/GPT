#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>


void foperation(char *function, double *numbers, int length)
{
    double solution = 0;
    if (!strcmp(function, "SUM"))
    {
        for (int i = 0; i < length; i++)
        {
            solution += numbers[i];
        }
        printf("%.2lf\n", solution);
    }
    else if (!strcmp(function, "SUBTRACTION"))
    {
        solution = numbers[0];
        for (int i = 1; i < length; i++)
        {
            solution -= numbers[i];
        }
        printf("%.2lf\n", solution);
    }
    else if (!strcmp(function, "DIVISION"))
    {
        solution = numbers[0];
        for (int i = 1; i < length; i++)
        {
            solution = solution / numbers[i];
        }
        printf("%lf.2\n", solution);
    }
    else if (!strcmp(function, "MULTIPLICATION"))
    {
        solution = numbers[0];
        for (int i = 1; i < length; i++)
        {
            solution = solution / numbers[i];
        }
        printf("%lf.2\n", solution);
    }
    else
    {
        printf("Someting went wrong!");
    }
}

void specialPrint(char *formatString, ...)
{
    va_list args;
    va_start(args, formatString);

    while (*formatString != '\0')
    {
        if (*formatString == '%')
        {
            // printf("formatString before : %s", formatString);
            ++formatString;
            // printf("formatString after : %s", formatString);

            if (*formatString == 'd')
            {
                int i = va_arg(args, int);
                printf("\033[32m%d\033[0m", i);
            }
            else if (*formatString == 's')
            {
                char *s = va_arg(args, char *);
                printf("\033[31m%s\033[0m", s);
            }

            // switch(*formatString){
            //     case 'd':
            //         printf(*formatString);
            //         // int i = va_arg(args, int);
            //         // printf("\033[31m%d\033[0m",i);
            //         break;
            //     case 's':
            //         printf(*formatString);
            //         // char* s = va_arg(args, char*);
            //         // printf("\033[34m%s\033[0m",s);
            //         break;
            // }
        }
        else
        {
            printf("%c", *formatString);
        }
        formatString++;
    }
    va_end(args);
}



int str_length(char* str){

    int length;
    for(length = 0; str[length] != '\0'; length++); //We iterate trough every character in 
    //the string and  check if it is the same as '\0'. This specifiyc character means it is 
    //at the end of the string. While iterating over the string variable length increments 
    //by each character. So once it hits the char '\0' it has iterated over all the characters
    // and counted the number of chars in the string.
    
    return length;
}






char **str_split(char *str, char *token)
{

    int strlen = str_length(str);
    // printf("This is our string that we want to split : ");
    for (int i = 0; i < strlen; i++)
    {
        printf("%c", *(str + i));
    }
    // printf("\n");
    // printf("this is the token %c\n", *token);

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
        }
        *(str_token + splitAtPosition) = '\0';

        *(splittedString + counter) = str_token;
        counter++;
        totalArrayLength++;
    }

    return splittedString;
}

void consoleInput(int buffer)
{
    char text[buffer]; // make an array of buffer characters
    int counter = 0;
    printf("Enter text. Use enter to exit\n");
    do
    {
        text[counter] = getchar();
        counter++;

    } while ((text[counter] != '\n') && (counter < buffer));
    printf("%s\n", text);
};

void readConfigFile(char *path)
{

    int c;
    FILE *fp;

    fp = fopen(path, "r");

    if (fp)
    {
        char txt[128];
        while (fgets(txt, sizeof(txt), fp) != NULL)
        {

            char **mainSplit = str_split(txt, "=");
            char *operator= mainSplit[0];
            printf("%s\n", operator);

            printf("rest of string %s\n", mainSplit[1]);

            int numberOfValues = 0;

            for (int i = 0; i < str_length(mainSplit[1]); i++)
            {
                if (mainSplit[1][i] == ':')
                {
                    numberOfValues++;
                }
                // we need to know how many numbers are in the equation, by iterating to the rest of the string and looking for the
                //  ":" operand we know how much value's we are dealing with.
            }

            printf("numberOfValues %d\n", numberOfValues);

            // double** numbers = calloc(numberOfValues,sizeof(double)); //make memory for the numbers that we will assing later to this variable
            double *numbers = (double *)calloc(numberOfValues, sizeof(double));

            char **secondSplit = str_split(mainSplit[1], ","); 
            // split the rest of the string of the first split at position
            //',' to seperate all values from each other

            for (int i = 0; i < numberOfValues; i++)
            { // iterate over the splitted numbers still holding the VALUE keyword. This function
              //  will sepearte the actual numbers and convert to floats while storing it in our
              // allocated memory "numbers"
                printf("Values : %s\n", secondSplit[i]);
                char **numberSplit = str_split(secondSplit[i], ":");
                numbers[i] = atof(numberSplit[1]); // atoi converts a variable to a float
            }

            for (int i = 0; i < numberOfValues; i++)
            {
                printf("numbers  : %.2lf\n", numbers[i]);
            }
            printf("calculated result : ");
            foperation(operator,numbers,numberOfValues);


            printf("END \n");
            printf("\n");
            printf("\n");
        }
        fclose(fp);
    }
};