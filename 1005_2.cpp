#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm> 
using namespace std;
//각 건물의 인덱스 0번에 건설 시간을 저장한다. 
int t,build[1001][1001],isFirst[1001]={0,},value[1001],path[1001];
int x,y,n,k,w;
queue<int> q; 
 
int bfs(){  
    int ret = 0;
    //시작점이 가능한 것들을 전부 큐에 넣는다. 
    for(int i=1;i<=n;i++){
        if(isFirst[i]==0){
            q.push(i);
            //초기 빌드의 누적 비용을 건설 비용으로 초기화한다. 
            value[i] = build[i][0];
        }
    }   
    //BFS를 진행한다. 
    while(!q.empty()){
        //큐에서 인덱스를 하나씩 꺼내서, 다음 경로에서 가능한 것을 찾는다.
         int p = q.front(); q.pop();
         if(p==w){
            ret = max(ret,value[p]);
         }
         else{
         for(int i=1;i<=path[p];i++){
            if(build[p][i]>=1){
            	int a = build[p][i];
                // 다음 빌드를 짓는데에 드는 최대 비용을 구한다.  
                if(value[a] < value[p]+build[a][0]){
                    value[a] =value[p] + build[a][0];
                    q.push(a);
                 } 	
             }
         }
        }
    }
    return ret;
}
int main(){
    scanf("%d",&t);
    while(t--){
    	//초기화// 
        for(int i=0; i<q.size();i++) q.pop();
        memset(build,0,sizeof(build));
        memset(value,0,sizeof(value));
        memset(isFirst,0,sizeof(isFirst));
        memset(path,0,sizeof(path));
        
        //건물의 갯수와 건설 규칙 순서 
        scanf("%d %d",&n,&k);
        //각 건물 0번 인덱스에 건물의 건설 시간을 저장한다. 
        for(int i=1;i<=n;i++)
            scanf("%d",&build[i][0]);
                     
        for(int i=0;i<k;i++){
            scanf("%d %d",&x,&y);
            //해당 경로가 있음을 표시하기위해  1을 저장한다. 
            build[x][++path[x]] = y;
            //또한 해당 경로가 시작점이 가능한지 아닌지도 체크를 해야된다.
            isFirst[y] = 1; 
        } 
        //목표 건물 
        scanf("%d",&w);
        printf("%d\n",bfs());       
    } 
}
