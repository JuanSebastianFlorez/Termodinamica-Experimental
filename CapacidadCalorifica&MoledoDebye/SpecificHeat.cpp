#include <iostream>
#include <cmath>
 const double Ti = 77.0;
 const double TfAl = 291.0;
 const double TfPb = 292.0;
 const double TfZn = 292.0;
 const double TfCu = 290.0;
 const double TfSn = 295.0;
 const double TfBronze = 291.0;
const double MasaMolarAl = 26.981;
const double MasaMolarPb = 207.2;
const double MasaMolarCu = 63.546;
const double MasaMolarSn =  118.71;
const double MasaMolarZn =  65.38 ;
const double MasaMolarBronze = 0.88*MasaMolarCu + 0.12*MasaMolarSn;
const double K_bxAvo=8.314469723;
const double MasaAl=66.5;
const double MasaPb=229.1;
const double MasaCu=63.3;
const double MasaSn=62.8;
const double MasaZn=64.4;
const double MasaBronze=26.3;
const double QAl=10447.5;
const double QPb=6109.3;
const double QCu=4417.8;
const double QSn=2825.8;
const double QBronze=1950.2;
const double QZn=4776;
const double KAl=9*K_bxAvo*MasaAl/MasaMolarAl;
const double KPb=9*K_bxAvo*MasaPb/MasaMolarPb;
const double KCu=9*K_bxAvo*MasaCu/MasaMolarCu;
const double KSn=9*K_bxAvo*MasaSn/MasaMolarSn;
const double KZn=9*K_bxAvo*MasaZn/MasaMolarZn;
const double KBronze=9*K_bxAvo*MasaBronze/MasaMolarBronze;
const int N1=10000;
using namespace std;

double f1(double a)
{ return pow(a,3)/(exp(a)-1);
}

double f2(double a)
{ return pow(a,4)*exp(a)/((exp(a)-1)*(exp(a)-1));
}

double IntegralPorSimpson( double b, double a)
{
  
  // int N = rint( (b-a)*N1/100);
       int N=N1;
  //double h = 0.00001;
  /*
  int i; double xi,suma,integral;

suma=0;
 xi=a;
 for(i=0;xi<=b+h;i++)
    {
    xi=a+i*h;
    if((i==0)||(xi>b))
    suma+=f1(xi);
    else if(i%2==0)
    suma+=2*f1(xi);
    else
suma+=4*f1(xi);
}
integral=h/3*suma;
return integral;
  */

 double h=(b-a)/N;
int i; double xi,suma,integral;

suma=0;
for(i=0;i<=N;i++)
    {
    xi=a+i*h;
    if((i==0)||(i==N))
    suma+=f1(xi);
    else if(i%2==0)
    suma+=2*f1(xi);
    else
suma+=4*f1(xi);
}
integral=h/3*suma;
return integral;

}


int main(void)
{
  double a=0.000000001, dt=0.01, F,Td,holdnew,holdold;
  /*
 for(T=0.1;T<500;T+=dt){
   F=K*pow(T,4)*IntegralPorSimpson(Td/T,a)/pow(Td,3);
   cout<<T<<" "<<F<<endl;
 }
  */
   holdold=1;
  
for(Td=0.01;Td<450;Td+=dt){
  //  F=(KAl/pow(Td,3))*pow(Ti,4)*IntegralPorSimpson(Td/Ti,a);
   holdnew = (KPb/pow(Td,3))*(pow(TfPb,4)*IntegralPorSimpson(Td/TfPb,a) - pow(Ti,4)*IntegralPorSimpson(Td/Ti,a))-QPb;
   //   F = (KCu/pow(Td,3))*(pow(TfCu,4)*IntegralPorSimpson(Td/TfCu,a) - pow(Ti,4)*IntegralPorSimpson(Td/Ti,a))-QCu;
//F = (K/pow(Td,3))*pow(Tf,4)*IntegralPorSimpson(Td/Tf,a) ;

 if(holdold*holdnew<0) cout<<Td<<endl;
 holdold=holdnew;

 

 //cout<<Td<<" "<<F<<endl;
}

return 0;

}
