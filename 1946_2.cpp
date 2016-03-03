#include <cstdio>
#include <algorithm>
int t,n,rank[100000][2],r1,r2;

void qsort(int s, int e) {
	int pivot = rank[s][0];
	int bs = s, be = e;
	while (s<e) {	
		while (pivot <= rank[e][0]&&s<e) e--;
		if (s>e) break;
		while (pivot >= rank[s][0]&&s<e) s++;
		if (s>e) break;
		std::swap(rank[s][0], rank[e][0]);
		std::swap(rank[s][1], rank[e][1]);
	}
	std::swap(rank[bs][0], rank[s][0]);
	std::swap(rank[bs][1], rank[s][1]);
	if(bs<s)
		qsort(bs, s-1);
	if(be>e)
		qsort(s+1, be);

}

int recruit(){
	int min = rank[0][1],count = 1;
	for(int i=1;i<n;i++){
		if(min>rank[i][1]){
			count++;
			min = rank[i][1];
		}
	}	
	return count;
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		//각 사원의 등수 입력 
		for(int i =0; i<n;i++){
			scanf("%d %d",&rank[i][0],&rank[i][1]);
			if(rank[i][0] == 1) r1 = i;
			if(rank[i][1] == 1) r2 = i;
		}
		//서류점수를 오름차순으로 정렬 
		qsort(0,n-1);
		printf("%d\n",recruit());
	}
}
