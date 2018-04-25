#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	int N;int C;cin >> N >> C;int cur = 0;
	int a[N];int freq[C];vector <int> b;
	for(int i=0;i<N;i++){
		cin >> a[i];
	}
	for (int i = 0; i < N; i++) {
		int found = 0;
		for (int j = 0; j < i; j++) {
			if (a[i] == a[j]) found++;
		}
		if (found == 0) {
			freq[i] = 1;
			for (int j = i + 1; j < N; j++)
				if (a[i] == a[j]){ freq[i]++;}
			for(int k =0;k<freq[i];k++)
				b.push_back(a[i]);
		}
	}
	
	
	for(int k =0;k<N;k++)
		cout << b.at(k) << freq[k]<< ' ';
}