#include <cstdio>
#include <queue>
using namespace std;
//������ Ǯ���� BFS�����ʹ� �ٸ���, visited �迭�� ���� ������ �����Ͽ���. 
int n, k, visited[100001]={0,};
queue<int> q;
int bfs(){
	//ť�������� ��ġ�� �ְ�, �湮�� üũ�ϴ� �迭�� 1�� �־��ش�. 
	q.push(n); visited[n] = 1;
	//bfs ���� 
	while(!q.empty()){
		//ť�� ������, �����̰� ������ ��ġ�� �����ߴ��� Ȯ���Ѵ�. 
		int p = q.front(); q.pop();
		if(p==k) return visited[p]-1;
		
		//������ ���� ��ġ -1�� 0���� ũ�ų� ����, �湮�� ���� �������. 
		if(p-1>=0&&visited[p-1]==0){
			visited[p-1] = visited[p]+1;
			q.push(p-1);
		}
		//������ ���� ��ġ�� +1�� 100,000���� �۰ų� ����, �湮�� ���� �������.
		if(p+1<=100000&&visited[p+1]==0){
			visited[p+1] = visited[p]+1;
			q.push(p+1);
		}
		//������ ���� ��ġ�� 2�谡 0���� ũ�ų� ����, �湮�� ���� �������.
		if(2*p<=100000&&visited[2*p]==0){
			visited[2*p] = visited[p]+1;
			q.push(2*p);
		}
	}
}
int main(){
	scanf("%d %d",&n,&k);
	printf("%d",bfs());
}
