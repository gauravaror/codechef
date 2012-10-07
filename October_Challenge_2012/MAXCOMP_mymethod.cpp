#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <iostream>
#include <map>

using namespace std;

//Logic for Getting Fast Input and Output.
class FastInput {
		public:
				FastInput() {
						m_dataOffset = 0;
						m_dataSize = 0;
						m_v = 0x80000000;
				}
				uint32_t ReadNext() {
						if (m_dataOffset == m_dataSize) {
								int r = read(0, m_buffer, sizeof(m_buffer));
								if (r <= 0) return m_v;
								m_dataOffset = 0;
								m_dataSize = 0;
								int i = 0;
								if (m_buffer[0] < '0') {
										if (m_v != 0x80000000) {
												m_data[m_dataSize++] = m_v;
												m_v = 0x80000000;
										}
										for (; (i < r) && (m_buffer[i] < '0'); ++i);
								}
								for (; i < r;) {
										if (m_buffer[i] >= '0') {
												m_v = m_v * 10 + m_buffer[i] - 48;
												++i;
										} else {
												m_data[m_dataSize++] = m_v;
												m_v = 0x80000000;
												for (i = i + 1; (i < r) && (m_buffer[i] < '0'); ++i);
										}
								}
						}
						return m_data[m_dataOffset++];
				}
		public:
				uint8_t m_buffer[32768];
				uint32_t m_data[16384];
				size_t m_dataOffset, m_dataSize;
				uint32_t m_v;
};
 
 
class FastOutput {
		public:
				FastOutput() {
						m_dataOffset = 0;
				}
				~FastOutput() {
				}
				void Flush() {
						if (m_dataOffset) {
								if (write(1, m_data, m_dataOffset));
								m_dataOffset = 0;
						}
				}
				void PrintUint(uint32_t v, char d) {
						if (m_dataOffset + 11 > sizeof(m_data)) Flush();
						if (v < 100000) {
								if (v < 1000) {
										if (v < 10) {
												m_data[m_dataOffset + 0] = v + 48;
												m_dataOffset += 1;
										} else if (v < 100) {
												m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
												m_data[m_dataOffset + 0] = v + 48;
												m_dataOffset += 2;
										} else {
												m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
												m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
												m_data[m_dataOffset + 0] = v + 48;
												m_dataOffset += 3;
										}
								} else {
										if (v < 10000) {
												m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;
												m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
												m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
												m_data[m_dataOffset + 0] = v + 48;
												m_dataOffset += 4;
										} else {
												m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48; v /= 10;
												m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;
												m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
												m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
												m_data[m_dataOffset + 0] = v + 48;
												m_dataOffset += 5;
										}
								}
						} else {
								if (v < 100000000) {
										if (v < 1000000) {
												m_data[m_dataOffset + 5] = v - v / 10 * 10 + 48; v /= 10;
												m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48; v /= 10;
												m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;
												m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
												m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
												m_data[m_dataOffset + 0] = v + 48;
												m_dataOffset += 6;
										} else if (v < 10000000) {
												m_data[m_dataOffset + 6] = v - v / 10 * 10 + 48; v /= 10;
												m_data[m_dataOffset + 5] = v - v / 10 * 10 + 48; v /= 10;
												m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48; v /= 10;
												m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;
												m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
												m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
												m_data[m_dataOffset + 0] = v + 48;
												m_dataOffset += 7;
										} else {
												m_data[m_dataOffset + 7] = v - v / 10 * 10 + 48; v /= 10;
												m_data[m_dataOffset + 6] = v - v / 10 * 10 + 48; v /= 10;
												m_data[m_dataOffset + 5] = v - v / 10 * 10 + 48; v /= 10;
												m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48; v /= 10;
												m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;
												m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
												m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
												m_data[m_dataOffset + 0] = v + 48;
												m_dataOffset += 8;
										}
								} else {
										if (v < 1000000000) {
												m_data[m_dataOffset + 8] = v - v / 10 * 10 + 48; v /= 10;
												m_data[m_dataOffset + 7] = v - v / 10 * 10 + 48; v /= 10;
												m_data[m_dataOffset + 6] = v - v / 10 * 10 + 48; v /= 10;
												m_data[m_dataOffset + 5] = v - v / 10 * 10 + 48; v /= 10;
												m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48; v /= 10;
												m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;
												m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
												m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
												m_data[m_dataOffset + 0] = v + 48;
												m_dataOffset += 9;
										} else {
												m_data[m_dataOffset + 9] = v - v / 10 * 10 + 48; v /= 10;
												m_data[m_dataOffset + 8] = v - v / 10 * 10 + 48; v /= 10;
												m_data[m_dataOffset + 7] = v - v / 10 * 10 + 48; v /= 10;
												m_data[m_dataOffset + 6] = v - v / 10 * 10 + 48; v /= 10;
												m_data[m_dataOffset + 5] = v - v / 10 * 10 + 48; v /= 10;
												m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48; v /= 10;
												m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;
												m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
												m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
												m_data[m_dataOffset + 0] = v + 48;
												m_dataOffset += 10;
										}
								}
						}
						m_data[m_dataOffset++] = d;
				}
				void PrintChar(char d) {
						if (m_dataOffset + 1 > sizeof(m_data)) Flush();
						m_data[m_dataOffset++] = d;
				}
				void ReplaceChar(int offset, char d) {
						m_data[m_dataOffset + offset] = d;
				}
		public:
				uint8_t m_data[32768];
				size_t m_dataOffset;
};

