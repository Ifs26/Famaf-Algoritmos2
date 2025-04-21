/*
  @file main.c
  @brief Defines main program function
*/
// gcc -Wall -Wextra -pedantic -std=c99 -c weather_table.c weather.c main.c
// gcc -Wall -Wextra -pedantic -std=c99 weather_table.o weather.o main.o -o weather
// ./weather ../input/weather_cordoba.in > weather_cordoba.out

/* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/* Then, this project's includes, alphabetically ordered */
#include "weather_table.h"
#include "weather_utils.h"

/**
 * @brief print usage help
 * @param[in] program_name Executable name
 */
void print_help(char *program_name) {
    /* Print the usage help of this program. */
    printf("Usage: %s <input file path>\n\n"
           "Load climate data from a given file in disk.\n"
           "\n"
           "The input file must exist in disk and every line in it must have the following format:\n\n"
           "<year> <month> <day> <temperature> <high> <low> <pressure> <moisture> <precipitations>\n\n"
           "Those elements must be integers and will be copied into the multidimensional integer array 'a'.\n"
           "\n\n",
           program_name);
}

/**
 * @brief reads file path from command line
 *
 * @param[in] argc amount of command line arguments
 * @param[in] argv command line arguments
 *
 * @return An string containing read filepath
 */
char *parse_filepath(int argc, char *argv[]) {
    /* Parse the filepath given by command line argument. */
    char *result = NULL;

    if (argc < 2) {
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }

    result = argv[1];

    return (result);
}

void print_array(int a[],int largo){
    printf("[");
    for(int i=0;i<largo;++i){
        printf("%d, ",a[i]);
    }
    printf("]\n\n");
}
void print_array_uns(unsigned int a[],int largo){
    printf("[");
    for(int i=0;i<largo;++i){
        printf("%d, ",a[i]);
    }
    printf("]\n\n");
}


/**
 * @brief Main program function
 *
 * @param[in] argc amount of command line arguments
 * @param[in] argv command line arguments
 *
 * @return EXIT_SUCCESS when programs executes correctly, EXIT_FAILURE otherwise
 */
int main(int argc, char *argv[]) {
    char *filepath = NULL;

    /* parse the filepath given in command line arguments */
    filepath = parse_filepath(argc, argv);

    /* create a table variable */
    WeatherTable table;

    /* parse the file to fill the table */
    table_from_file(table, filepath);

    printf("Temp minima: %d\n",tempMin(table));

    int a[YEARS];
    maxTempAnos(table,a);
    print_array(a,37);

    
    unsigned int b[YEARS];
    maxRainMes_Anos(table,b);
    print_array_uns(b,YEARS);
    

    

    /* show the table in the screen */
    table_dump(table);

    return EXIT_SUCCESS;
}
