
#include <iostream>
#include <stdlib.h> 

#define printdebug false
#define value 1000000000
long long result[value][value];

using namespace std;

void calculateBitWiseAnd() {
	for (int i=0;i<value;i++) {
		for (int k=0;k<value;k++){
			result[i][k] = (i)&(k);
		}
	}
	if(printdebug) {
		cout<<"\n";
	for (int i=0;i<value;i++) {
		for (int k=0;k<value;k++){
			cout<<result[i][k]<<"  ";
		}
		cout<<"\n";
	}	
	}
}

long long calculateAnswer(long long A,long long B,long long K){
	long long count =0;
	for (int i=0;i<A;i++) {
		for (int k=0;k<B;k++){
			if(result[i][k] < K) {
				count++;
			}
		}
	}
	return count;
}
int main() {

	int notest;
	cin >> notest;
	if (printdebug) {
		cout<<notest;
	}
	
	long long A,B,K;
	

	if (printdebug) {
		cout<<"A : "<<A<<" B: "<<B<<" K: "<<K;
	}
	
	

	
	calculateBitWiseAnd();	
	for (int i=0;i<notest;i++) {
		cin>>A;
		cin>>B;
		cin>>K;
		long long Ans = calculateAnswer(A,B,K);
		cout<<"Case #"<<i+1<<": "<<Ans<<"\n";

	}
}

