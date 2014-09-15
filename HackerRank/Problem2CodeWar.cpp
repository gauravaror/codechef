#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <algorithm> 
#include <stdio.h>
#define debug false

using namespace std;


double findWeigt(int * weightconfig_,int ** discrete,int discretecount,int** contious,int contiouscount) {
	double currentTastiness = 0.0 ;
	for( int i = 0 ; i < discretecount;i++) {
		for(int j = 0; j < weightconfig_[i]; j++) {
			currentTastiness += (discrete[i][1] - (j*discrete[i][2]));
		}
	}
	for( int i = 0 ; i < contiouscount;i++) {
		currentTastiness += ((contious[i][0]*weightconfig_[discretecount + i]) - ((contious[i][1]*weightconfig_[discretecount +i]*weightconfig_[discretecount + i])/2.0));
	}
	
	return currentTastiness;
}

double findTastenessWithaddition(int * weightconfig_,int addtion,int ** discrete,int discretecount,int** contious,int contiouscount) {

	weightconfig_[addtion]++;
	double weightCal = findWeigt(weightconfig_,discrete,discretecount,contious,contiouscount);
	weightconfig_[addtion]--;
	return weightCal;

}


int main() {
	int components,weight;
	cin>>components;
	cin>>weight;
	if(debug)
		cout<<"Weight: "<<weight<<"components : "<<components<<endl;
	int** discrete = (int **) malloc(components*sizeof(int *));
	int** contious = (int **) malloc(components*sizeof(int *));
	int* weightopt = (int *)malloc(weight+1*sizeof(int));
	int** weightconfig = (int **)calloc(weight+1,sizeof(int *));
	for (int a =0;a < weight+1;a++)	 {
		weightconfig[a] = (int *) malloc(components*sizeof(int));
		for (int b =0;b < components;b++)	 {
			weightconfig[a][b] = 0;
		}
	}
	weightopt[0] = 0;

	for (int a =0;a < components;a++)	 {
		discrete[a] = (int *) malloc(3*sizeof(int));
		contious[a] = (int *) malloc(3*sizeof(int));
	}
	int discretecount = 0 ;
	int contiouscount = 0 ;

	for (int i = 0; i < components; ++i)
	{
		char type;
		cin>>type;
		if (type == 'D') {
			cin>>discrete[discretecount][0];
			cin>>discrete[discretecount][1];
			cin>>discrete[discretecount][2];
			discretecount++;

		} else if( type == 'C') {
			cin>>contious[contiouscount][0];
			cin>>contious[contiouscount][1];
			contiouscount++;
			if(debug)
				cout<<"contious 0  : "<<contious[i][0]<<"contious 1 : "<<contious[i][1]<<endl;
		}

	}

	if(debug)
		cout<<"discretecount : "<<discretecount<<"contiouscount : "<<contiouscount<<endl;
	for( int i=1;i< weight+1;i++) {
		double maxweight = 0;
		int maxweightpostn = -1;
		double currenttasteness = 0 ;
		int currenttastenesspostn = -1;
		int copyPostn = -1;
		for( int j =0; j< discretecount;j++) {
			if(((i-discrete[j][0]) >= 0)  && weightopt[i-discrete[j][0]] >= 0) {
				currenttasteness  = findTastenessWithaddition(weightconfig[(i-discrete[j][0])],j,discrete,discretecount,contious,contiouscount);
				currenttastenesspostn = j;
			}
		

			if(currenttasteness > maxweight) {
				maxweight = currenttasteness;
				maxweightpostn = currenttastenesspostn;
				copyPostn = i-discrete[j][0];
			}

		}
		
		for( int j =0; j< contiouscount;j++) {
			currenttasteness  = findTastenessWithaddition(weightconfig[(i-1)],discretecount + j,discrete,discretecount,contious,contiouscount);
			currenttastenesspostn = discretecount + j;

			if(currenttasteness > maxweight) {
				maxweight = currenttasteness;
				maxweightpostn = currenttastenesspostn;
				copyPostn = i-1;
			}
		}
		if(maxweightpostn != -1 ) { 
			weightopt[i] = maxweight;
			
			for (int k = 0;k<components;k++) {
				weightconfig[i][k] = weightconfig[copyPostn][k];
			}
			weightconfig[i][maxweightpostn]++;
		} else {
			weightopt[i] = -1;
		}
	}
	double finalWeight = findWeigt(weightconfig[weight],discrete,discretecount,contious,contiouscount);
	if(finalWeight ==0 ){
		cout<<"Impossible"<<endl;
	} else {
		cout<<finalWeight<<endl;
	}

}
