// This is Magician Question of CodeJam.

#include <iostream>
#include <stdlib.h> 

using namespace std;

int main() {

	int notest;
	cin >> notest;
	//cout<<notest;
	int * rownumbers = (int *)malloc(sizeof(int)*4);
	int * rowdata = (int *)malloc(sizeof(int)*4);
	int * columndata = (int *)malloc(sizeof(int)*4);
	int ** rownumbers2 = (int **)malloc(sizeof(int)*4);
	for (int i =0;i<4;i++) {
		rownumbers2[i] = (int *)malloc(sizeof(int)*4);
	}
	for (int i=0;i<notest;i++) {
		int firstrow;
		int secondrow;
		cin>>firstrow;
		//cout<<firstrow;
		for (int j=0;j<4;j++) {
			for (int k=0;k<4;k++){
				int tmp;
				if (j==(firstrow-1)) {
					cin >> rownumbers[k];
				}
				else {
					cin >> tmp;
				}
			}
		}

		cin>>secondrow;
		//cout<<secondrow;
		int count=0;
		for (int j=0;j<4;j++) {
			for (int k=0;k<4;k++){
				cin >> rownumbers2[j][k];
				if (rownumbers2[j][k] == rownumbers[0] || rownumbers2[j][k] == rownumbers[1] || rownumbers2[j][k] == rownumbers[2] || rownumbers2[j][k] == rownumbers[3]) {
					rowdata[count] = j;
					columndata[count] = k;
					//cout<<j<<k;
					count++;
				}
			}
		}
		int count1 =0;
		int index;
		for (int a =0;a<4;a++) {
			if ( rowdata[a] == (secondrow-1)) {
				count1++;
				index = a;

			}
			//cout<<count1<<index<<rowdata[i]<<secondrow;
		}
		if (count1 == 1) {
			cout<<"Case #"<<i+1<<": "<<rownumbers2[rowdata[index]][columndata[index]]<<"\n";
		}
		else if (count1 > 1) {
			cout<<"Case #"<<i+1<<": Bad magician!"<<"\n";
		}
		else if( count1 == 0) {
			cout<<"Case #"<<i+1<<": Volunteer cheated!"<<"\n";
		}

	}
			
}
