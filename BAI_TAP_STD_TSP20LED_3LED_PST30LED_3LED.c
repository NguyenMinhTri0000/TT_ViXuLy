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
      for (i=0;i<7; i++)   //7*4 l� 28LED != 25LED
      {
         y=((y<<4)|0x0000000F)&0x01FFFFFF;
         xuat_32led_don_1dw(y);
         delay_ms(200);
      } 
      
      y=0;
      for (i=0;i<7; i++)
      {
         y=((y>>3)|0x000E0000)&0x000FFFFF;
         xuat_32led_don_1dw(y);  //7*3 =21LED != 20LED
         delay_ms(200);
         
      }      
   }
}
