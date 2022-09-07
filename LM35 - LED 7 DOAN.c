
#include <tv_pickit2_shift_1.c> 

unsigned INT8     j, solan=100;  
unsigned INT16   lm35a, lm35b; 

void doc_nd_lm35a() 
{
   set_adc_channel (0);
   delay_ms(1);         //them vao so voi giao trinh - thoi gian chon kenh
   lm35a = 0;
   FOR (j = 0; j<solan; j++)
   {
      lm35a = lm35a + read_adc ();
      delay_us (100);
   }

   lm35a = lm35a / 2.046;
   lm35a = lm35a / solan;
}

void doc_nd_lm35b() 
{
   set_adc_channel (1);
   delay_ms(1);            //them vao so voi giao trinh - thoi gian chon kenh
   lm35b = 0;
   FOR (j = 0; j<solan; j++)
   {
      lm35b = lm35b + read_adc ();
      delay_us (100);
   }

   lm35b = lm35b / 2.046;
   lm35b = lm35b / solan;
}

void main() 
{
   
   set_up_port_ic_chot ();
   setup_adc (adc_clock_div_32);
   setup_adc_ports (an0_to_an1|vss_vdd);
   
   WHILE (true)
   {
      doc_nd_lm35a ();
      doc_nd_lm35b ();
      xuat_4led_7doan_4so (ma7doan[lm35b/10], ma7doan[lm35b%10]&0x7F,ma7doan[lm35a/10], ma7doan[lm35a%10]);
   }
}

