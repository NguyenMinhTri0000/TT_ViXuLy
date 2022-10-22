//!#include <tv_pickit2_shift_1_proteus.c>
#include <tv_pickit2_shift_1.c>
#include <tv_pickit2_shift_lcd.c>
#include <tv_pickit2_shift_key4x4_138.c>

signed INT8 mp,tg;

void main()
{
   set_up_port_ic_chot();
   setup_lcd ();
   lcd_GOTO_xy (0, 0) ;
   lcd_data ("DIEU KHIEN BUZZER ");
   lcd_GOTO_xy (1, 0) ;
   lcd_data ("BUZZER: XXX, TX:Y");  
   tg = 1;
   while(true)
   {
      mp = key_4x4_dw();
      if(mp!=0xff)
      {
         if(mp<10)
         {
            tg = mp;
            LCD_GOTO_XY(1, 16);
            LCD_DATA(tg+0X30);
         }
         if(mp == 0x0A) 
         {
//!            BUZZER_ON();
            XUAT_32LED_DON_1DW(0xffffffff);
            LCD_GOTO_XY(1, 8);
            LCD_DATA("ON ");
            Delay_ms(1000*TG);
//!            BUZZER_OFF();
            XUAT_32LED_DON_1DW(0);            
            LCD_GOTO_XY(1, 8);
            LCD_DATA("OFF");            
         }
      }   
   }
}
