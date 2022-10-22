
#include <tv_pickit2_shift_1.c>
#include <tv_pickit2_shift_glcd128x64.c>

void main()
{
   set_up_port_ic_chot();
   setup_glcd(glcd_text_mode);
   glcd_command(glcd_addr_line1);
   glcd_data("dh-supham kt hcm");
   glcd_command(glcd_addr_line2);
   glcd_data("bo mon dien tu");
   glcd_command(glcd_addr_line3);
   glcd_data("cong nghiep ");
   glcd_command(glcd_addr_line4);
   glcd_data("thuc hanh vdk");
   WHILE(true);
}

