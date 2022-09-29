#include <tv_pickit2_shift_1.c>
void main()
{
   set_up_port_ic_chot();
   set_tris_b(0x3c);    //0011   1100
   xuat_32led_don_4byte(0, 0, 0, 0);
   while (true)
   {
   
      if (input(bt0) ==0)
      xuat_32led_don_4byte(0, 0, 0, 0xff);
      else if (input(bt1) == 0)
      xuat_32led_don_4byte(0, 0, 0 , 0);      
   }
}


