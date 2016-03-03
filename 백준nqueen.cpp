#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
vector<int> ret;
int n, t, a[13], count=0,flag=0;
//�� ��ġ�� ���ո��� ������ �ִ���, �� �������� üũ�Ѵ�. 
bool check(int cur) {
	//0���� �� ����� ��� �����Ѵ�. 
	for (int i = n; i>cur; i--) {
		//���� ���� ���� �ְų�, �밢���������� ������ �Ұ����� ���Ƿ� false�� ��Ʈ. 
		if(ret[i]==ret[cur] || i-cur==abs(ret[cur]-ret[i])){
			return false;
		}	 
	}
	return true;
}
void nqueen(int cur) { 
	//������� : ���� ���޾����� �÷��׸� �����ϰ�  ��ȯ�Ѵ�. 
	if(cur==0) {
		flag=1;
		return; 
	}

	//���� ���� �������� �ʾ����� ���� ��ġ�� ã�´�. 
	for(int i=0;i<n;i++){
		ret.push_back(i);
		//check�� ���̸� ���Ϳ� �ְ� ���� ���ո��� ã��, ��ã���� ��Ʈ��ŷ�Ѵ�.
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
