#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
//#define Debug

using namespace std;

long long ** houses;
long long centroidx;
long long centroidy;
int people;
long long  tmp[4] = {1000000000,1000000000,1000000000,1000000000};
int  index[4] = {-1,-1,-1,-1};
long long eludistance(int,int);
long long dist(int,int);
long long min4(long long,long long,long long,long long);
void media_approx();
void maintain4min(long long,int);
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    cin>>people;
    centroidx = 0;
    centroidy = 0;
    houses = (long long **) malloc((people+1) * sizeof(long long));
    for ( int i = 0; i < people ; i++ ) {
        houses[i] = (long long *)malloc(2*sizeof(long long));
        cin>>houses[i][0]>>houses[i][1];       
        centroidx = centroidx + houses[i][0];
        centroidy = centroidy + houses[i][1]; 
    }  
    houses[people] = (long long *)malloc(2*sizeof(long long));
    houses[people][0] = floor(centroidx/ people);
    houses[people][1] = floor(centroidy / people);
    //media_approx();
        
    long long min  = 1000000000;
    //tmp = new long long[4];
    //index = new int[4];
    // tmp =  {1000000000,1000000000,1000000000,1000000000};
    //index = {-1,-1,-1,-1};
     
     long long temp;
    #ifdef Debug
    cout<<"Centroids = ("<<houses[people][0]<<","<<houses[people][1]<<")"<<endl;
    #endif
    for ( int i = 0; i < people ; i++ ) {
        temp = dist(i,people);
        maintain4min(temp,i);
    }
    #ifdef Debug
    cout<<"Meeting point should be :"<<index[0]<<index[1]<<index[2]<<index[3]<<endl;
    #endif
    long long dist[] =  {0,0,0,0};
    for ( int i = 0; i < people ; i++ ) {
        for ( int j = 0; j<4;j++) {
            if(j < (people-1)) {
            dist[j] += eludistance(i,index[j]);
            }
            else {
            dist[j] = 1000000000;
            }
        }
    }
    cout<<min4(dist[0],dist[1],dist[2],dist[3])<<endl;
    #ifdef Debug
    cout<<"Final Distance is :"<<dist[0]<<dist[1]<<dist[2]<<dist[3]<<endl;
    #endif
    return 0;
}

long long eludistance(int a, int b) { 
    long long x = houses[a][0] - houses[b][0];
    long long y = houses[a][1] - houses[b][1];
    x = x > 0 ? x : -x;
    y = y > 0 ? y : -y;
    return x > y ? x : y;
}
long long dist(int a,int b) {
    return sqrt(pow((houses[a][0] - houses[b][0]),2) + pow((houses[a][1] - houses[b][1]),2));
}

void maintain4min(long long temp,int in) {
        if (tmp[3] > temp ) {
            tmp[3] = temp;
            index[3] = in;
        }
        else {  
        return;
        }
    for (int i = 3;i>0;i--) {
        if ( tmp[i] < tmp[i-1] ) {
            long long d = tmp[i];
            tmp[i] = tmp[i-1];
            tmp[i-1] = d;
            int l = index[i];
            index[i] = index[i-1];
            index[i-1] = l;
        }
    }    
}

long long min4(long long a,long long b,long long c,long long d) {
    long long min1 = a < b ? a:b;
    long long min2 = c < d ? c:d;
    return min1 < min2 ? min1 : min2;
    
}

void media_approx() {
    double W = 0.0; 
    float w = 0.0 ;
    long long d,x,y;
    x = 0.0;
    y = 0.0;
    for (int i = 0; i <people;i++) {
        d = dist(people,i);
        if (d != 0 ) {
            w = 1.0 /d;
            W += w;
            x += houses[i][0]*w;
            y += houses[i][1]*w;
            #ifdef Debug
            cout<<"people "<<i<<"houses x y"<<houses[i][0]<<"  "<<houses[i][1]<<" w  "<<w<<" W "<<W<<"x  "<<x<<"y  "<<y<<"  dist  "<<d<<endl;
            #endif
        }
    }
    #ifdef Debug
    cout<<"W "<<W<<"x  "<<x<<"y  "<<y<<endl;
    #endif
    houses[people][0]  = x/W;
    houses[people][1] = y/W;
}
