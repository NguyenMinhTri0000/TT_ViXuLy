 //use lcdgoto(x,y)
#include <tv_pickit2_shift_1_proteus.c>
#include <tv_pickit2_shift_lcd.c>
void main()
{ 
set_up_port_ic_chot(); 
 setup_lcd(); 
 
 lcd_command(lcd_addr_line1);
 lcd_data("A                  B");    // if > 20 => line 1 -> line 3, line 2 -> line 4

 lcd_command(lcd_addr_line2); 
 lcd_data("                    "); 

 lcd_command(lcd_addr_line3); 
 lcd_data("                    "); 
 
 lcd_command(lcd_addr_line4); 
 lcd_data("C                  D"); 

 while(true);
 }
