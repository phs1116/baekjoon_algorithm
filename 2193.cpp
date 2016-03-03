#include <cstdio>
#include <cstring>
long long n, bi[91][2];
long long int bc(int c, int b) {	
	if(c==n-1) return 1;
	long long& ret = bi[c][b];
	if(ret!=-1)return ret;
	if(b==1) ret=bc(c+1,0);
	else ret=bc(c+1,0)+bc(c+1,1);
	return ret;
}
int main() {
	memset(bi, -1, sizeof(bi));
	scanf("%d", &n);
	printf("%lld",bc(0,1));	
}
