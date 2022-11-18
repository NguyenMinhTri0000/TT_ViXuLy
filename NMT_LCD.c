
//thac mac hang 25
//!#include <tv_pickit2_shift_1.c>
#include <tv_pickit2_shift_1_proteus.c>
#include <tv_pickit2_shift_lcd.c>

unsigned CHAR hang1[] = {"                    NGUYEN MINH TRI                    "};   //20+15+20 = 55 (55-20+1=36):vitri1
unsigned CHAR hang2[] = {"                    19161306                           "};    //20+8+20=48 (48-20+1=29):vitri2
int Size_Of(char mang[])
   {
       int i;
       while (mang[i]!='\0')
       {
           i++;
       }
       return i;
   }
   void lcd_dich_trai_1hang(char mang1[], int8 hang)
   {
      if(hang == 0)  lcd_command (lcd_addr_line1) ;
      if(hang == 1)  lcd_command (lcd_addr_line2) ;
      if(hang == 2)  lcd_command (lcd_addr_line3) ;
      if(hang == 3)  lcd_command (lcd_addr_line4) ;   
      unsigned int8 vitri1 ;  // dung
//!      unsigned int8 vitri1 = 0;      //sai???
      FOR (unsigned int8 i = vitri1; i < 20 +vitri1; i++)
      {
         LCD_DATA (mang1[i]);
      }

      delay_ms (100);
      vitri1++;
      IF (vitri1 == Size_Of(mang1)- 20 + 1) vitri1 = 0;   
   }

void main()
{
   set_up_port_ic_chot ();
   setup_lcd ();


   WHILE (true)
   {
      lcd_dich_trai_1hang(hang1, 2);
      lcd_dich_trai_1hang(hang2, 3);      
//!      lcd_dich_phai(hang1, 0);
//!      lcd_dich_phai(hang2, 1);

   }
}

