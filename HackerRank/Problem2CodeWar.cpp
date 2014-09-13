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
	int components,weight;
	cin>>components;
	cin>>weight;
	if(debug)
		cout<<"Weight: "<<weight<<"components : "<<components<<endl;
	int** discrete = (int **) malloc(components*sizeof(int *));
	int** contious = (int **) malloc(components*sizeof(int *));
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
			cin>>discrete[i][0];
			cin>>discrete[i][1];
			cin>>discrete[i][2];
			discretecount++;

		} else if( type == 'C') {
			cin>>contious[i][0];
			cin>>contious[i][1];
			contiouscount++;
		}
	}
	if(debug)
		cout<<"discretecount : "<<discretecount<<"contiouscount : "<<contiouscount<<endl;

}
