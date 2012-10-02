#include <iostream>
//Total number of bit used to represent.
#define MAXN 13
//Number of bits in each hexagon.
#define HEXBIT 6
//Number of Hexagonal in the Puzzel.
#define NOHEX 3

using namespace std;

//Given Puzzel 
char trihexagonalpuzzel[MAXN+1];
bool bithexagonalpuzzel[MAXN];

//Representative bit index of hexgonal A , B,C in bit hexpuzzel.
int  bitindex[NOHEX][HEXBIT] = {{0,3,6,8,5,2},{1,4,7,9,6,3},{6,9,11,12,10,8}};

//Number of Black currently
int blackvertex[NOHEX];
int blackcorrect[NOHEX];

// Function to convert the char stream to the bool bit representing color.
void converToBits() {
	for ( int i =0 ; i < MAXN ; i++) {
		if ( trihexagonalpuzzel[i] == '1' ) {
			bithexagonalpuzzel[i] = true;
		} else {
			bithexagonalpuzzel[i] = false;
		}
	}
}

//Function collect stats of how many black are in place in A,B,C and how many black  to co

void collectStats() {
	for ( int i = 0; i < NOHEX ; i++ ) {	
		int numbertrue = 0 ;
		int correctposition = 0;
		for ( int j = 0;j < HEXBIT ; j++ ) {
			if(bithexagonalpuzzel[bitindex[i][j]] == true ) {
				numbertrue++;
				if ( j == 3 || j == 6 || j == 8 || j == 9) {
					correctposition++;
				}
			}
		}
		blackvertex[i] = numbertrue;
		blackcorrect[i] = correctposition;
		cout<<"\nHEX "<<i<<"Number of Bit black"<<blackvertex[i]<<" Correctly placed"<< blackcorrect[i];
	}
}

int main(void)
{
	int testcase;
	cin>>testcase;
	while(testcase--) {
		cin>>trihexagonalpuzzel;
		converToBits();
		collectStats();
	}
	return 0;
}

