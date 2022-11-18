//NEU CHI HIEN LED7, KHONG HIEN LED QUET LAI KHONG DUOC

#include <tv_pickit2_shift_1.c>
//!#include <tv_pickit2_shift_1_proteus.c>
signed INT8 giay,bdn;
int1 UD_Timer, TT_DC;
#INT_timer1
void interrupt_timer1()    //timer 1 2^16 =  65535 => so tr�n = 65536
{
   bdn++;
   set_timer1(3036);    //20MHz bo chia 4 = 5MHz he so chia 8 (t1_div_by_8) = 625000Hz > 65536 => phai dem 10 lan
                        //65536 - 625000/10 = 3036
}
void phim_ON_OFF()
{
   IF (!input (BT1))
   {
      delay_ms (20);
      IF (!input (BT1))
      {
         UD_Timer = ~UD_Timer; 
         WHILE ( ! input (BT1)) ;
      }
   }
}
void phim_dung()
{
   IF (!input (BT0))
   {
      delay_ms (20);
      IF (!input (BT0))
      {
         TT_DC = ~TT_DC; 
         WHILE ( ! input (BT0)) ;
      }
   }
}
void Timer(So_Nho, So_Lon)
{
         IF (bdn < 10)
         {
         hien_thi_8led_7doan_quet();  
         }

         ELSE
         {
            bdn = bdn - 10;      // tai sao - 10

            IF (UD_Timer == 0)
            {
               giay++;
               IF (giay > So_Lon) giay = So_Nho;
            }

            else IF (UD_Timer == 1)
            {
               giay--;
               IF (giay < So_Nho) giay = So_Lon;
            }


         }
}
void giai_ma_gan_cho_8led_quet()
{
   led_7dq[0] = ma7doan [giay %10];
   led_7dq[1] = ma7doan [giay/10];
}

void main()
{
   set_up_port_ic_chot();
   //khoi tao ngat
//!   setup_timer_1(t1_internal | t1_div_by_8);
   set_timer1(3036);
   enable_interrupts(global);
   enable_interrupts(INT_timer1);
   
   giay =0;
   bdn=0;

   WHILE(true)
   {
      phim_ON_OFF();
      phim_dung();
      if(TT_DC == 0)
      {
         setup_timer_1(t1_internal | t1_div_by_8);
      }
      else
      {
         setup_timer_1(T1_DISABLED);
      }
      
   
      giai_ma_gan_cho_8led_quet();
      xuat_4led_7doan_2so(ma7doan[giay/10], ma7doan[giay%10]);      
      Timer(4, 52);
   }
}

