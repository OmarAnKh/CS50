#include <cs50.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
const int HEADER_SIZE=44;

int main( int argc , char *argv[]){
if (argc!=4)
{
    printf("there is something wrong u entered");
}

FILE *input=fopen(argv[1],"r");
    if(input == NULL){
        printf("could'n open the file\n");
        return 1;
    }


FILE *output=fopen(argv[2],"r");
    if (output==NULL){
         printf("could'n open the file\n");
        return 1;
    }

float n=atof(argv[3]);
  uint8_t header[HEADER_SIZE];
 fread(&header,HEADER_SIZE,1,input);
 fwrite(&header,HEADER_SIZE,1,output);
int16_t buffer;
while (fread(&buffer,sizeof(int16_t),1,input))
{
    buffer *=n;
    fwrite(&buffer,sizeof(int16_t),1,output);
};
fclose(input);
fclose(output);