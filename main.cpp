/**
 * @file main.cpp
 * @brief This is a brief description of the file.
 * 
 * This is a more detailed description of the file that can include
 * additional information, such as the purpose of the file or the author.
 */

#include "mbed.h"
#include "arm_book_lib.h"

int main()
{
    
    /*! 
     * @brief Declaracion de puertos 
     *
     * Se crean los objetos correspondientes para declararlos como de entrada/salida
     *  y se configura su la resistencia de PullDown
     */
    DigitalIn gasDetector(D4); //DigitalIn es una clase que sobrecarga el constructor para admitir como parametros "pin" o "pin" y "mode"
                                //Ademas tiene metodos de read() que devuelve 1 o 0 segun el estado del pin
                                // tambien el metodo mode() que permite setear la resistencia de pull up o pull down none o open drain
                                //Ademas sobreescribe el operador de casteo int para que al igualar una variable int con el objeto devuelva el 
                                // valor del pin
    DigitalOut alarmLed(LED1); // Idem al DigitalOut pero solo tiene metodo read() and write() y tambien sobreescribe el operador ==

    gasDetector.mode(PullDown);


    alarmLed = OFF;

    /*! 
     * @brief Test function
     *
     * This function prints "Iniciando" to the console.
     */
    printf("%s\n","Iniciando");

    while (true) {
        if ( gasDetector == ON ) {
            alarmLed = ON;
            printf("%s\n","Se detecto gas...\n alarma encendida!");
        }
        
        if ( gasDetector == OFF ) {
            alarmLed = OFF;
            printf("%s\n","No se detecto gas...\n alarma apagada :)");
        }
    }
}
