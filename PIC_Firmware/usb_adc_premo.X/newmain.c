/* 
 * File:   newmain.c
 * Author: tyrio
 *
 * Created on 7 de mayo de 2018, 19:54
 */
#include <main.h>

char c,d; 
int8 a = 0;


void main() {
   int16 adc_valor;
   float voltios;
   

	setup_adc_ports(AN0_TO_AN8);
	setup_adc(ADC_CLOCK_INTERNAL);

   output_high(PIN_C1);
   usb_cdc_init();
   usb_init(); //inicializamos el USB

      while (!usb_cdc_connected()) {}
         do{
               usb_task(); //usb_cdc_putc('/n');
               if(usb_enumerated()){
               /* PRUEBA, BORRAR A PARTIR DE AQUÍ
                     int i = 0;
                     set_adc_channel(0);
                     delay_us(20);
                     adc_valor = read_adc();
                     voltios = adc_valor/1;
                     printf(usb_cdc_putc, "Dato %d \f%3.2f \n",i, voltios);
                     */
                //HASTA AQUÍ
                
                 // /*
                  for(int i = 0; i<9; i++){
                     set_adc_channel(i);
                     delay_ms(2);
                     adc_valor = read_adc();
                     voltios = adc_valor/1;
                     voltios = voltios*3.3;
                     voltios = voltios/64;
                     voltios = voltios/1024;
                     //voltios = adc_valor/1;
                     printf(usb_cdc_putc, "Dato %d \f%3.3f \n ",i, voltios); 

                  }//*/
                  delay_ms(5000);
                  
               
               }

            }  while (TRUE);
    }


               /*
               if(usb_enumerated()) 
                  {

//**********************************************************************************************
                     if (usb_cdc_kbhit()) //Envia por Serial todo lo recibido por USB
                        { 
                           c = usb_cdc_getc();
                fprintf(PORT1,"%c",c);    
                        }
//************************************************************************************************
                     if (kbhit(PORT1)) //Envia por USB todo lo recibido por el Puerto 1
                        {
                           d=getc(PORT1);
                           usb_cdc_putc(d);
                        }
//**************************************************************************************************
                  }*/
