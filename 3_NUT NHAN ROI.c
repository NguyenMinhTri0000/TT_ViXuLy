
#include    <tv_pickit2_shift_1.c> 

unsigned INT8 y; 
  
void phim_inv() 
{
   IF (!input (inv))
   {
      delay_ms (20);
      {
         IF (!input (inv))
         {
            y = ~y;
            xuat_32led_don_4byte (0, 0, 0, y);
            WHILE ( ! input (inv));
         }
      }
   }
}

  
void main() 
{
   
   set_up_port_ic_chot ();
   set_tris_b (0x3c);
   y = 0x00;
   xuat_32led_don_4byte (0, 0, 0, 0);

   WHILE (true)
   {
      WHILE (input (on));
      y = 0x0f;
      xuat_32led_don_4byte (0, 0, 0, y);
      DO{ phim_inv (); }
      WHILE (input (off));
      xuat_32led_don_4byte (0, 0, 0, 0);
   }
}

