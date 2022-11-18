
#include <tv_pickit2_shift_1.c>

unsigned INT8 j, solan=100;
unsigned INT16 lm35a, T0;
void counter_dem_len(unsigned int8  gioi_han_duoi, gioi_han_tren)    //phai set gia tri dau o main set_timer 
{
   t0 = get_timer0 () ;
//!   giai_ma_hien_thi (t0);
   IF (t0 >= gioi_han_tren+1) set_timer0 (gioi_han_duoi + 1);
}

void doc_nd_lm35a()
{
   set_adc_channel(0);
   delay_ms(1);
   lm35a = 0;
   FOR (j = 0; j<solan; j++)
   {
      lm35a = lm35a + read_adc ();
      delay_us (100) ;
   }

   lm35a = lm35a / 2.046;
   lm35a = lm35a / solan;
}

void main()
{
   set_up_port_ic_chot () ;
   setup_adc (adc_clock_div_32) ;
   setup_adc_ports (an0_to_an1|vss_vdd);
   set_timer0 (0);
   WHILE (true)
   {
      doc_nd_lm35a ();
      counter_dem_len(0, 99);
      xuat_4led_7doan_4so (ma7doan[T0/ 10], ma7doan[T0 % 10]&0X7F,ma7doan[ lm35a / 10], ma7doan[lm35a % 10]);
   }
}


