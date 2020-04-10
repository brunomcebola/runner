#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGHT 128

void help(char filename[])
{
    printf("Utilização correta:\n");
    printf("./program [ficheiro.c] [nome do executavel]\n");
}

int main(int argc, char *argv[])
{
    char compile[MAX_LENGHT] = "gcc -Wall -std=c99 -O3 -Wno-unused-result -o ";
    char run[MAX_LENGHT] = "./";
    int return_value;

    if (argc != 3)
    {
        printf("ERRO\n");
        help(argv[0]);
        exit(1);
    }

    strcat(compile, argv[2]); //adicionar o target name
    strcat(compile, " "); // adicionar um espaço
    strcat(compile, argv[1]); //adicionar o .c

    printf("%s\n", compile);

    return_value = system(compile); //compilar

    if ( return_value != 0)
    {
        printf("Your program has errors!! GO FIX IT!!!\n");
        return 1;
    } else
    {
        printf("Successfully compiled!!! Running it! :)\n\n");
        strcat(run, argv[2]);
        system(run);
    }

    return 0;
}
