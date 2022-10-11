
#include <tv_pickit2_shift_1.c>

signed INT8 giay, bdn, phut, gio;

#INT_timer1
void interrupt_timer1()    //timer 1 2^16 =  65535 => so tràn = 65536
{
   bdn++;
   set_timer1(3036);    //20MHz bo chia 4 = 5MHz he so chia 8 (t1_div_by_8) = 625000Hz > 65536 => phai dem 10 lan
                        //65536 - 625000/10 = 3036
}

void giai_ma_gan_cho_8led_quet()
{
   led_7dq[0] = ma7doan [giay%10];
   led_7dq[1] = ma7doan [giay/10];
   led_7dq[2] = ma7doan [phut%10];
   led_7dq[3] = ma7doan [phut/10];
   led_7dq[4] = ma7doan [gio%10];
   led_7dq[5] = ma7doan [gio/10];   
}
void main()
{
   set_up_port_ic_chot();
   //khoi tao ngat
   //setup_timer_1(t1_internal | t1_div_by_1); //chay nhanh hon de quan sat mo phong
   setup_timer_1(t1_internal | t1_div_by_8);   
   set_timer1(3036);
   enable_interrupts(global);
   enable_interrupts(INT_timer1);
   
   phut =0;   
   giay =0;
   gio =0;   
   bdn=0;

   WHILE(true)
   {
      giai_ma_gan_cho_8led_quet();
      IF (bdn<10) hien_thi_8led_7doan_quet();      //chay het 10 lan moi dc 1 giay

      ELSE
      {
         bdn = bdn-10;     //bdn = 0;
         giay++;
         IF (giay==60) 
         {
            giay =0;
            phut ++;
         }
         IF (phut==60) 
         {
            phut =0;
            gio++;
         }       
         IF (gio==60) 
         {
            gio = 0;
         }          
      }
   }
}

