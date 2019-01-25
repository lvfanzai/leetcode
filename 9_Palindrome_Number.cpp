#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <string>
#include <stack>

bool isPalindrome(int x) {
    if(x < 0) {//根据回文定义，为负数直接返回false
		return false;
	}
    
	char str[10] = {0};
	char b = 0;//计算每一位数值
	int index = 0;
	while(x > 0) {
		b = x%10 + '0';//转化为字符
		str[index ++] = b;
		x = x/10;
	}
	for(int i = 0; i < index; i++) {//循环判断前后知否相等
		if(str[i]!= str[index - i -1]) {
			return false;
		}
	}

	printf("str = %s\n",str);

    return true;   
}

int main(int argc, char* argv[])
{
	bool result;
	
	int input = 121;
	result = isPalindrome(input);
	printf("input = %d, result = %d\n",input, result);

	input = -121;
	result = isPalindrome(input);
	printf("input = %d, result = %d\n",input, result);

	input = 10;
	result = isPalindrome(input);
	printf("input = %d, result = %d\n",input, result);

	input = 9;
	result = isPalindrome(input);
	printf("input = %d, result = %d\n",input, result);

	return 0;
}