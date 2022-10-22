//!#include <tv_pickit2_shift_1_proteus.c>
#include <tv_pickit2_shift_1.c>
#include <tv_pickit2_shift_lcd.c>
unsigned INT16 t0,ch,dv,ch_gtcd,dv_gtcd,gia_tri_cai_dat;
///////xoa so 0 vo nghia
void gm_lcd()
{
   ch = t0 / 10 + 0x30;
   dv = t0 % 10 + 0x30;
   IF (ch == 0x30)
   ch = 0x20;
   ch_gtcd = gia_tri_cai_dat / 10 + 0x30;
   dv_gtcd = gia_tri_cai_dat % 10 + 0x30;
}

/////hien thi lcd xoa so 0 vo nghia
void hienthi_lcd()
{
   lcd_GOTO_xy (1, 17) ;
   lcd_data (ch);
   lcd_data (dv);
   lcd_GOTO_xy (0, 17) ;
   lcd_data (ch_gtcd);
   lcd_data (dv_gtcd);
}

void phim_clr()
{
   IF (!input (bt0))
   {
      delay_ms (20);
      IF ( ! input (bt0) )
      {
         gia_tri_cai_dat = 1;
         set_timer0 (0);
         WHILE ( ! input (bt0)) ;
      }
   }
}

void phim_up()
{
   IF (!input (bt1))
   {
      delay_ms (20);
      IF ( ! input (bt1) ) 
      {
         gia_tri_cai_dat++;
         IF (gia_tri_cai_dat == 100) gia_tri_cai_dat = 99;
         WHILE ( ! input (bt1)) ;
      }
   }
}

void phim_dw()
{
   IF (!input (bt2))
   {
      delay_ms (20);
      IF ( ! input (bt2) )
      {
         gia_tri_cai_dat--;
         IF (gia_tri_cai_dat <= 1) gia_tri_cai_dat = 1;
         WHILE ( ! input (bt2)) ;
      }
   }
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
   t0 = 0;
   gia_tri_cai_dat = 1;
   WHILE (true)
   {

      gm_lcd ();
      hienthi_lcd ();
      phim_clr ();
      phim_up ();
      phim_dw ();
      xuat_4led_7doan_4so (ma7doan[gia_tri_cai_dat / 10], ma7doan[gia_tri_cai_dat % 10], ma7doan[t0 / 10], ma7doan[t0 % 10]) ;      
      
      t0 = get_timer0 ();

         IF (t0 >= gia_tri_cai_dat) set_timer0 (1) ;

      delay_ms (50);
   }
}


