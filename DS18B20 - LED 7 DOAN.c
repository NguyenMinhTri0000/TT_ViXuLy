
#include    <tv_pickit2_shift_1.c>         
#include <tv_pickit2_shift_ds18b20.c> 
            

void main() 
{
   
   set_up_port_ic_chot ();
   khoi_tao_ds18b20 ();
   ds18a_tam = 0;
   xuat_4led_7doan_giaima_xoa_so0 (0);

   WHILE (true)
   {
      IF (touch_present ()) {doc_giatri_ds18b20 (); }
      IF (ds18al != ds18a_tam)
      {
         ds18a_tam = ds18al;
         ds18a = ds18a>>4;
         ds18a = ds18a&0x0ff;
         xuat_4led_7doan_giaima_xoa_so0 (ds18a);
      }

      
      DELAY_MS (100); //NEN THEM VAO KHI MO PHONG DE KHONG BI LOI QUA KHA NANG XU LY CUA CPU
   }
}

