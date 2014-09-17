//https://www.hackerrank.com/challenges/dortmund-dilemma
#include <iostream>
#include <stdlib.h>
#define debug false
#define MOD 1000000009
#define maxlen 100010
#define long long ll


using namespace std;

ll combinationdata[28][28];
ll cases[maxlen][27];
ll combination(ll N,ll K) {
	if(K> N) return 0;
	if(K == 1) return N;
	if(K == 0) return 0;
	if(N == K) return 1;
	if(combination[N][K] == -1 )  combinationdata[N,K] = (combination(N-1,K) + combination(N-1,K-1))%MOD;
	return combinationdata[N,K];
}

void calculateCases() {
	// Calculate all the String with k characters and no proper suffix and prefix.

	for( int i = 1 ;i < maxlen;i++) {
		for( int j = 1;j< K;j++){
			if( i == 1) cases[i][j] = j;
			else {
				
			}
		}
	}
}

int main() {
	if(debug) 
		cout<<"Starting program"<<endl;
	calculateCases();
	int N;
	cin>>N;
	if(debug) 
		cout<<"Number of testcases"<<N<<endl;
	for(int i=0;i<N;i++) {
		if(debug) 
		cout<<"testcase :"<<i<<endl;
		int namelength,diffchars;
		cin>>namelength>>diffchars;
		if(debug) 
			cout<<" Length of Name: "<<namelength<<" Diff type of chars: "<<diffchars<<end;
		cout<<(combination(26,diffchars)*cases[n,k])%MOD<<endl;
	}
}