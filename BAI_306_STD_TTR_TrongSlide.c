#include <tv_pickit2_shift_1.c>
unsigned int16 YT, YP;
unsigned int8 i;

void main()
{
   set_up_port_ic_chot();
   YT = 0;
   YP = 0;
   while(TRUE)
   {
   For(i = 0; i<16; i= i+1)
      {
         xuat_32led_don_2word( YT, YP);
         delay_ms(300);
         YT = (YT<<1)+0x0001;  //ngaoi vao
         YP = (YP>>1)+0x8000;
      }
   for(i = 0; i < 16; i++)
      {
         xuat_32led_don_2word( YT, YP);
         delay_ms(300);
         YT = YT << 1 ;
         YP = YP >> 1 ;
      }
           
   }
}

