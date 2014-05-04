
#include <iostream>
#include <stdlib.h> 
#include <string>

#define printdebug false

using namespace std;

string* Repeaterstring =NULL;

long long minimumMoveTheseString(int A,int B) {
 const char * stringfirst = Repeaterstring[A].c_str();
 const char * stringsecond = Repeaterstring[B].c_str();
 if (printdebug) {
 	for (int i =0;i< Repeaterstring[A].length();i++) {
 		cout<<stringfirst[i];
 	}
 	cout<<"\n";
 	for (int i =0;i< Repeaterstring[B].length();i++) {
 		cout<<stringsecond[i];
 	}
 	cout<<"\n";
}
 int currentlength=1;
 char currentchar=stringfirst[0];
 int currentindex=0;
 long long moves=0;
 bool pass = true;
 for (int i =1;i< Repeaterstring[A].length()+1;i++) {
 	if ( i == Repeaterstring[A].length() ) {
 		if (stringfirst[i-2] == stringfirst[i-1]) {
 			pass = false;
 		}
 		else {
 			pass = false;
 		}
 	}
 	if ( pass && (stringfirst[i-1] == stringfirst[i])) {
 		currentlength++;
 	}
 	else {

 			int index = currentindex;
 			int length=0;
 		for (int m = index;m< Repeaterstring[B].length();m++) {
 			
 			if ( stringsecond[m] == currentchar) {
 				currentindex = m+1;
 				length++;
 			}
 			else {
 				break;
 			}
 		}
 		if (length == 0) {
 			return -1;
 		}
 		else {
 			moves = moves + abs(length - currentlength);
 			if (printdebug)
 				cout<<moves<<" length : "<<length<<" currentlength "<< currentlength<<"\n";
 		}
 		currentlength=1;
 	}
 	currentchar = stringfirst[i];
}

//cout<<"Final Moves :"<<	moves;
if (currentindex != Repeaterstring[B].length()) {
	return -1;
}
return moves;
}


long long minimumMoveForIndex(int N,int in) {
	long long mov = -1;
	long long minimumMov = -1;
	for (int l=0;l<N;l++) {
		if (l != in){
			mov = minimumMoveTheseString(in,l);
			if (printdebug)
				cout<<"Min Move For Index ind: "<<mov<<"\n";

			if (l==0 || minimumMov == -1) {
				minimumMov = mov;
			}
			else {
				minimumMov = minimumMov+ mov;
			}
		}
	}
	if (printdebug)
		cout<<"Min Move For Index : "<<minimumMov<<"\n";
	return minimumMov;
}


long long minimumMove(int N){
	long long mov = -1;
	long long minimumMov = -1;
	for (int l=0;l<N;l++) {

		mov = minimumMoveForIndex(N,l);
		if (printdebug) {
			cout<<"Move for this: "<<mov;
		}
		if ( minimumMov == -1) {
			minimumMov = mov;
		}
		else if(  minimumMov > mov) {
			minimumMov = mov;
		}
	}
	return minimumMov;

}




int main() {

	int notest;
	cin >> notest;
	if (printdebug) {
		cout<<" Number of TestCases: "<<notest;
	}
	
	for (int i=0;i<notest;i++) {
		int N;
		cin>>N;
		if (printdebug)
		{
			cout<<" N: "<<N;	
		}
		Repeaterstring =new string[N];
		for (int k=0;k<N;k++) {
			cin>>Repeaterstring[k];
		}
		if (printdebug)
		{
			for (int k=0;k<N;k++) {
				cout<<" Kth String: "<<k<<" value: "<<Repeaterstring[k]<<"\n";
			}
		}
		long long moves = minimumMove(N);
		if (moves == -1) {
			cout<<"Case #"<<i+1<<": "<<"Fegla Won"<<"\n";
		}
		else {
			cout<<"Case #"<<i+1<<": "<<moves<<"\n";	
		}
		
	}
}
