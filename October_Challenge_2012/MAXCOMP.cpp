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


FastInput g_fi;
FastOutput g_fo;
int main() {
		uint32_t testcases = g_fi.ReadNext();

		for (uint32_t i = 0; i < testcases; ++i) {
				multimap<int,Activity> activitystore;
				multimap<int,Activity>::iterator itractivitystore,itr1activitystore;
				multimap<int,Activity> Y;
				multimap<int,Activity>::iterator itrY;
				activitystore.clear();
				uint32_t NumberofActivities = g_fi.ReadNext();
				cout<<"Testcase"<<i<<endl;
				for (int r = 0; r < NumberofActivities;r++) {
						uint32_t S = g_fi.ReadNext();
						uint32_t E = g_fi.ReadNext();
						uint32_t C = g_fi.ReadNext();
					//	cout<<"S :"<<S<<"   E :"<<E<<"   C :"<<C;
						Activity * ac = (Activity *)malloc(sizeof(Activity));
						ac->startTime = S;
						ac->endTime = E;
						ac->compensation = C;
						activitystore.insert(pair<int,Activity>(E,*ac));
						Y.insert(pair<int,Activity>(S,*ac));
					}
		
				//This variable will be used to maintain the index of the  lookup table which will help in DP
				int index = 1;

				//Building the lookup table for the dynamic program max thing.
				int *max = (int *)calloc(activitystore.size() +1  ,  sizeof(int));
				int answertc;
				//Iteration over the activity store available with us .
				for ( itractivitystore = activitystore.begin();itractivitystore != activitystore.end(); itractivitystore++,index++) {
					 (*itractivitystore).second.index = index;
					 int t  = 0;
					 int s  = 0;
					 int flag =0;
						for ( itrY = Y.begin();itrY != Y.end(); itrY++) {
							t++;
							if(flag == 0) {
								s++;
							}
							if (((*(itrY )).first == (*itractivitystore).second.startTime)) {
								flag = 1;										
							}

							if (((*(itrY )).first > (*itractivitystore).second.endTime )) {
						 	t--; 
							goto foundpoint;
							}
							
		 }
		foundpoint:	
				max[t] = max1(max[t-1],max[s] + (*(itractivitystore )).second.compensation);
//				cout<<"Maxx for "<<t<<"   "<<max[t]<<endl;
				answertc = max[t];	
				}
				free(max);
				g_fo.PrintUint(answertc, '\n');
		}
		g_fo.Flush();
		return 0;
}
