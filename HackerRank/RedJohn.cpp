//https://www.hackerrank.com/challenges/play-game
#include <iostream>
#include <stdlib.h>
#define debug true
using namespace std;
int findWallConfiguration(int wall_config) {

}

int getPrimeNumberTill(int till) {

}

int main() {
	if (debug) 
		cout<<"Starting program"<<endl;
	// Number of testcases;
	int N;
	cin>>N;
	if (debug) 
		cout<<"Number of testcases: "<<N<<endl;
	for (int i=0;i<N;i++) {
		if (debug) 
		cout<<"testcase :"<<i<<endl;
		int wall_config;
		cin>>wall_config;
		if (debug)
			cout<<"current wall config: "<<wall_config;
		int combinations = findWallConfiguration(wall_config);
		cout<<getPrimeNumberTill(combinations)<<endl;
	}

}
