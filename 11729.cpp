#include <cstdio>
#include <cmath>
int n;
void hanoi(int n,int fr,int to,int tm){
	if(n==1){
		printf("%d %d\n",fr,to);
		return;
	}
	hanoi(n-1,fr,tm,to);
	printf("%d %d\n",fr,to);
	hanoi(n-1,tm,to,fr);
	
}
int main(){
	scanf("%d",&n);
	printf("%d\n",(int)pow(2,n)-1);
	hanoi(n,1,3,2);
}
