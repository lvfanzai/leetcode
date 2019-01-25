#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <string>
#include <stack>

int symToInt(char c) {
	int value = 0;
	switch(c) {
		case 'I': value = 1; break;
		case 'V': value = 5; break;
		case 'X': value = 10;break;
		case 'L': value = 50;break;
		case 'C': value = 100; break;
		case 'D': value = 500; break;
		case 'M': value = 1000;break;
		default : value = 0; break;
	}
	return value;
}
int romanToInt(char* s) {
	int len = strlen(s);

	long result = 0;

	for(int i = 0; i < len; i++){
		result += symToInt(s[i]);
	}

	for(int i = 0; i < len - 1; i++){
			if((s[i]=='I')&&((s[i+1]=='V')||(s[i+1]=='X'))) {
				result -= 2;//由于先使用'I'加过1，故此时满足left to right 需要减2，下同
			}else if((s[i]=='X')&&((s[i+1]=='L')||(s[i+1]=='C'))) {
				result -= 20;
			}else if((s[i]=='C')&&((s[i+1]=='D')||(s[i+1]=='M'))) {
				result -= 200;
			}
	}

	return result;
}

int main(int argc, char* argv[])
{
	int result;
	
	char* input = "III";
	result = romanToInt(input);
	printf("input = %s, result = %d\n",input, result);

	input = "IV";
	result = romanToInt(input);
	printf("input = %s, result = %d\n",input, result);

	input = "IX";
	result = romanToInt(input);
	printf("input = %s, result = %d\n",input, result);

	input = "LVIII";
	result = romanToInt(input);
	printf("input = %s, result = %d\n",input, result);

	input = "MCMXCIV";
	result = romanToInt(input);
	printf("input = %s, result = %d\n",input, result);

	return 0;
}