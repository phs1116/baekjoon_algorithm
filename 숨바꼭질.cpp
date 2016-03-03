#include <cstdio>
#include <queue>
using namespace std;
//기존에 풀었던 BFS문제와는 다르게, visited 배열에 현재 레벨도 저장하였다. 
int n, k, visited[100001]={0,};
queue<int> q;
int bfs(){
	//큐에수빈의 위치를 넣고, 방문을 체크하는 배열애 1을 넣어준다. 
	q.push(n); visited[n] = 1;
	//bfs 시작 
	while(!q.empty()){
		//큐를 꺼내고, 수빈이가 동생의 위치에 도달했는지 확인한다. 
		int p = q.front(); q.pop();
		if(p==k) return visited[p]-1;
		
		//수빈이 현재 위치 -1이 0보다 크거나 같고, 방문한 적이 없을경우. 
		if(p-1>=0&&visited[p-1]==0){
			visited[p-1] = visited[p]+1;
			q.push(p-1);
		}
		//수빈이 현재 위치의 +1이 100,000보다 작거나 같고, 방문한 적이 없을경우.
		if(p+1<=100000&&visited[p+1]==0){
			visited[p+1] = visited[p]+1;
			q.push(p+1);
		}
		//수빈이 현재 위치의 2배가 0보다 크거나 같고, 방문한 적이 없을경우.
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
