#include <unistd.h>
#include <stdint.h>
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

uint8_t data[256*1024];

int main(int argv,char **argc) {
	uint8_t * const  p_begin =  data;
	uint8_t *pend;
	uint8_t *p = data;
	int n = 0;
	pend = p_begin + read(0,data,sizeof(data));
	
//			cout << "  went inside  "<<"    pbegin  "<<(void *)p_begin<<"  p now  "<< (void *)p <<"   Pend  "<<(void *)pend<<endl;
	for(; *p < '0' || *p > '9'; p++ ) ;
	
	for(;*p > '0' && *p < '9';p++) {
	 n = n*10 + (*p-48);
	}
	for(; *p < '0' || *p > '9'; p++ ) ;
	int k = 0;
	for(;*p > '0' && *p < '9';p++) {
	 k = k*10 + (*p-48);
	}
//	for(; *p < '0' || *p > '9'; p++ ) ;
            if (*p < '0' || *p > '9') { ++p;
        }
	int divisible = 0;
	for(int v,i = 0;i< n;i++) {
		if( (pend - p) < 16) { 
//			cout << "  went inside  "<<"    pbegin  "<<(void *)p_begin<<"  p now  "<< (void *)p <<"   Pend  "<<(void *)pend<<endl;
            memcpy(p_begin, p, pend - p);
			pend = p_begin + (pend - p) + read(0,p_begin + (pend  - p),(sizeof(data) - (pend - p)));
			p  = p_begin;
		}
		 v = 0;
        if (*p >= '0' && *p <= '9') { v = v * 10 + (*p++ - '0');
            if (*p >= '0' && *p <= '9') { v = v * 10 + (*p++ - '0');
            if (*p >= '0' && *p <= '9') { v = v * 10 + (*p++ - '0');
            if (*p >= '0' && *p <= '9') { v = v * 10 + (*p++ - '0');
            if (*p >= '0' && *p <= '9') { v = v * 10 + (*p++ - '0');
            if (*p >= '0' && *p <= '9') { v = v * 10 + (*p++ - '0');
            if (*p >= '0' && *p <= '9') { v = v * 10 + (*p++ - '0');
            if (*p >= '0' && *p <= '9') { v = v * 10 + (*p++ - '0');
            if (*p >= '0' && *p <= '9') { v = v * 10 + (*p++ - '0');
            if (*p >= '0' && *p <= '9') { v = v * 10 + (*p++ - '0');
        }}}}}}}}}}
        if (*p < '0' || *p > '9') { ++p;
            if (*p < '0' || *p > '9') { ++p;
        }}

/*//		cout<<"BIT out"<<*p<<endl;
	for(; *p < '0' || *p > '9'; p++ ) ;
//	cout<<"BIT spaces"<<*p<<endl;
	int ti = 0;
	for(;*p > '0' && *p < '9';p++) {
	 ti = ti*10 + (*p-48);
//		cout<<"BIT in"<<*p<<endl;
	}*/
	cout<<"Number"<<v<<endl;

	if ( v % k  == 0) {
		divisible++;
	}
	}	
	
	cout<<(divisible)<<endl;

return 0;	

}
