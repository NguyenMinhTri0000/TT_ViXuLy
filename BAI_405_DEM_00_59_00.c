#include <tv_pickit2_shift_1_proteus.c>
signed int8 i;
void main()
{
   set_up_port_ic_chot();
   while(true)
   {
      for(i = 0; i<60; i++)
      {
         xuat_4led_7doan_2so(ma7doan[i/10], ma7doan[i%10]);
         delay_ms(200);
      }
      for(i = 59; i>0; i--)      // kh?ng c? gi?y 60
      {
         xuat_4led_7doan_2so(ma7doan[i/10], ma7doan[i%10]);
         delay_ms(200);
      }      
   }
}
