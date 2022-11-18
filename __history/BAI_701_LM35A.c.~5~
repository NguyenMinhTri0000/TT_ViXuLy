
#include <tv_pickit2_shift_1.c>

unsigned INT8 j, solan=100;
unsigned INT16 lm35a;

void main()
{
   set_up_port_ic_chot () ;
   setup_adc (adc_clock_div_32) ;
   setup_adc_ports (an0|vss_vdd);
   set_adc_channel (0);

   WHILE (true)
   {
      lm35a = 0;
      FOR (j = 0; j<solan; j++)
      {
         lm35a = lm35a + read_adc ();
         delay_ms (1) ;
      }

      lm35a = lm35a / 2.046;
      lm35a = lm35a / solan;
      xuat_4led_7doan_giaima_xoa_so0(lm35a);
   }
}



