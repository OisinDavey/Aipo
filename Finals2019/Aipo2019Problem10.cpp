#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<double, double> dd;

vector<pair<dd,dd> > edges;
vector<dd> points;

bool above(double x, double y, int i){
	double x1 = edges[i].first.first;
	double y1 = edges[i].first.second;
	double x2 = edges[i].second.first;
	double y2 = edges[i].second.second;
	if(y1==y2){
		return (y < y1 && min(x1,x2)<=x && x<=max(x1,x2));
	}else if(x1==x2){
		return (x==x1 && y<=min(y1,y2));
	}else{
		double m = (y1-y2)/(x1-x2);
		double c = y1 - m*x1;
		return (min(x1,x2)<=x && x<=max(x1,x2))?(y<=(m*x + c)):0;
	}
}

int main(){
	int n;
	double inside=0,outside=0;
	cin >> n;
	for(int i=0;i<n;i++){
		dd p;
		cin >> p.first >> p.second;
		points.push_back(p);
	}for(int i=0;i<points.size()-1;i++){
		pair<dd,dd> edge;
		edge.first = points[i];
		edge.second = points[i+1];
		edges.push_back(edge);
	}edges.push_back({points[points.size()-1],points[0]});
	for(double x = 0.00;x<=1.00;x+=0.001){//1'000 loops
		for(double y = 0.00;y<=1.00;y+=0.001){//1'000 loops, 1'000'000 total
			int num=0;
			for(int i=0;i<edges.size();i++)//20 loops, 20'000'000 total
				num+=(above(x,y,i));
			(num%2)?inside++:outside++;
		}
	}cout << inside/(inside+outside);
}
