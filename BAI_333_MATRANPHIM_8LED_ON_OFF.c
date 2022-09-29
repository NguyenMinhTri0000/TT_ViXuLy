#include <tv_pickit2_shift_1.c>
#include <tv_pickit2_shift_key4x4_138.c>
signed int8 mp;      //signed là bao nhieu den bao nhieu
void main()
{
set_up_port_ic_chot();
set_tris_b(0x3c); //RB2 - RB5
   while(true)
   {
      do
      {
         mp = key_nhan();
      }
      while(mp != 1);
      xuat_32led_don_4byte(0, 0, 0, 0xff);
      
      do
      {
         mp = key_nhan();
      }
      while(mp != 0);
      xuat_32led_don_4byte(0, 0, 0, 0);      
   }
}

