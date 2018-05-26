#include<reg51.h>
#define LCDDATA P2 
sbit RS= P3^0;
sbit E = P3^1;
sbit C1 = P1^0;
sbit C2 = P1^1;
sbit C3 = P1^2;
sbit R1 = P1^3;
sbit R2 = P1^4;
sbit R3 = P1^5;
sbit R4 = P1^6;
void mydelay(int i)
{	
 int m,n;
 for (m=0;m<i;m++)
  {
   for (n=0;n<1000;n++)
   {}
  }
}
void lcd_data(char c)
{RS=1;E=1;LCDDATA=c;mydelay(1);E=0;}
void lcd_cmd(char c)
{RS=0;E=1;LCDDATA=c;mydelay(1);E=0;}
void strp(unsigned char *str)
 {
  while(*str!='\0')
   {
    lcd_data(*str);
    str++;
   }
 } 
 void Pass()
{
 lcd_cmd(0x38);
 lcd_cmd(0x01);
 lcd_cmd(0x0e);
 lcd_cmd(0x80);
 strp("Enter Password");
} 
void lcd_init()
{
 
 lcd_cmd(0x38);
 
 lcd_cmd(0x0e);
 lcd_cmd(0xc0);
}
void main()
{
 int n1,n2;
     n1=n2=0;
// Pass();	   	 
 lcd_init();
 R1=R2=R3=R4=C1=C2=C3=1;
 while(1)
  {
   C1=0;
   if(R1==0) { lcd_data('1');while(R1==0);n1=n1*10+1;} 
   if(R2==0)  {lcd_data('4');while(R2==0);n1=n1*10+4;} 
   if(R3==0)  {lcd_data('7');while(R3==0);n1=n1*10+7;} 
   if(R4==0)  {lcd_data('*');while(R4==0);n1=0;lcd_cmd(0x01);}
   C1=1; C2=0;
   if(R1==0)  {lcd_data('2');while(R1==0);n1=n1*10+2;}
   if(R2==0)  {lcd_data('5');while(R2==0);n1=n1*10+5;} 
   if(R3==0)  {lcd_data('8');while(R3==0);n1=n1*10+8;}
   if(R4==0)  {lcd_data('0');while(R4==0);n1=n1*10+0;} 
   C2=1;	  C3=0;
   if(R1==0)  {lcd_data('3');while(R1==0);n1=n1*10+3;}
   if(R2==0)  {lcd_data('6');while(R2==0);n1=n1*10+6;} 
   if(R3==0)  {lcd_data('9');while(R3==0);n1=n1*10+9;}
   if(R4==0)  {lcd_data('#');while(R4==0);n1=0;n2=1;} 
   C3=1;	 
   mydelay(10);
   if(n2==1)
    {
	 lcd_cmd(0x01);
	 strp("You R Welcome");
	}

  }
}