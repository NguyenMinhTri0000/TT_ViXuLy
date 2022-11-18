#INCLUDE <TV_PICKIT2_SHIFT_1.c>
#INCLUDE <TV_PICKIT2_SHIFT_DS18B20.c>  
unsigned INT16  T0;

void counter_dem_len(unsigned int8  gioi_han_duoi, gioi_han_tren)    //phai set gia tri dau o main set_timer 
{
   t0 = get_timer0 () ;
   //giai_ma_hien_thi (t0);
   IF (t0 >= gioi_han_tren+1) set_timer0 (gioi_han_duoi + 1);
}

VOID MAIN()
{
   SET_UP_PORT_IC_CHOT();
   setup_adc (adc_clock_div_32) ;
   setup_adc_ports (an0|vss_vdd);
   set_adc_channel (0);   
   KHOI_TAO_DS18B20();
   DS18A_TAM=0;
   XUAT_4LED_7DOAN_GIAIMA_XOA_SO0(0);
   SET_TIMER0(0);
   WHILE(TRUE)
   {
      IF(TOUCH_PRESENT())   DOC_GIATRI_DS18B20();
         DS18A=DS18A>>4;
         DS18A=DS18A&0X0FF;
         counter_dem_len(0,99);
         XUAT_4LED_7DOAN_2_SO(DS18A,T0);
   }
}
