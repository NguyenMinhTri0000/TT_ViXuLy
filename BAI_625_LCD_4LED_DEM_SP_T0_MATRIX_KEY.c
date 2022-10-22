//dem san pham, hien thi lcd, 7 doan
//!#include <tv_pickit2_shift_1_proteus.c>
#include <tv_pickit2_shift_1.c>
#include <tv_pickit2_shift_lcd.c>
#include <tv_pickit2_shift_key4x4_138.c>

unsigned INT16 t0,gia_tri_cai_dat, mp;
unsigned INT8 led[] = {0x7F, 0x7F, 0x7F, 0x7F};
void hien_thi_lcd_7doan()
{
   lcd_GOTO_xy (0, 17) ;
   lcd_data (gia_tri_cai_dat / 10 + 0x30);
   lcd_GOTO_xy (0, 18) ;
   lcd_data (gia_tri_cai_dat % 10 + 0x30);
   lcd_GOTO_xy (1, 17) ;
   lcd_data (t0 / 10 + 0x30);
   lcd_GOTO_xy (1, 18) ;
   lcd_data (t0 % 10 + 0x30);
   xuat_4led_7doan_4so (ma7doan[gia_tri_cai_dat / 10], ma7doan[gia_tri_cai_dat % 10], ma7doan[t0 / 10], ma7doan[t0 % 10]) ;
}

void main()
{
   set_up_port_ic_chot ();
   setup_lcd ();
   lcd_GOTO_xy (0, 0) ;
   lcd_data ("gia tri cai dat:");
   lcd_GOTO_xy (1, 0) ;
   lcd_data ("gia tri dem:");
   setup_timer_0 (t0_ext_l_to_h|t0_div_1);
   set_timer0 (0);
   gia_tri_cai_dat = 1;

   WHILE (true)
   {
      mp = key_4x4_dw ();

      IF (mp != 0xff)
      {
         IF (mp < 10)
         {
            led[1] = led[0]; //dich phim
            led[0] = mp + 0x30;
         }

         IF (mp == 0x0f) //enter
         {
            gia_tri_cai_dat = (led[1] - 0x30) * 10 + (led[0] - 0x30); //sao thay ghi tru
         }

         IF (mp == 0x0c)
         {
            led[1] = 0; //hien thi
            led[0] = 1;
            gia_tri_cai_dat = 1;
         }
      }

      t0 = get_timer0 ();
      IF (t0 >= gia_tri_cai_dat) set_timer0 (1) ;
      hien_thi_lcd_7doan () ;
   }
}

