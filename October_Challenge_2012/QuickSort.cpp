#include <stdlib>
#include <iostream>

using namespace std;

quickSort(int * array,int sindex,int eindex)  {

}

// This Main is written to test the above library QuickSort.


int main() {
	
	uint32_t n;
	cout<<"Number of Elements"<<endl;
	cin>>n;
	uint32_t *Y = (uint32_t *)malloc(n*sizeof(uint32_t));
	quickSort(Y,0,n);
}
