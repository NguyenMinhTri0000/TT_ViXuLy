
#include <tv_pickit2_shift_1.c>
#define nd_tren 40
#define nd_duoi 40

unsigned INT8 j, solan=100;
unsigned INT16 lm35a;
int1 ttqn=0;

void so_sanh_dk_buzzer()
{
   IF ((lm35a>nd_tren))
   {
      ttqn = 1;
//!      buzzer_on () ;
      XUAT_32LED_DON_4BYTE (0, 0, 0, 0XFF);
     // triac_2_off () ;
//!     XUAT_32LED_DON_4BYTE (0,0,0,0);
   }

   else IF ((lm35a < nd_tren)&& (ttqn == 1))
   {
      ttqn = 0;
//!      buzzer_off () ;
      XUAT_32LED_DON_4BYTE (0, 0, 0, 0);
   }

   IF ((lm35a < nd_duoi)&& (ttqn == 0)) 
   //triac_2_on ();
   XUAT_32LED_DON_4BYTE (0xff, 0, 0, 0);
}

void main()
{
   set_up_port_ic_chot () ;
   setup_adc (adc_clock_div_32) ;
   setup_adc_ports (an0|vss_vdd);
   set_adc_channel (0);
   ttqn = 0;

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
      xuat_4led_7doan_giaima_xoa_so0 (lm35a);
      so_sanh_dk_buzzer () ;
   }
}


