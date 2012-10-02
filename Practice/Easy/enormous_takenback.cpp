#include <unistd.h>
#include <stdint.h>
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

uint8_t data[2556*1024];

int main(int argv,char **argc) {
	uint8_t * const  p_begin =  data;
	uint8_t *pend;
	uint8_t *p = data;
	int n = 0;
	pend = p_begin + read(0,data,sizeof(data));
	for(;(p < pend) &&( *p < '0' || *p > '9'); p++ ) ;
	
	for(;(p < pend) && (*p >= '0' && *p <= '9');p++) {
	 n = n*10 + (*p-48);
	}
	for(;(p < pend) &&( *p < '0' || *p > '9'); p++ ) ;
	int k = 0;
	for(;(p < pend) && (*p >= '0' && *p <= '9');p++) {
	 k = k*10 + (*p-48);
	}
	int divisible = 0;
	for(int i = 0;i< n;i++) {
		if( (pend - p) < 16) { 
            memcpy(p_begin, p, pend - p);
			pend = p_begin + (pend - p) + read(0,p_begin + (pend  - p),(sizeof(data) - (pend - p)));
			p  = p_begin;
		}
	for(;(p < pend) &&( *p < '0' || *p > '9'); p++ ) ;
	int ti = 0;
	for(;(p < pend) && (*p >= '0' && *p <= '9');p++) {
	 ti = ti*10 + (*p-48);
	}
	if ( ti % k  == 0) {
		divisible++;
	}
	}	
    printf("%u\n", divisible);

return 0;	

}
