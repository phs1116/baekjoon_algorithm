#include <cstdio>
#include <cstring>
#define max(x,y) (x)>(y)?(x):(y)
int n,box[1001],cache[1001],ret=0;
//�ִ� �κ� ���� ���� 
int LIS(int s){
	int& ret = cache[s+1];
	if(ret!=-1) return ret;
	
	//���� �ڱ���ġ�� �� ���� �ּ� 1(�ڱ� ����) 
	ret = 1;
	//���� ���� �κ� ����. ��� ��츦 �� ���Ѵ�. 
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
	//LIS(-1)���� ��� ����� ���� ū ���� ����ȴ�. 
	printf("%d",LIS(-1)-1);
}
