#include <stdio.h>
#include <stdlib.h>

void main(){
    
    //Create File
    char * path = "genesis.txt";
    char * newPath = "genesis_reverse.txt";
    FILE * inputStream, * outputStream, * stream;
    int length;
    inputStream = fopen(path, "r");
    outputStream = fopen(newPath, "w");

    //Find length of path
    stream = fopen(path, "r");
    fseek(stream, 0, SEEK_END);
    length = ftell(stream);
    fclose(stream);

    //Copy over contents of path to array;
    char * buffer;
    buffer = malloc(length);

    char * str[length]=inputStream;
    int x=length;
    if (fread(buffer, length, 1, inputStream) > 0){
        fwrite(str, length-1, 1, outputStream);
    }
    
    
    
    fclose(inputStream);
    fclose(outputStream);
    free(buffer);    
}