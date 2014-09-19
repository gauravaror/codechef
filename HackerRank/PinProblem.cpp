//https://www.hackerrank.com/contests/csindia/challenges/pin-problem-1
#include <iostream>
#include <stdlib.h>
#include <map>
#include <list>
#include <vector>
#define debug false
using namespace std;
#define mx 10010

bool isDivisors[11][mx];
map<int,list<int> > numbers;

void proProcess() {
		for (int k = 2; k <= 10; ++k)
		{
			std::list<int> v;
			numbers[k] = v;
			for (int l = 1; l < mx; ++l)
			{
				if ( l%k == 0) {
					if(debug) cout<<"dividing";
					isDivisors[k][l] = true;
					numbers[k].push_back(l);
				} else {
					if(debug) cout<<"not dividing";
					isDivisors[k][l] = false;
				}
				if(debug) cout<<" l :"<<l<<" k :"<<k<<" isDivisors "<<isDivisors[k][l]<<endl;
			}
		}
}


int main() {

	int testcases;
	cin>>testcases;
	proProcess();
	if(debug) cout<<" testcases: "<<testcases<<endl;
	for (int i = 0; i < testcases; ++i)
	{
		int n,m;
		list<int> div_;
		list<int>::iterator it;
		cin>>n>>m;
		if (debug) cout<<"n : "<<n<<" m  :"<<m<<endl;
		int * divisors =  (int *)malloc(m*sizeof(int));

		for ( int j = 0; j < m; ++j ) {
			int temp;
			cin>>temp;
			div_.push_back(temp);
			if(debug) cout<<" divisors :"<<j<<" is "<<temp<<endl;
		}
		div_.remove(1);
		div_.reverse();
		div_.unique();

		it = div_.begin();
		if(m == 1 && div_.size() == 0) {
			cout<<n<<endl;
			continue;
		}
		list<int> highestfactors(numbers[*it]);
		list<int> copyhighestfactors(numbers[*it]);
		std::list<int>::iterator vit;
		list<int>  highestfactors1 (copyhighestfactors);		
		int count = 0;
		for (; it != div_.end(); ++it)   {
			int internalcount = 1;
			list<int>  highestfactors (copyhighestfactors);
			for(vit = highestfactors.begin(); vit != highestfactors.end();++vit) {
				if(*vit > n) {
					copyhighestfactors.remove(*vit);
				}
				if(!isDivisors[*it][*vit]) {
					copyhighestfactors.remove(*vit);
				} else {
					internalcount++;
				}
			}
		}
		cout<<copyhighestfactors.size()<<endl;
	}
	return 0;
}