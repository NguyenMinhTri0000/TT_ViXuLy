#include <tv_pickit2_shift_1_proteus.c>
signed int16 i;
void main()
{
   set_up_port_ic_chot();
   while(true)
   {
      for(i = 0; i<999; i++)
      {
//!         xuat_4led_7doan_4so(ma7doan[0], ma7doan[i/100], ma7doan[i%100/10], ma7doan[i%10]);     //thay van dung
         xuat_4led_7doan_3so( ma7doan[i/100], ma7doan[i/10%10], ma7doan[i%10]);
         delay_ms(50);
      }   
   }
}
