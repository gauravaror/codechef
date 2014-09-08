//https://www.hackerrank.com/challenges/play-game
#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <vector>
#include <set>
#include <algorithm> 
#define debug true
//#define arrayLength 299915
 #define arrayLength 909915
using namespace std;


long long int FactorialFind(int num) {
	long long int factorial = 1;
	for(int i=1;i<=num;i++) {
		factorial= factorial*i;
	}
	return factorial;
}

// A function to print all prime factors of a given number n
long long int primeFactors(int n)
{
	int number = n;
	int totalPrimeFactors = 0;
	long long int numerator =1 ;
	long long int denominator=1;
	int currentFactor = 0;

    // Print the number of 2s that divide n
    while (n%2 == 0)
    {
    	if(debug)
    	 //	cout<<" "<<2<<" ";
        totalPrimeFactors++;
        n = n/2;
        currentFactor++;
    }
    denominator = denominator*FactorialFind(currentFactor);
    currentFactor = 0;
 
    // n must be odd at this point.  So we can skip one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i+2)
    {
        // While i divides n, print i and divide n
        while (n%i == 0)
        {
        	if(debug)
         //   	cout<<" "<<i<<" ";
            totalPrimeFactors++;
            n = n/i;
        }
        denominator = denominator*FactorialFind(currentFactor);
    	currentFactor = 0;
    }
  
    numerator = FactorialFind(totalPrimeFactors);
 	//-cout<<" number "<<number<<" prime factors "<<totalPrimeFactors<<" configs  "<<numerator/denominator<<" numerator "<<numerator<<"  denominator  "<< denominator<<endl;
    return numerator/denominator;
}


int main() {
	//count[0] = count[1] = count[2] =1;
	int * count = (int *)malloc(arrayLength*sizeof(int));
	bool * is_prime = (bool *)malloc(arrayLength*sizeof(bool));
	std::vector<std::pair<int,long long int> > primes;
	std::set<long long int> insertedPrimes;
	cout<<"initial not done of 2"<<arrayLength<<endl;
	is_prime[0] = false;
	is_prime[1] = false;
	is_prime[2] = false;
	for(int i=0;i<arrayLength;i++) {
		is_prime[i] = true;
	}
	for( int i =4;i<arrayLength;i=i+2) {
		//cout<<"dsdfsd"<<i;
		is_prime[i] = false;
	}
	cout<<"initial done of 2"<<endl;
	for( int j = 3;j<sqrt(arrayLength);j=j+2) {
		 for(int k=j;k*j<=sqrt(arrayLength);k++)
                is_prime[k*j]=false;
	}
	cout<<"initial done of 4"<<endl;
	 count[0]=count[1]=count[2]=0;
    for(int i=2;i<=arrayLength;i++)
	{
		count[i]=count[i-1];
		//cout<<"Prime number"<<i<<<<endl;
		if(is_prime[i]) {
		
		 count[i]+=1;
		} else {
			//cout<<"NON Prime number"<<i<<endl;
			long long int curr  = primeFactors(i);
			
			if(insertedPrimes.end() == insertedPrimes.find(curr)) {
				pair<int,long long int> g = std::make_pair(i,curr);
				cout<<"number "<<i<<"  sequences "<<curr<<endl;
				primes.push_back(g);
				insertedPrimes.insert(curr);
			}
		}
	}
	
}

