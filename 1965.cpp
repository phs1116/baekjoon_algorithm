#include <cstdio>
#include <cstring>
#define max(x,y) (x)>(y)?(x):(y)
int n,box[1001],cache[1001],ret=0;
//최대 부분 증가 수열 
int LIS(int s){
	int& ret = cache[s+1];
	if(ret!=-1) return ret;
	
	//현재 자기위치의 총 길이 최소 1(자기 갯수) 
	ret = 1;
	//최장 증가 부분 수열. 모든 경우를 다 비교한다. 
	for(int i = s+1; i<n; i++){
		if(s==-1||box[i] > box[s]) 
		 ret = max(ret, 1+LIS(i));
	}
	return ret;
}
int main(){	
	scanf("%d",&n);
	memset(cache,-1,sizeof(cache));
	for(int i = 0; i<n;i++)
		scanf("%d",&box[i]);
	//LIS(-1)에는 모든 경우의 가장 큰 값이 저장된다. 
	printf("%d",LIS(-1)-1);
}
