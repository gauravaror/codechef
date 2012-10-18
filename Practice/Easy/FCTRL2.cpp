#include <iostream>
#include <malloc.h>

#define ONLINE_JUDGE

using namespace std;

// Variable to store the factorial of number and since it can be of 200 digit .. we store it in array form
int number[101][200];

// Stores the length of facorial for all number;
int digits[101];

//Print the Value for the factorial at number @number
void printnumber(int numb) {
	for (int i = digits[numb]-1;i>=0;i--) {
		cout<<number[numb][i];
	}
	cout<<endl;
}

// this function perform the actual calcultion of factorial for the number by multiplying with previous numbers
void calfac(int k) {
int addtonext  = 0;
for (int i  = 0;i < digits[k-1];i++) {
	int multans = k*number[k-1][i] + addtonext;
	int thisposition = multans%10;
	addtonext = multans/10;
	number[k][i] = thisposition;
}
int i = 0;
while( addtonext > 0) {
i++;
    #ifndef ONLINE_JUDGE
	cout<<"Add to next  "<<addtonext<<endl;
    #endif
int thisposition = addtonext%10;
    #ifndef ONLINE_JUDGE
	cout<<"Add to this "<<addtonext<<endl;
    #endif
number[k][digits[k-1] - 1 +i] = thisposition;
    #ifndef ONLINE_JUDGE
	cout<<"Add to  "<<number[k][digits[k-1]+i]<<" k "<<k<<" i "<<i<<"  difi "<<digits[k-1]<<endl;
    #endif
addtonext = addtonext/10;
}
digits[k] = digits[k-1]+i;
}
int main() {
int testcases;
    #ifndef ONLINE_JUDGE
		cout<<"Starting the solution solution"<<endl;
    #endif
// stores the maimimum value calculated
int maximum_calculated = 1;
cin>>testcases;
int num;
number[1][0]  = 1;
digits[1] = 1;
for ( int i = 0;i<testcases;i++) {
	cin>>num;
	if (num < maximum_calculated ) {
		printnumber(num);
		continue;
	} else {
		for (int k = maximum_calculated+1 ;k < num +1 ;k++ ) {
			calfac(k);
		}
		printnumber(num);
		maximum_calculated = num;
	}
}
return 0;
}

