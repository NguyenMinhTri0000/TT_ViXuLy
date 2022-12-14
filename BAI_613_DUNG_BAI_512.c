
#include <tv_pickit2_shift_1.c>
#include <tv_pickit2_shift_lcd.c>
signed INT8 giay,bdn, gio, phut;
#INT_timer1
void interrupt_timer1()    //timer 1 2^16 =  65535 => so tr?n = 65536
{
   bdn++;
   set_timer1 (3036); //20MHz bo chia 4 = 5MHz he so chia 8 (t1_div_by_8) = 625000Hz > 65536 = > phai dem 10 lan
   //65536 - 625000 / 10 = 3036
}

void lcd_hienthi_dongho()
{
   lcd_GOTO_xy (0, 12);
   lcd_data (gio / 10 + 0x30); lcd_data (gio % 10 + 0x30);
   lcd_data (' ');
   lcd_data (phut / 10 + 0x30); lcd_data (phut % 10 + 0x30);
   lcd_data (' ');
   lcd_data (giay / 10 + 0x30); lcd_data (giay % 10 + 0x30);
}

void main()
{
   set_up_port_ic_chot () ;
   //khoi tao ngat
   setup_timer_1 (t1_internal|t1_div_by_8) ;
   set_timer1 (3036) ;
   enable_interrupts (global) ;
   enable_interrupts (INT_timer1) ;
   
   giay = 0;
   gio = 0;
   phut = 0;
   bdn = 0;
   WHILE (true)
   {
      IF (bdn < 10) lcd_hienthi_dongho () ;  //chay het 10 lan moi dc 1 giay
      ELSE
      {
         bdn = bdn - 10; //bdn = 0;
         giay++;
         IF (giay == 60)
         {
            giay = 0;
            phut++;
         }

         IF (phut == 60)
         {
            phut = 0;
            gio++;
            IF (gio == 60)
            {
               gio = 0;
            }
         }
      }
   }
}


