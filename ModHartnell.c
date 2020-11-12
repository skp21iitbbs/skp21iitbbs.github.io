//modified Hartnell Study
#include<stdio.h>
#include<math.h>
#define W 9.81*(M)
#define Phi 3.14*phi/180
double mod(double x){
if(x>=0) return x;
else return(-1*x);}
int main(){
double N1,N2,phi,r0,Fc1,Fc2,r1,r2,c;
float x,y,S1,S2,M,m,h1,h2;
printf("Enter the value of angle between arms: ");
scanf("%lf",&phi);
printf("Enter the value of sleeve arm length and bell crank lengths in mtrs\n");
scanf("%f%f",&y,&x);
printf("the mean radial distance in m: ");
scanf("%lf",&r0);
printf("Enter the values of bell crank mass, sleeve mass respectively\n\n");
printf("Bell crank mass: ");
scanf("%f",&m);
printf("Sleeve mass: ");
scanf("%f",&M);
printf("uplift in m is: ");
scanf("%f",&h1);
printf("downlift in m is: ");
scanf("%f",&h2);
printf("Enter the value of spring force at max and min condition in newtons\n");
scanf("%f%f",&S1,&S2);
//Modified Hartnell Governor
//x=c*PB
printf("enter the modified value of c: ");
scanf("%lf",&c);
if(c==1)
{
printf("centrifugal force will no longer produce restoring effect, hence S1=S2=-W\n");
return 0;}
r1=r0-(x*(c-1)*cos(Phi)/c)+(x*(c-1)*h1*sin(Phi)/(y*c));
r2=r0-(x*(c-1)*cos(Phi)/c)-(x*(c-1)*h2*sin(Phi)/(y*c));
Fc1=(m*9.81*(cos(Phi)-((h1/y)*sin(Phi)))/((h1/y)*cos(Phi)+sin(Phi)))+(W+S1)*y*c/(x*(c-1))*(2*((h1/y)*cos(Phi)+sin(Phi)));
Fc2=(m*9.81*(cos(Phi)+((h2/y)*sin(Phi)))/((h2/y)*cos(Phi)-sin(Phi)))+(W+S2)*y*c/(x*(c-1))*(2*((h2/y)*cos(Phi)-sin(Phi)));
N1=sqrt(mod(Fc1/(m*r1)))*60/(2*3.14);
N2=sqrt(mod(Fc2/(m*r2)))*60/(2*3.14);
printf("For modified Hartnell Governor, maximum speed and minimum speed values for the fixed parameters is coming as %lf rpm and %lf rpm\nThe working range coming to be %lf rpm\nThe coefficient of insensitivity is: %lf\n",N1,N2,(N1-N2),2*(N1-N2)/(N1+N2));
//normal Hartnell Governor
r1=r0+(h1*(x/y));
r2=r0-(h2*(x/y));
Fc1=(W+S1)*(y/(2*x))-m*9.81*(h1/y);
Fc2=(W+S2)*(y/(2*x))+m*9.81*(h2/y);
N1=sqrt(mod(Fc1/(m*r1)))*60/(2*3.14);
N2=sqrt(mod(Fc2/(m*r2)))*60/(2*3.14);
printf("For normal Hartnell governor, maximum speed and minimum speed values for the fixed parameters is coming as %lf rpm and %lf rpm\nThe working range coming to be %lf rpm\nThe coefficient of insensitivity is: %lf",N1,N2,(N1-N2),2*(N1-N2)/(N1+N2));
printf("\nInitial Elongation will be %f mtrs\n",(h1+h2)*S2/(S1-S2));
return 0;
}
