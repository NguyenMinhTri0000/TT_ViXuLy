
#include <tv_pickit2_shift_1.c> 

signed INT8       giay,bdn; 
#INT_timer1 

void interrupt_timer1() 
{  
   bdn++;
   set_timer1 (3036);
}
     
void giai_ma_gan_cho_8led_quet() 
{  
   led_7dq[0] = ma7doan [giay % 10];
   led_7dq[1] = ma7doan [giay / 10];
}

void main() 
{
   
   set_up_port_ic_chot ();
   setup_timer_1 (t1_internal|t1_div_by_8);
   set_timer1 (3036);
   enable_interrupts (global);
   enable_interrupts (INT_timer1);
   giay = 0;
   bdn = 0;

   WHILE (true)
   {
      giai_ma_gan_cho_8led_quet ();
      IF (bdn < 10) hien_thi_8led_7doan_quet ();

      ELSE
      {
         bdn = bdn - 10;
         giay++;
         IF (giay == 60) giay = 0;
      }
   }
}

