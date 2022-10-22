//sua
#include <tv_pickit2_shift_1.c>
//!#include <tv_pickit2_shift_1_proteus.c>

unsigned INT8 t0;
unsigned INT8 donvi, chuc, tram;

int1 TT_start_stop;

void phim_start_stop()
{
   IF (!input (BT1))
   {
      delay_ms (20);
      IF (!input (BT1))
      {
         TT_start_stop = ~TT_start_stop; 
         WHILE ( ! input (BT1)) ;
      }
   }
}

void phim_CLR()
{
   IF (!input (CLR))
   {
      delay_ms (20);
      IF (!input (CLR))
      {
         SET_TIMER0(0); 
         WHILE ( ! input (CLR)) ;
      }
   }
}

void giai_ma_hien_thi (UNSIGNED int16 tam)
{
   donvi = ma7doan[tam %10];
   chuc = ma7doan[tam/10%10];
   IF (chuc==0xc0) chuc=0xff;
   xuat_4led_7doan_4so(0xff,0xff,chuc,donvi);
}

void main()
{  
   set_up_port_ic_chot();
   setup_timer_0 (t0_ext_l_to_h | t0_div_1|t0_8_bit);
   set_timer0(0);
   TT_start_stop = 0;

   WHILE(true)
   {
     
      t0=get_timer0();
      giai_ma_hien_thi (t0);
      HIEN_THI_8LED_7DOAN_QUET();
      
      IF (t0>=100) set_timer0(0);
      LED_7DQ[0]=MA7DOAN[T0%10];
      LED_7DQ[1]=MA7DOAN[T0/10];
      
      phim_start_stop();
      PHIM_CLR();
      
      IF (TT_start_stop == 1)
      {
         setup_timer_0 (t0_ext_l_to_h|t0_div_1|t0_8_bit);          
         xuat_32led_don_4byte (0XFF, 0XFF, 0XFF, 0XFF);
      }
      ELSE 
      {
         setup_timer_0 (t0_OFF);
         xuat_32led_don_4byte (0, 0, 0, 0);
      }
   }
}


