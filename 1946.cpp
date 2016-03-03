자신을 제외한 다른 모든 신입사원과 비교해서 가능해야하므로
두 점수중 하나라도 1등인 지원자는 무조건 선발된다.(한명(두 종목 다 1등) 혹은 두명)
//서류점수를 오름차순으로 정렬한다. 그후 서류등수를 내려가면서
//서류점수 1등의 면접점수보다 등수가 높은사람을 찾는다, 찾으면 카운터를 하나 증가시키고
//그 지원자의 면접등수를 다시 기준으로 설정하고, 그 면접보다 등수가 높은사람을 찾아나간다. 
//그 뒤에 그 인원보다 면접점수가 높은 사람은 서류등수가 기준이된 면접점수자보다 항상 높으므로
//선발이 가능하다. 
 
#include <cstdio>
#include <algorithm>
int t,n,rank[100000][2],r1,r2;
int recruit(){
	//정렬한다. 
	for(int i = 0; i<n; i++){
		for(int j= 1;j<n-i;j++){
			if(rank[j][0]<rank[j-1][0]){
				std::swap(rank[j][0],rank[j-1][0]);
				std::swap(rank[j][1],rank[j-1][1]);
			}
		}
	}
	
	int min = rank[0][1],count = 1;;
	for(int i=0;i<n;i++){
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
		printf("%d\n",recruit());
	}
}
