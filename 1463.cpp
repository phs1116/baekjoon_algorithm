#include <cstdio>
#include <cstring>
#define min(x,y) (x)<(y)?(x):(y)
using namespace std;
int cache[1000001],n;
int one(int n,int count){
	if(n==1) return count;
	int& ret = cache[n];
	if(ret!=-1) return ret;
	ret = one(n-1,count+1);
	if(n%3==0) ret = min(ret,one(n/3));
	if(n%2==0) ret = min(ret,one(n/2));
	return ret;
}
int main(){
	memset(cache,-1,sizeof(cache));
	scanf("%d",&n);
	printf("%d",one(n,0));
}
