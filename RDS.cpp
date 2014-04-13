#include <iostream.h>

using namespace std;

int testcases;
int n;
int k;
long double **memo;

int main() {


cin>>testcases;
while (testcases > 0 ) {
    cin>>n>>k;
     
    testcases--;
}

void intializememo() {
    memo = (long double **) malloc(sizeof(long double **)*k);
    for (int i = 0;i < k;i++) {
        *memo = (long double *) malloc(sizeof(long double *) *n);
        
    }

}
