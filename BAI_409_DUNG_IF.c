#include <tv_pickit2_shift_1.c>
signed int16 i, j;
void main()
{
   set_up_port_ic_chot();
   i = 0;   
   while(true)
   {
            xuat_4led_7doan_4so(ma7doan[j/10], ma7doan[j%10], ma7doan[i/10], ma7doan[i%10]);
            delay_ms(50); //mo phong
            i ++;
            if(i == 60)
            {
               i = 0;
               j++;
            }
            if(j == 60)
            {
               j = 0;            
            }
   }
}
