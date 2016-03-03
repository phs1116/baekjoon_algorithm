#include <cstdio>
#include <cstring>
#include <cstdlib>
char cal[51] = { 0, };
char ca[51] = {0,};
char* ptr;
int ret,i=0;
//덧셈을 처리하는 함수. 전과 달라진건 -,+을 안가리고 전부 더해버린다. 
int calculate(char* str) {
	int r = 0;
	char* ptr2;
	ptr2 = strtok(str, "+-");
	r += atoi(ptr2);
	while (ptr2 = strtok(NULL, "+-")) {
		r += atoi(ptr2);
	}
	return r;
}
int main() {
	scanf("%s", cal);
	//첫 -를 기준으로 토큰을 나눈다. 
	ptr = strtok(cal, "-");
	strcpy(ca,ptr);
	//첫 - 이후의 문자열을 받는다. 
	ptr = strtok(NULL,"");  
	ret=calculate(ca);
	//첫 - 이후의 문자열은 전부 덧셈 처리한 뒤 빼준다. 
	if(ptr!=NULL)ret-=calculate(ptr); 
	printf("%d",ret);
}
