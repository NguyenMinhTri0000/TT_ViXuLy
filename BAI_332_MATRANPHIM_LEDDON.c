#include <tv_pickit2_shift_1.c>
#include <tv_pickit2_shift_key4x4_138.c>
signed int8 mp;      //signed l� bao nhieu den bao nhieu
void main()
{
set_up_port_ic_chot();
set_tris_b(0x3c); //RB2 - RB5
   while(true)
   {
      mp = key_4x4_dw();      //kiem tra ma tran phim
      if(mp != 0xff) xuat_32led_don_4byte(0, 0, 0, mp);
   }
}

