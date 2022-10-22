#include <tv_pickit2_shift_1_proteus.c>
#include <tv_pickit2_shift_lcd.c>
signed INT gio,phut,giay;
void lcd_hienthi_dongho()
{
   lcd_GOTO_xy (0, 12);
   lcd_data (gio / 10 + 0x30); lcd_data (gio % 10 + 0x30);
   lcd_data (' ');
   lcd_data (phut / 10 + 0x30); lcd_data (phut % 10 + 0x30);
   lcd_data (' ');
   lcd_data (giay / 10 + 0x30); lcd_data (giay % 10 + 0x30);
}

void main()
{
   set_up_port_ic_chot ();
   setup_lcd ();
   lcd_GOTO_xy (0, 0) ;
   lcd_data ("dong ho:"); //9 symbol
   giay = 0; phut = 0; gio = 0;
   WHILE (true)
   {
      lcd_hienthi_dongho () ;
      //delay_ms (1000) ;
      delay_ms (200) ;      
      giay++;
      IF (giay == 60)
      {
         giay = 0; phut++;
         IF (phut == 60)
         {
            phut = 0;
            gio++;
         }

         IF (gio == 24)
         {
            gio = 0;
         }
      }
   }
}


