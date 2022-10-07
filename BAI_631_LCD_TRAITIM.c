
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
signed INT8 i;
void main()
{
   set_up_port_ic_chot();
   setup_lcd();
   lcd_GOTO_xy(0,0);
   lcd_data(" hien thi trai tim ");
   lcd_command(0x40);      //vi tri dau trang 148
   FOR (i=0;i<8;i++) { lcd_data(hang2[i]); }       //0x40 luu hang2[0] 0x41 luu hang2[1]...
   lcd_GOTO_xy(1,0);       //vi tri tao ma   
   lcd_data(0);               //dia chi ki tu trang 148
   WHILE(true);
}


