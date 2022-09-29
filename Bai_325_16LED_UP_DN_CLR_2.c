
#include <tv_pickit2_shift_1.c>
unsigned int16 y, TT;

void TT0()
{
//nut up
   if(input(UP)==0)    //kiem tra lan 1
   {
      delay_ms(20);
      {
         if(input(UP)==0)    //kiem tra lan 2
         {
            //lenh chuong trinh

               delay_ms(200);
               y = (y<<1)+1;
               xuat_32led_don_2word(0, y);               
           // }         
            while(input(UP)==0);   //cho nha phim
         }
      }

   }
//nut dw
   if(input(DW)==0)    //kiem tra lan 1
   {
      delay_ms(20);
      {
         if(input(DW)==0)    //kiem tra lan 2
         {
            //lenh chuong trinh
             
               delay_ms(200);
               y = (y>>1); 
               xuat_32led_don_2word(0, y);                 
            while(input(DW)==0);   //cho nha phim
         }
      }
   }
}

void TT1()
{
//nut up
   if(input(UP)==0)    //kiem tra lan 1
   {
      delay_ms(20);
      {
         if(input(UP)==0)    //kiem tra lan 2
         {
            //lenh chuong trinh

               delay_ms(200);
               y = (y>>1)+0x8000;
               xuat_32led_don_2word(0, y);               
           // }         
            while(input(UP)==0);   //cho nha phim
         }
      }

   }
//nut dw
   if(input(DW)==0)    //kiem tra lan 1
   {
      delay_ms(20);
      {
         if(input(DW)==0)    //kiem tra lan 2
         {
            //lenh chuong trinh
              
               delay_ms(200);
               y = (y<<1);     
               xuat_32led_don_2word(0, y);                
            while(input(DW)==0);   //cho nha phim
         }
      }
   }
}
void Nut_clr()
{
   if(input(CLR)==0)    //kiem tra lan 1
   {
      delay_ms(20);
      {
         if(input(CLR)==0)    //kiem tra lan 2
         {
         //lenh chuong trinh
         y = 0x0000;
         TT  = ~ TT;
         xuat_32led_don_2word( 0, 0);          
            while(input(CLR)==0);   //cho nha phim
         }
      }
   }

}
void main()
{
   set_up_port_ic_chot();
   set_tris_b(0xff);    //0011   1100
   y = 0x00;
   TT = 0;
   xuat_32led_don_2word( 0, 0);
   while (true)
   {
      Nut_clr();
      if (TT == 0)
      TT0();
      else
      TT1();
   }
}


