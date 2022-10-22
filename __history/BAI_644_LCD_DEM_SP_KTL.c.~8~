#include <tv_pickit2_shift_1_proteus.c>
#include <tv_pickit2_shift_lcd.c>
unsigned INT16 t0,i;
// GIAI MA HIEN THI XOA SO 0 VO NGHIA
void lcd_hienthi_so_z_toado_xy(SIGNED int8 lcd_so, x1, y1)
{
   lcd_GOTO_xy (x1, y1) ;
   FOR (i = 0; i < 6; i++) //mot so LCD duoc tao thanh tu 6 phan, 3 tren, 3 duoi
   {
      IF (i == 3) lcd_goto_xy (x1 + 1, y1);
      lcd_data (lcd_so_x[lcd_so][i]) ;
   }
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
   lcd_GOTO_xy(0,0);
   lcd_data("**DEM SAN PHAM ** ");
      t0 = get_timer0 ();
         lcd_command (0x40) ;
         FOR (i = 0; i < 64; i++) { lcd_data (lcd_ma_8doan[i]);  }
         lcd_hienthi_so_z_toado_xy (t0/100, 2, 0);      //tram             
         lcd_hienthi_so_z_toado_xy (t0/10, 2, 4);      //chuc
         lcd_hienthi_so_z_toado_xy (t0%10, 2, 8);      //don vi
      IF (t0 >= 1000) set_timer0 (1) ;
   }
}


