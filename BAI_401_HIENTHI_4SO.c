#include <tv_pickit2_shift_1.c>
void main()
{
   set_up_port_ic_chot();
   xuat_4led_7doan_4so(0xb0, 0xa4, 0xf9, 0xc0);
   while(true);
}
