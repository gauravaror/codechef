#include <cstdio>
#include <cstdlib>
#include <inttypes.h>

#include <iostream>
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

int main( int argc, char **argv ){
	unsigned int TC, N, R;
	
	TC = getu32();
	
	while( TC-- ){	
		N = getu32();
		
		R = 0LL;
		while(N){
			N /= 5;
			R += N;
		}
		
		printf( "%ld\n", R );
	}
	
	return 0;
}
