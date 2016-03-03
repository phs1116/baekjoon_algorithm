#include <cstdio>
char cal[51] = { 0, };
int ret=0,n=0,i=0,flag=0;
int main() {
	scanf("%s", cal);
	while(cal[i] != 0){
		//숫자이면 
		if(cal[i] >='0' && cal[i]<='9'){
			//이전에 저장한 숫자의 자릿수를 하나 늘려주고 이 값을 더해준다. 
			n*=10;
			n+=cal[i]-'0'; 
		}
		//그 후 지금까지 숫자값들을 0으로 초기화해준다. 
		else{
			//-연산자를 만난적이 없으면, 즉 flag가 0이면 그냥 더해준다.
			if(flag==0) ret +=n;
			//-연산자를 만난적이 있으면, 즉 flag가 1이면 뺄셈처리한다.
			else ret-=n;
			//첫 -이면, 즉 -이고 flag가 0이면 flag를 1로 만들어준다. 
			if(cal[i]=='-'&&flag==0) flag=1;
			n = 0; 
		} 
		i++;
	}
	//마지막 숫자를 플래그에 맞게 처리해준다. 
	if(flag==0) ret+=n;
	else if(flag==1) ret-=n;
	printf("%d",ret);
}
