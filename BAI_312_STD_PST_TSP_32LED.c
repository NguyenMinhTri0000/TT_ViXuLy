#include <tv_pickit2_shift_1.c>
unsigned int8 dem_led;
unsigned int32 y;
void delay_tuy_y(unsigned int8 d12)
{
   unsigned int8 d1;
   for (d1 = 0; d1 <d12; d1++) delay_ms(10);
}
void sang_tat_dan_pst_32led(unsigned int8 d1)
{
   if(dem_led <32)
   {
      xuat_32led_don_1dw(y);
      y = (y<<1) + 0x00000001;
      delay_tuy_y (d1);
   }
   else if(dem_led<64)
   {
      xuat_32led_don_1dw(y);
      y = (y <<1);
      delay_tuy_y(d1);
   }
   else if(dem_led <96)
   {
      xuat_32led_don_1dw(y);
      y = (y>>1) + 0x80000000;
      delay_tuy_y (d1);
   }
   else if(dem_led<128)
   {
      xuat_32led_don_1dw(y);
      y = (y >>1);
      delay_tuy_y(d1);
   }   

   else
   {
      dem_led = 0;
      y = 0;
   }
      dem_led ++;
}   
void main()
{
   set_up_port_ic_chot();
   y = 0;
   while(true)
   sang_tat_dan_pst_32led(2);
}
