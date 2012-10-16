#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main()
{
	int testcases;
	cin >> testcases;
	getchar();
	while(testcases > 0 ) {
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
		
		 char char1 = getchar();
		//cout<<"CHar"<<char1-'1';
		int  a =0;
		while(a != -39) {
			int dig1 = char1 - '0' ;
			if (dig1 == 4) count1_4++;
			if (dig1 == 7) count1_7++;
			if (dig1 < 4 ) count1_l4++;
			if (dig1 < 7 ) count1_l7++;
			if (dig1 < 7 && dig1 != 4 ) count1_4l7++;
			if (dig1 < 7 && dig1 > 4 ) count1_g4l7++;
			char1 = getchar();
			a = char1 - '1';
		//cout<<"CHar    "<<a;
		}
		//cout<<" 4  "<<count1_4<<"   7  "<<count1_7<<"   <4  "<<count1_l4<<"   <7  "<<count1_l7<<"   4<7  "<<count1_g4l7<<endl;
		char chart2 = getchar();
		int size = 0;
//		cout<<"CHar"<<chart2;
		while(chart2 -'1' != -39) {
			int dig2 = chart2 - '0';
			if (dig2 == 4) count2_4++;
			if (dig2 == 7) count2_7++;
			if (dig2 < 4 ) count2_l4++;
			if (dig2 < 7 ) count2_l7++;
			if (dig2 < 7 && dig2 != 4 ) count2_4l7++;
			if (dig2 < 7 && dig2 > 4 ) count2_g4l7++;
			chart2 = getchar();
			size++;
//			cout<<"CHar"<<chart2;
		}
//		cout<<" 4  "<<count2_4<<"   7  "<<count2_7<<"   <4  "<<count2_l4<<"   <7  "<<count2_l7<<"   4<7  "<<count2_g4l7<<endl;
		
		int needed4foroverwritting7 = count1_7 - count2_4l7;
		if ( count1_7 > count2_g4l7) {
			int tmp  = count1_7 - count2_g4l7;
			count2_g4l7 = 0;
			if ( tmp > count2_l4 ) {
				tmp = tmp - count2_l4; 
				count2_l4 = 0;
			} else {
				count2_l4 = count2_l4 - tmp;
			}
		} else {
			count2_g4l7 = count2_g4l7 - count1_7;
		}

		if (needed4foroverwritting7 > count2_4) {
			int got7s = count2_4;
			count2_4 = 0;
			int needeed7 =  (needed4foroverwritting7 - count2_4);
			if ( needeed7 > 0 && count2_7 > 0 ) {
				if ( needeed7 > count2_7 ) {
					needed4foroverwritting7 = needed4foroverwritting7 - count2_7;
					got7s += count2_7;
					count2_7 = 0;	
				}
				else {
				needed4foroverwritting7 = needed4foroverwritting7 - needeed7 ;
				count2_7 = count2_7 - needeed7;
				got7s += needeed7;
				}
			}
			count1_7 = count1_7 - (needed4foroverwritting7 - got7s);
		} else if(needed4foroverwritting7 > 0) {
			count2_4 = count2_4 - needed4foroverwritting7;
		}

		int qneeded4foroverwritting7 = count2_7 - count1_4l7;
		if (qneeded4foroverwritting7 > count1_4) {
			int got7s = count1_4;
			int needeed7 =  (qneeded4foroverwritting7 - count1_4);
			if ( needeed7 > 0 && count1_7 > 0 ) {
				if ( needeed7 > count1_7 ) {
					qneeded4foroverwritting7 = qneeded4foroverwritting7 - count1_7;
					got7s += count1_7;
					count1_7 = 0;	
				}
				else {
				qneeded4foroverwritting7 = qneeded4foroverwritting7 - needeed7 ;
				count1_7 = count1_7 - needeed7;
				got7s += needeed7;
				}
			}

			count1_7 = count1_7 - (qneeded4foroverwritting7 - got7s);
			count1_4 = 0;
		} else if (qneeded4foroverwritting7 > 0) {
			count1_4 = count1_4 - qneeded4foroverwritting7;
		}
		
		if ( count1_4 > count2_l4) {
			int temp = count1_4 - count2_l4;
			if ( temp > count2_4) {
				count1_4  = count1_4 - (temp- count2_4);
				count2_4 = 0;
			} else {
				count2_4 =  count2_4 - temp;
			}
		}
		if ( count2_4 > count1_l4) {
			int temp = count1_4 - count1_l4;
			if (temp > count1_4 ) {
				count2_4  = count2_4 - (temp - count1_4);
				count1_4 = 0;
			} else {
				count1_4 = count1_4 - temp;
			}
		}
		int total7s  = count1_7 + count2_7;
		int total4s = count1_4 + count2_4;
		if ( total7s > size ) {
			total7s = size;
			total4s = 0;
		} else if ( total7s + total4s > size ) {
			total4s = size - total7s;
		} else if (total7s + total4s < size ) {
			
		}
		for(int k=0;k< total7s ;k++) {
			cout<<"7";
		}
		for(int k=0;k< total4s ;k++) {
			cout<<"4";
		}
		testcases--;
		cout<<endl;
		}
    return 0;
}

