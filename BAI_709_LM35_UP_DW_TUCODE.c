//CUA THAY XIN HON, TAI CODE NH�M
#include <tv_pickit2_shift_1.c>


unsigned INT8 j, solan=100, GTCDT ;
unsigned INT16 lm35a;
int1 ttqn=0;
void phim_up()
{
   if(input(bt0)==0)    //kiem tra lan 1
   {
      delay_ms(50);
     
         if(input(bt0)==0)    //kiem tra lan 2
         {
         //lenh chuong trinh
            GTCDT++;
            while(input(bt0)==0);   //cho nha phim
         }   
   }
}
void phim_down()
{
   if(input(bt1)==0)    //kiem tra lan 1
   {
      delay_ms(50);
     
         if(input(bt1)==0)    //kiem tra lan 2
         {
         //lenh chuong trinh
            GTCDT--;
            while(input(bt1)==0);   //cho nha phim
         }   
   }
}
void so_sanh_dk_buzzer()
{
   IF ((lm35a>GTCDT))
   {
      ttqn = 1;
//!      buzzer_on () ;
      XUAT_32LED_DON_4BYTE (0, 0, 0, 0XFF);
     // triac_2_off () ;
//!     XUAT_32LED_DON_4BYTE (0,0,0,0);
   }

   else IF ((lm35a < (GTCDT-5))&& (ttqn == 1))
   {
      ttqn = 0;
//!      buzzer_off () ;
      XUAT_32LED_DON_4BYTE (0, 0, 0, 0);
   }

   IF ((lm35a < (GTCDT-5))&& (ttqn == 0)) 
   //triac_2_on ();
   XUAT_32LED_DON_4BYTE (0xff, 0, 0, 0);
}

void main()
{
   set_up_port_ic_chot () ;
   setup_adc (adc_clock_div_32) ;
   setup_adc_ports (an0|vss_vdd);
   set_adc_channel (0);
   ttqn = 0;

   WHILE (true)
   {

   if(GTCDT<60) phim_up();    
   if(GTCDT>35) phim_down();     
      lm35a = 0;
      FOR (j = 0; j<solan; j++)
      {
         lm35a = lm35a + read_adc ();
         delay_ms (1) ;
      }

      lm35a = lm35a / 2.046;
      lm35a = lm35a / solan;
      xuat_4led_7doan_4so (ma7doan[GTCDT/ 10],ma7doan[GTCDT % 10]&0X7F,ma7doan[ lm35a / 10], ma7doan[lm35a % 10]);
      so_sanh_dk_buzzer () ;
   }
}


