#include <cstdio>
#include <cstring>
#include <cstdlib>
char cal[51] = { 0, };
char ca[51] = {0,};
char* ptr;
int ret,i=0;
//������ ó���ϴ� �Լ�. ���� �޶����� -,+�� �Ȱ����� ���� ���ع�����. 
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
	//ù -�� �������� ��ū�� ������. 
	ptr = strtok(cal, "-");
	strcpy(ca,ptr);
	//ù - ������ ���ڿ��� �޴´�. 
	ptr = strtok(NULL,"");  
	ret=calculate(ca);
	//ù - ������ ���ڿ��� ���� ���� ó���� �� ���ش�. 
	if(ptr!=NULL)ret-=calculate(ptr); 
	printf("%d",ret);
}
