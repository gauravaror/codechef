//https://www.hackerrank.com/challenges/play-game
#include <iostream>
#include <stdlib.h>
#include <cmath>
#define debug true
#define arrayLength 299915
using namespace std;
int calculateWallConfiguration(int max_length,int * WallConfig) {
	WallConfig[0] = 1;
	WallConfig[1] = 1;
	WallConfig[2] = 1;
	WallConfig[3] = 1;
	for(int i= 4;i<4+max_length;i++) {
		WallConfig[i] = WallConfig[i-1] + WallConfig[i-4];
	}
}

int getPrimeNumberTill(int* count,int * tile) {
	//count[0] = count[1] = count[2] =1;
	bool * is_prime = (bool *)malloc(arrayLength*sizeof(bool));
	is_prime[0] = false;
	is_prime[1] = false;
	is_prime[2] = false;
	for( int i =4;i<tile[41];i+2) {
		is_prime[i] = false;
	}
	for( int j = 3;j<tile[41];j+2) {
		 for(int k=j;k*j<=sqrt(tile[41]);k++)
                is_prime[k*j]=false;
	}
	 count[0]=count[1]=count[2]=0;
    for(int i=2;i<=tile[41];i++)
        {
            count[i]=count[i-1];
            if(is_prime[i]) count[i]+=1;
        }
	
}

int main() {
	if (debug) 
		cout<<"Starting program"<<endl;
	// Number of testcases;
	int * WallConfig = (int *)malloc(41*sizeof(int));
	int * PrimeCalc = (int *)malloc(arrayLength*sizeof(int));
	calculateWallConfiguration(38,WallConfig);
	if (debug) 
		cout<<"test case"<<WallConfig[41]<<endl;
	getPrimeNumberTill(PrimeCalc,WallConfig);
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
		//int combinations = findWallConfiguration(wall_config);
		cout<<" -d sd "<<PrimeCalc[wall_config]<<endl;
	}

}
