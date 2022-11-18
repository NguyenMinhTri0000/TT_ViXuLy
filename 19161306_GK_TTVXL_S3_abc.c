   
#include <tv_pickit2_shift_1.c>
#include <tv_pickit2_shift_lcd.c>
#include<tv_pickit2_shift_key4x4_138.c>

signed INT8 giay,bdn,i,LCH,LDV, chuc, donvi,t0,DV_SP_LCD, HC_SP_LCD, MP;
unsigned int1 UD_Counter_Timer = 0, TT_LCD = 1;


#INT_timer1

void interrupt_timer1()
{
   bdn++;
   set_timer1 (3036) ;
}




VOID GIAIMA_LCD_LON(UNSIGNED int8 GTL)
{
   LDV = GTL % 10;
   LCH = GTL / 10;
   IF (LCH == 0) LCH = 10;
}

void lcd_hienthi_so_z_toado_xy(SIGNED int8 lcd_so, x1, y1)
{
   lcd_GOTO_xy (x1, y1) ;
   FOR (i = 0; i < 6; i++)
   {
      IF (i == 3) lcd_goto_xy (x1 + 1, y1);
      lcd_data (lcd_so_x[lcd_so][i]) ;
   }
}

void giai_ma_hien_thi(UNSIGNED int16 tam)
{
   donvi = ma7doan[tam % 10];
   chuc = ma7doan[tam / 10];
   IF (chuc == 0xc0) chuc = 0xff; //xoa so 0 vo nghia
   xuat_4led_7doan_4so (donvi&0x7f, 0xF7, 0xb7, chuc&0x7f) ;
}


VOID GM_LCD()
{
   HC_SP_LCD = T0 / 10 + 0X30;
   DV_SP_LCD = T0 % 10 + 0X30;
   IF (HC_SP_LCD == 0X30) HC_SP_LCD = 0X20;
}

VOID HT_LCD()
{
      LCD_GOTO_XY (0, 0) ;
         LCD_DATA ("Don vi:");
         
      LCD_GOTO_XY (0, 15) ;
         LCD_DATA ("Chuc:");
         
         
      LCD_GOTO_XY (3, 5) ;  
         LCD_DATA ("DemSP=");
   LCD_DATA (HC_SP_LCD);
   LCD_DATA (DV_SP_LCD);
   
   lcd_hienthi_so_z_toado_xy (T0 / 10, 1, 16) ;
   lcd_hienthi_so_z_toado_xy ( T0 % 10, 1, 0);
}
void Chop_tat_lcd()
{
if (TT_LCD == 0)
{
HT_LCD();
delay_ms(1500);
         LCD_COMMAND(LCD_CLEAR_DISPLAY);
         delay_ms(500);
}
else if (TT_LCD == 1)
{
HT_LCD();
}
}
void main()
{
   set_up_port_ic_chot () ;
   setup_lcd () ;
   setup_timer_0 (t0_ext_l_to_h|t0_div_1);
   set_timer0 (6) ;
   
   setup_timer_1 (t1_internal|t1_div_by_8) ;
   set_timer1 (3036) ;
   enable_interrupts (global) ;
   enable_interrupts (INT_timer1) ;
   
   giay = 8;
   bdn = 0;
   


   WHILE (true)
   {
   
      MP = KEY_4X4_DW () ;

      IF (mp != 0xff)
      {
         IF (mp == 6) TT_LCD = ~ TT_LCD;
         IF (mp == 3) 
         {
         UD_Counter_Timer = ~UD_Counter_Timer;
         set_timer0 (14 - get_timer0 ()) ;         
         }
      }   
      
   GM_LCD();
Chop_tat_lcd();
      IF (bdn < 10)
      {
         HIEN_THI_8LED_7DOAN_QUET ();
      }

      ELSE IF (UD_Counter_Timer == 0)
      {
         bdn = bdn - 10;
         giay++;
         IF (giay >= 17) giay = 8;
      }

      ELSE IF (UD_Counter_Timer == 1)
      {
         bdn = bdn - 10;
         giay--;
         IF (giay <= 8) giay = 17;
      }
      giai_ma_hien_thi(giay);
      //counter

      if(UD_Counter_Timer==0)
      {
         t0=get_timer0();
         if(t0>14) set_timer0(6);
      }
      if(UD_Counter_Timer==1)
      {
         t0=14-get_timer0();
         if(t0<=6) set_timer0(14);
      }    
      
      

      
      
   }
}

