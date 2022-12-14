
#include <tv_pickit2_shift_1.c>
signed INT8 gio,phut,giay,bdn;
unsigned INT8 gia_tri_mod,i;
#INT_timer1
void interrupt_timer1()
{
   bdn++;
   set_timer1(3036);
}

void giai_ma_gan_cho_8led_quet()
{
   led_7dq[0]= ma7doan [giay %10];
   led_7dq[1]= ma7doan [giay /10];
   led_7dq[3]= ma7doan [phut %10];
   led_7dq[4]= ma7doan [phut /10];
   led_7dq[6]= ma7doan [gio %10];
   led_7dq[7]= ma7doan [gio /10];   
   IF (gia_tri_mod==1) led_7dq[6]=led_7dq[6] & 0x7f;     //0X7f la dau cham, cham o dau chinh o do
   else IF (gia_tri_mod==2) led_7dq[3]=led_7dq[3] & 0x7f;
   else IF (gia_tri_mod==3) led_7dq[0]=led_7dq[0] & 0x7f;
}

void delay_hienthi()
{
   FOR(i=0;i<100;i++) hien_thi_8led_7doan_quet();     //1 lan quet l? delay 0.2ms =>100 lan l? 20ms => tao delay
}

void phim_mod()      //bt3
{
   IF (!input(mod))        
   {
      delay_hienthi();
      IF(!input(mod))
      {
         gia_tri_mod++;
         IF (gia_tri_mod>=4) gia_tri_mod=0;
         giai_ma_gan_cho_8led_quet();
         DO{ hien_thi_8led_7doan_quet(); }
         WHILE(!input(mod));
      }
   }
}

void phim_up()    //bt0
{
   IF (!input(up))
   {
      delay_hienthi();
      IF(!input(up))
      {
         SWITCH (gia_tri_mod)
         {
            case 1: IF (gio==23) gio=0;
            ELSE gio++;
            BREAK;
            case 2: IF (phut==59) phut=0;
            ELSE phut++;
            BREAK;
            case 3: IF (giay==59) giay=0;
            ELSE giay++;
            BREAK;
            DEFAULT: break;
         }

         giai_ma_gan_cho_8led_quet();
         DO{ hien_thi_8led_7doan_quet(); }
         WHILE(!input(up));
      }
   }
}

void phim_dw()    //bt1
{
   IF (!input(dw))
   {
      delay_hienthi();
      IF(!input(dw))
      {
         SWITCH (gia_tri_mod)
         {
            case 1: IF (gio==0) gio=23;
            ELSE gio--;
            BREAK;
            case 2: IF (phut==0) phut=59;
            ELSE phut--;
            BREAK;
            case 3: IF (giay==0) giay=59;
            ELSE giay--;
            BREAK;
            DEFAULT: break;
         }

         giai_ma_gan_cho_8led_quet();
         DO{ hien_thi_8led_7doan_quet(); }
         WHILE(!input(dw));
      }
   }
}

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void main()
{
   set_up_port_ic_chot();
   setup_timer_1(t1_internal | t1_div_by_8);
   set_timer1(3036);
   enable_interrupts(global);
   enable_interrupts(INT_timer1);;
   giay =0x00; phut=0; gio=0; gia_tri_mod=0;
   WHILE(true)
   {
      giai_ma_gan_cho_8led_quet();
      IF(bdn<10)      //chay het 10 lan moi dc 1 giay
      {
         hien_thi_8led_7doan_quet();
         phim_mod();
         phim_up();
         phim_dw();
      }

      ELSE
      {
         bdn = bdn-10;
         giay++;
         IF (giay==60)
         {
            giay =0;
            phut++;
            IF (phut==60)
            {
               phut=0;
               gio++;
               IF (gio==24) gio =0;
            }
         }
      }
   }
}


