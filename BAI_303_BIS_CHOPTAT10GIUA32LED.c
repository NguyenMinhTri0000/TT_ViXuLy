#include <tv_pickit2_shift_1.c>
unsigned int8 x, y;
void main()
{
   set_up_port_ic_chot();
   x = 0x1f;
   y = 0xf8;
   while(true)
   {
     // xuat_32led_don_4byte( 0, 0x1f, 0xf8, 0);
      xuat_32led_don_4byte( 0, x, y, 0);      
      delay_ms(200);
    //  y = ~y;
      xuat_32led_don_4byte( 0, 0, 0, 0);
      delay_ms(200);    
   }
}
