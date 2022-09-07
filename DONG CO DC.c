
#include <tv_pickit2_shift_1.c> 
#include <tv_pickit2_shift_dc_motor.c> 

void phim_inv() 
{
   IF (!input (inv))
   {
      delay_ms (20);
      {
         IF (!input (inv))
         {
            dc_motor_stop ();
            delay_ms (1000);
            dcmotor_tn = ~dcmotor_tn;
            dc_motor_control ();
            WHILE ( ! input (inv));
         }
      }
   }
}

void main() 
{
   
   set_up_port_ic_chot ();
   dc_motor_enable ();
   dc_motor_stop ();

   WHILE (true)
   {
      WHILE (input (on)) DELAY_MS(100); //THEM VAO DE XU LY LOI QUA TAI CPU 
                                          //cho nhan stop
      dcmotor_onoff = 1;
      dc_motor_control ();

      DO
      {
         phim_inv ();
         DELAY_MS(100);    //THEM VAO DE XU LY LOI QUA TAI CPU
      }
      WHILE (input (off));

      dc_motor_stop ();
   }
}

