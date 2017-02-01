#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "sorting.h"

int main(int argc, char* argv[]) {
    //Test 1: Successfully open the binary file
    char* fileName = "15.b";
    int Size; 
    long* unsortedArray = Load_From_File(fileName, &Size);
    assert(unsortedArray != NULL);
    assert(Size == 15);
    //Test 2: Successfully write the binary file
    //Test 3: Generate and write the Sequence
    //Test 4: Perform insertion sort on a worst case list
    //Test 5: Perform selection sort
    //Test 6: Write Selection Sort to binary file
    free(unsortedArray);
    return EXIT_SUCCESS;
}
