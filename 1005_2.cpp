#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm> 
using namespace std;
//�� �ǹ��� �ε��� 0���� �Ǽ� �ð��� �����Ѵ�. 
int t,build[1001][1001],isFirst[1001]={0,},value[1001],path[1001];
int x,y,n,k,w;
queue<int> q; 
 
int bfs(){  
    int ret = 0;
    //�������� ������ �͵��� ���� ť�� �ִ´�. 
    for(int i=1;i<=n;i++){
        if(isFirst[i]==0){
            q.push(i);
            //�ʱ� ������ ���� ����� �Ǽ� ������� �ʱ�ȭ�Ѵ�. 
            value[i] = build[i][0];
        }
    }   
    //BFS�� �����Ѵ�. 
    while(!q.empty()){
        //ť���� �ε����� �ϳ��� ������, ���� ��ο��� ������ ���� ã�´�.
         int p = q.front(); q.pop();
         if(p==w){
            ret = max(ret,value[p]);
         }
         else{
         for(int i=1;i<=path[p];i++){
            if(build[p][i]>=1){
            	int a = build[p][i];
                // ���� ���带 ���µ��� ��� �ִ� ����� ���Ѵ�.  
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
    	//�ʱ�ȭ// 
        for(int i=0; i<q.size();i++) q.pop();
        memset(build,0,sizeof(build));
        memset(value,0,sizeof(value));
        memset(isFirst,0,sizeof(isFirst));
        memset(path,0,sizeof(path));
        
        //�ǹ��� ������ �Ǽ� ��Ģ ���� 
        scanf("%d %d",&n,&k);
        //�� �ǹ� 0�� �ε����� �ǹ��� �Ǽ� �ð��� �����Ѵ�. 
        for(int i=1;i<=n;i++)
            scanf("%d",&build[i][0]);
                     
        for(int i=0;i<k;i++){
            scanf("%d %d",&x,&y);
            //�ش� ��ΰ� ������ ǥ���ϱ�����  1�� �����Ѵ�. 
            build[x][++path[x]] = y;
            //���� �ش� ��ΰ� �������� �������� �ƴ����� üũ�� �ؾߵȴ�.
            isFirst[y] = 1; 
        } 
        //��ǥ �ǹ� 
        scanf("%d",&w);
        printf("%d\n",bfs());       
    } 
}
