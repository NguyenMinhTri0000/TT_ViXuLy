
#include <tv_pickit2_shift_1.c>
#include <tv_pickit2_shift_key4x4_138.c>
#include <tv_pickit2_shift_lcd.c>
signed int8 mp;      //signed l� bao nhieu den bao nhieu
void main()
{
   set_up_port_ic_chot ();
   setup_lcd ();
   set_tris_b(0x3c); //RB2 - RB5
   lcd_GOTO_xy (0, 0) ;
   lcd_data ("HAY NHAN PHIM:"); //9 symbol
   while(true)
   {
      mp = key_4x4_dw();      //kiem tra ma tran phim
      if(mp < 10) 
      {
         lcd_GOTO_xy (1, 0);
         lcd_data (mp + 0x30);       
      }
      else 
      {
         lcd_GOTO_xy (1, 0);
         lcd_data (mp + 0x37);   
      }
   }
}

