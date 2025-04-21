/*
  @file weather_table.c
  @brief Weather table implementation
*/
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "weather_table.h"

/**
 * @brief Write the content of the table 'a' into stdout.
 * @param[in] a table to dump in stdout
 */
void table_dump(WeatherTable a) {
    for (unsigned int year = 0u; year < YEARS; ++year) {
        for (month_t month = january; month <= december; ++month) {
            for (unsigned int day = 0u; day < DAYS; ++day) {
                // imprimir año, mes y día
                fprintf(stdout, "%u %u %u ", year + FST_YEAR, month + 1, day + 1);

                // imprimir datos para ese día
                weather_to_file(stdout, a[year][month][day]);

                // imprimir salto de línea
                fprintf(stdout, "\n");
            }
        }
    }
}

/**
 * @brief reads a table of weather information from file
 * @details
 *
 *  Each element is read from the file located at 'filepath'.
 *  The file must exist in disk and must have its contents in a sequence of
 *  lines, each with the following format:
 *
 *   <year> <month> <day> <temperature> <high> <low> <pressure> <moisture> <precipitations>
 *
 *   Those elements are copied into the multidimensional table 'a'.
 *
 * @param a table which will contain read file
 * @param filepath file with weather data
 */
void table_from_file(WeatherTable a, const char *filepath) {
    FILE *file = NULL;

    file = fopen(filepath, "r"); //Se abre el archivo
    if (file == NULL) {
        fprintf(stderr, "File does not exist.\n");
        exit(EXIT_FAILURE);
    }

    unsigned int k_year = 0u;
    unsigned int k_month = 0u;
    unsigned int k_day = 0u;

    //Este bucle va leyendo cada linea!
    while (!feof(file)) { //La guarda verifica que no s haya llegado al final del archivo
        
        /*Lee la primera fecha*/
        //fscan es lo que itera a la siguiente linea, hay un puntero interno!
        int res = fscanf(file, " %u %u %u ", &k_year, &k_month, &k_day);
        if (res != 3) {
            fprintf(stderr, "Invalid table.\n");
            exit(EXIT_FAILURE);
        }
        /*
        // Ir a la función 'weather_from_file' en weather.c y completar!
        Weather weather = weather_from_file(file);


        ¡Si ya weather contiene todo y 
        a es un arreglo muldimencional de Weather por dios!
         |
         V
        a[k_year][k_month][k_day]._average_temp = weather._average_temp;
        a[k_year][k_month][k_day]._max_temp = weather._max_temp;
        a[k_year][k_month][k_day]._min_temp = weather._min_temp;
        a[k_year][k_month][k_day]._moisture = weather._moisture;
        a[k_year][k_month][k_day]._pressure = weather._pressure;
        a[k_year][k_month][k_day]._rainfall = weather._rainfall;
        */
        
        //Filtro de errores
        if (k_year < FST_YEAR || k_year > LST_YEAR || k_month < 1 || k_month > MONTHS || 
            k_day < 1 || k_day > DAYS) {
            fprintf(stderr, "fecha invalida! %u/%u/%u \n", k_year, k_month, k_day);
            exit(EXIT_FAILURE);
        }

        /*¡Si al usar 2 scanf los elementos a chequear no se cruzan entonces
        el puntero avanza solo una vez!*/
        Weather weather = weather_from_file(file);

        /*
        => Recordar que a[YEARS=37][MONTHS=12][DAY=28]
            => Osea que si dejaba solo k_year la ubicacion se salia siempre 
            y nunca se guardaba
        */
        a[k_year-FST_YEAR][k_month-1][k_day-1] = weather;

    }

    fclose(file); //se cierra el archivo
}
