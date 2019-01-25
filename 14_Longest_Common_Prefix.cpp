#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <string>
#include <stack>

char* longestCommonPrefix(char** strs, int strsSize) {
	if(strsSize < 1) {
		return "";
	}
	int* len = (int*)malloc(strsSize*sizeof(int));
	int max_len = 0;
	int min_len = 1000;//注意此处min_len不能初始化为0

	//先求出数组中最长和最短的字符长度
    for(int i = 0; i < strsSize; i++) {
		len[i] = strlen(strs[i]);
		if(max_len < len[i]) max_len = len[i];
		if(min_len > len[i]) min_len = len[i];
	}
	//如果相同，则必然是最短的
	char* cp = (char*)malloc(min_len + 1);
	memset(cp,'\0',min_len+1);//添加结束符

	for(int i = 0; i < min_len; i++) {
		char c = strs[0][i];
		for(int j = 0; j < strsSize; j++) {
			if(c !=strs[j][i]) {
				free(len);
				return cp;
			}
		}
		cp[i] = c;
	}
	free(len);
	return cp;
}

int main(int argc, char* argv[])
{
	char* result;
	
	char* input[3] = {"flower","flow","flight"};
	result = longestCommonPrefix(input,3);
	printf("result = %s\n", result);

	char* input1[3] = {"dog","racecar","car"};
	result = longestCommonPrefix(input1,3);
	printf("result = %s\n",result);

	return 0;
}