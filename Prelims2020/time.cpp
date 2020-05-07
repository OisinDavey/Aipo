#include<bits/stdc++.h>

//clock_t tStart = clock();	
//printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

#define rep(j,n) for(int i=j;i<n;i++)
#define rup(k,n) for(int j=k;j<n;j++)
#define pb push_back
#define MX_N 100001
#define INF 100000000
#define mod7 1000000007
#define f first
#define s second
#define LSB(i) ((i) & -(i)) 

typedef long double lf;
typedef long long int ll;
typedef unsigned long long int ull;

ll gcd(ull a, ull b){return (a==0)?b:gcd(b%a,a);}
ll lcm(ull a, ull b){return a*(b/gcd(a,b));}
int trinum(int x){return x*(x+1)/2;}
int kx[8] = {+2,+2,-2,-2,+1,+1,-1,-1};
int ky[8] = {+1,-1,+1,-1,+2,-2,+2,-2};
int d9x[9] = {+1,+1,+1,+0,+0,+0,-1,-1,-1};
int d9y[9] = {+1,+0,-1,+1,+0,-1,+1,+0,-1};

using namespace std;

int m[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

struct T{
	int year;
	int month;
	int day;
	int hour;
	int minute;
};

bool leap(int year){
	if(year%400==0){
		return 1;
	}if(year%100==0){
		return 0;
	}if(year%4==0){
		return 1;
	}else{
		return 0;
	}
	
}

bool after(T a, T b){//returns if a is later than b
	if(a.year >= b.year){
		if(a.year > b.year)
			return 1;
		else if(a.month >= b.month){
			if(a.month > b.month)
				return 1;
			else if(a.day >= b.day){
				if(a.day > b.day)
					return 1;
				else if(a.hour >= b.hour){
					if(a.hour > b.hour)
						return 1;
					else if(a.minute >= b.minute){
						if(a.minute > b.minute)
							return 1;
					}
				}
			}
		}
	}return 0;
}

T oneday(T a){//deducts one day from the time
	if(a.day > 1){
		a.day--;
	}else{
		if(a.month == 3){
			a.month = 2;
			if(leap(a.year)){
				a.day = 29;
			}else{
				a.day = 28;
			}
		}else{
			if(a.month == 1){
				a.year--;
				a.month = 12;
				a.day = 31;
			}else{
				a.month--;
				a.day = m[a.month];
			}
		}
	}return a;
}

T addoneday(T a){
	if(a.month == 2){
		if(leap(a.year)){
			if(a.day < 29){
				a.day++;
			}else{
				a.day = 1;
				a.month = 3;
			}
		}else{
			if(a.day < 28){
				a.day++;
			}else{
				a.day = 1;
				a.month = 3;
			}
		}
	}else{ 
		if(a.day < m[a.month]){
			a.day++;
		}else{
			a.day = 1;
			if(a.month == 12){
				a.month = 1;
				a.year++;
			}else{
				a.month++;
			}
		}
	}return a;
}

T onehour(T a){//deducts an hour from the time
	if(a.hour > 0){
		a.hour--;
		return a;
	}else{
		a.hour = 23;
		return oneday(a);
	}
}

T addtenmin(T a){//adds ten minutes to the time
	if(a.minute < 50){
		a.minute+=10;
	}else if(a.hour < 23){
		a.hour++;
		a.minute = (a.minute+10)-60;
	}else{
		a.minute = (a.minute+10)-60;
		a.hour = 0;
		return addoneday(a);
	}return a;
}

bool equal(T a,T b){
	if( (a.year == b.year) && (a.month == b.month) && (a.day == b.day) && (a.hour == b.hour) && (a.minute == b.minute) ){
		return 1;
	}else{
		return 0;
	}
}

int main(){
	srand (time(NULL));
	//ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
	char W;
	T start,end;;
	cin >> start.year >> W >> start.month >> W >> start.day >> start.hour >> W >> start.minute;
	cin >> end.year >> W >> end.month >> W >> end.day >> end.hour >> W >> end.minute;
	int n;
	cin >> n;
	for(int i=0;i<n;++i){
		T x;
		cin >> x.year >> W >> x.month >> W >> x.day >> x.hour >> W >> x.minute;
		if(equal(x,end)||after(x,end)||after(onehour(start),x)){
			cout << "Missed";
		}else{
			if(equal(x,onehour(start))||equal(x,start)){
				cout << "Early";
			}else if(after(x,onehour(start))&&after(start,x)){
				cout << "Early";
			}else{
				if(equal(x,addtenmin(start))){
					cout << "On time";
				}else if(after(x,start)&&after(addtenmin(start),x)){
					cout << "On time";
				}else{
					cout << "Late";
				}
			}
		}cout << endl;
	}
}