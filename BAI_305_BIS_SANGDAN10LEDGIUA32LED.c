#include <tv_pickit2_shift_1.c>
unsigned int8 i;
unsigned int32 y;
void main()
{
   set_up_port_ic_chot();
   y=0;
   while (true)
   {
      y=0;
      xuat_32led_don_4byte(y,y,y,y);
      delay_ms(200);
      for (i=0;i<10; i++)
      {
         y=((y<<1)|0x00000800);
         xuat_32led_don_1dw(y);
         delay_ms(200);
      } 
      
      y=0;
      for (i=0;i<10; i++)
      {
         y=(y>>1)|0x00100000;
         xuat_32led_don_1dw(y);
         delay_ms(200);
         
      }      
   }
}
