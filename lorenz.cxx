#include <iostream>

using namespace std;

void f(double* k, double* x,int a, int b, double c){
    k[0]=a*(x[1]-x[0]);
    k[1]=x[0]*(b-x[2])-x[1];
    k[2]=x[0]*x[1]-c*x[2];
}

int main(){
    const int t_max=100;
    int N=100;
    double step = (double) t_max/N;
    int a=10;
    int b=28;
    double c=8.0/3.0;
    
    double x[3]; double xtemp[3];
    double k1[3]; double k2[3]; double k3[3]; double k4[3];

    
    x[0]=1;
    x[1]=1;
    x[2]=0;
    
    
    cout << 0 << '\t' << 1 << '\t' << 1 << '\t' << 1 << endl;
    
    for(int i=1;i<N;i++)
    {
        f(k1,x,a,b,c);
        xtemp[0]=x[0]+step*0.5*k1[0];
        xtemp[1]=x[1]+step*0.5*k1[1];
        xtemp[2]=x[2]+step*0.5*k1[2];
        
        f(k2,xtemp,a,b,c);
        xtemp[0]=x[0]+step*0.5*k2[0];
        xtemp[1]=x[1]+step*0.5*k2[1];
        xtemp[2]=x[2]+step*0.5*k2[2];
        
        
        f(k3,xtemp,a,b,c);
        xtemp[0]=x[0]+step*k3[0];
        xtemp[1]=x[1]+step*k3[1];
        xtemp[2]=x[2]+step*k3[2];
        
        f(k4,xtemp,a,b,c);
        
        x[0]=x[0]+step/6*(k1[0]+2*k2[0]+2*k3[0]+k4[0]);
        x[1]=x[1]+step/6*(k1[1]+2*k2[1]+2*k3[1]+k4[1]);
        x[2]=x[2]+step/6*(k1[2]+2*k2[2]+2*k3[2]+k4[2]);
        
        
        cout << step*i << '\t' << x[0] << '\t' << x[1] << '\t' << x[2] << endl;
    }
    
    
    return 0;
}