#include <cstdio>
int n,m,ar[301][301]={0,},k,i,j,x,y,tmp;
int main(){
	scanf("%d %d",&n,&m);
	for(int t=1;t<=n;t++)
		for(int j=1;j<=m;j++){
			scanf("%d",&tmp);
			ar[t][j] = tmp + ar[t-1][j] + ar[t][j-1] - ar[t-1][j-1];
		}
	scanf("%d",&k);
	for(int t=0; t<k;t++){
		 scanf("%d %d %d %d",&i,&j,&x,&y);
		 printf("%d\n", ar[x][y] -ar[i-1][y]-ar[x][j-1]+ar[i-1][j-1]);
	}
}
