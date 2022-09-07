//NEN CHON DELAY 200MS DE MO PHONG KHONG BI LOI XU LY QUA TAI CPU


#include    <tv_pickit2_shift_1.c> 

unsigned INT8  i,j; 
unsigned INT32 y; 
  
void sang_tat_32led_5lan() 
{
   FOR (j = 0; j < 5; j++)
   {
      xuat_32led_don_4byte (0, 0, 0, 0);
      delay_ms (200);
      xuat_32led_don_4byte (0xff, 0xff, 0xff, 0xff);
      delay_ms (200);
   }
}

void sang_tat_dan_pst_32led_2lan() 
{
   
   FOR (j = 0; j < 2; j++)
   {
      FOR (i = 0; i < 32; i++)
      {
         xuat_32led_don_1dw (y);
         delay_ms (200);
         y = (y<<1) + 1;
      }

      FOR (i = 0; i < 32; i++)
      {
         xuat_32led_don_1dw (y);
         delay_ms (200);
         y = (y<<1);
      }
   }
}

  
void sang_tat_dan_tsp_32led_2lan() 
{
   
   FOR (j = 0; j < 2; j++)
   {
      FOR (i = 0; i < 32; i++)
      {
         xuat_32led_don_1dw (y);
         delay_ms (200);
         y = (y>>1) + 0x80000000;
      }

      FOR (i = 0; i < 32; i++)
      {
         xuat_32led_don_1dw (y);
         delay_ms (500);
         y = (y>>1);
      }
   }
}

  
void main() 
{
   
   set_up_port_ic_chot ();
   y = 0x00000000;

   WHILE (true)
   {
      sang_tat_32led_5lan ();
      sang_tat_dan_pst_32led_2lan ();
      sang_tat_32led_5lan ();
      sang_tat_dan_tsp_32led_2lan ();
   }
}

