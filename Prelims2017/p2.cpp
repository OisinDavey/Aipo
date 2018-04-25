#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main() {
	int A;int B;int G;int Agoal=0;int Bgoal=0;
	cin >> A >> B >> G;
	string Ateam [A];string Bteam [B];
	for(int i=0;i<A;i++){
		string AcurPlay;
		cin >> AcurPlay;
		Ateam[i] = AcurPlay;
	}
	for(int j=0;j<B;j++){
		string BcurPlay;
		cin >> BcurPlay;
		Bteam[j] = BcurPlay;
	}
	for(int c=0;c<G;c++){
		string GcurPlay;
		cin >> GcurPlay;
		for(int k=0;k<A;k++){
			if (GcurPlay == Ateam[k]) {Agoal++;}
		}
		for(int k=0;k<B;k++){
			if (GcurPlay == Bteam[k]) {Bgoal++;}
		}
	}
	if(Agoal>Bgoal){cout << 'A';}
	else if(Bgoal>Agoal){cout << 'B';}
	else {cout << "TIE";}
}