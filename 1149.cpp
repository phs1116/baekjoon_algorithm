#include <cstdio>
#include <algorithm>
#include <cstring>
int n,ret=987654, hc[1000][3], cache[1000][3];
int rgb(int h, int c) {
	if (h == n - 1) return hc[h][c];
	int& ret = cache[h][c];
	if (ret != -1) return ret;
	ret = hc[h][c];
	return ret += std::min(rgb(h + 1, (c + 1) % 3), rgb(h + 1, (c + 2) % 3));	
}
int main() {
	memset(cache, -1, sizeof(cache));
	scanf("%d", &n);
	for (int i = 0; i<n; i++)
		for (int j = 0; j<3; j++)
			scanf("%d", &hc[i][j]);//해당 집의 색 가격			
	for (int i = 0; i<3; i++)
		ret=std::min(ret,rgb(0,i));
	printf("%d",ret);	
		
}
