#include<stdio.h>
#include<math.h>
#include<vector>
#include<iostream>
using namespace std;

#define EPS 1e-7
// +0.0000000001

#define S(x)	((x)*(x))
#define Z(x)	(fabs(x) < EPS)

struct Vector{
	double x,y,z;

	Vector(double x=0,double y=0,double z=0){
		this->x=x;
		this->y=y;
		this->z=z;
	}
	bool isZero(){
		return Z(x) && Z(y) && Z(z);
	}
	double mag(){
		return sqrt(mag2());
	}
	double mag2(){
		return S(x)+S(y)+S(z);
	}
	void normalize(){ //make this unit
		double m = mag();
		if(Z(m))return;
		x/=m;
		y/=m;
		z/=m;
	}
	Vector unit(){	//this unchanged, make a unit copy of this
		Vector u(x,y,z);
		u.normalize();
		return u;
	}
};

double dotp(Vector a, Vector b){
	return a.x*b.x + a.y*b.y + a.z*b.z;
}

Vector crossp(Vector a, Vector b){
	Vector c;
	c.x = a.y*b.z - a.z*b.y;
	c.y = a.z*b.x - a.x*b.z;
	c.z = a.x*b.y - a.y*b.x;
	return c;
}

Vector operator+(Vector a,Vector b){
	return Vector(a.x+b.x, a.y+b.y, a.z+b.z);	}

Vector operator-(Vector a){
	return Vector(-a.x, -a.y, -a.z);	}

Vector operator-(Vector a,Vector b){
	return Vector(a.x-b.x, a.y-b.y, a.z-b.z);	}

Vector operator*(Vector a,Vector b){
	return crossp(a,b);	}

Vector operator*(Vector a, double b){		// A*2.
	return Vector(a.x*b, a.y*b, a.z*b);	}

Vector operator*(double b, Vector a){		// 2.*A
	return Vector(a.x*b, a.y*b, a.z*b);	}

Vector operator/(Vector a, double b){		// A/2.
	return Vector(a.x/b, a.y/b, a.z/b);	}

double angle(Vector a, Vector b){
	return acos( dotp(a,b) / (a.mag()*b.mag()) );
}



int N;
Vector dir;
Vector old,now;
struct Cir
{
    Vector c;
    double r;
};
Cir cir[107];

struct Intp
{
    Vector I;
    int id;
    Intp(){}
    Intp(Vector _I,int _id){I=_I,id=_id;}
};

vector< Intp >intp;

void getIntp()
{
    int i;
    double t;
    dir.normalize();
    for(i=0;i<N;i++)
    {
        Vector temp=(old-cir[i].c);
		double B=2*dotp(dir,temp);
        double D=B*B-4*(dotp(temp,temp)-cir[i].r*cir[i].r);
        if(D>=0.00)
        {
            t=-B+sqrt(D);
			t/=2;
            if(t>EPS)intp.push_back(Intp((old+t*dir),i));

            t=-B-sqrt(D);
			t/=2;
            if(t>EPS)intp.push_back(Intp((old+t*dir),i));
        }
    }
}

int main()
{
	//freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
    int i;
    while(scanf("%d",&N)==1)
    {
        if(!N)break;
        scanf("%lf%lf%lf",&dir.x,&dir.y,&dir.z);
        old=Vector(0,0,0);
        for(i=0;i<N;i++)
        {
            scanf("%lf%lf%lf%lf",&cir[i].c.x,&cir[i].c.y,&cir[i].c.z,&cir[i].r);
        }
        while(true)
        {
            intp.clear();
            getIntp();
            if(!intp.size())break;
            double tdist,dist=999999999.99;
            int id;
            int sz=intp.size();
            for(i=0;i<sz;i++)
            {
                tdist=dotp((intp[i].I-old),(intp[i].I-old));

                if(dist>tdist)
                {
                    dist=tdist;
                    now=intp[i].I;
                    id=intp[i].id;
                }
            }
            Vector u = now-cir[id].c;
			u.normalize();
			dir=2*u*dotp(u,-dir)+dir;
            old=now;

        }
        printf("%.6lf %.6lf %.6lf\n",old.x,old.y,old.z);
    }
    return 0;
}
