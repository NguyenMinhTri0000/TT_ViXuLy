#include <tv_pickit2_shift_1.c>
#include <tv_pickit2_shift_key4x4_138.c>
unsigned int8 led[] = {0, 0, 0, 0};
unsigned int8 mp;
void dich7led()
{
   led[3] = led[2];
   led[2] = led[1];
   led[1] = led[0];
   led[0] = mp;  
//xuat_4led_7doan_4so(ma7doan[led[3]], ma7doan[led[2]], ma7doan[led[1]], ma7doan[led[0]]);   
}
void main()
{
   set_up_port_ic_chot ();
   set_tris_b(0x3c); //RB2 - RB5
   while (true)
   {
   mp = key_4x4_dw();      //kiem tra ma tran phim
   if(mp != 0xff)
   {
   dich7led();
   xuat_4led_7doan_4so(ma7doan[led[3]], ma7doan[led[2]], ma7doan[led[1]], ma7doan[led[0]]);     
   }
   }
}
