#include <tv_pickit2_shift_1_proteus.c>

unsigned INT8 t0;

void main()
{
   set_up_port_ic_chot();
   setup_timer_0 (t0_ext_l_to_h|t0_div_1|t0_8_bit);
                //couter t0, xung ngo�i, canh l�n| ti l� 1:1| 8bit (0-255)
   set_timer0 (0);

   WHILE (true)
   {
      t0 = get_timer0 ();

      xuat_4led_7doan_3so (ma7doan[t0 / 100], ma7doan[t0 / 10 % 10], ma7doan[t0 % 10]);
      IF (t0 >= 101) set_timer0 (1);
   }
   
   //delay_ms(500);    //delay khi m� phong proteus
   //v�n chua �n
}

