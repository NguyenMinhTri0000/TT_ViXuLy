
//DO cot song chua chac nen cho hinh vuong di chuyen
//#include <tv_pickit2_shift_1.c>
#include <tv_pickit2_shift_1_proteus.c>
#include <tv_pickit2_shift_lcd.c>

const UNSIGNED char hang4[]={0x1f,0x11,0X11,0x11,0x1f,0,0,0};     //hinh thoi\
//!1 1 1 1 1      0x1f
//!1 0 0 0 1      0x11
//!1 0 0 0 1      0x11
//!1 0 0 0 1      0x11
//!1 1 1 1 1     0x1f
//!0 0 0 0 0      0�00
//!0 0 0 0 0              0�00
//!0 0 0 0 0               0�00  
signed INT8 i, j, vitri_x, vitri_y;

void hien_hinh_vuong(INT8 vitri_y, int8 vitri_x)
{
   lcd_command (0x50); //vi tri dau trang 148
   FOR (i = 0; i < 8; i++) { lcd_data (hang4[i]); } //0x40 luu hang2[0] 0x41 luu hang2[1]...
   lcd_GOTO_xy (vitri_y, vitri_x);  //vi tri tao ma
   lcd_data (2);   //dia chi ki tu trang 148
}

void main()
{
   set_up_port_ic_chot () ;
   setup_lcd () ;
   
   WHILE (true)
   {
      FOR (j = 0; j < 20; j++)
      {
         //trai sang phai
         hien_hinh_vuong (0, j);
         lcd_GOTO_xy (0, j - 1);
         lcd_data (" ") ;
         delay_ms (100);
      }

      FOR (j = 19; j > -1; j--)
      {
         //trai sang phai
         hien_hinh_vuong (0, j);
         lcd_GOTO_xy (0, j + 1);
         lcd_data (" ") ;
         delay_ms (100);
      }

   }
}

