
#include <tv_pickit2_shift_1.c>
#include <tv_pickit2_shift_key4x4_138.c>
#include <tv_pickit2_shift_lcd.c>
//unsigned int8 led[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
//unsigned char led[] = {0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10};
unsigned char led[] = {0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20};
unsigned int8 mp, i;
void dich()
{
   for(i = 19; i >0; i--)
   {
   led[i] = led[i-1];
   }
   if(mp < 10)  led[0] = mp + 0x30;       
   else         led[0] = mp + 0x37;   
  
}
void xuat_lcd()
{
   lcd_GOTO_xy (1, 0);   
   for(i = 19; i > 0; i--)
   {
         lcd_data (led[i]);    
   }
}
void main()
{
   set_up_port_ic_chot ();
   setup_lcd ();
   lcd_goto_xy(0, 0);
   lcd_data("HAY NHAP PHIM:");
   while (true)
   {
   mp = key_4x4_dw();      //kiem tra ma tran phim
   if(mp != 0xff)
   {
   dich();
   xuat_lcd();    
   }
   }
   delay_ms(50);
}
