/* First, the standard lib includes, alphabetically ordered */
/* Primero, incluimos las librerias estandard ordenadas alfabéticamente */
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/* Maximum allowed length of the array */
/* Longitud máxima permitida del arreglo */

#define MAX_SIZE 100000

void print_help(char *program_name){

    /* Print the usage help of this program. */
    /* Imprime la ayuda para usar este programa. */

    printf("Usage: %s <input file path>\n\n"
           "Loads an array given in a file in disk and prints it on the screen."
           "\n\n"
           "The input file must have the following format:\n"
           " * The first line must contain only a positive integer,"
           " which is the length of the array.\n"
           " * The second line must contain the members of the array"
           " separated by one or more spaces. Each member must be an integer."
           "\n\n"
           "In other words, the file format is:\n"
           "<amount of array elements>\n"
           "<array elem 1> <array elem 2> ... <array elem N>\n\n",
           program_name);
}

char *parse_filepath(int argc, char *argv[]){
    
    /* Parse the filepath given by command line argument. */
    /* Imprime la ayuda para usar este programa. */

    char *result = NULL;

    // Program takes exactly two arguments
    // El programa toma exactamente dos argumentos
    
    // (the program's name itself and the input-filepath)
    // (el nombre del programa en sí y la ruta del archivo de entrada)
    bool valid_args_count = (argc == 2);

    if (!valid_args_count){
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }

    result = argv[1];

    return result;
}

unsigned int array_from_file(int array[], unsigned int max_size, const char *filepath){
    //your code here!!!
}

void array_dump(int a[], unsigned int length){
    //your code here!!!
}


int main(int argc, char *argv[]){
    
    /*argc: es la cantidad de argumentos que va a tener el programa, el argumento 0 es 
     * el nombre del programa ./"nombre del programa" lo que ponga despues del nombre del
     * programa van a ser los argumentos siguientes
     * argv se va a guardar la cadena de strings en la posicion correspondiente*/

    char *filepath = NULL; /* Se inicializa una variable puntero nula osea no apunta
    a ninguna direccion de memoria */

    /* parse the filepath given in command line arguments */
    /* analiza la ruta del archivo proporcionada en los argumentos de la línea de comando */

    /* Guarda en una variable de tipo puntero, los argumentos sin el nombre del programa */
    filepath = parse_filepath(argc, argv);
    
    /* create an array of MAX_SIZE elements */
    /* crea un arreglo de tamano MAX_SIZE */
    int array[MAX_SIZE];
    
    /* parse the file to fill the array and obtain the actual length */
    /* analiza el archivo para llenar el arreglo y obtener la longitud real */
    
    /* una variable de tipo int no signada osea que solo va a tener numeros positivos */

    unsigned int length = array_from_file(array, MAX_SIZE, filepath);
    
    /* dumping the array */
    /* volcando el arreglo */
    array_dump(array, length);
    
    return EXIT_SUCCESS;
}

/*Empieza la aventura*/
