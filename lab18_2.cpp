#include<iostream>
#include<algorithm>
#include<utility>
#include<cmath>
using namespace std;

struct Rect{
	double x,y,w,h;
};

double overlap(Rect *A, Rect *B){
    pair<double, double> result = minmax((*A).x, (*B).x);
    pair<double, double> result1 = minmax(((*A).x+(*A).w), ((*B).x+(*B).w));
    pair<double, double> result2 = minmax((*A).y, (*B).y);
    pair<double, double> result3 = minmax(((*A).y-(*A).h), ((*B).y-(*B).h));
    
    double Kwang=0, Yaw=0;
    if(((*A).x+(*A).w) > (*B).x)
    {
        Kwang += (result1.first - result.second);
        Yaw += (abs(result2.first) + abs(result3.second));
        return Kwang*Yaw;
    }
    else{return 0;}
}