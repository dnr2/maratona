//http://acm.timus.ru/problem.aspx?space=1&num=1686
//#tag geometry 3D

#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <iostream>

#define db(x) cerr << #x " == " << x << "\n"
#define _ << ", " <<
using namespace std;


struct pt{
	double x, y, z;
	pt(double x=0, double y=0, double z=0):x(x), y(y), z(z){}
	pt operator-(const pt & p){return pt(x-p.x, y-p.y, z-p.z);}
	pt operator+(const pt & p){return pt(x+p.x, y+p.y, z+p.z);}
	pt operator/(double k){return pt(x/k, y/k, z/k);}
	pt operator*(double k){return pt(x*k, y*k, z*k);}
	double nor(){return sqrt(x*x+y*y+z*z);}
} g[4], v[10];
ostream &operator<<(ostream &os, const pt &p){os<<"(" << p.x<<","<<p.y<<","<<p.z<<")";}

double dot(pt p, pt q){return p.x*q.x+p.y*q.y+p.z*q.z;}
pt cross(pt a, pt b){return pt(a.y*b.z-a.z*b.y, a.z*b.x - a.x*b.z, a.x*b.y-a.y*b.x);}     
pt ppl(pt a, pt b, pt c){
	return a+(b-a)*dot(c-a, b-a)/dot(b-a,b-a);
}
pt ppl2(pt c, pt b){
	return c*( dot(b,c)/dot(c,c) );
}
int n;
int main(){
	for(int i=0;i<4;i++)scanf("%lf%lf%lf", &g[i].x, &g[i].y, &g[i].z);
	scanf("%d", &n);
	for(int i=0;i<n;i++)scanf("%lf%lf%lf", &v[i].x, &v[i].y, &v[i].z);
	double res=0;
	for(int i=0;i<4;i++)for(int j=i+1;j<4;j++)for(int k=j+1;k<4;k++){
		//db(i _ j _ k);
		for(int m=0;m<n;m++){
			
			pt a=g[i], b=g[j], c=g[k];
			int z;
			for(z=0;z==i||z==j||z==k;z++);
			pt d = cross(b-a, c-a);
			//d = ppl(a, a+d, a-g[z]);
			d = ppl2(d, a-g[z]);
			
			if(dot(d,v[m])/(d.nor()*v[m].nor())>0 )
			{
				//pt x = ppl(g[i],g[i]+v[m], g[i]*-1);
				//pt y = ppl(g[j],g[j]+v[m], g[j]*-1);
				//pt z = ppl(g[k],g[k]+v[m], g[k]*-1);
				pt x = g[i]+ppl2(v[m], g[i]*-1);
				pt y = g[j]+ppl2(v[m], g[j]*-1);
				pt z = g[k]+ppl2(v[m], g[k]*-1);
				//db( x _ y _ z _ v[m]);
				res+=fabs(((cross(y-x, z-x)).nor())/2.0)*(v[m].nor());
				
				//pt dir = cross(b-a, c-a);
				//double area = fabs(((cross(y-x, z-x)).nor())/2.0);
				//db( i _ j _ k _ area _ dir);
				
					
			}
			
		}
	}
	printf("%.5lf\n", res*2);
	
	return 0;
}
