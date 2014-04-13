#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>

using namespace std;

int main()
{
	int testcases;
	cin >> testcases;
	while(testcases > 0 ) {
	    string str1,str2;
		cin >> str1;
		cin >> str2;
//		cout<<"str1 "<<str1;
//		cout<<"str2 "<<str2;
	    std::stringstream tmp_stream1;
	    std::stringstream tmp_stream2;
		bool done = false;
	    tmp_stream1 << str1;
		tmp_stream2 << str2;

 		int string_size1 = 	tmp_stream1.str().size();
 		int string_size2 = 	tmp_stream2.str().size();

		int * digits1 = (int *)malloc( string_size1 * sizeof(int));
		int * digits2 = (int *)malloc( string_size2 * sizeof(int));

		//Book keeping for first string
		int count1_4 = 0;
		int count1_7 = 0;
		int count1_l4 = 0;
		int count1_l7 = 0;
		int count1_4l7 = 0;
		int count1_g4l7 = 0;

		//bookkeeping for second string
		int count2_4 = 0;
		int count2_7 = 0;
		int count2_l4 = 0;
		int count2_l7 = 0;
		int count2_4l7 = 0;
		int count2_g4l7 = 0;

		for ( int i = string_size1 -1 ; i >= 0 ; i--) {
			char chart = tmp_stream1.str().at(i);
			digits1[i] = chart - '0' ;
			if (digits1[i] == 4) count1_4++;
			if (digits1[i] == 7) count1_7++;
			if (digits1[i] < 4 ) count1_l4++;
			if (digits1[i] < 7 ) count1_l7++;
			if (digits1[i] < 7 && digits1[i] != 4 ) count1_4l7++;
			if (digits1[i] < 7 && digits1[i] > 4 ) count1_g4l7++;
			
		}
//		cout<<" 4  "<<count1_4<<"   7  "<<count1_7<<"   <4  "<<count1_l4<<"   <7  "<<count1_l7<<"   4<7  "<<count1_g4l7<<endl;
		for ( int i = string_size2 -1 ; i >= 0 ; i--) {
			char chart = tmp_stream2.str().at(i);
			digits2[i] = chart - '0';
			if (digits2[i] == 4) count2_4++;
			if (digits2[i] == 7) count2_7++;
			if (digits2[i] < 4 ) count2_l4++;
			if (digits2[i] < 7 ) count2_l7++;
			if (digits1[i] < 7 && digits2[i] != 4 ) count2_4l7++;
			if (digits2[i] < 7 && digits2[i] > 4 ) count2_g4l7++;
		}
//		cout<<" 4  "<<count2_4<<"   7  "<<count2_7<<"   <4  "<<count2_l4<<"   <7  "<<count2_l7<<"   4<7  "<<count2_g4l7<<endl;
		
		int needed4foroverwritting7 = count1_7 - count2_4l7;
		if (needed4foroverwritting7 > count2_4) {
			count2_4 = 0;
			count1_7 = count1_7 - (needed4foroverwritting7 - count2_4);
		} else if(needed4foroverwritting7 > 0) {
			count2_4 = count2_4 - needed4foroverwritting7;
		}

		int qneeded4foroverwritting7 = count2_7 - count1_4l7;
		if (qneeded4foroverwritting7 > count1_4) {
			count2_4 = 0;
			count1_7 = count1_7 - (qneeded4foroverwritting7 - count1_4);
		} else if (qneeded4foroverwritting7 > 0) {
			count1_4 = count1_4 - qneeded4foroverwritting7;
		}
		
		if ( count1_4 > count2_l4) {
			count1_4 = count2_l4;
		}
		if ( count2_4 > count1_l4) {
			count2_4 = count1_l4;
		}
		for(int k=0;k<count1_7+count2_7;k++) {
			cout<<"7";
		}
		for(int k=0;k<count1_4+count2_4;k++) {
			cout<<"4";
		}
		testcases--;
		cout<<endl;
		}
    return 0;
}

