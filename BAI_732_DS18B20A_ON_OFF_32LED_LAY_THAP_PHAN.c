#INCLUDE <TV_PICKIT2_SHIFT_1.c>
#INCLUDE <TV_PICKIT2_SHIFT_DS18B20.c> 
INT1  TTQN;
#DEFINE  GH_NDA_TREN    33
#DEFINE  GH_NDA_DUOI    31

VOID MAIN()
{
   SET_UP_PORT_IC_CHOT();
   KHOI_TAO_DS18B20();
   DS18A_TAM=0;
   XUAT_4LED_7DOAN_GIAIMA_XOA_SO0(0);
   XUAT_32LED_DON_1DW(0);
   TTQN=0;
   WHILE(TRUE)
   {
      IF(TOUCH_PRESENT())
      { DOC_GIATRI_DS18B20();}
         DS18A=DS18A>>4;   
         unsigned int16 thapphan =(DS18A&0X000F)*100/16;      //lay 1 so thap phan nhan 10
                                                              //lay 2 so thap phan nhan 100   
                                                              //lay 3 so thap phan nhan 1000 
                                                              //lay 4 so thap phan nhan 10000 
         XUAT_4LED_7DOAN_2_SO(DS18A,thapphan);
         
         IF ((DS18A>GH_NDA_TREN)&&(TTQN==0))
         {
            TTQN=1;
            XUAT_32LED_DON_1DW(0X0000FFFF);
         }
         ELSE IF((DS18A<GH_NDA_DUOI)&&(TTQN==1))
         {
            TTQN=0;
            XUAT_32LED_DON_1DW(0XFFFF0000);
      }
   }
}
