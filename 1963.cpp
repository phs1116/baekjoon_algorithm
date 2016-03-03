#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue> 
using namespace std;
int t, x, y, a[10000] = { 0, }, visited[10000] = { 0, }, num[4];
typedef struct {
	int num, count;
}Prime;
queue<Prime> q;
//�����佺�׳׽��� ü�� 9999������ �Ҽ����� ��� ���Ѵ�. 
void era(int n) {
	int i;
	while (true) {
		for (i = 2; i <= n; i++)
			if (a[i] == 0) break;
		if (i>n) return;
		a[i] = 1;
		for (int j = 2; j*i <= n; j++) {
			if (a[i*j] == 0) {
				a[i*j] = 2;
			}
		}
	}
}
//�迭�� ���ڷ� �ٲ۴�.
int numToArr(){
	int ret=0;
	for(int i=0; i<4;i++){
		ret+=num[i]*pow(10,3-i);
	}
	return ret;
}
//�ڸ����� �ѹ� �ٲ� ���� �Ҽ����� �Ǻ��ϰ�, �Ҽ��̸� ť�� �ִ´�.
void check(int i,int count){
	int k = i==0?0:1;
	int bak = num[i];
	while(num[i]-1>=1-k){
		num[i] -=1;
		int n = numToArr();
		if(a[n]==1&&visited[n]==0){
			Prime p1 = {n,count+1};
			visited[n]=1;
			q.push(p1);
		}
	}
	num[i]=bak;
	while(num[i]+1<=9){
		num[i] +=1;
		int n = numToArr();
		if(a[n]==1&&visited[n]==0){
			Prime p1 = {n,count+1};
			visited[n]=1;
			q.push(p1);
		}
	}
	num[i]=bak;
}
//�ʺ�켱 Ž��.
int dfs() {
	Prime p = { x,0 };
	q.push(p);
	while (!q.empty()) {
		p = q.front(); q.pop();
		//���� ã������ ��ȯ 
		if (p.num == y) return p.count;
		//���ڸ� �迭�� ���� 
		for(int i=0;i<4;i++){
			num[i] = p.num/pow(10,3-i);
			p.num = p.num-num[i]*pow(10,3-i);
		}
		for(int i=0;i<4;i++){
			check(i,p.count);
		}
	}
	//��ã������ -1�� ��ȯ�Ѵ�. 
	return -1;
}
int main() {
	era(9999);
	scanf("%d",&t);
	while(t--){
		scanf("%d %d", &x, &y);
		int ret = dfs();
		printf(ret==-1?"Impossible\n":"%d\n",ret);
		while(!q.empty())q.pop();
		memset(visited,0,sizeof(visited));
	}
}
