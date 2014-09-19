//https://www.hackerrank.com/challenges/dortmund-dilemma
#include <iostream>
#include <stdlib.h>

using namespace std;


#define debug false
#define MOD 1000000009
#define maxlen 100010





long long combinationdata[28][28];
long long cases[maxlen][27];
long long combination(int N,int K) {
	if (debug)
	{
		cout<<"combination : "<<N<<" K : "<<K<<"  combinationdata "<<combinationdata[N][K]<<endl;
	}
	if(K> N) return 0;
	if(K == 1) return N;
	if(K == 0) return 0;
	if(N == K) return 1;
	if(combinationdata[N][K] == -1  || combinationdata[N][K] == 0)  combinationdata[N][K] = (combination(N-1,K) + combination(N-1,K-1))%MOD;
	return combinationdata[N][K];
}

void calculateCases() {
	// Calculate all the String with k characters and no proper suffix and prefix.

	for( int i = 1 ;i < maxlen;i++) {
		if(debug) cout<<"Stage 1"<<i<<endl;
		for( int j = 1;j< 27;j++){
			if( i == 1) cases[i][j] = j;
			else {
				cases[i][j] = (j*cases[i-1][j])%MOD;
				if(i%2 == 0) {
					cases[i][j] -= cases[i/2][j];
					cases[i][j] %= MOD;
				}
				if(cases[i][j] < 0 ) cases[i][j] += MOD;
			}
				if(debug) cout<<cases[i][j]<<"i "<<i<<" j "<<j<<"  before stage 1"<<endl;
		}
	
	}


	// Calculate the string with atleast one or more prper suffix and prefix.
	for (int i = 1; i < 27; ++i)
	{
		if(debug) cout<<"Stage 2"<<i<<endl;
		long long prod=1;
		for (int j = 1; j < maxlen; ++j)
		{
				prod *= i;
				prod %= MOD;
				cases[j][i] = prod - cases[j][i];
				cases[j][i]%= MOD;
				if(cases[j][i] < 0 ) cases[j][i] += MOD;
				if(debug)  cout<<cases[j][i]<<"i "<<i<<" j "<<j<<"  before stage 2"<<endl;
		}
	}

	//Make the string with all the k characters.

	for (int i = 1; i < 27; ++i)
	{
		if(debug) cout<<"Stage 3"<<i<<endl;
		long long prod=1;
		for (int j = 1; j < maxlen; ++j) {
			for (int l = i; l >= 1; l--)
			{
				if(debug)  cout<<cases[j][i]<<"i "<<i<<" j "<<j<<"  before "<<endl;
				cases[j][i] -= (combination(i,l-1)*cases[j][l-1])%MOD;
				cases[j][i]%= MOD;
				if(cases[j][i] < 0 ) cases[j][i] += MOD;
				if(debug)  cout<<cases[j][i]<<"i "<<i<<" j "<<j<<endl;
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
			cout<<" Length of Name: "<<namelength<<" Diff type of chars: "<<diffchars<<"  cases ans"<<cases[namelength][diffchars]<<" combination"<<combination(26,diffchars)<<endl;
		cout<<(combination(26,diffchars)*cases[namelength][diffchars])%MOD<<endl;
	}
}