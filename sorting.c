#include "sorting.h"

long* Load_From_File(char* Filename, int* Size) {
    FILE* fp;
    fp = fopen(Filename, "r"); 
    long* longAddress = NULL;
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
    int numSaved = 0;
    numSaved = fwrite(Array, sizeof(long), Size, fp);
    fclose(fp);
    return numSaved;
}
void Shell_Insertion_Sort(long* Array, int Size, double* N_Comp, double* N_Move) {
    for(int i = 1; i < Size; i++) {
        long x = Array[i];
        int j = i - 1;
        while(j >= 0 && Array[j] > x) {
            Array[j+1] = Array[j];
            j--;
        }
        Array[j+1] = x;
    }
    return;
}
/*void Shell_Selection_Sort(long* Array, int Size, double* N_Comp, double* N_Move) {
    return;
}
int Print_Seq(char* Filename, int Size) {
    return //placeholder;
} */
