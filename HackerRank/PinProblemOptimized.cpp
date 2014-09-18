//https://www.hackerrank.com/contests/csindia/challenges/pin-problem-1
#include <iostream>
#include <stdlib.h>
#include <map>
#include <list>
#include <vector>
#include <math.h>
#define debug false
using namespace std;
#define mx 10010

 int gcd(int a, int b)
{	if(debug) cout<<" gcd: "<<a<<"  b " <<b<<endl;
    while (b > 0)
    {
        //int temp = b;
        return gcd(b,a % b); // % is remainder
       // a = temp;
    }
    return a;
}

int main() {

	int testcases;
	cin>>testcases;
	if(debug) cout<<" testcases: "<<testcases<<endl;
	for (int i = 0; i < testcases; ++i)
	{
		int n,m;
		list<int> div_;
		list<int>::iterator it;
		cin>>n>>m;
		if (debug) cout<<"n : "<<n<<" m  :"<<m<<endl;
		int * divisors =  (int *)malloc(m*sizeof(int));
		int divisorproduct =1;
		for ( int j = 0; j < m; ++j ) {
			int temp;
			cin>>temp;
			div_.push_back(temp);
			//divisorproduct *= temp;
			if(debug) cout<<" divisors :"<<j<<" is "<<temp<<endl;
		}
		div_.reverse();
		div_.unique();
		it = div_.begin();
		divisorproduct =  1;
		int lcd = 1;
		if(debug) cout<<" lcd: "<<lcd<<endl;
		int * array = (int *)malloc(sizeof(int)*div_.size());
		int l =0;
		for (; it != div_.end(); ++it)   {
			//if(it == div_.end()) continue;
			array[l] = *it;
			l++;
			if(debug) cout<<"coming ir "<<*it<<endl;
			//lcd = gcd(*it,lcd);
			//lcd = lcd*(*it)/gcd_;
			divisorproduct *= *it;
			if(debug) cout<<" divisors :"<<" is "<<lcd<<endl;
		}
		//int lcd = 1;
			int lcm =1;
			bool a2loopbreak = false;
			while (!a2loopbreak) {
				a2loopbreak = true;
				for(int h = 0 ; h < div_.size();h++) {
					if(array[h]%2  == 0) {
						array[h] /= 2;
						
						a2loopbreak = false;

					}

				}
				if(a2loopbreak == false) lcm = lcm*2;
			}
			if(debug) cout<<"look break"<<lcm<<endl;
			bool a3loopbreak = false;
			while (!a3loopbreak) {
				a3loopbreak = true;
				for(int h = 0 ; h < div_.size();h++) {
					if(array[h]%3  == 0) {
						array[h] /= 3;
						a3loopbreak = false;

					}
				}
				if(a3loopbreak == false) lcm = lcm*3;
			}
			if(debug) cout<<"look break"<<lcm<<endl;
			bool a5loopbreak = false;
			while (!a5loopbreak) {
				a5loopbreak = true;
				for(int h = 0 ; h < div_.size();h++) {
					if(array[h]%5  == 0) {
						array[h] /= 5;
						a5loopbreak = false;

					}
				}
				if(a5loopbreak == false) lcm = lcm*5;
			}
			if(debug) cout<<"look break"<<lcm<<endl;
			bool a7loopbreak = false;
			while (!a7loopbreak) {
				a7loopbreak = true;
				for(int h = 0 ; h < div_.size();h++) {
					if(array[h]%7  == 0) {
						array[h] /= 7;
						a7loopbreak = false;

					}
				}
				if(a7loopbreak == false) lcm = lcm*7;
			}
			if(debug) cout<<"look break"<<lcm<<endl;
		if(debug) cout<<lcm<<"fdsf lcm"<<endl;

		int gcd_ = divisorproduct/lcm;
			//gcd_ = divisorproduct/double(lcd);
		if(debug) cout<<"number "<<n<<" divisorproduct "<<gcd_<<"  divisorproduct "<<divisorproduct<<endl;
		cout<<floor(n/lcm)<<endl;
	}
	return 0;
}