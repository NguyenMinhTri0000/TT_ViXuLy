#include <tv_pickit2_shift_1_proteus.c>
#include <tv_pickit2_shift_lcd.c>
unsigned INT16 t0,DV,CH,TR;
// GIAI MA HIEN THI XOA SO 0 VO NGHIA
VOID GM_LCD()
{
   DV = T0 % 10 + 0X30;
   CH = T0 / 10 % 10 + 0X30;
   TR = T0 / 100 + 0X30;
   IF (TR == 0X30)   //0x30 là so 0
   {
      TR = 32; //0X20 là khoang trong
      IF (CH == 0X30) CH = 0X20;
   }
}

VOID HT_LCD()
{
   lcd_GOTO_xy(0,17);
   lcd_data (TR);
   lcd_data (CH);
   lcd_data (DV);
}

void main()
{
   set_up_port_ic_chot ();
   setup_lcd ();
   lcd_GOTO_xy (0, 0) ;
   lcd_data ("dem san pham:");
   setup_timer_0 (t0_ext_l_to_h|t0_div_1);
   set_timer0 (0);
   t0 = 0;
   WHILE (true)
   {
      GM_LCD () ;
      HT_LCD () ;
      t0 = get_timer0 ();
      
      xuat_4led_7doan_giaima_xoa_so0 (t0);
      IF (t0 >= 1000) set_timer0 (1) ;
   }
}


