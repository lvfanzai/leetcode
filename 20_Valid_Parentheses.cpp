#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <string>
#include <stack>

using namespace std;

/*
括号匹配，设计思路
1.定义一个栈
2.如果是'('或者‘[',或者'{'则压栈
3.第二个字符与第一个字符比较，则出栈，不等则压栈
4.依次循环2，3，直到符号处理完成
5.当4处理完成之后，栈不为空，则不匹配，否则为匹配
*/

bool isValidcpp(string s) {
	if(s.empty()) return true;
	if(s.length()%2!=0) return false;

	stack<char> data;
	if((s[0]==')')||(s[0]=='}')||(s[0]==']')) return false;

	for(int i = 0; i < s.length(); i++){
		if((s[i]==')')&&(data.top()=='(')) data.pop();
		else if((s[i]==']')&&(data.top()=='[')) data.pop();
		else if((s[i]=='}')&&(data.top()=='{')) data.pop();
		else data.push(s[i]);
	}

    return data.empty();
}

bool isValidc(char* s) {
	if(s == NULL) return false;

	int len = strlen(s);
	printf("len = %d\n",len);

	char *stack = (char*)malloc(len);//应该判空，在此省略
	int index = 0;
	int stack_index = 0;
    //判断，如果字符串刚开始就是右括号，则直接返回错误
    if((s[0]==')')||(s[0]==']')||(s[0]=='}')) {
		free(stack);
		return false;
	}
	while(s[index]!='\0') {
		if((s[index]=='(')||(s[index]=='{')||(s[index]=='[')) {
			stack[stack_index++] = s[index];
		}else if((stack_index!= 0)&&(s[index]==')')&&(stack[stack_index-1]=='(')) {
			stack_index --;
		}else if((stack_index!= 0)&&(s[index]=='}')&&(stack[stack_index-1]=='{')) {
			stack_index --;
		}else if((stack_index!= 0)&&(s[index]==']')&&(stack[stack_index-1]=='[')) {
			stack_index --;
		}else{
			free(stack);
			return false;
		}
		index ++;
	}
	printf("stack_index = %d\n",stack_index);
	free(stack);
	if(stack_index != 0) return false;

    return true;    
}
int main(int argc, char* argv[])
{
	bool result;
	
	string input = "()";
	result = isValidcpp(input);
	printf("input = %s, result = %d\n",input.c_str(), result);

	input = "()[]{}";
	result = isValidcpp(input);
	printf("input = %s, result = %d\n",input.c_str(), result);

	input = "(]";
	result = isValidcpp(input);
	printf("input = %s, result = %d\n",input.c_str(), result);
		
	input = "([)]";
	result = isValidcpp(input);
	printf("input = %s, result = %d\n",input.c_str(), result);

	input = "{[]}";
	result = isValidcpp(input);
	printf("input = %s, result = %d\n",input.c_str(), result);

	input = "()()((())(())";
	result = isValidcpp(input);
	printf("input = %s, result = %d\n",input.c_str(), result);

	input = ")(";
	result = isValidcpp(input);
	printf("input = %s, result = %d\n",input.c_str(), result);

	input = ")";
	result = isValidcpp(input);
	printf("input = %s, result = %d\n",input.c_str(), result);
		
	input = "(])";
	result = isValidcpp(input);
	printf("input = %s, result = %d\n",input.c_str(), result);

	char* inputc = "()";
	result = isValidc(inputc);
	printf("inputc = %s, result = %d\n",inputc, result);

	inputc = "()[]{}";
	result = isValidc(inputc);
	printf("inputc = %s, result = %d\n",inputc, result);

	inputc = "(]";
	result = isValidc(inputc);
	printf("inputc = %s, result = %d\n",inputc, result);
		
	inputc = "([)]";
	result = isValidc(inputc);
	printf("inputc = %s, result = %d\n",inputc, result);

	inputc = "{[]}";
	result = isValidc(inputc);
	printf("inputc = %s, result = %d\n",inputc, result);

	inputc = "()()((())(())";
	result = isValidc(inputc);
	printf("inputc = %s, result = %d\n",inputc, result);

	inputc = ")(";
	result = isValidc(inputc);
	printf("inputc = %s, result = %d\n",inputc, result);

	inputc = ")";
	result = isValidc(inputc);
	printf("inputc = %s, result = %d\n",inputc, result);
		
	inputc = "(])";
	result = isValidc(inputc);
	printf("inputc = %s, result = %d\n",inputc, result);

	return 0;
}