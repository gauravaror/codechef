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
		unsigned long long int optimalMove = (unsigned long long int *)malloc(bricks*sizeof(unsigned long long int));
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
		findOptiomalMoves(storebricks,optimalMove , 0,bricks-1);
		calculateMaxScore(storebricks,optimalMove , 0,bricks-1);

	}

}

long long int findOptiomalMoves (long long int * bricks,unsigned long long int optimalMove, int start,int end) {

	for( int i=end ; i< start; i--) {
		long long int picked1 = pick1(storebricks,optimalMove , i,end);
		long long int picked2 = pick2(storebricks,optimalMove , i,end);
		long long int picked3 = pick3(storebricks,optimalMove , i,end);
		if( picked1 > picked3) {
			if(picked1 >picked2) {

			} else if(picked1 >picked2) {

			} else if(picked1 == picked2 ) {

			}
		} else if (picked1 < picked3) {
			if(picked3 > picked2) {

			} else if(picked3 >picked2) {

			} else if(picked3 == picked2 ) {

			}

		}
	}


}

long long int calculateMaxScore (long long int * bricks,unsigned long long int optimalMove, int start,int end) {


}

long long int pick1 (long long int * bricks,unsigned long long int optimalMove, int current,int end) {

}

long long int pick2 (long long int * bricks,unsigned long long int optimalMove, int current,int end) {
	
}

long long int pick3 (long long int * bricks,unsigned long long int optimalMove, int current,int end) {
	
}