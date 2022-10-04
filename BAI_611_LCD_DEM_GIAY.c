#include <tv_pickit2_shift_1_proteus.c>
#include <tv_pickit2_shift_lcd.c>
signed INT8 giay;
void lcd_hienthi_dongho()
{
   lcd_GOTO_xy (0, 18);
   delay_us (20) ;
   lcd_data (giay / 10 + 0x30); //0x30 is code ASCII number 0
   lcd_data (giay % 10 + 0x30) ;
}

void main()
{
   set_up_port_ic_chot ();
   setup_lcd () ;
   lcd_GOTO_xy (0, 0) ;
   lcd_data ("dong ho:");
   giay = 0;
   WHILE (true)
   {
      lcd_hienthi_dongho () ;
      //delay_ms (1000) ;
      delay_ms (100) ;
      giay++;
      IF (giay == 60) giay = 0;
   }
}


