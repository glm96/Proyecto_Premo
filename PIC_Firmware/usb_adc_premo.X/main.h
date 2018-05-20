#include <18F4550.h>
#device ADC=16
  //configura cristal de 20Mhz
  #fuses HSPLL,NOWDT,NOPROTECT,NOLVP,NODEBUG,USBDIV,PLL5,CPUDIV1,VREGEN
  //#fuses   USBDIV, PLL1, CPUDIV1, PROTECT, NOCPD, noBROWNOUT,HSPLL,NOWDT,nolvp, VREGEN
  #use delay(clock=20MHZ)
#use rs232(BAUD=19200,BITS =8,PARITY=N, XMIT=PIN_C6, RCV=PIN_C7, STREAM=PORT1)

#define USB_STRINGS_OVERWRITTEN

char USB_STRING_DESC_OFFSET[]={0,4,14};

char const USB_STRING_DESC[]={
   //string 0 - language
      4,  //length of string index
      0x03,  //descriptor type (STRING)
      0x09,0x04,  //Microsoft Defined for US-English
   //string 1 - manufacturer
      10,  //length of string index
      0x03,  //descriptor type (STRING)
      'h',0,
      'o',0,
      'l',0,
      'a',0,
   //string 2 - product
      12,  //length of string index
      0x03,  //descriptor type (STRING)
      'a',0,
      'm',0,
      'i',0,
      'g',0,
      'o',0
};

#include <usb_cdc.h>
