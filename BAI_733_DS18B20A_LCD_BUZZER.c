#INCLUDE <TV_PICKIT2_SHIFT_1.c>
#INCLUDE <TV_PICKIT2_SHIFT_DS18B20.c> 
INT1  TTQN;
#DEFINE  GH_NDA_TREN    35
#DEFINE  GH_NDA_DUOI    33

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
         DS18A=DS18A&0X0FF;      //khi nhiet do <0 thi 4 bit dau l? 111 | 0000 = 0
         XUAT_4LED_7DOAN_GIAIMA_XOA_SO0(DS18A);
         
         IF ((DS18A>GH_NDA_TREN)&&(TTQN==0))
         {
            TTQN=1;
            XUAT_32LED_DON_1DW(0X0000FFFF);     //BUZZER ON
         }
         ELSE IF((DS18A<GH_NDA_DUOI)&&(TTQN==1))
         {
            TTQN=0;
            XUAT_32LED_DON_1DW(0XFFFF0000);     //TRIAC ON
      }
   }
}
