
//#include <tv_pickit2_shift_1.c>
#include <tv_pickit2_shift_1_proteus.c>
#include <tv_pickit2_shift_lcd.c>
const UNSIGNED char hang2[]={0x0a,0x15,0x11,0x11,0x0a,0x04,0,0};
signed INT8 i, j;
void main()
{
   set_up_port_ic_chot () ;
   setup_lcd () ;
   lcd_GOTO_xy (0, 0) ;
   lcd_data (" hien thi trai tim ") ;
   FOR (j = 0; j < 20; J++)
   {
      lcd_command (0x40) ;
      FOR (i = 0; i < 8; i++) { lcd_data (hang2[i]);  }
      lcd_GOTO_xy (1, j) ;
      lcd_data (0);     //dia chi ki tu trang 148
   }

   WHILE (true) ;
}


