#include <stdio.h>
#include <limits.h>

char* itobs(int, char*);
void show_bstr(char*);
int invert_end(int num, int bits);

int main()
{
	char arr1[CHAR_BIT * sizeof(int) + 1];
	int number;
	printf("������ʮ�����������򷵻����������\n");
	while (scanf("%d", &number) == 1)
	{
		itobs(number, arr1);
		printf("%d�Ķ���������:", number);
		show_bstr(arr1);
		printf("\n");
		number = invert_end(number, 4);
		printf("ת�����4λ����Ķ�������Ϊ:");
		show_bstr(itobs(number, arr1));
		printf("\n");
	}
	printf("�������\n");
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