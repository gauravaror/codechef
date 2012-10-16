#include <stdio.h>
#include <iostream>

using namespace std;

int main(int argv ,char ** argc) {
unsigned int testcases;
cin>>testcases;
unsigned int numberdish;

for (int i = 0; i < testcases ; i++ ) {
unsigned long long menus = 3;
	cin>> numberdish;
	for ( int i =0;i<numberdish-1;i++) {
	menus  = (3*menus)%(1000000007);
	}
	if(numberdish % 2  == 0) {
	menus += 3;
	} else {
	menus -= 3;
	}
cout<<menus<<endl;
}
}
