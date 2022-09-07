#include <tv_pickit2_shift_1.c> 

signed INT8      giay; 
unsigned INT16      i; 
void hienthi_delay() 
{
   
   FOR (i = 0; i < 20; i++)
   {
      xuat_8led_7doan_quet_2 (0, ma7doan [giay % 10]);
      delay_MS (20);
      xuat_8led_7doan_quet_tat_led ();
      
      xuat_8led_7doan_quet_2 (1, ma7doan [giay / 10]);
      delay_MS (20);
      xuat_8led_7doan_quet_tat_led ();
   }
}

void main() 
{
   
   set_up_port_ic_chot ();

   WHILE (true)
   {
      FOR (giay = 0; giay < 15; giay ++) hienthi_delay ();
   }
}

