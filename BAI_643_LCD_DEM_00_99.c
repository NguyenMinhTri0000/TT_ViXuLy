
//#include <tv_pickit2_shift_1.c>
#include <tv_pickit2_shift_1_proteus.c>
#include <tv_pickit2_shift_lcd.c>
signed INT8 i, j;
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
   set_up_port_ic_chot () ;
   setup_lcd () ;
   WHILE (true)
   {
      FOR (j = 0; j < 99; j++)
      {
         lcd_command (0x40) ;
         FOR (i = 0; i < 64; i++) { lcd_data (lcd_ma_8doan[i]);  }
         lcd_hienthi_so_z_toado_xy (j/10, 2, 0);         
         lcd_hienthi_so_z_toado_xy (j%10, 2, 4);
         delay_ms (200) ;
      }
//!      j = 0;
   }
}


