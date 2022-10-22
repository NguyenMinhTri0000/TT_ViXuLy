
//                i don't know
#include <tv_pickit2_shift_1.c>
//!#include <tv_pickit2_shift_1_proteus.c>
#include <tv_pickit2_shift_key4x4_138.c>
#include <tv_pickit2_shift_lcd.c>

unsigned CHAR led[] = {0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20};
unsigned INT8 mp, i, j;

void dich()
{
   FOR (i = 19; i > 0; i--)
   {
      led[i] = led[i - 1];
      j++;
   }

   IF (mp < 10) led[0] = mp + 0x30;
   ELSE  led[0] = mp + 0x37;
}

void xuat_lcd()
{
   lcd_GOTO_xy (1, 0);
   FOR (i = 19; i > 0; i--)
   {
      lcd_data (led[i - 1]); //i - 1 dúng, còn i thì bi cham??
   }
}

void main()
{
   set_up_port_ic_chot ();
   setup_lcd ();
   lcd_GOTO_xy (0, 0);
   lcd_data ("HAY NHAP PHIM:") ;
   j = 0;

   WHILE (true)
   {
      mp = key_4x4_dw (); //kiem tra ma tran phim
      IF (mp != 0xff)
      {
//!         IF (j < 20)
//!         {
//!            lcd_command (lcd_addr_line1) ;
//!            dich () ;
//!         }
//!
//!         else IF (j < 40)
//!         {
//!            lcd_command (lcd_addr_line2) ;
//!            dich () ;
//!         }
//!
//!         else IF (j < 60)
//!         {
//!            lcd_command (lcd_addr_line3) ;
//!            dich () ;
//!         }
//!
//!         ELSE
//!         {
//!            lcd_command (lcd_addr_line4) ;
//!            dich () ;
//!         }
         dich();
         xuat_lcd ();
      }
   }

   delay_ms (50) ;
}

