#include <tv_pickit2_shift_1.c>
#include <tv_pickit2_shift_lcd.c>
unsigned CHAR hang1[] = {"                    NGUYEN MINH TRI                     "};   //20+16+20 = 56 (56-20+1=37):vitri1
unsigned CHAR hang2[] = {"                    19161306                            "};    //20+8+28= 56(56-20+1=37):vitri2
unsigned INT8 i, j, vitri1, vitri2;
void main()
{
   set_up_port_ic_chot ();
   setup_lcd ();
   vitri1 = 36;
   vitri2 = 36;
   WHILE (true)
   {
      //lcd_command (0x80); //chua hieu
      lcd_command(lcd_addr_line1);
      FOR (i = vitri1; i < 20 +vitri1; i++)
      {
         LCD_DATA (hang1[i]);
      }

      delay_ms (200) ;
      vitri1--;
      IF (vitri1 == 0) vitri1 = 36;

      lcd_command(lcd_addr_line2);     
      FOR (j = vitri2; j < 20 +vitri2; j++)
      {
         LCD_DATA (hang2[j]);
      }

      delay_ms (200) ;
      vitri2--;
      IF (vitri2 == 0) vitri2 = 36;      
   }
}

