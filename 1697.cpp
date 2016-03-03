#include <cstdio>
#include <queue>
#define MAX 100000
int n, k, t = 0, x[MAX] = { 0, };
typedef struct {
	int x;
	int c;
}Pos;
std::queue<Pos> q;
int main() {
	scanf("%d %d", &n, &k);
	Pos p = {n,0}; q.push(p);
	x[n] = 1;
	while (!q.empty()) {
		p = q.front(); q.pop();
		n = p.x; t = p.c;
		if (n - 1 == k || n + 1 == k || n * 2 == k) {t+=1; break;}
		if(n==k) break;
		if ((n-1)>=0&&x[n - 1] == 0) {
			p = { n - 1,t + 1 }; q.push(p);
			x[n - 1] = 1;
		}
		if ( (n+1)<=MAX&&x[n + 1] == 0) {
			p = { n + 1,t + 1 }; q.push(p);
			x[n + 1] = 1;
		}
		if ((2*n)<=MAX&&x[n * 2] == 0) {
			p = { n * 2,t + 1 }; q.push(p);
			x[2 * n] = 1;
		}
	}
	printf("%d", t);
}
