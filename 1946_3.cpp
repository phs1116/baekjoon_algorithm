#include <cstdio>
using namespace std;
int t,n,rank[100001],rx,ry;
int recruit(){
	int min = rank[1],count = 1;
	for(int i=1;i<=n;i++){
		if(min>rank[i]){
			count++;
			min = rank[i];
		}
	}	
	return count;
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		//�� ����� ��� �Է� 
		for(int i =0; i<n;i++){
			//�������� ��� ������� ���� ������ �Է¹޴´�. 
			scanf("%d %d",&rx,&ry);
			rank[rx] = ry; 
		}
		printf("%d\n",recruit());
	}
}
