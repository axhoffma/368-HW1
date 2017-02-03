#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "sorting.h"

int main(int argc, char* argv[]) {
    double N_Comp = 0;
    double N_Move = 0;
    clock_t ioStart;
    clock_t ioEnd;
    double ioTime;
    clock_t sortStart;
    clock_t sortEnd;
    double sortTime;

    int Size = 0;
    if(argc < 5) {
        fprintf(stderr, "Invalid input\n");
        return EXIT_FAILURE;
    }
    char sortMethod = *argv[1];
    char* inputFile = argv[2];
    char* sequenceOutput = argv[3];
    char* outputFile = argv[4];

    ioStart = clock();
    long* Array = Load_From_File(inputFile, &Size);
    ioEnd = clock();
    ioTime = (double) (ioEnd - ioStart) / CLOCKS_PER_SEC;
    
    if(sortMethod == 'i') {
        sortStart = clock();
        Shell_Insertion_Sort(Array, Size, &N_Comp, &N_Move);
        sortEnd = clock();
        sortTime = (double) (sortEnd - sortStart) / CLOCKS_PER_SEC;
    }
    else if(sortMethod == 's') {
        sortStart = clock();
        Shell_Selection_Sort(Array, Size, &N_Comp, &N_Move);
        sortEnd = clock();
        sortTime = (double) (sortEnd - sortStart) / CLOCKS_PER_SEC;
    }
    else {
        fprintf(stderr, "Not proper sort indication\n");
        return EXIT_FAILURE;
    }
    int sequence = Print_Seq(sequenceOutput, Size);
    Save_To_File(outputFile, Array, Size);
    printf("Number of long integers read: %d\n", Size);
    printf("Number of long integers stored: %d\n", Size);
    printf("Length of sequence: %d\n", sequence);
    printf("Number of comparisons: %le\n", N_Comp);
    printf("Number of Moves: %le\n", N_Move);
    printf("I/O time: %le\n", ioTime);
    printf("Sorting time: %le\n", sortTime);
    return EXIT_SUCCESS;
}
