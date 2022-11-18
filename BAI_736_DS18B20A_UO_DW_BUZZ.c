
#include <tv_pickit2_shift_1.c>
#INCLUDE <TV_PICKIT2_SHIFT_DS18B20.c>  
#include <tv_pickit2_shift_lcd.c>
int1 ttqn; 

unsigned INT16 gtcdt;
signed INT8 bdn;

#INT_timer1
void interrupt_timer1()    //timer 1 2^16 =  65535 => so tr�n = 65536
{
   bdn++;
   set_timer1(3036);    //20MHz bo chia 4 = 5MHz he so chia 8 (t1_div_by_8) = 625000Hz > 65536 => phai dem 10 lan
                        //65536 - 625000/10 = 3036
}
void giai_ma_gan_cho_8led_quet()
{
   led_7dq[0] = ma7doan [DS18A %10];
   led_7dq[1] = ma7doan [DS18A/10];
   led_7dq[6] = ma7doan [gtcdt %10];
   led_7dq[7] = ma7doan [gtcdt/10];   
}
void lcd_hienthi()
{

   lcd_GOTO_xy (0, 0);
   delay_us (20) ;
   lcd_data (gtcdt / 10 + 0x30); //0x30 is code ASCII number 0
   lcd_data (gtcdt % 10 + 0x30) ;
   
   lcd_GOTO_xy (0, 18);
   delay_us (20) ;
   lcd_data (DS18A / 10 + 0x30); //0x30 is code ASCII number 0
   lcd_data (DS18A % 10 + 0x30) ;
}

void so_sanh_dk_buzzer()
{
   IF ((DS18A>gtcdt)&&(ttqn==0))
   {
      ttqn = 1;
      //buzzer_on () ;
      //triac_2_off () ;
      XUAT_32LED_DON_4BYTE (0, 0, 0, 0xff);
   }

   else IF ((DS18A < gtcdt)&& (ttqn == 1))
   {
      ttqn = 0;
      //buzzer_off () ;
      XUAT_32LED_DON_4BYTE (0, 0, 0, 0);
   }

   else IF ((DS18A < gtcdt - 3)&& (ttqn == 0)) 
   //triac_2_on ();
   XUAT_32LED_DON_4BYTE (0xff, 0, 0, 0);
}

void phim_up()
{
   IF (( ! input (up))&& (gtcdt < 60))
   {
      delay_ms (20) ;
      {
         IF (!input (up))
         {
            gtcdt++;
            WHILE ( ! input (up)) ;
         }
      }
   }
}

void phim_dw()
{
   IF (( ! input (dw))&& (gtcdt > 35))
   {
      delay_ms (20) ;
      {
         IF (!input (dw))
         {
            gtcdt--;
            WHILE ( ! input (dw)) ;
         }
      }
   }
}

void main()
{
   set_up_port_ic_chot () ;
   setup_adc (adc_clock_div_32) ;
   setup_adc_ports (an0|vss_vdd) ;
   set_adc_channel (0);
   gtcdt = 35;
   xuat_4led_7doan_4so(ma7doan[gtcdt/10],ma7doan[gtcdt%10]&0x7f,ma7doan[DS18A/10],ma7doan[DS18A%10]);
   setup_timer_1(t1_internal | t1_div_by_8);
   set_timer1(3036);
   enable_interrupts(global);
   enable_interrupts(INT_timer1);
   setup_lcd ();
   WHILE (true)
   {
      IF(TOUCH_PRESENT())   DOC_GIATRI_DS18B20();
         if(DS18A!= DS18A_tam)
         {
         DS18A_tam = DS18A;
         DS18A=DS18A>>4;
         DS18A=DS18A&0X0FF;
         xuat_4led_7doan_4so(ma7doan[gtcdt/10],ma7doan[gtcdt%10]&0x7f,ma7doan[DS18A/10],ma7doan[DS18A%10]);   
         }

      phim_up () ;
      phim_dw () ;
      so_sanh_dk_buzzer () ;
      lcd_hienthi();
      
      
      //quet led
            giai_ma_gan_cho_8led_quet();
      IF (bdn<10) hien_thi_8led_7doan_quet();         //chay het 10 lan moi dc 1 giay

      ELSE
      {
         bdn = bdn-10;     //bdn = 0;
      }
   }
}


