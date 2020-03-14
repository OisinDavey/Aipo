#include<bits/stdc++.h>

#define INF 100000000
#define mod7 1000000007

typedef long double lf;
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

struct person{
	string name;
	int age;
	string status;
	string relationship;
	string rebel;
	string luck;
};

int main(){
	//ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
	person you;
	person them;
	cin >> you.name >> you.age >> you.status >> you.relationship >> you.rebel >> you.luck;
	cin >> them.name >> them.age >> them.status >> them.relationship >> them.rebel >> them.luck;
	if(you.age < 15){
		if(them.age < 15){
			cout << "tu";
		}else{
			if(you.relationship == "family"){
				cout << "tu";
			}else{
				cout << "vous";
			}
		}
	}else{
		if(them.age < 15){
			if(them.status == "royal"){
				cout << "vous";
			}else{
				cout << "tu";
			}
		}else{
			if(them.relationship == "friend" || them.relationship == "lover"){
				cout << "tu";
			}else if(you.relationship == "spouse"){
				if(them.name == "Jacques-Chirac"){
					cout << "vous";
				}else{
					cout << "tu";
				}
			}else if(you.relationship == "father-in-law"){
				cout << "dunno";
			}else if(you.relationship == "boss"){
				if(you.status == "Le-Google-employed"){
					cout << "tu";
				}else{
					if(you.rebel == "ticked-off"){
						cout << "tu";
					}else{
						cout << "vous";
					}
				}
			}else if(you.relationship == "teacher"){
				if((you.age - them.age) >= 20){
					cout << "tu";
				}else{
					cout << "vous";
				}
			}else{
				if(them.status == "god"){
					cout << "tu";
				}else{
					if((them.age-you.age) >= 10){
						cout << "vous";
					}else{
						if(you.rebel == "May-1968"){
							cout << "tu";
						}else{
							if(you.rebel == "Woodstock"){
								cout << "tu";
							}else{
								if(them.relationship == "peer"){
									cout << "tu";
								}else if(you.relationship == "unsure"){
									if(you.luck == "lucky"){
										cout << "tu";
									}else{
										cout << "vous";
									}
								}else{
									cout << "vous";
								}
							}
						}
					}
				}
			}
		}
	}
}