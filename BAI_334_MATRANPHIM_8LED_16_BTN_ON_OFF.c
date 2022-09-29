#include <tv_pickit2_shift_1.c>
#include <tv_pickit2_shift_key4x4_138.c>
signed int8 mp, y;      //signed là bao nhieu den bao nhieu
void main()
{
set_up_port_ic_chot();
set_tris_b(0x3c); //RB2 - RB5
   while(true)
   {
      mp = key_4x4_dw();
      if(mp!=0xff)
         {
            delay_ms(200);    //giam toc do kt phim
            //xu li chuc nang
            if(mp == 0) y = 0x01|y;   //0000   0001   //or y là de khong mat led cu
            if(mp == 1) y = 0x02|y;   //0000   0010   //|1 = 1, |0 = chinh no
            if(mp == 2) y = 0x04|y;   //0000   0100
            if(mp == 3) y = 0x08|y;   //0000   1000    
            if(mp == 4) y = 0x10|y;   
            if(mp == 5) y = 0x20|y;   //0010   0000
            if(mp == 6) y = 0x40|y;  
            if(mp == 7) y = 0x80|y;     
            
            if(mp == 0x08) y = 0xfe&y;  //1111  1110     //&0 = 0, &1 = chinh no
            if(mp == 0x09) y = 0xfd&y;  //1111  1101
            if(mp == 0x0A) y = 0xfb&y;  //1111  1011 
            if(mp == 0x0B) y = 0xf7&y;  //1111  0111
            if(mp == 0x0C) y = 0xef&y;  //1110  1111  
            if(mp == 0x0D) y = 0xdf&y;  //1101  1111
            if(mp == 0x0E) y = 0xbf&y;  //1011  1111            
            if(mp == 0x0F) y = 0x7f&y;  //0111  1111            
             xuat_32led_don_4byte(0, 0, 0, y);
         }
   }
}

