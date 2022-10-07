
//#include <tv_pickit2_shift_1.c>
#include <tv_pickit2_shift_1_proteus.c>
#include <tv_pickit2_shift_lcd.c>
const UNSIGNED char hang2[]={0x0a,0x15,0x11,0x11,0x0a,0x04,0,0};     //hinh trai tim
//!0 1 0 1 0      0x0A
//!1 0 1 0 1      0X15
//!1 0 0 0 1      0�11
//!1 0 0 0 1      0�11
//!0 1 0 1 0      0�0A
//!0 0 1 0 0      0�04
//!               0�00
//!               0�00  
const UNSIGNED char hang3[]={0x04,0X0A,0X11,0X0A,0x04,0,0,0};     //hinh thoi
//!0 0 1 0 0      0x04
//!0 1 0 1 0      0X0A
//!1 0 0 0 1      0�11
//!0 1 0 1 0      0X0A
//!0 0 1 0 0     0x04
//!0 0 0 0 0      0�00
//!0 0 0 0 0              0�00
//!0 0 0 0 0               0�00  
const UNSIGNED char hang4[]={0x1f,0x11,0X11,0x11,0x1f,0,0,0};     //hinh thoi\
//!1 1 1 1 1      0x1f
//!1 0 0 0 1      0x11
//!1 0 0 0 1      0x11
//!1 0 0 0 1      0x11
//!1 1 1 1 1     0x1f
//!0 0 0 0 0      0�00
//!0 0 0 0 0              0�00
//!0 0 0 0 0               0�00  
signed INT8 i;

void show_heart()
{
   lcd_command(0x40);      //vi tri dau trang 148
   FOR (i=0;i<8;i++) { lcd_data(hang2[i]); }       //0x40 luu hang2[0] 0x41 luu hang2[1]...
   lcd_GOTO_xy(1,10);       //vi tri tao ma   
   lcd_data(0);              //dia chi ki tu trang 148
}
void hien_hinh_thoi()
{
   lcd_command(0x47);      //vi tri dau trang 148
   FOR (i=0;i<8;i++) { lcd_data(hang3[i]); }       //0x40 luu hang2[0] 0x41 luu hang2[1]...
   lcd_GOTO_xy(2,10);       //vi tri tao ma   
   lcd_data(1);            //dia chi ki tu trang 148
}
void hien_hinh_vuong()
{
   lcd_command(0x50);      //vi tri dau trang 148
   FOR (i=0;i<8;i++) { lcd_data(hang4[i]); }       //0x40 luu hang2[0] 0x41 luu hang2[1]...
   lcd_GOTO_xy(3,10);       //vi tri tao ma   
   lcd_data(2);            //dia chi ki tu trang 148
}
void main()
{
   set_up_port_ic_chot();
   setup_lcd();
   lcd_GOTO_xy(0,0);
   lcd_data(" HIEN THI 3 KY TU ");
   show_heart();
   hien_hinh_thoi();  
   hien_hinh_vuong()   ;
   WHILE(true);
}


