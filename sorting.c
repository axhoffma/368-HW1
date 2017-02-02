#include "sorting.h"

long* Load_From_File(char* Filename, int* Size) {
    long* longAddress = NULL;
    FILE* fp;
    fp = fopen(Filename, "r"); 
    if(fp == NULL) {
        *Size = 0;
        fprintf(stderr, "There was an error while opening the read file\n");
        return longAddress;
    }
    //Get length of the file in bytes, return number of integers in array
    fseek(fp, 0, SEEK_END);
    int len = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    *Size =  len / sizeof(long);
    //Assign memory for array
    longAddress = malloc(sizeof(long) * *Size);
    //Read array into memory
    fread(longAddress, sizeof(long), *Size, fp);
    fclose(fp);
    return longAddress;
}
int Save_To_File(char* Filename, long* Array, int Size) {
    FILE* fp;
    fp = fopen(Filename, "w");
    if(fp == NULL) {
        Size = 0;
        fprintf(stderr, "There was an error while opening the save file\n");
        return 0;
    }
    int numSaved = 0;
    numSaved = fwrite(Array, sizeof(long), Size, fp);
    fclose(fp);
    return numSaved;
}
void Shell_Insertion_Sort(long* Array, int Size, double* N_Comp, double* N_Move) {
    for(int i = 1; i < Size; i++) {
        long x = Array[i];
        *N_Move++;
        int j = i - 1;
        while(j >= 0 && Array[j] > x) {
            *N_Comp++;
            Array[j+1] = Array[j];
            *N_Move++;
            j--;
        }
        Array[j+1] = x;
        *N_Move++;
    }
    return;
}
void Shell_Selection_Sort(long* Array, int Size, double* N_Comp, double* N_Move) {
    int min;
    int temp;
    for(int i = 0; i < Size - 1; i++) {
       min = i;
       for(int j = i+1; j < Size; j++) {
           if(Array[j] < Array[min]) {
               *N_Comp++;
               min = j;
           }
       }
       if(min != i) {
           temp = Array[i];
           Array[i] = Array[min];
           Array[min] = temp;
           *N_Move = *N_Move + 3;
       }
    }
    return;
}
/*int Print_Seq(char* Filename, int Size) {
    return //placeholder;
} */
