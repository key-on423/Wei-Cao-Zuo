#include <stdio.h>
#include <limits.h>

char* itobs(int, char*);
void show_bstr(char*);
int invert_end(int num, int bits);

int main()
{
	char arr1[CHAR_BIT * sizeof(int) + 1];
	int number;
	printf("请输入十进制数，程序返还其二进制数\n");
	while (scanf("%d", &number) == 1)
	{
		itobs(number, arr1);
		printf("%d的二进制数是:", number);
		show_bstr(arr1);
		printf("\n");
		number = invert_end(number, 4);
		printf("转换其后4位数后的二进制数为:");
		show_bstr(itobs(number, arr1));
		printf("\n");
	}
	printf("程序结束\n");
	return 0;
}

char* itobs(int ha, char*ps)
{
	int i;
	const static int size = CHAR_BIT * sizeof(int);
	for (i = size - 1;i>= 0;ha >>= 1,i--)
		ps[i] = (01 & ha)+'0';
		ps[size] = '\0';
		return ps;
}
void show_bstr(char*ps)
{
	int i = 0;
	while (ps[i])
	{
		putchar(ps[i]);
		if (++i % 4 == 0 && ps[i])
			printf(" ");
		
	}
}
int invert_end(int num, int bits)
{
	int ma = 1;
	int yuan = 0;
	while (bits-- > 0)
	{
	    	yuan |= ma;
			ma <<= 1;
	}
	return num ^ yuan;
}