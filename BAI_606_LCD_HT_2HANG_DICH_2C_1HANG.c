//4 h�ng van chay song song, khong theo thu tu
#include <tv_pickit2_shift_1.c>
#include <tv_pickit2_shift_lcd.c>

unsigned CHAR hang1[] = {"                    NGUYEN MINH TRI                     "};   //20+16+20 = 56 (56-20+1=37):vitri1
unsigned CHAR hang2[] = {"                    19161306                            "};    //20+8+28= 56(56-20+1=37):vitri2
unsigned CHAR hang3[] = {"                    TT VXL                              "};   //20+16+20 = 56 (56-20+1=37):vitri3
unsigned CHAR hang4[] = {"                    THAY NGOC ANH                       "};    //20+8+28= 56(56-20+1=37):vitri4
unsigned INT8 i, j, k, h, vitri1, vitri2, vitri3, vitri4;
unsigned INT1 TT;

void main()
{
   set_up_port_ic_chot ();
   setup_lcd ();
   vitri1 = 0;
   vitri2 = 0;
   vitri3 = 36;
   vitri4 = 36;   
   TT = 0;
   WHILE (true)
   {
   if (TT == 0)
   {
      lcd_command(lcd_addr_line1);
      FOR (i = vitri1; i < 20 +vitri1; i++)
      {
         LCD_DATA (hang1[i]);
      }

      delay_ms (100) ;
      vitri1++;
      IF (vitri1 == 36) vitri1 = 0;

      lcd_command(lcd_addr_line2);     
      FOR (j = vitri2; j < 20 +vitri2; j++)
      {
         LCD_DATA (hang2[j]);
      }
      delay_ms (100) ;
      vitri2++;
      IF (vitri2 == 36) vitri2 = 0;       
     
      TT = 1;
   }
   else if(TT==1)
   {
       lcd_command(lcd_addr_line3);
      FOR (k  = vitri3; k  < 20 +vitri3; k ++)
      {
         LCD_DATA (hang3[k]);
      }

      delay_ms (100) ;
      vitri3--;
      IF (vitri3 == 0) vitri3 = 36;

      lcd_command(lcd_addr_line4);     
      FOR (h = vitri4; h < 20 +vitri4; h++)
      {
         LCD_DATA (hang4[h]);
      }

      delay_ms (100) ;
      vitri4--;
      IF (vitri4 == 0) vitri4 = 36;   
      TT = 0;
   }    
   }
}

