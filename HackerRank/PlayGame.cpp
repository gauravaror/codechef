//https://www.hackerrank.com/challenges/play-game
#include <iostream>
#include <stdlib.h>
#define debug true
using namespace std;

long long int calculateMaxScore(long long int * bricks,int start,int end);

int main() {
	if(debug) 
		cout<<"Starting program"<<endl;
	// Number of testcases;
	int N;
	cin>>N;
	if(debug) 
		cout<<"Number of testcases"<<N<<endl;
	for(int i=0;i<N;i++) {
		if(debug) 
		cout<<"testcase :"<<i<<endl;
		int bricks;
		cin>>bricks;
		long long int * storebricks = (long long int *)malloc(bricks*sizeof(long long int));
		if(debug) 
		cout<<"bricks for this testcase:"<<bricks<<endl;
		for(int j = 0;j < bricks; j++){
			cin>>storebricks[j];
		}
		if (debug){
			for(int j = 0;j < bricks; j++){
				cout<<storebricks[j]<<" , ";
			}
			cout<<endl;
		}
		calculateMaxScore(storebricks,0,bricks-1);

	}

}

long long int calculateMaxScore(long long int * bricks,int start,int end) {


}