//Logic for Sorting the Input by starting Time ..

//Activity Class which store the activity
struct Activity {
uint32_t startTime;
uint32_t endTime;
uint32_t compensation;
uint32_t index;
};

int max1(int a, int b)
{
int x = a > b ? a:b;
return (x);
}
void startTimeSort(int* starttimes) {



}
int activitycompare(const void *i,const void *j) {
	
	Activity * A1 = *(Activity **)i;
	Activity * A2 = *(Activity **)j;
	if (A1->startTime > A2->startTime) return (1);
	if (A1->startTime < A2->startTime) return (-1);
	return (0);
}

int binarySearch(Activity **s,Activity * key,int low,int high) {
	int middle;
	if ( low > high ) return (high);
	middle = (low+high)/2;

	if ( s[middle]->startTime == key->startTime) {
			int i = middle;
			int flag =0;
			while ( s[i]->startTime == key->startTime && (i < high)) {
			i--;
			flag++;
			}
			if (flag ==0) {
				return i;
			}
			return(i+1);
	}

	if (s[middle]->startTime > key->startTime) 
			return (binarySearch(s,key,low,middle-1));
	else
		return (binarySearch(s,key,middle+1,high));
}

FastInput g_fi;
FastOutput g_fo;
Activity** activitystore;
uint32_t NumberofActivities;
int *max2;
int evaluation(int a) {
	//cout<<"Working for a  = "<<a<<endl;
	Activity *key = (Activity *) malloc(sizeof(Activity *));
	key->startTime = activitystore[a]->endTime;
	int pItem =  binarySearch(activitystore,key,0,NumberofActivities-1);
	//cout<<"Pitem"<<pItem<<endl;
	int nextstart = activitystore[pItem]->startTime;
	//cout<<"Next Start"<<nextstart<<"This Ends"<<key->startTime<<endl;
	if ( nextstart != key->startTime ) {
	pItem = pItem+1;
	}
	//cout<<"Just Before starting : pItem  "<<pItem<<"    a+1 "<<a+1<<endl;
	if ((pItem < NumberofActivities) && (a+1 < NumberofActivities)) {
		//cout<<"Both Small"<<endl;
		if(max2[pItem] == 0) {	
			max2[pItem] = evaluation(pItem);
			//cout<<"Calculted Max2 for pItem  "<<pItem<<"   value is  "<<max2[pItem]<<endl;
		 }
		if(max2[a+1] == 0) {
			max2[a+1] = evaluation(a+1);
			//cout<<"Calculted Max2 for a+1  "<<a+1<<"   value is  "<<max2[a+1]<<endl;
		}
		return (max1(max2[a+1],activitystore[a]->compensation + max2[pItem]));
	}
	else if ((pItem < NumberofActivities) && (a+1 >= NumberofActivities)) {
		//cout<<"PItem Small"<<endl;
		max2[pItem] = evaluation(pItem);
		//cout<<"Calculted Max2 for pItem  "<<pItem<<"   value is  "<<max2[pItem]<<endl;
		return (max1(0,activitystore[a]->compensation + max2[pItem]));
	}
	else  if ((pItem >= NumberofActivities) && (a+1 < NumberofActivities)) {
		//cout<<"a+1 Small"<<endl;
		max2[a+1] = evaluation(a+1);
			//cout<<"Calculted Max2 for a+1  "<<a+1<<"   value is  "<<max2[a+1]<<endl;
		return (max1(max2[a+1],activitystore[a]->compensation ));
	} else {
		//cout<<"Both Large"<<endl;
		return (activitystore[a]->compensation);
	}
}
int main() {
		uint32_t testcases = g_fi.ReadNext();

		for (uint32_t i = 0; i < testcases; ++i) {
				 //cout<<"Test Cases  "<<i<<endl;
				 NumberofActivities = g_fi.ReadNext();
				activitystore = (Activity **)malloc(NumberofActivities*sizeof(Activity **));
				for (int r = 0; r < NumberofActivities;r++) {
						uint32_t S = g_fi.ReadNext();
						uint32_t E = g_fi.ReadNext();
						uint32_t C = g_fi.ReadNext();
						Activity * ac = (Activity *)malloc(sizeof(Activity *));
						ac->startTime = S;
						ac->endTime = E;
						ac->compensation = C;
						activitystore[r] = ac;
					}
		
				//This variable will be used to maintain the index of the  lookup table which will help in DP
				int index = 1;

				//Building the lookup table for the dynamic program max2 thing.
				max2 = (int *)calloc(NumberofActivities  ,  sizeof(int));
				int answertc;
				//Sorting the Elements.
				qsort(activitystore,NumberofActivities,sizeof(Activity *),activitycompare);
				//Iteration over the activity store available with us .
					answertc = evaluation(0);	
				/*for ( int i = 0;i < activitystore.size()+1;i++) {
					cout<<"Max t"<<i<<"   "<<max2[i];
				}*/
				free(max2);
				g_fo.PrintUint(answertc, '\n');
				free(activitystore);
		}
		g_fo.Flush();
		return 0;
}
