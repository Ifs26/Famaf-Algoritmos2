#include <stdio.h>
#include "weather_table.h"
#include <assert.h>

//Voy a utilizar un puntero para ver cada posicion?
int tempMin(WeatherTable table){
    int res = table[0u][january][1]._min_temp;
    for (unsigned int year=0u;year < YEARS;++year){
        for(month_t month=january;month<=december;++month){
            for(unsigned int day = 0; day < DAYS;++day){
                if(table[year][month][day]._min_temp<res){
                    res = table[year][month][day]._min_temp;
                }
            } 
        }
    }
    
    return res;
}

void maxTempAnos(WeatherTable table, int output[YEARS]){
    for(unsigned int year=0u;year<YEARS;++year){
        output[year]=table[year][january][0]._max_temp;
        for(month_t month=january;month<=december;++month){
            for(unsigned int day=0;day<DAYS;++day){
                if(table[year][month][day]._max_temp > output[year]){
                    output[year] = table[year][month][day]._max_temp;
                }
            }
        }
    }
}

void maxRainMes_Anos(WeatherTable table, unsigned int output[YEARS]){
    for(unsigned int year=0u;year<YEARS;++year){ //Cada año
        output[year] = 0u;
        month_t mes = january;

        for(month_t month=january;month<=december;++month){ //Cada mes
            unsigned int lluvia_mensual = 0;
            for(unsigned int day=0;day<DAYS;++day){ //Cada dia
                lluvia_mensual = lluvia_mensual+ table[year][month][day]._rainfall;
            }
            if(output[year]<lluvia_mensual){
                output[year] = lluvia_mensual;
                mes = month;
            }
        }

        output[year] = 0u;
        for(month_t month_aux=january;month_aux<=mes;++month_aux){
            output[year]= output[year]+1;
        }
    }
}

