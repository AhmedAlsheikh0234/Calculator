/*
 * Calculator2.c
 *
 * Created: 2/9/2024 4:43:27 AM
 *  Author: Ahmed Al-Sheikh
 */ 


#include <avr/io.h>
#include <stdio.h>
#define F_CPU 8000000UL
#include <util/delay.h>

#include "LCD_driver.h"
#include "keybad_driver.h"

int main(void)
{
	LCD_init();
	keybad_init();
	LCD_sendstring("Welcome ^^");
	_delay_ms(1000);
	LCD_clearscr();
	unsigned long long arr1[9]={};                //arrays for the input values
	unsigned long long arr2[9]={};
	unsigned char string_to_print[10] = {' '};	
	unsigned char C1=0;           //counters for number arrays
	unsigned char C2=0;
	unsigned char op;
	unsigned long long y;
	unsigned long y1,y2;
	unsigned long x1,x2;
	unsigned long long x;
	unsigned long long  res;
	float f_res;
	
	
    while(1)
    {
		reset:
		LCD_sendstring("Enter 1st number");
		_delay_ms(1000);
		LCD_clearscr();
		for (C1=0;C1<10;C1++)
		{
			do 
			{
				arr1[C1]=keybad_checkpress();
			} while (arr1[C1]==NOTPRESSED);
			if (arr1[C1]=='=')
			{
				break;
			} 
			else if(arr1[C1]=='A'||arr1[C1]=='+'||arr1[C1]=='-'||arr1[C1]=='/'||arr1[C1]=='*')
			{
				LCD_clearscr();
				goto reset;
			}
			else 
			{
				LCD_sendchar(arr1[C1]);
				_delay_ms(200);
			}
		}
		switch(C1)
		{
			case 1:
			x=(arr1[C1-1]-48);
			LCD_clearscr();
			LCD_sendchar(x);
			LCD_movecursor(2,1);
			LCD_sendstring("2nd Number");
			_delay_ms(2000);
			LCD_clearscr();
			break;
			
			case 2:
			x=(arr1[C1-1]-48)+((arr1[C1-2]-48)*10);
			LCD_clearscr();
			LCD_sendnumber(x);
			LCD_movecursor(2,1);
			LCD_sendstring("2nd Number");
			_delay_ms(2000);
			LCD_clearscr();
			break;
			
			case 3:
			x=(arr1[C1-1]-48)+((arr1[C1-2]-48)*10)+((arr1[C1-3]-48)*100);
			LCD_clearscr();
			LCD_sendnumber(x);
			LCD_movecursor(2,1);
			LCD_sendstring("2nd Number");
			_delay_ms(2000);
			LCD_clearscr();
			break;
			
			case 4:
			x=(arr1[C1-1]-48)+((arr1[C1-2]-48)*10)+((arr1[C1-3]-48)*100)+((arr1[C1-4]-48)*1000);
			LCD_clearscr();
			LCD_sendnumber(x);
			LCD_movecursor(2,1);
			LCD_sendstring("2nd Number");
			_delay_ms(2000);
			LCD_clearscr();
			break;
			
			case 5:
			x1=(arr1[C1-1]-48)+((arr1[C1-2]-48)*10)+((arr1[C1-3]-48)*100)+((arr1[C1-4]-48)*1000);
			x2=((arr1[C1-5]-48)*10000);
			x=(unsigned long) x1+ (unsigned long)x2 ;
			LCD_clearscr();
			LCD_sendnumber(x);
			LCD_movecursor(2,1);
			LCD_sendstring("2nd Number");
			_delay_ms(2000);
			LCD_clearscr();
			break;
			
			case 6:
			x1=(arr1[C1-1]-48)+((arr1[C1-2]-48)*10)+((arr1[C1-3]-48)*100)+((arr1[C1-4]-48)*1000);
			x2=((arr1[C1-5]-48)*10000)+((arr1[C1-6]-48)*100000);
			x=(unsigned long) x1+ (unsigned long)x2 ;
			LCD_clearscr();
			LCD_sendnumber(x);
			LCD_movecursor(2,1);
			LCD_sendstring("2nd Number");
			_delay_ms(2000);
			LCD_clearscr();
			break;
			
			case 7:
			x1=(arr1[C1-1]-48)+((arr1[C1-2]-48)*10)+((arr1[C1-3]-48)*100)+((arr1[C1-4]-48)*1000);
			x2=((arr1[C1-5]-48)*10000)+((arr1[C1-6]-48)*100000)+((arr1[C1-7]-48)*1000000);
			x=(unsigned long) x1+ (unsigned long)x2 ;
			LCD_clearscr();
			LCD_sendnumber(x);
			LCD_movecursor(2,1);
			LCD_sendstring("2nd Number");
			_delay_ms(2000);
			LCD_clearscr();
			break;
			
			
			default:
			break;
		}
		/* End of First number code.............................................................. */
		
		for (C2=0;C2<10;C2++)
		{
			do
			{
				arr2[C2]=keybad_checkpress();
			} while (arr2[C2]==NOTPRESSED);
			if (arr2[C2]=='=')
			{
				break;
			}
			else if(arr2[C2]=='A'||arr2[C2]=='+'||arr2[C2]=='-'||arr2[C2]=='/'||arr2[C2]=='*')
			{
				LCD_clearscr();
				goto reset;
			}
			else
			{
				LCD_sendchar(arr2[C2]);
				_delay_ms(200);
			}
		} 
		switch(C2)
		{
			case 1:
			y=arr2[C2-1]-48;
			LCD_clearscr();
			LCD_sendchar(y);
			LCD_movecursor(2,1);
			LCD_sendstring("Enter operation");
			_delay_ms(2000);
			LCD_clearscr();
			break;
			
			case 2:
			y=(arr2[C2-1]-48)+((arr2[C2-2]-48)*10);
			LCD_clearscr();
			LCD_sendnumber(y);
			LCD_movecursor(2,1);
			LCD_sendstring("Enter operation");
			_delay_ms(2000);
			LCD_clearscr();
			break;
			
			case 3:
			y=(arr2[C2-1]-48)+((arr2[C2-2]-48)*10)+((arr2[C2-3]-48)*100);
			LCD_clearscr();
			LCD_sendnumber(y);
			LCD_movecursor(2,1);
			LCD_sendstring("Enter operation");
			_delay_ms(2000);
			LCD_clearscr();
			break;
			
			case 4:
			y=(arr2[C2-1]-48)+((arr2[C2-2]-48)*10)+((arr2[C2-3]-48)*100)+((arr2[C2-4]-48)*1000);
			LCD_clearscr();
			LCD_sendnumber(y);
			LCD_movecursor(2,1);
			LCD_sendstring("Enter operation");
			_delay_ms(2000);
			LCD_clearscr();
			break;
			
			case 5:
			y1=(arr2[C2-1]-48)+((arr2[C2-2]-48)*10)+((arr2[C2-3]-48)*100)+((arr2[C2-4]-48)*1000);
			y2=((arr2[C2-5]-48)*10000);
			y=(unsigned long) y1+ (unsigned long)y2 ;
			LCD_clearscr();
			LCD_sendnumber(y);
			LCD_movecursor(2,1);
			LCD_sendstring("Enter operation");
			_delay_ms(2000);
			LCD_clearscr();
			break;
			
			case 6:
			y1=(arr2[C2-1]-48)+((arr2[C2-2]-48)*10)+((arr2[C2-3]-48)*100)+((arr2[C2-4]-48)*1000);
			y2=((arr2[C2-5]-48)*10000)+((arr2[C2-6]-48)*100000);
			y=(unsigned long) y1+ (unsigned long)y2 ;
			LCD_clearscr();
			LCD_sendnumber(y);
			LCD_movecursor(2,1);
			LCD_sendstring("Enter operation");
			_delay_ms(2000);
			LCD_clearscr();
			break;
			
			case 7:
			y1=(arr2[C2-1]-48)+((arr2[C2-2]-48)*10)+((arr2[C2-3]-48)*100)+((arr2[C2-4]-48)*1000);
			y2=((arr2[C2-5]-48)*10000)+((arr2[C2-6]-48)*100000)+((arr2[C2-7]-48)*1000000);
			y=(unsigned long) y1+ (unsigned long)y2 ;
			LCD_clearscr();
			LCD_sendnumber(y);
			LCD_movecursor(2,1);
			LCD_sendstring("Enter operation");
			_delay_ms(2000);
			LCD_clearscr();
			break;
			
			
			
			default:
			break;
		}
		/*End of second number code*/
		do 
		{
			op=keybad_checkpress();
		} while (op==NOTPRESSED);
		_delay_ms(200);
		switch(op)
		{
			case '+':
			res=x+y;
			LCD_sendstring("Result =");
			LCD_movecursor(2,1);
			LCD_sendnumber(res);
			do
			{
				op=keybad_checkpress();
			} while (op==NOTPRESSED);
			_delay_ms(200);
			if (op=='A')
			{
				LCD_clearscr();
				goto reset;
			}
			else
			{
				_delay_ms(3000);
				LCD_clearscr();
			}
			break;
			
			case '-':
			if (x>y)
			{
				res=x-y;
				LCD_sendstring("Result =");
				LCD_movecursor(2,1);
				LCD_sendnumber(res);
				do
				{
					op=keybad_checkpress();
				} while (op==NOTPRESSED);
				_delay_ms(200);
				if (op=='A')
				{
					LCD_clearscr();
					goto reset;
				}
				else
				{
					_delay_ms(3000);
					LCD_clearscr();
				}
			}
			else if (x<y)
			{
				res=y-x;
				LCD_sendstring("Result =");
				LCD_movecursor(2,1);
				LCD_sendstring("-");
				LCD_sendnumber(res);
				do
				{
					op=keybad_checkpress();
				} while (op==NOTPRESSED);
				_delay_ms(200);
				if (op=='A')
				{
					LCD_clearscr();
					goto reset;
				}
				else
				{
					_delay_ms(3000);
					LCD_clearscr();
				}
			}
			break;
			
			case '*':
				res= x*y;
				LCD_sendstring("Result =");
				LCD_movecursor(2,1);
				LCD_sendnumber(res);
				do
				{
					op=keybad_checkpress();
				} while (op==NOTPRESSED);
				_delay_ms(200);
				if (op=='A')
				{
					LCD_clearscr();
					goto reset;
				}
				else
				{
					_delay_ms(3000);
					LCD_clearscr();
				}
			break;
			
			case '/':
			if (x % y != 0)
			{
				f_res=(float)x/(float)y;
				sprintf(string_to_print, "%6.4f", f_res);
				LCD_sendstring("Result =");
				LCD_movecursor(2,1);
				LCD_sendstring(string_to_print);
				do
				{
					op=keybad_checkpress();
				} while (op==NOTPRESSED);
				_delay_ms(200);
				if (op=='A')
				{
					LCD_clearscr();
					goto reset;
				}
				else
				{
					_delay_ms(3000);
					LCD_clearscr();
				}
			}
			else
			{
				res=x/y;
				LCD_sendstring("Result =");
				LCD_movecursor(2,1);
				LCD_sendnumber(res);
				do
				{
					op=keybad_checkpress();
				} while (op==NOTPRESSED);
				_delay_ms(200);
				if (op=='A')
				{
					LCD_clearscr();
					goto reset;
				}
				else
				{
					_delay_ms(3000);
					LCD_clearscr();
				}
			}
			break;
			default:
			break;
		} 		      
   } 
}