//!dem nguoc ve 0 sang 100 dung
//!khi dao chieu bi lech vai giay
#include <tv_pickit2_shift_1.c>
//!#include <tv_pickit2_shift_1_proteus.c>
unsigned INT8 t0;
unsigned INT8 donvi, chuc, tram;
unsigned INT1 tt;
void phim_bt0()
{                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
   IF (input (bt0) == 0) //kiem tra lan 1
   {
      delay_ms (50);
      
      IF (input (bt0) == 0) //kiem tra lan 2
      {
         //lenh chuong trinh
         tt = ~ tt;
         set_timer0(100 - get_timer0());
         WHILE (input (bt0) == 0); //cho nha phim
      }
   }
}

void giai_ma_hien_thi (UNSIGNED int16 tam)
{
   donvi = ma7doan[tam % 10];
   chuc = ma7doan[tam / 10 % 10];
   tram = ma7doan[tam / 100];
   IF (tram == 0xc0)  //ma 7 doan cua so 0
   {
      tram = 0xff;  //tat het led 7 doan (anode chung)
      IF (chuc == 0xc0) chuc = 0xff;
   }

   xuat_4led_7doan_3so (tram, chuc, donvi);
}

void main()
{
   set_up_port_ic_chot () ;
   setup_timer_0 (t0_ext_l_to_h|t0_div_1|t0_8_bit);
   set_timer0 (0);
   WHILE (true)
   {
      IF (tt == 1)
      {
         t0 = 99 - get_timer0 () ;
         giai_ma_hien_thi (t0);         
         IF (t0 == 0) set_timer0(99);
      }

      IF (tt == 0)
      {
         t0 = get_timer0 ();
         giai_ma_hien_thi (t0);         
         IF (t0 >= 101) set_timer0(1);
      }
      phim_bt0();

   }
}


