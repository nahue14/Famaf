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
    /* Imprime un mensaje de ayuda sobre como usar el programa */

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
    
    /*parse_filepath: esta funcion verifica si el programa fue llamado con la 
     * cantidad correcta de argumentos y extrae el archivo de entrada.
     *
     *  argc = Indica la cantidad de argumentos pasados al programa. El primer
     *  argumento es siempre el nombre del programa.
     *
     * *argv[] = Es un arreglo de punteros a char, donde cada posicion contiene
     * un argumento como cadena de caracteres. Ejemplo: argv[0] es el nombre del 
     * programa y argv[1] seria la ruta al archivo de entrada*/

    /*Se inicializa una variable de puntero a char en NULL osea que no apunta
     * a nada*/
    char *result = NULL;
    
    /*Esta variable verifica que en la linea de comandos haya solo dos cosas
     * el ./nombredelprograma y la ruta del archivo que voy a poner en la entrada*/
    bool valid_args_count = (argc == 2);

    /*Se pone un if para, en el caso de que si se llama al programa sin la ruta
     * del archivo me llame a la funcion que me imprime la ayuda para saber
     * como usar el programa y corta el programa en ese momento, en caso contrario
     * no entra al if y el programa sigue guardando en la variable puntero a char 
     * result la ruta del archivo, esto se hace para que la ruta del archivo no se 
     * pierda a medida que el programa se va ejecutando*/
    if (!valid_args_count){
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }

    result = argv[1];

    return result;
}

unsigned int array_from_file(int array[], unsigned int max_size, const char *filepath){
    /*usar man pages y fopen, fscanf, fclose*/
    

    FILE *file = fopen(filepath, "r");
	/*El fscanf, va leyendo el arreglo en este caso solo nos interesa imprimir
	 * el contenido del arreglo nomas*/
        unsigned int largodelarreglo;
        fscanf(file, "%u", &largodelarreglo);	

        for(unsigned int i = 0; i < max_size; i++){
            fscanf(file, "%d", &array[i]); /*Lee cada elemento del arreglo y lo guarda en
	    las posiciones del arreglo*/

	}
        
        fclose(file); /*Se cierra el archivo*/

    return largodelarreglo;
}

void array_dump(int a[], unsigned int length){
    
    for(unsigned int i = 0; i < length ; i++){
        printf("%d ",a[i]);
    }
}


int main(int argc, char *argv[]){
    
    /*Yo al ponerle argumentos al main, estoy diciendo que al programa hay que 
     * meterle si o si dos entradas, el nombre del programa y la ruta del archivo*/

    char *filepath = NULL; /* Se inicializa una variable puntero a char nula osea no 
			   apunta a ninguna direccion de memoria */
    
    /* Guarda en una variable de tipo puntero, la ruta del archivo de entrada */
    filepath = parse_filepath(argc, argv);
    
    /* Crea un arreglo de tamano MAX_SIZE, osea voy a tener un arreglo vacio de tamano
     * MAX_SIZE*/
    int array[MAX_SIZE];
    
    /* Se crea una variable de tipo int no signada osea que solo va a tener numeros 
     * positivos, donde se va a llamar a la funcion array_from_file, que come tres cosas
     * el arreglo vacio, el tamano del arreglo vacio y la direccion del archivo */

    unsigned int length = array_from_file(array, MAX_SIZE, filepath);
    
    /* dumping the array */
    /* volcando el arreglo */
    array_dump(array, length);
    
    return EXIT_SUCCESS;
}

/*Empieza la aventura*/
/*Primer intento de compilacion*/
