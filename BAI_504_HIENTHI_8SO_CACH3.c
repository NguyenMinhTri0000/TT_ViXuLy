
#include <tv_pickit2_shift_1.c>

unsigned INT8 led7dq[8]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8};
unsigned INT8 i;

void hien_thi_8led()
{
   FOR(i=0;i<8;i++)
   {
      xuat_8led_7doan_quet_2(i, led7dq[i]);
      delay_us(100);
      xuat_8led_7doan_quet_tat_led();
   }
}

void main()
{
   set_up_port_ic_chot();

   WHILE(true)
   {
      hien_thi_8led();
   }
}

