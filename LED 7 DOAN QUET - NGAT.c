char segment_array[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6  F};//cmmon cathode_non dot

sbit digit0 at RC0_bit;
sbit digit1 at RC1_bit;
sbit digit2 at RC2_bit;
sbit digit3 at RC3_bit;

char digits[5];
void display_7segment(int number)
{
   digits[3]=number/1000u;
   digits[2]=(number/100u)%10u;
   digits[1]=(number/10u)%10u;
   digits[0]=(number/1u)%10u;
}

void InitTimer0()
{
  OPTION_REG     = 0x85;
  TMR0           = 100;
  INTCON         = 0xA0;
}

int position=0;
void Interrupt() iv 0x0004 ics ICS_AUTO
{
  if (TMR0IF_bit)
  {
    TMR0IF_bit   = 0;
    TMR0         = 100;
    
    digit0 = 1;
    digit1 = 1;
    digit2 = 1;
    digit3 = 1;
    if(position>3)position=0;
    
    if(position==1)PORTB = segment_array[digits[position]]+128; //dot point
    else PORTB = segment_array[digits[position]];
    
    if(position==3)
    {
        digit0 = 0;
        digit1 = 1;
        digit2 = 1;
        digit3 = 1;
    }
    else if(position==2)
    {
        digit0 = 1;
        digit1 = 0;
        digit2 = 1;
        digit3 = 1;
    }
    else if(position==1)
    {
        digit0 = 1;
        digit1 = 1;
        digit2 = 0;
        digit3 = 1;
    }
    else if(position==0)
    {
        digit0 = 1;
        digit1 = 1;
        digit2 = 1;
        digit3 = 0;
    }
    position++;
  }
}



unsigned int cnt=0;

void main()
{
 TRISB=0x00;//all output
 TRISC=0x00;//all output
 PORTB=0x00;
 PORTC=0x00;//clear ports
 InitTimer0();//5ms timer
 while(1)
 {

    display_7segment(cnt);
    cnt++; Delay_ms(200);
    if(cnt>9999)cnt=0;
 }
}

