#include <tv_pickit2_shift_1.c>
unsigned INT8 t0, t0_tam, y;

void main()
{
   set_up_port_ic_chot();
   setup_timer_0 (t0_OFF);
   set_timer0 (0);
   t0_tam = t0 = 0;
   xuat_4led_7doan_giaima_xoa_so0 (t0) ;     //chuong trinh nay d�u
   y = 0xff;
   WHILE (true)
   {
      t0 = get_timer0 ();
      //khong bo if nay vao trong while(input(on) v� do la khi giu phim n� moi chay
      IF (t0 != t0_tam)
      {
         t0_tam = t0;
         xuat_4led_7doan_giaima_xoa_so0 (t0) ;
         IF (t0 >= 101) set_timer0 (1);
      }      
      If(input(On)==0)
      {
         setup_timer_0 (t0_ext_l_to_h|t0_div_1|t0_8_bit);      
         xuat_32led_don_4byte(y, y, y , y);         
      }
      
      if(input(off)==0)
      {
         setup_timer_0 (t0_off);  
         xuat_32led_don_4byte(0, 0, 0, 0);      
      }
   }
}


