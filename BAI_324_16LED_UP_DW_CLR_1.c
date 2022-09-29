
#include <tv_pickit2_shift_1.c>
unsigned int16 y;

void Nut_up()
{
   if(input(UP)==0)    //kiem tra lan 1
   {
      delay_ms(20);
      {
         if(input(UP)==0)    //kiem tra lan 2
         {

               //xuat_32led_don_2word(0, y);
               delay_ms(200);
               y = (y<<1)|0x0001;     
               xuat_32led_don_4byte( 0, 0, y>>8 ,  y);               
            while(input(UP)==0);   //cho nha phim
         }
      }
   }
}
void Nut_dw()
{
   if(input(DW)==0)    //kiem tra lan 1
   {
      delay_ms(20);
      {
         if(input(DW)==0)    //kiem tra lan 2
         {

               //xuat_32led_don_2word(0, y);               
               delay_ms(200);
               y = (y>>1);      
               xuat_32led_don_4byte( 0, 0, y>>8 ,  y);  //phai xuat sau y thay doi, neu khong no se bi lech nhip          
            while(input(DW)==0);   //cho nha phim
         }
      }
   }
}

void main()
{
   set_up_port_ic_chot();
   set_tris_b(0x3c);    //0011   1100 00111100
   y = 0x00;
   xuat_32led_don_4byte( 0, 0, 0, 0);
   while (true)
   {
      do
      {
      Nut_up();
      Nut_dw();      
      }
      while(input(CLR)) ; 
      xuat_32led_don_4byte( 0, 0, 0 ,0);  
      
   }
}


