#include <iostream>
#include <stdlib.h> 
#include <iomanip>

using namespace std;

int main() {

	int notest;
	cin >> notest;
	//cout<<notest;
	
	for (int i=0;i<notest;i++) {
		double productionRate=2.0000000;
		double TimeSpent=0;
		double C,F,X;
		cin>>C>>F>>X;
		//cout<<C<<" "<<F<<" "<<X<<"\n";
		double directTime = X/productionRate;
		double TimeAfterBuyingFarm = C/productionRate + X/(productionRate+F);
		while(directTime>TimeAfterBuyingFarm) {
			//cout<<"Dirext "<<directTime<<" "<<TimeAfterBuyingFarm<<" "<<C/productionRate<<"\n";
			TimeSpent=TimeSpent+C/(productionRate+0.000000);
			productionRate=productionRate+F;
			directTime = X/productionRate;
			TimeAfterBuyingFarm = C/productionRate + X/(productionRate+F);
			//cout<<TimeSpent<<" "<<C/productionRate<<"\n";
		}
		TimeSpent=TimeSpent+directTime;
		cout<<"Case #"<< std::fixed << std::setprecision(7)<<i+1<<": "<<TimeSpent<<"\n";
	}
}