#include <iostream>
using namespace std;
int gcd(int n1,int n2){
	return n2==0?n1:gcd(n2,n1%n2);
}
int main(){
	int testcase,a,b;
	cin>>testcase;
	while(testcase--){
		cin>>a>>b;
		cout<<a*b/gcd(a,b)<<endl;
	}
}
