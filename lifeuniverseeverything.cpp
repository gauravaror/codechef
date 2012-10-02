//Including header file to get input and show  output.
#include <iostream>

// Indicating to use namespace as standard
using namespace std;

int main( int argc,char * argv[]) {
	int number;
	while (1) {
		cin >> number;
		if (number == 42) {
			return 0;
		}
		cout<< "\n"<<number;
	}
return 0;
}
