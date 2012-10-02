#include <iostream>
#include <malloc.h>
#include <inttypes.h>

typedef unsigned int uint_t;

using namespace std;

static inline uint32_t getu32()
{
	uint32_t v;
	do {
		v = getchar() - '0';
	} while (v >= 10);

	uint32_t res = v;

	for (;;) {
		v = getchar() - '0';
		if (v >= 10)
			break;
		res = res * 10 + v;
	}

	return res;
}

int main (int argv,char ** argc ) {
	int testcases;
	cin >> testcases;
	while ( testcases > 0 ) {
	uint_t numberofbox;
	numberofbox = getu32();
	uint_t * candesinbox = (uint_t *)malloc(numberofbox*sizeof(uint_t));
	int maximumcandies ;
	int sum = 0;
	int average;
	for ( int i = 0 ;i < numberofbox;i++) {
		 candesinbox[i] = getu32();
		if ( i == 0) {
			maximumcandies = candesinbox[i];
		}
		sum += candesinbox[i];
		average = sum/(i+1);
		if ( maximumcandies > average) {
			maximumcandies = average;
		}
	}
	if ( testcases != 1 ) {
		cout<<maximumcandies<<endl;
	} else {
		cout<<maximumcandies;
	}
	testcases--;
	}
	return 0;
}
