#include "datastruct.h"
#include <stdio.h>


int main( int argc, char** argv ) {
    

    List myList;
    myList = CreateList();
    if (myList == NULL) {
        fprintf(stderr, "Failed to create a list. Exiting...\n");
    }
    printList(myList);
    // Insert an element (e.g., the value 42) into the list
    Insert(42, myList);

   



    // Other code here




    return 0;

}
