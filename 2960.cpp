#include <cstdio>
int n,k,a[1001]={0,},i,count=0;
int main(){
	scanf("%d %d",&n,&k);
	while(count!=k){
		//지우지 않은 가장 작은 수를 찾는다. 
		for(i=2;i<=n;i++)
			if(a[i]==0) break;
		//다 찾았는데 i가 1000이라면 다 지웠으므로 탈출한다. 
		if(i==1000) break;
		//i번째 수를 1을 채워 지웠음을 표시하고, 차례로 그 배수를 지워나간다. 
		for(int j=1;j*i<=n;j++){
			//만약 지우지 않은 숫자이면 해당 숫자 카운트를 증가시킨다. 
			if(a[i*j]==0){
				a[i*j]=1;
				count++;
			}
			if(count==k){
				printf("%d",i*j);
				return 0;	
			}
		}
	}
}
