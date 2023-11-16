#include "stringManipulaties.h"
#include <stdio.h>


int main( int argc, char** argv ) {
    
    // int length = str_length("ben");

    // printf("The length of the string is :  %d\n", length);

    // char* concatenatedString = str_cat("cat", "ben");

    // printf("%s\n", concatenatedString);

    char** stringSplit = str_split("gevorderde;programmeer;technieken",";");
    printf("returned split_string : %s\n",*(stringSplit));
    printf("returned split_string : %s\n",*(stringSplit+1));
    printf("returned split_string : %s\n",*(stringSplit+2));
    
    
    



    

    return 0;

}

