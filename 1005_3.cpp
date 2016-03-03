#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm> 
using namespace std;
//�� �ǹ��� �ε��� 0���� �Ǽ� �ð��� �����Ѵ�. 
int t,build[1001][1001],isFirst[1001]={0,},value[1001];
int x,y,n,k,w;
queue<int> q; 

int bfs(){
	int ret = 987654321;
	//�������� ������ �͵��� ���� ť�� �ִ´�. 
	for(int i=1;i<=n;i++){
		if(isFirst[i]==0){
			q.push(i);
			value[i] = build[i][0];
		}
	}	
	//BFS�� �����Ѵ�. 
	while(!q.empty()){
		//ť���� �ε����� �ϳ��� ������, ���� ��ο��� ������ ���� ã�´�.
		 int p = q.front(); q.pop();
		 if(p==w){
		 	ret = min(ret,value[p]);
		 	
		 }
		 
		 for(int i=1;i<=n;i++){
		 	if(build[p][i]==1){
				 value[i] =max(value[i], value[p] + build[i][0]);
				 q.push(i);
			 }
		 }
	}
	
	return ret;
} 


int main(){
	scanf("%d",&t);
	while(t--){
		memset(build,0,sizeof(build));
		memset(value,0,sizeof(value));
		//�ǹ��� ������ �Ǽ� ��Ģ ���� 
		scanf("%d %d",&n,&k);
		//�� �ǹ� 0�� �ε����� �ǹ��� �Ǽ� �ð��� �����Ѵ�. 
		for(int i=1;i<=n;i++)
			scanf("%d",&build[i][0]);
					
		for(int i=0;i<k;i++){
			scanf("%d %d",&x,&y);
			//�ش� ��ΰ� ������ ǥ���ϱ�����  1�� �����Ѵ�. 
			build[x][y] = 1;
			//���� �ش� ��ΰ� �������� �������� �ƴ����� üũ�� �ؾߵȴ�.
			isFirst[y] = 1; 
		} 
		//��ǥ �ǹ� 
		scanf("%d",&w);
		printf("\n�� :%d\n\n",bfs());
		
		
	} 
}
