
#include <tv_pickit2_shift_1.c> 

unsigned INT8    ttct=1, t0, t0_tam; 
#include    <tv_pickit2_shift_32led_don.c>   
  

void phim_up() 
{
   IF (!input (up) && (ttct < 7) )
   {
      delay_ms (10);

      IF (!input (up))
      {
         ttct++;
         WHILE ( ! input (up));
      }
   }
}

  
void phim_dw() 
{
   IF (!input (dw)&& (ttct > 1))
   {
      delay_ms (10);

      IF (!input (dw))
      {
         ttct--;
         WHILE ( ! input (dw));
      }
   }
}

  
void phim_clr() 
{
   IF (!input (clr)&& (ttct > 1)) ttct=1;
}

  
void main() 
{
   
   set_up_port_ic_chot ();
   setup_timer_0 (t0_ext_l_to_h|t0_div_1|t0_8_bit);
   set_timer0 (0);
   set_tris_b (0x3c);
   t0_tam = t0 = 0;
   xuat_4led_7doan_giaima_xoa_so0 (t0);

   WHILE (true)
   {
      t0 = get_timer0 ();

      IF (t0 != t0_tam)
      {
         t0_tam = t0;
         xuat_4led_7doan_giaima_xoa_so0 (t0);
         IF (t0 >= 101) set_timer0 (1);
      }

      IF (ttct == 1) sang_tat_32led (10, 0);
      IF (ttct == 2) sang_tat_dan_pst_32led (10, 0);
      IF (ttct == 3) sang_tat_dan_tsp_32led (10, 0);
      IF (ttct == 4) sang_tat_dan_ngoai_vao_32led (10, 0);
      IF (ttct == 5) sang_tat_dan_trong_ra_32led (10, 0);
      IF (ttct == 6) sang_don_pst_32led (10, 0);
      IF (ttct == 7) sang_don_tsp_32led (10, 0);
      phim_dw ();
      phim_up ();
      phim_clr ();
   }
}

