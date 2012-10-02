#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdint.h>
#ifdef ONLINE_JUDGE
 #include <unistd.h>
#endif
#ifndef ONLINE_JUDGE
#include <sys/io.h>
#include "/usr/x86_64-w64-mingw32/include/intrin.h"
#endif

//  return __rdtsc();

#define BUFSIZE 8192
class Reader	{
public:
	Reader(int bufsize)	{
		Buf=new char[BUFSIZE];
		DBuf=new char[BUFSIZE];
		leftpointer=0;
		BufSize=read(0,Buf,BUFSIZE);
	}
	virtual ~Reader()	{
		delete [] Buf;
		delete [] DBuf;
	}
	int GetInt32()	{
		int ans=Buf[leftpointer]-'0',dig;

		while((dig=Buf[++leftpointer])>='0') {
			ans*=10;ans+=dig-'0';
		}
		leftpointer++;
		return ans;
	}
	void Process(int sz)	{
		int index=0;
		int quot,rem,tm=0;
		char cBuf[11];cBuf[10]=10;
		for (int i=0;i<sz;i++) {
			int ans=0,dig;
			for (;;) 
				dig=Buf[leftpointer++];
				if (leftpointer==BufSize) {
					leftpointer=0;
					write(1,DBuf,index);
					index=0;
					BufSize=read(0,Buf,BUFSIZE);
				}
				if (dig<'0') break;
				ans*=10;ans+=dig-48;
			} 
			//process ans
			quot=ans/78125;
			rem=ans%78125;
			ans=19531*quot+LUT[quot]+LUT[rem];
			//format it for output
			bool started=false;int dindex;
			if (ans>=200000000) {
				DBuf[index++]=50;//digit 2
				ans-=200000000;
				started=true;
			}
			else if (ans>=100000000) {
				DBuf[index++]=49;///digit 1
				ans-=100000000;
				started=true;
			}
			rem=ans%10000;quot=ans/10000;
			dindex=quot*5+4;int ln;
			if (started) ln=4;else if (quot==0) ln=0;else ln=strs[dindex];//include leading zeroes
			dindex-=ln;
			int cmp=index+ln;
			for (;index<cmp;index++) {
				DBuf[index]=strs[dindex];dindex++;
			}
			dindex=rem*5+4;
			if (started || ln>0) ln=4;else ln=strs[dindex];//include leading zeroes including the ans ans=0
			dindex-=ln;
			cmp=index+ln;
			for (;index<cmp;index++) {
				DBuf[index]=strs[dindex];dindex++;
			}
			DBuf[index++]=10;
		}
		write(1,DBuf,index);
	/*	asm ("nop\n\t"
			 "nop");*/
	}

	void BuildLUT()	{
		LUT[0]=0;
		for (int i=0;i<15625;i++) {
			int val=i+LUT[i];
			for (int j=0;j<5;j++) LUT[i*5+j]=val;
		}
		//the strs
		int index=0,ln;
		for (int th=0;th<10;th++) {
			char dig_th=th+48;
			for (int hu=0;hu<10;hu++)	{
				char dig_hu=hu+48;
				for (int tn=0;tn<10;tn++) {
					char dig_tn=tn+48;
					for (int un=0;un<10;un++) {
						strs[index]=dig_th;
						strs[index+1]=dig_hu;
						strs[index+2]=dig_tn;
						strs[index+3]=un+48;
						if (th>0) ln=4;
						else if (hu>0) ln=3;
						else if (tn>0) ln=2;
						else ln=1;
						strs[index+4]=ln;
						index+=5;
					}
				}
			}
		}
	}

	protected:
		char *Buf,*DBuf;
		int BufSize,leftpointer;
		uint16_t LUT[15625*5];
		char strs[5*10000];
};

int main(void)	{
#ifndef ONLINE_JUDGE
	uint64_t st=__rdtsc();
#endif
	unsigned int N,TC,R;
	Reader *RC=new Reader(1100000);
	TC=RC->GetInt32();
	delete RC;
    while( TC-- ){
	Reader *RC1=new Reader(1100000);
         N = RC1->GetInt32();
 		delete RC1;
         R = 0LL;
         while(N){
             N /= 5;
             R += N;
         }
 
       printf( "%ld\n", R );
  }

#ifndef ONLINE_JUDGE
	uint64_t tm=__rdtsc()-st;
	double lapse=tm*1.0/1.7e6;
	fprintf(stderr,"lapse: %.6f\n",lapse);
#endif
	return 0;
}
