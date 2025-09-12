#include <stdio.h>
#include <stdlib.h>
int main(){
    int num;
    FILE *fptr;
    fptr = fopen("File_Handling/hi.txt","r");
    if(fptr == NULL){
        printf("Enter a Numberrr mann");
        exit(1);
    }
    
        fscanf(fptr,"%d",&num);
        printf("n = %d",num);
    fptr = fopen("File_Handling/hi.txt","w");
    fprintf(fptr,"%d",69);
    fclose(fptr);
    return 0;
}