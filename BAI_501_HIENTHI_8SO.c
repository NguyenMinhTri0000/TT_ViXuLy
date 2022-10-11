
#include <tv_pickit2_shift_1.c>
unsigned INT16 tg_delay;
void main()
{
   set_up_port_ic_chot();
   tg_delay=1;
   WHILE(true)
   {
      xuat_8led_7doan_quet_1(0x7f, 0xc0); //0
      delay_ms(tg_delay);
      xuat_8led_7doan_quet_1(0xbf, 0xf9); //1
      delay_ms(tg_delay);
      xuat_8led_7doan_quet_1(0xdf, 0xa4); //2
      delay_ms(tg_delay);
      xuat_8led_7doan_quet_1(0xef, 0xb0); //3
      delay_ms(tg_delay);
      xuat_8led_7doan_quet_1(0xf7, 0x99); //4
      delay_ms(tg_delay);
      xuat_8led_7doan_quet_1(0xfb, 0x92); //5
      delay_ms(tg_delay);
      xuat_8led_7doan_quet_1(0xfd, 0x82); //6
      delay_ms(tg_delay);
      xuat_8led_7doan_quet_1(0xfe, 0xf8); //7
      delay_ms(tg_delay);
   }
}


