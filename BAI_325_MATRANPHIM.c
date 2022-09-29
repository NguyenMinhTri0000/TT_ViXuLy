//nhan sang dan, roi nhan tat dan => n� kh�ng tat lien, m� sang them 1 led roi moi tat. Nguoc lai cung vay
 //phai xuat sau y thay doi, neu khong no se bi lech nhip
#include <tv_pickit2_shift_1.c>
#include <tv_pickit2_shift_key4x4_138.c>
signed int8 mp;      //signed l� bao nhieu den bao nhieu
unsigned int16 y, TT;
void TT1()
{
   mp = key_4x4_dw();
   if(mp!=0xff)
      {
         delay_ms(200);    //giam toc do kt phim
         //xu li chuc nang
         if(mp == 0)       //button up
         {
            xuat_32led_don_2word(0, y);
            delay_ms(200);
            y = (y<<1)+1;               
         }
         else if(mp == 1)       //button dw
         {
            xuat_32led_don_2word(0, y);               
            delay_ms(200);
            y = (y>>1);            
         }
         else if(mp == 2)       //button clr
         {
            xuat_32led_don_2word(0, 0);    
            TT = 1;
         }         

      }
}

void TT2()
{
   mp = key_4x4_dw();
   if(mp!=0xff)
      {
         delay_ms(200);    //giam toc do kt phim
         //xu li chuc nang
         if(mp == 0)       //button up
         {

            delay_ms(200);
            y = (y>>1)+0x8000;   
            xuat_32led_don_2word(0, y);            
         }
         else if(mp == 1)       //button dw
         {              
            delay_ms(200);
            y = (y<<1);            
            xuat_32led_don_2word(0, y);             
         }
         else if(mp == 2)       //button clr
         {
            xuat_32led_don_2word(0, 0);
            TT = 0;
         }         

      }
}
void main()
{
set_up_port_ic_chot();
set_tris_b(0x3c); //RB2 - RB5
y = 0;
TT = 0;
   while(true)
   {
   if(TT == 0) TT1();
   else if (TT == 1) TT2();
   }
}

