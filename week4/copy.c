#include <stdio.h>
#include <string.h>
#include<cs50.h>
#include <stdlib.h>
#include<ctype.h>
int main(void){
    char *s=get_string("s: ");
    char *t=malloc(strlen(s)+1);
    if (t==NULL){
        return 1;
    }
    strcpy(t,s);

    if (strlen(s)>0){

    t[0]=toupper(t[0]);

    }
else {
    return 1;
}

    printf("s: %s\n",s);
    printf("s: %s\n",t);
    free(t);
}