#include&lt;reg51.h&gt;
sbit P2_0 = P2^0;
sbit P2_1 = P2^1;
sbit P2_2 = P2^2;

void delay(int a)
{
	unsigned b,c,d;
	for(b=0; b&lt;a; b++)
	for(c=0; c&lt;90; c++)
	for(d=0; d&lt;90; d++);
}

void Superdelay(int a)
{
	unsigned b,c,d;
	for(b=0; b&lt;a; b++)
	for(c=0; c&lt;300; c++)
	for(d=0; d&lt;300; d++);
}

void reverse()
{
	for(;;)
	{
		unsigned i;
		unsigned int x=1;
		P0=0x00;
		P3=0x00;
		P1=0xF4;
		while(P2_0 == 1 &amp;&amp; P2_1 == 1 &amp;&amp; P2_2 == 1)
		{
			Superdelay(1);
			if(P2_0 == 1 &amp;&amp; P2_1 == 1 &amp;&amp; P2_2 == 1)
			{
				x++;
				if(x==3)
				{
					P1=0xF2;
					Superdelay(1);
					P1=0xF1;
					Superdelay(5);
					for(i=0; i&lt;6; i++)
					{
						P3 = 0x22;
						P0 = 0x82;
						delay(1);
						P3 = 0x28;
						P0 = 0x88;
						delay(1);
						P3 = 0x88;
						P0 = 0x28;
						delay(1);
						P3 = 0x82;
						P0 = 0x22;
						delay(1);
					}
					goto outer;
				}
				else
					continue;
			}
			else
				break;
		}
	
	}

outer:;
}

void main()
{
	for(;;)
	{
		unsigned int x=1;
		unsigned i;
		P2_0 = 1;
		P2_1 = 1;
		P2_2 = 1;
		P1=0xF4;
		P0=0x00;
		P3=0x00;
		while(P2_0 == 0 &amp;&amp; P2_1 == 0 &amp;&amp; P2_2 == 0)
		{
			Superdelay(1);
			if(P2_0 == 0 &amp;&amp; P2_1 == 0 &amp;&amp; P2_2 == 0)
			{
				x++;
				if(x==5)
				{
					P1=0xF2;
					Superdelay(1);
					P1=0xF1;
					Superdelay(5);
					for(i=0; i&lt;6; i++)
					{
						P0 = 0x22;
						P3 = 0x82;
						delay(1);
						P0 = 0x28;
						P3 = 0x88;
						delay(1);
						P0 = 0x88;
						P3 = 0x28;
						delay(1);
						P0 = 0x82;
						P3 = 0x22;
						delay(1);
					}
					reverse();
				}
				else
					continue;
			}
			else
				break;
		}
	}
}