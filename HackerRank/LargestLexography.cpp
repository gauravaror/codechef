//https://www.hackerrank.com/contests/csindia/challenges/largest-lexicographical-rotation
#include <iostream>
#include <stdlib.h>
#include <map>
#include <list>
#include <string>
#include <vector>
#include <math.h>
#define debug false
using namespace std;

int findRotationIndex(const char* charString,int length) {
	int maxChar=1;
	list<int> index;
	if(debug) cout<<"length : "<<length<<endl;
	for (int j = length-1; j >= 0; --j)
	{ 
		
		int temp = charString[j];
		if(debug) cout<<"dsfsdf "<<charString[j]<<" dsd  "<<temp<<endl;
		if(temp> maxChar) {
		 maxChar = (int)charString[j];
		 index.clear();
		 index.push_back(j);
		} else if( charString[j] == maxChar) {
			index.push_back(j);
		}
		
		
	}
	if(index.size() == 1 && maxChar != 1) {
		return *index.begin();
	} else if(index.size() > 1){
		list<int>::iterator it;
		 int max = -1;
		 int maximumindex = -1;
		 int maxCharVal;
		for(it= index.begin();it != index.end();++it ) {
			if( max == -1 ) {
				max = *it +1;
				maxCharVal = charString[max];
			}
			int temp =  charString[*it+1];
			if( temp > maxCharVal) {
				max = *it +1;
				maxCharVal = charString[max];
			}
		}
		return max -1;
	}
	
}

int main() {

	int testcases;
	cin>>testcases;
	if(debug) cout<<" testcases: "<<testcases<<endl;
	for (int i = 0; i < testcases; ++i)
	{
		string a;
		cin>> a;
		int length = a.length();
		if(debug) cout<<a<<endl;
		const char * characterString = a.c_str();
		if (debug)
		{
			for (int j = length-1; j >= 0; --j)
			{
				cout<<characterString[j];
			}

		}
		int index = findRotationIndex(characterString,length);
		//int index =3;
		for(int f= index;f<length;f++) {
			cout<<characterString[f];
		}
		for(int f= 0;f<index;f++) {
			cout<<characterString[f];
		}
        cout<<endl;
	}
}