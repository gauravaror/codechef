#include <iostream>
#include <malloc.h>
#include <math.h>

using namespace std;

long double **pattern;
int main() {
int testcases;
cin>>testcases;
pattern = (long double **)malloc(2000*sizeof(long double));
pattern[0] = (long double *)malloc(1*sizeof(long double));
pattern[0][0] = 1.0/2.0;
pattern[1] = (long double *)malloc(2*sizeof(long double));
pattern[1][0] = 1.0/2.0;
pattern[1][1] = 1.0/2.0;
pattern[2] = (long double *)malloc(3*sizeof(long double));
pattern[2][0] = 0.75;
pattern[2][1] = 0.5;
pattern[2][2] = 0.75;
for(int i = 3; i< 2000;i++) {
//	cout<<"Entering patter"<<i<<endl;
	pattern[i] = (long double *)calloc((i+1),sizeof(long double));
	for (int j =0;j<i+1;j++) {
		if( j < i-1 ) {
		pattern[i][j] += pattern[i-2][j]/4.0;
		}
		if(j > 0 && j < i) {
			pattern[i][j] += 2.0*pattern[i-2][j-1]/4.0;
		}
		if(j > 1 && j < i+1) {
			pattern[i][j] += pattern[i-2][j-2]/4.0;
		}
		if( (j == 0 || j == i)) {
		pattern[i][j] += 0.5;
		}
	}
	float sum = 0;
//	cout<<"i   "<<i<<endl;
	for (int j =0;j<i+1;j++) {
	sum = sum + pattern[i][j];
//	cout<<pattern[i][j]<<"  ";
	}
//	cout<<"\nSUM :"<<sum<<endl;
//	cout<<" Answer :"<<sum;
//	cout<<endl;
}
pattern[0][0] = 1.0;	
int NumberDiamond;
for ( int k =0 ;k<testcases;k++) {
cin>>NumberDiamond;
int value;
double sum = 0.0;
for(int l = 0;l<NumberDiamond;l++) {
cin>>value;
/*cout<<"value :"<<value<<endl;
cout<<"pattern value :"<<pattern[NumberDiamond-1][l]<<endl;
cout<<"Sum"<<sum<<endl;*/

sum = sum + pattern[NumberDiamond-1][l]*value;
}
sum = (double)sum*1.000;
printf("%f\n",sum);
//cout<<sum<<endl;
}
}

