//https://www.hackerrank.com/challenges/play-game
#include <iostream>
#include <stdlib.h>
#define debug false
using namespace std;


int maximum(unsigned long long int x, unsigned long long int y, unsigned long long int z) {
	int max = x; /* assume x is the largest */

	if (y > max) { /* if y is larger than max, assign y to max */
		max = y;
	} /* end if */

	if (z > max) { /* if z is larger than max, assign z to max */
		max = z;
	} /* end if */

	return max; /* max is the largest value */
} 

void setOptimalScoreAndMove( unsigned long long int * optimalMoveScore, int * optimalMove, int current,int picked1,int picked2,int picked3) {
	unsigned long long int max  = maximum(picked1,picked2,picked3);
	if( max == picked3) {
		optimalMove[current] = 3;
		optimalMoveScore[current] = picked3;
	} else if (max == picked2) {
		optimalMove[current] = 2;
		optimalMoveScore[current] = picked2;
	} else if (max == picked1) {
		optimalMove[current] = 1;
		optimalMoveScore[current] = picked1;
	}

}

long long int getOptimalScore (long long int * bricks,unsigned long long int * optimalMoveScore, int * optimalMove, int start,int end) {
	bool getScore=false;
	unsigned long long int score=0;
	int otherMove =  optimalMove[start];
	start = start + otherMove;
	if(start <= end) {
		return optimalMoveScore[start];
	} else {
		return 0;
	}

}

void findOptiomalMoves (long long int * bricks,unsigned long long int * optimalMoveScore, int* optimalMove, int start,int end) {

	optimalMove[end]  = 1;
	optimalMoveScore[end] = 	bricks[end];
	optimalMove[end-1]  = 2;
	optimalMoveScore[end-1] =  bricks[end] + bricks[end-1];
	optimalMove[end-2]  = 3;
	optimalMoveScore[end-2] =  bricks[end] + bricks[end -1] + bricks[end -2];
	for( int i=end-3; i >= start; i--) {
		long long int picked1 = bricks[i] + getOptimalScore(bricks,optimalMoveScore ,optimalMove,i+1,end);
		long long int picked2 = bricks[i] + bricks[i+1] + getOptimalScore(bricks,optimalMoveScore , optimalMove,i+2,end);
		long long int picked3 = bricks[i] + bricks[i+1] + + bricks[i+2]  + getOptimalScore(bricks,optimalMoveScore ,optimalMove,i+3,end);
		setOptimalScoreAndMove(optimalMoveScore,optimalMove,i,picked1,picked2,picked3);
	}
		
}

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
		unsigned long long int * optimalMoveScore = (unsigned long long int *)malloc(bricks*sizeof(unsigned long long int));
		int * optimalMove = (int *)malloc(bricks*sizeof(int));
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
		findOptiomalMoves(storebricks,optimalMoveScore , optimalMove,0,bricks-1);
	//	calculateMaxScore(storebricks,optimalMove , 0,bricks-1);
		cout<<optimalMoveScore[0]<<endl;

	}

}
