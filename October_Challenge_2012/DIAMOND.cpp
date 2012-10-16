#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <iostream>
#include <math.h>
#include <map>
#include <string.h>

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


int max1(int a, int b)
{
int x = a > b ? a:b;
return (x);
}
FastInput g_fi;
FastOutput g_fo;
uint32_t NumberofDiamonds;
float max2[2000][2000];
int used[2000][2000];
int *diamonds;
int tc;

float expecteddiamondvalue(int start,int end) {
	cout<<"Start : "<<start<<"END :"<<end<<endl;
		if ( end < 0 || start > (NumberofDiamonds -1) ) {
			return 0.0;
		}
	if ( end - start <= 2 ) {
		if ( (end - start) == 2 ) {
	//		cout<<2*diamonds[start] + diamonds[start+1] + diamonds[end] + 2*diamonds[end] + diamonds[start] + diamonds[start + 1]<<endl;
			return (2*diamonds[start] + diamonds[start+1] + diamonds[end] + 2*diamonds[end] + diamonds[start] + diamonds[start + 1])/4.00;
		}
		if (start == end) {
	//		cout<<diamonds[start];
			return diamonds[start];
		}

		if (( end - start) == 1) {
	//		cout<< diamonds[start] + diamonds[end]<<endl ;
			return (diamonds[start] + diamonds[end] )/2.00;
		}
		
	}

	if( used[start][end] == tc+1) {
	//	cout<<max2[start][end]<<endl;
		return	max2[start][end];
	}

	if(used[start+2][end] < tc+1) {
	//	cout<<"Start+2"<<"end"<<endl;
		max2[start+2][end] = expecteddiamondvalue(start+2,end);
		used[start+2][end] = tc+1;
	}

	if(used[start+1][end-1] < tc+1) {
	//	cout<<"Start+2"<<"end"<<endl;
	max2[start+1][end-1] = expecteddiamondvalue(start+1,end-1);
	used[start+1][end-1] = tc+1;
	}

	if(used[start][end-2] < tc+1) {
		max2[start][end-2] = expecteddiamondvalue(start,end-2);
		used[start][end-2] = tc+1;
	}
	
//	cout<<"snkj"<<(2*diamonds[start] + 2*diamonds[end] + max2[start+2][end] + 2*max2[start+1][end-1] + max2[start][end-2])<<endl;
	return (float)(2*diamonds[start] + 2*diamonds[end] + max2[start+2][end] + 2*max2[start+1][end-1] + max2[start][end-2])/(4.00);
//	return (float)(2*diamonds[start] + 2*diamonds[end] + expecteddiamondvalue(start+2,end) + 2*expecteddiamondvalue(start+1,end-1) + expecteddiamondvalue(start,end-2))/(4.00);

}	

int main() {
		uint32_t testcases = g_fi.ReadNext();
/*				max2 = (float **)calloc(2000,  sizeof(float*));
				used = (int **)calloc(2000  ,  sizeof(int *));
				for (int r = 0; r < 2000;r++) {
					max2[r] = (float *)calloc(2000  ,  sizeof(float));
					used[r] = (int *)calloc(2000  ,  sizeof(int));
				}*/
//			memset(max2, 0, sizeof(float)*2000*2000);
//			memset(used, 0, sizeof(int)*2000*2000);

		for (tc = 0; tc < testcases; ++tc) {
				 //cout<<"Test Cases  "<<i<<endl;
				 NumberofDiamonds =  g_fi.ReadNext();
				diamonds = (int *)malloc(NumberofDiamonds*sizeof(int *));
				for (int r = 0; r < NumberofDiamonds;r++) {
						uint32_t S = g_fi.ReadNext();
						diamonds[r] = S;
					}
				
		
				//This variable will be used to maintain the index of the  lookup table which will help in DP
				int index = 1;

				//Building the lookup table for the dynamic program max2 thing.

				float answertc;
				//Sorting the Elements.
				//Iteration over the activity store available with us .
					answertc = expecteddiamondvalue(0,NumberofDiamonds-1);	
				/*for ( int i = 0;i < activitystore.size()+1;i++) {
					cout<<"Max t"<<i<<"   "<<max2[i];
				}*/
				
				printf("%f\n",answertc);

//				memset(max2, 0, sizeof(float)*2000*2000);
//				memset(used, 0, sizeof(int)*2000*2000);
				free(diamonds);
}

		//				g_fo.PrintUint(answertc, '\n');
				////cout<<"final answer  : "<<a<<"After division by :"<<divis<<endl;
/*
				for (int r = 0; r < NumberofDiamonds;r++) {
					free(max2[r]);
					free(used[r]);
				}
				free(max2);
				free(used);*/
		g_fo.Flush();
		return 0;
}
