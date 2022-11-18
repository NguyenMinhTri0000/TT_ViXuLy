
//NEN DUNG CACH 2
//dao se bi ngung
#include <tv_pickit2_shift_1.c>
//!#include <tv_pickit2_shift_1_proteus.c>

unsigned INT8 t0;
unsigned INT8 donvi, chuc, tram, san_pham;
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
         set_timer0 (100 - san_pham);
         WHILE (input (bt0) == 0); //cho nha phim
      }
   }
}

void giai_ma_hien_thi (UNSIGNED int16 tam)
{
   donvi = ma7doan[tam % 10];
   chuc = ma7doan[tam / 10 % 10];
   tram = ma7doan[tam / 100];

   IF (tram == 0xc0) //ma 7 doan cua so 0
   {
      tram = 0xff; //tat het led 7 doan (anode chung)
      IF (chuc == 0xc0) chuc = 0xff;
   }

   xuat_4led_7doan_3so (tram, chuc, donvi);
}

void dem_xuong(UNSIGNED int8  gioi_han_tren, gioi_han_duoi)    //ket hop bien TOAN CUC san_pham nam trong gioi han tren v� duoi
{
   t0 = get_timer0 ();
   //!      UNSIGNED int8 san_pham = 6;

   IF (t0 == 1)
   {
      set_timer0 (0);
      san_pham--;
      IF (san_pham == gioi_han_duoi - 1) san_pham = gioi_han_tren - 1;
   }

   giai_ma_hien_thi (san_pham);
}

void dem_len(UNSIGNED int8  gioi_han_duoi, gioi_han_tren)    //ket hop bien TOAN CUC san_pham nam trong gioi han tren v� duoi
{
   t0 = get_timer0 ();
   //!      UNSIGNED int8 san_pham = 6;

   IF (t0 == 1)
   {
      set_timer0 (0);
      san_pham++;
      IF (san_pham == gioi_han_tren + 1) san_pham = gioi_han_duoi + 1;
   }

   giai_ma_hien_thi (san_pham);
}

void main()
{
   set_up_port_ic_chot ();
   setup_timer_0 (t0_ext_l_to_h|t0_div_1|t0_8_bit);
   set_timer0 (0);
   san_pham = 5;
   tt = 0;

   WHILE (true)
   {
      phim_bt0 ();
      t0 = get_timer0 ();
      
      IF (tt == 0) 
      {
      dem_xuong(100, 1);
      XUAT_32LED_DON_1DW(0xff);
      }
      IF (tt == 1) dem_len(1, 100);
      XUAT_32LED_DON_1DW(0);
   }
}

