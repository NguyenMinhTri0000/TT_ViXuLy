#include <tv_pickit2_shift_1_proteus.c>
signed int8 i;
void main()
{
   set_up_port_ic_chot();
   while(true)
   {
      for (i=0;i<10;i++)
      {
      xuat_4led_7doan_1so(ma7doan[i]);
      delay_ms(500);
      }
   }
}
