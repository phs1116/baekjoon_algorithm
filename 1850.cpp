#include <iostream>
using namespace std;
int gcd(int n1,int n2){
	return n2==0?n1:gcd(n2,n1%n2);
}
int main(){
	int a,b;
	cin>>a>>b;
	cout<<gcd(a,b)<<endl;
}
