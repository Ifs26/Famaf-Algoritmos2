#include <stdio.h>
#include "weather_table.h"

unsigned int tempMin(WeatherTable table);

void maxTempAnos(WeatherTable table, int output[YEARS]);

void maxRainMes_Anos(WeatherTable table, unsigned int output[YEARS]);
/*
    Devuelve un arreglo con el mes (en int) que tuvo mas precipitaciones en cada año
*/