#INCLUDE <TV_PICKIT2_SHIFT_1.c>
#INCLUDE <TV_PICKIT2_SHIFT_DS18B20.c>  
unsigned INT16 lm35a;
unsigned int8 j, solan=100;
int8 LM35()
{
      lm35a = 0;
      FOR (j = 0; j<solan; j++)
      {
         lm35a = lm35a + read_adc ();
         delay_ms (1) ;
      }

      lm35a = lm35a / 2.046;
      lm35a = lm35a / solan;
      return lm35a;
}
VOID MAIN()
{
   SET_UP_PORT_IC_CHOT();
   setup_adc (adc_clock_div_32) ;
   setup_adc_ports (an0|vss_vdd);
   set_adc_channel (0);   
   KHOI_TAO_DS18B20();
   DS18A_TAM=0;
   XUAT_4LED_7DOAN_GIAIMA_XOA_SO0(0);
   WHILE(TRUE)
   {
      IF(TOUCH_PRESENT())   DOC_GIATRI_DS18B20();
         DS18A=DS18A>>4;
         DS18A=DS18A&0X0FF;
         int16 a = LM35();
         XUAT_4LED_7DOAN_2_SO(DS18A,a);
   }
}
