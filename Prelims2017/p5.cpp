#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main() {
	int x;
	cin >> x;
	int y = ((x+2)*((x-1)*(x-1)+(x-1))*0.5);
	cout << fixed << y+(x*x+2*x);
}