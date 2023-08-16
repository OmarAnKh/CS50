#include<cs50.h>
#include<stdio.h>
#include<string.h>

int main(void) {
    string names[]={"omar","moe","ruba","anan","obada","amjad","nour"};
    for (int i = 0; i<7;++i){
        if (strcmp(names[i],"omars")==0){
            printf("found\n");
            return EXIT_SUCCESS;
        }

    }

    printf("not found %d", EXIT_FAILURE);

    return EXIT_FAILURE;
}
