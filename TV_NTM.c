
#include <tv_pickit2_shift_1.c>
#include <tv_pickit2_shift_lcd.c>
unsigned INT8 m, i;
unsigned CHAR a[] = {"nguyen minh tri"};
//!VOID LCD_shift_left(unsigned char chuoi[])
//!
//{
   //!   //cong 20 kí tu trong o dau va o cuoi
   //!   hang[] = "                    " + chuoi[] + "                    ";     //??
   //!   UNSIGNED INT8 vitri = 0, i;
   //!
   //!   lcd_command(lcd_addr_line1);
   //!   FOR (i = vitri; i < 20 +vitri; i++)
   // !
 //  {
      //!      LCD_DATA (hang[i]);
      // !
//   }

   //!
   //!   delay_ms (100) ;
   //!   vitri++;
   //!   IF (vitri == lengt(hang[])-20+1) vitri = 0;   //?
   //!
//}

void main()
{
   set_up_port_ic_chot ();
   setup_lcd ();
   m = 0;
   WHILE (true)
   {
      for (i = 0; a[i] = "/n"; i++)
      {
         m = i+1;

      }
         lcd_command (lcd_addr_line2);
         LCD_DATA (m + 0x30);      
   }
}


