#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
vector<int> ret;
int n, t, a[13], count=0,flag=0;
//이 위치에 여왕말을 놓을수 있는지, 즉 유망한지 체크한다. 
bool check(int cur) {
	//0부터 이 행까지 모두 조사한다. 
	for (int i = n; i>cur; i--) {
		//열이 같은 것이 있거나, 대각선범위내에 있으면 불가능한 경우므로 false로 셋트. 
		if(ret[i]==ret[cur] || i-cur==abs(ret[cur]-ret[i])){
			return false;
		}	 
	}
	return true;
}
void nqueen(int cur) { 
	//기저사례 : 끝에 도달았으면 플래그를 갱신하고  반환한다. 
	if(cur==0) {
		flag=1;
		return; 
	}

	//아직 끝에 도달하지 않았으면 다음 위치를 찾는다. 
	for(int i=0;i<n;i++){
		ret.push_back(i);
		//check이 참이면 벡터에 넣고 다음 여왕말을 찾고, 못찾으면 백트래킹한다.
		if(check(cur-1)){
			nqueen(cur-1);
			if(flag==1) return;
		}
		ret.pop_back();
	} 
}
int main() {
	scanf("%d",&t);
	while(t--){
		ret.clear();
		count = 0;
		scanf("%d", &n);
		nqueen(n+1);
		//printf("\n%d\n",count);
		for(int i=0; i<n;i++){
			printf("%d ",ret[i]+1);
		}
	}	
}
