#include <tv_pickit2_shift_1.c>
unsigned int8 y;
void phim_inv()
{
   if(input(inv)==0)    //kiem tra lan 1
   {
      delay_ms(50);
      {
         if(input(inv)==0)    //kiem tra lan 2
         {
         //lenh chuong trinh
            y = ~y;
            xuat_32led_don_4byte(0, 0, 0, y);
            while(input(inv));   //cho nha phim
             //if(!input(inv));
         }
      }
   }
}
void main()
{
   set_up_port_ic_chot();
   set_tris_b(0x3c);    //0011   1100
   y = 0x00;
   xuat_32led_don_4byte(0, 0, 0, 0);
   while (true)
   {
      if(input(on)==0)
      {
      y = 0x0f;   //0000   1111
      xuat_32led_don_4byte(0, 0, 0, y);
      }
      if (input(off)==0)
      {
            xuat_32led_don_4byte(0, 0, 0 , 0);
      }
      else         phim_inv();
      
   }
}


