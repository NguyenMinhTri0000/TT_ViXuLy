// lam o nha, proteus chay khong duoc, chua thu
//!#include <tv_pickit2_shift_1.c>
#include <tv_pickit2_shift_1_proteus.c>
#include <tv_pickit2_shift_lcd.c>
signed INT8 giay, bdn;
unsigned INT16 t0,DV,CH,TR, i, tt_counter_dao, san_pham;
unsigned INT1 tt = 0;
#INT_timer1
void interrupt_timer1()    //timer 1 2^16 =  65535 => so tr�n = 65536
{
   bdn++;
   set_timer1 (3036); //20MHz bo chia 4 = 5MHz he so chia 8 (t1_div_by_8) = 625000Hz > 65536 = > phai dem 10 lan
   //65536 - 625000 / 10 = 3036
}

void giai_ma_gan_cho_8led_quet()
{
   led_7dq[6] = ma7doan [giay % 10];
   led_7dq[7] = ma7doan [giay / 10];
   
   led_7dq[0] = ma7doan [t0 % 10];
   led_7dq[1] = ma7doan [t0 / 10];   
}

void hien_thi_quet_led()
{
   giai_ma_gan_cho_8led_quet () ;
   IF (bdn < 10) hien_thi_8led_7doan_quet (); //chay het 10 lan moi dc 1 giay
   ELSE
   {
      bdn = bdn - 10; //bdn = 0;
      giay++;
      IF (giay == 60)
      {
         giay = 0;
      }
   }
}
void hienthi_lcd()
{
   lcd_GOTO_xy (0, 0);
   delay_us (20) ;
   lcd_data (giay / 10 + 0x30); //0x30 is code ASCII number 0
   lcd_data (giay % 10 + 0x30) ;
   //couter
   DV = T0 % 10 + 0X30;
   CH = T0 / 10 % 10 + 0X30;
   TR = T0 / 100 + 0X30;
   IF (TR == 0X30)   //0x30 l� so 0
   {
      TR = 32; //0X20 l� khoang trong
      IF (CH == 0X30) CH = 0X20;
   }
   
   lcd_GOTO_xy(0,17);
   lcd_data (TR);
   lcd_data (CH);
   lcd_data (DV);   
}
void hien_thi_led_7_doan()
{
         xuat_4led_7doan_4so(ma7doan[t0/10], ma7doan[t0%10], ma7doan[giay/10], ma7doan[giay%10]);
}
void phim_bt0()      //dem, dung dem
{
   if(input(bt0)==0)    //kiem tra lan 1
   {
      delay_ms(50);
     
         if(input(bt0)==0)    //kiem tra lan 2
         {
         //lenh chuong trinh
            tt = ~ tt;         
            while(input(bt0)==0);   //cho nha phim
         }
      
   }
}
void phim_bt1()
{
   if(input(bt1)==0)    //kiem tra lan 1
   {
      delay_ms(50);
     
         if(input(bt1)==0)    //kiem tra lan 2
         {
         //lenh chuong trinh
            trang_thai = ~ trang_thai;         
            while(input(bt1)==0);   //cho nha phim
         }
      
   }
}
void lcd_hienthi_so_z_toado_xy(SIGNED int8 lcd_so, x1, y1)
{
   lcd_GOTO_xy (x1, y1) ;
   FOR (i = 0; i < 6; i++) //mot so LCD duoc tao thanh tu 6 phan, 3 tren, 3 duoi
   {
      IF (i == 3) lcd_goto_xy (x1 + 1, y1);
      lcd_data (lcd_so_x[lcd_so][i]) ;
   }
}
void hien_thi_so_lon()
{
         lcd_command (0x40) ;
         FOR (i = 0; i < 64; i++) { lcd_data (lcd_ma_8doan[i]);  }    
         lcd_hienthi_so_z_toado_xy (giay/10, 2, 0);      //chuc
         lcd_hienthi_so_z_toado_xy (giay%10, 2, 4);      //don vi         
         lcd_hienthi_so_z_toado_xy (t0/10, 2, 12);      //chuc
         lcd_hienthi_so_z_toado_xy (t0%10, 2, 16);      //don vi
         IF (t0 >= 1000) set_timer0 (1) ;
}
void dem_couter()
{
      t0 = get_timer0 ();
      //khong bo if nay vao trong while(input(on) v� do la khi giu phim n� moi chay

      xuat_4led_7doan_giaima_xoa_so0 (t0) ;
      IF (t0 >= 101) set_timer0 (1);
 
      If(tt == 0)
      {
         setup_timer_0 (t0_ext_l_to_h|t0_div_1|t0_8_bit);      
//!         xuat_32led_don_4byte(1, 1, 1 , 1);         
      }
      
      else if(tt == 1)
      {
         setup_timer_0 (t0_off);  
//!         xuat_32led_don_4byte(0, 0, 0, 0);      
      } 

}

void dem_giay()
{

}
void main()
{
   set_up_port_ic_chot () ;
   setup_lcd ();
   setup_timer_0 (t0_off);
   set_timer0 (0);   
   //khoi tao ngat
   //setup_timer_1 (t1_internal|t1_div_by_1); //chay nhanh hon de quan sat mo phong
   setup_timer_1 (t1_internal|t1_div_by_8);
   set_timer1 (3036) ;
   
   enable_interrupts (global) ;
   enable_interrupts (INT_timer1) ;
   
   giay = 0;
   bdn = 0;
   t0 = 0;
   WHILE (true)
   {
      phim_bt0(); //dung dem couter
      phim_bt1(); //dung dem giay
      hien_thi_led_7_doan();
      hien_thi_quet_led() ;
      hienthi_lcd();
      dem_couter();
      hien_thi_so_lon();
   }
}


