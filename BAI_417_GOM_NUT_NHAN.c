//GHEP 2 phim_ON_OFF THANH 1 PHIM
//chua chay

#include <tv_pickit2_shift_1.c>
unsigned INT8 t0, t0_tam;
int1 TT_ON_OFF;

void phim_ON_OFF()
{
   IF (!input (BT1))
   {
      delay_ms (20);
      IF (!input (BT1))
      {
         TT_ON_OFF = ~TT_ON_OFF; 
         WHILE ( ! input (BT1)) ;
      }
   }
}

void main()
{
   TT_ON_OFF = 0;
   set_up_port_ic_chot();
   setup_timer_0 (t0_ext_l_to_h|t0_div_1|t0_8_bit);
   set_timer0 (0);
   t0_tam = t0 = 0;
   xuat_4led_7doan_giaima_xoa_so0 (t0) ;
   WHILE (true)
   {
      t0 = get_timer0 ();
      IF (t0 >= 101) set_timer0 (1);         
      xuat_4led_7doan_giaima_xoa_so0 (t0) ;
      
      phim_ON_OFF();
      
      IF (TT_ON_OFF == 1)
      {
         setup_timer_0 (t0_ext_l_to_h|t0_div_1|t0_8_bit);          
         xuat_32led_don_4byte (0XFF, 0XFF, 0XFF, 0XFF);  
      }
      ELSE 
      {
         setup_timer_0 (t0_OFF);
         xuat_32led_don_4byte (0, 0, 0, 0);
      }
   }

   
}



