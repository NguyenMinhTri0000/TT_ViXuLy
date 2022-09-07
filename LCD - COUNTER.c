
#include <tv_pickit2_shift_1.c> 
#include <tv_pickit2_shift_lcd.c> 

signed INT16    i,dem, T0; 

void lcd_hienthi_so_z_toado_xy(SIGNED int8 lcd_so, x1, y1) 
{
   lcd_GOTO_xy (x1, y1);
   FOR (i = 0; i < 6; i++)
   {
      IF (i == 3) lcd_goto_xy (x1 + 1, y1);
      lcd_data (lcd_so_x[lcd_so][i]);
   }
}

void main() 
{
   
   set_up_port_ic_chot ();
   setup_timer_0 (t0_ext_l_to_h|t0_div_1|t0_8_bit);
   set_timer0 (5);
   
   
   setup_lcd ();
   lcd_GOTO_xy (0, 0);
   lcd_data ("**COUNTER tu 5-15 **");
   
   lcd_command (0x40) ;
   FOR (i = 0; i < 64; i++) { lcd_data (lcd_ma_8doan[i]);  }
   
   WHILE (true)
   {
      t0 = get_timer0 ();
      IF (t0 >= 15) set_timer0 (5);
      
      xuat_4led_7doan_giaima_xoa_so0 (t0);
      
      lcd_hienthi_so_z_toado_xy (T0 / 10, 2, 0);
      lcd_hienthi_so_z_toado_xy (T0 % 10, 2, 3);
      
      DELAY_MS(200); //NEN THEM VAO KHI MO PHONG DE KHONG BI LOI QUA KHA NANG XU LY CUA CPU
                     //GIAM THOI GIAN CAP NHAT THONG TIN VA HIEN THI
   }
}

