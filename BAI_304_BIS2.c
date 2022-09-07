#include <tv_pickit2_shift_1.c>
unsigned int8 y, i;
void main()
{
   set_up_port_ic_chot();
   y=0;
   while (true)
   {
      Y=0;
      xuat_32led_don_4byte(0,0,0,y);
      delay_ms(200);
      for (i=0;i<4; i++)
      {
         y=((y<<1)|0x04);
         xuat_32led_don_4byte(0,0,0,y);
         delay_ms(200);
      } 
      
      Y=0;
      for (i=0;i<4; i++)
      {
         y=(y>>1)|0x20;
         xuat_32led_don_4byte(0,0,0,y);
         delay_ms(200);
         
      }      
   }
}
