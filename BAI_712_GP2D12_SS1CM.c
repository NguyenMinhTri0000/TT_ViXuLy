#INCLUDE <TV_PICKIT2_SHIFT_1.c>
UNSIGNED INT8 J;
UNSIGNED INT16 KQADC;
FLOAT K_CACH,CLK_CACH;
VOID GIAI_MA_HIENTHI_4LED(FLOAT TAM)
{
   UNSIGNED INT16 X;
   X=(UNSIGNED INT16) TAM;
   XUAT_4LED_7DOAN_GIAIMA_XOA_SO0(X);
}

VOID MAIN()
{
   SET_UP_PORT_IC_CHOT();
   SETUP_ADC(ADC_CLOCK_DIV_32);
   SETUP_ADC_PORTS(AN0_TO_AN2|VSS_VDD);
   SET_ADC_CHANNEL(2);
   WHILE(TRUE)
   {
      KQADC=0;
      FOR(J=0;J<20;J++)
      {
         KQADC=KQADC+READ_ADC();
         DELAY_MS(10);
      }   
         KQADC=KQADC/20;
         
         IF(KQADC<=80)               K_CACH=80;
         ELSE IF((KQADC>80)&&(KQADC<87))
            {
               CLK_CACH=KQADC-80;
               K_CACH=80 - CLK_CACH/0.77;
            }
            
         ELSE IF(KQADC==87)          K_CACH=70;
         ELSE IF((KQADC>87)&&(KQADC<106))
            {
               CLK_CACH=KQADC-87;
               K_CACH=70 - CLK_CACH/2.11;
            }
         
         ELSE IF(KQADC==106)          K_CACH=60;
         ELSE IF((KQADC>106)&&(KQADC<124))
            {
               CLK_CACH=KQADC-106;
               K_CACH=60 - CLK_CACH/2;
            }
         
         ELSE IF(KQADC==124)          K_CACH=50;
         ELSE IF((KQADC>124)&&(KQADC<150))
            {
               CLK_CACH=KQADC-124;
               K_CACH=50 - CLK_CACH/2.88;
            }
         
         ELSE IF(KQADC==150)          K_CACH=40;
         ELSE IF((KQADC>150)&&(KQADC<196))
            {
               CLK_CACH=KQADC-150;
               K_CACH=40 - CLK_CACH/5.11;
            }
         
         ELSE IF(KQADC==196)          K_CACH=30;
         ELSE IF((KQADC>196)&&(KQADC<276))
            {
               CLK_CACH=KQADC-196;
               K_CACH=30 - CLK_CACH/8.88;
            }
         
         ELSE IF(KQADC==276)          K_CACH=20;
         ELSE IF((KQADC>276)&&(KQADC<490))
            {
               CLK_CACH=KQADC-276;
               K_CACH=20 - CLK_CACH/23.77;
            }
         
         ELSE IF(KQADC==490)          K_CACH=10;
         GIAI_MA_HIENTHI_4LED(K_CACH);
      }
   }

