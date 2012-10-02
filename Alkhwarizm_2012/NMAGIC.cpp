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
	    string num;
		cin >> num;
	    std::stringstream tmp_stream;
		bool done = false;
	    tmp_stream << num;
 		int string_size = 	tmp_stream.str().size();
		int * digits = (int *)malloc( string_size * sizeof(int));
		for ( int i = string_size -1 ; i >= 0 ; i--) {
			char chart = tmp_stream.str().at(i);
			digits[i] = atoi(&chart);
			if ( digits[i] == 4  && !done ) {
				digits[i] = 7;
				done = true;
			}
			else if ( digits[i] == 7  && !done  ) {
				digits[i] = 4;
			}
		}
		if(!done) {
			cout<<4;
		}
		for ( int i = 0 ;i < string_size; i++) {
				if ( digits[i] == 4 || digits[i] == 7) {
				cout<<digits[i];
				}
				else {
					tmp_stream.str().at(i);
				}
		}
		testcases--;
		cout<<endl;
	}
    return 0;
}

