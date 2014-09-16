#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <algorithm> 
#include <stdio.h>
#define debug true

using namespace std;

int main() {
	int number;
	while(cin>>number) {
	bool found = false;
	if(debug)
		cout<<"number: "<<number<<endl;
	bool sol;
/*	int 4dime = 1;
	int 1/2dime = 1;
	int 1/4dime = 1;*/
	int y,z;
	int loopbound = (3*number - 17)/15;
	for( int x=1 ; x < loopbound+1;x++) {
		y = 3*number - 16 - 15*x;
		z = number - 3 -x - y;
		if ( z < 1) {
			continue;
		}
		int calc  = 4*(x+1) + (0.5)*(y+1) + (0.25)*(z+1);
		int finalcoincount = x + y + z +3;
		if( finalcoincount == number && calc == number) {
			cout<<x+1<<" coins of 4 asiap each"<<endl;
			cout<<y+1<<" coins of 1/2 asiap each"<<endl;
			cout<<z+1<<" coins of 1/4 asiap each"<<endl;
			cout<<"==="<<endl;
			found = true;
			break;
		}

	}
	if(!found) {
		cout<<"No Solution found"<<endl;
		cout<<"==="<<endl;
	}
}
}