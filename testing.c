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
    fileName = "testWrite.b";
    int numSaved = Save_To_File(fileName, unsortedArray, Size);
    assert(numSaved == 15);
    //Test 3: Perform insertion sort
    double N_Comp;
    double N_Move;
    Shell_Insertion_Sort(unsortedArray, Size,  &N_Comp, &N_Move);
    fileName = "testInsertionSorted.b";
    numSaved = Save_To_File(fileName, unsortedArray, Size);
    assert(numSaved == 15);
    //Test 4: Perform selection Sort
    N_Comp = 0;
    N_Move = 0;
    unsortedArray = Load_From_File(fileName, &Size);
    Shell_Selection_Sort(unsortedArray, Size,  &N_Comp, &N_Move);
    fileName = "testSelectionSorted.b";
    numSaved = Save_To_File(fileName, unsortedArray, Size);
    assert(numSaved == 15);
    //Test 4: Generate and write the Sequence
    //Test 5: Perform selection sort
    //Test 6: Write Selection Sort to binary file
    free(unsortedArray);
    return EXIT_SUCCESS;
}
