#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <cfloat>
using namespace std;

struct Point
{
	long long int x;
	long long int y;
};

void printPoints(Point P[],int n)
{
	for(int i=0;i<n;i++)
		cout << P[i].x <<","<< P[i].y << " ";
	cout << endl << endl;
}


bool compareX(Point p1,Point p2)
{   return p1.x < p2.x; }

bool compareY(Point p1,Point p2)
{	return p1.y < p2.y; }

long double dist(Point p1,Point p2)
{ return (long double)(sqrt((long double)((p1.x-p2.x)*(p1.x-p2.x)) + (long double)((p1.y-p2.y)*(p1.y-p2.y)))); }

long double comp_dbl(long double a,long double b)
{	return (a<b)?a:b;  }

long double bruteForce(Point P[],int n)
{
	long double min_dbl = DBL_MAX;
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			min_dbl = comp_dbl(dist(P[i],P[j]),min_dbl);
		}
	}
	return min_dbl;
}

long double stripClosest(Point strip[],int size,float d)
{
	long double min_dbl = d;
	sort(strip,strip+size,compareY);
	for(int i=0;i<size;i++)
		for(int j=i+1;j<size&&(strip[j].y-strip[i].y) < min_dbl;j++)
			min_dbl = comp_dbl(dist(strip[i],strip[j]),min_dbl);
	return min_dbl;
 }

 long double closest(Point P[],int n)
 {
 	if (n<=3)
 		return bruteForce(P,n);

 	int mid = n/2;
 	Point mid_point = P[mid];

 	long double dl = closest(P,mid);
 	long double dr = closest(P+mid,n-mid);
 	long double d = comp_dbl(dl,dr);

 	Point strip[n];
 	int j = 0;
 	for(int i=0;i<n;i++)
 		if (abs(P[i].x - mid_point.x) < d)
 			strip[j++] = P[i];

 	return comp_dbl(d,stripClosest(strip,j,d));
 
 }

long double minimal_distance(Point P[],int n) 
{
	sort(P,P+n,compareX);
	return closest(P,n);
}

int main() {
  size_t n;
  std::cin >> n;
  Point arr[n];
  for (size_t i = 0; i < n; i++) {
    cin >> arr[i].x >> arr[i].y;
  }
  //Point arr[6] = { {2,3},{12,30},{40,50},{5,1},{12,10},{3,4} };
  std::cout << std::fixed;
  std::cout << std::setprecision(9) << minimal_distance(arr,n) << "\n";
}
