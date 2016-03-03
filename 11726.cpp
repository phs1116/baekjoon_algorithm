#include <cstdio>
#include <cstring>
int cache[1001],n;
int tiling(int w){
	if(w==n)return 1;
	if(w>n) return 0;
	int& ret = cache[w];
	if(ret!=-1) return ret;
	ret=tiling(w+1)+tiling(w+2);
	return ret%10007;
}
int main(){
	memset(cache,-1,sizeof(cache));
	scanf("%d",&n);
	printf("%d",tiling(0));
}
