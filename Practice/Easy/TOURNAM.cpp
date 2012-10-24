#include <iostream>
#include <stdint.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stdio.h>

//#define NOTJUDGE

using namespace std;

class  Player {
int pos;
double P;

public:
Player(int pst,double prob) {
	pos = pst;
	P = prob;
}

void setPosition(int a) {
	pos = a;
}

int getPosition() {
	return pos;
}

void setProb(double pr) {
	P = pr;
}

double getProb() {
	return P;
}

};

bool playerComparator(Player a,Player b) {
	return (a.getPosition() < b.getPosition());
}

Player * fight(Player a,Player b,int P) {
/*	#ifdef NOTJUDGE
	cout<<"CALLED FIGHT"<<endl;
	#endif*/
	double pro = (double)P/100;
	int newposition = b.getPosition()/2;
	double newprobability = ((a.getProb()*b.getProb()) + (a.getProb()*(1 - b.getProb())*pro) + (b.getProb()*(1 - a.getProb())*pro));
	Player *temp = (Player *)malloc(sizeof(Player));
	temp->setProb(newprobability);
	temp->setPosition(newposition);
	return temp;
}


Player * fightwithothers(Player a,int P) {
/*	#ifdef NOTJUDGE
	cout<<"CALLED FIGHT WITH OTHERS"<<endl;
	#endif*/
	double pro = (double)P/100;
	int newposition;
		newposition = (a.getPosition())/2;
	double newprobability = ((a.getProb()*pro));
	Player *temp = (Player *)malloc(sizeof(Player));
	temp->setProb(newprobability);
	temp->setPosition(newposition);
	return temp;
}

int main() {
	uint32_t testcases,N,M,P;
	int * positions;
	cin>>testcases;
	for ( int i = 0; i < testcases ; i++) {
		cin>>N>>M>>P;
/*		#ifdef NOTJUDGE
		cout<<"N "<<N<<" M "<<M<<" P "<<P<<endl;
		#endif*/
		vector< vector<Player> > playersrow;	
		int pos;
		Player * pl;
		vector<Player> pll;
		playersrow.push_back(pll);
		for (int  j = 0;j<M;j++) {
			cin>>pos;
			pl = new Player(pos-1,1.0);
			playersrow[0].push_back(*pl);
		}
		sort(playersrow[0].begin(),playersrow[0].end(),playerComparator);
		/*#ifdef NOTJUDGE
		for ( int j = 0;j<M;j++) {
		cout<<"Position j "<<playersrow[0][j].getPosition()<<" Prob  "<<playersrow[0][j].getProb()<<endl;
		}
		#endif*/
		
		int level = 0;
		while(N > 1) {
						vector<Player> plll1;
						playersrow.push_back(plll1);
			
			for( int i = 0; i< playersrow[level].size();i++) {
				if ((i != (playersrow[level].size() -1) ) && (playersrow[level][i+1].getPosition()/2 == (playersrow[level][i].getPosition()/2))) {
					playersrow[level+1].push_back( *fight(playersrow[level][i],playersrow[level][i+1],P));
					i = i+1;
				}
				else {
					playersrow[level+1].push_back(*fightwithothers(playersrow[level][i],P));
				}
			}
		level++;
/*		#ifdef NOTJUDGE
			cout<<"Level "<<level<<endl;
			for( int i = 0; i< playersrow[level].size();i++) {
					cout<<"Position j "<<playersrow[level][i].getPosition()<<" Prob  "<<playersrow[level][i].getProb()<<endl;
			}
		#endif*/
		N = N/2;
		}
		printf("%.13lf\n",playersrow[level][0].getProb()*100);
		playersrow.clear();	

	}
}

