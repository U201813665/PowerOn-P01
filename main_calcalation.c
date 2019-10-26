#include"calculation.h"
#include<stdio.h>
#include<stdlib.h>








void main()
{
	
	char* Ptr = "12 3 4 + * 6 - 8 2 / -";
	char ptr[16] = {0};
	//printf("%s", Ptr);

	//int _size = sizeof(Ptr) / sizeof(Ptr[0]);
	
	int value = RPNValue(Ptr);
	_itoa_s(value, ptr,10,10);
	printf("%s", ptr);
	
	
	while (1);
	
}

	

