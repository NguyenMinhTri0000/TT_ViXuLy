#include<tv_pickit2_shift_1.c>
signed int8 t0=0,ch,dv;
unsigned int8 tt_sp=0,tt_ht=0,tt_d=0;
void PHIM_SP()
{
   if(input(bt0)==0)
   {
      if(input(bt0)==0)
      {
         tt_sp++;
         if(tt_sp==2) tt_sp=0;
         while(input(bt0)==0);
      }
   }
}
void PHIM_HT()
{
   if(input(bt1)==0)
   {
      if(input(bt1)==0)
      {
         tt_ht++;
         if(tt_ht==2) tt_ht=0;
         while(input(bt1)==0);
      }
   }
}
void PHIM_DAO()
{
   if(input(bt2)==0)
   {
      if(input(bt2)==0)
      {
         set_timer0(99-get_timer0());
         tt_d++;
         if(tt_d==2) tt_d=0;
         while(input(bt2)==0);
      }
   }
}
void GM_HT()
{
   ch=ma7doan[t0/10];
   dv=ma7doan[t0%10];
   if(ch==0xc0) ch=0xff;
}
void main()
{
   set_up_port_ic_chot();
   setup_timer_0(t0_ext_l_to_h|t0_div_1|t0_8_bit);
   set_timer0(t0); 
   while(true)
   {
      GM_HT();
      PHIM_SP();
      if(tt_sp==0)
      {
         setup_timer_0(t0_ext_l_to_h|t0_div_1|t0_8_bit);
         xuat_32led_don_4byte(0xff,0xff,0xff,0xff);
      }
      if(tt_sp==1)
      {
         setup_timer_0(t0_off);
         xuat_32led_don_4byte(0,0,0,0);
      }
      PHIM_HT();
      if(tt_ht==0)
      {
         xuat_4led_7doan_4so(ch,dv&0x7f,ma7doan[5],0x8c);
      }
       if(tt_ht==1)
      {
         xuat_4led_7doan_4so(ma7doan[5],0x8c&0x7f,ch,dv);
      }
      PHIM_DAO();
      if(tt_d==0)
      {
         t0=get_timer0();
         if(t0>99) set_timer0(0);
      }
      if(tt_d==1)
      {
         t0=99-get_timer0();
         if(t0<=-1) set_timer0(0);
      }
   }
}

