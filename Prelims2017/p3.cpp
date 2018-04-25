#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int N;int K;int Pair = 0;
	cin >> N >> K;
	int Narr [N];
	for(int i=0;i<N;i++) {
		int cur;
		cin >> cur;
		Narr[i] = cur;
	}
	for(int j=0;j<N;j++) {
		int Kcur = (K - Narr [j]);
		for (int c=0;c<N;c++) {
			if (Kcur == Narr[c]) {Pair++;}
		}
	}
	cout << ceil(Pair/2);
}