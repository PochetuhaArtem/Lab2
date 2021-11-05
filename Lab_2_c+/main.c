#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void Dump(double S,double Fault,int n )//Вивід інфомації на консоль
{
    printf("S = %lf\n",S);
    printf("fault = %lf\n",Fault);
    printf("Count of steps = %d\n",n);
    printf("ALL OK\n\n");
}

double Calc(double x)//Функція розрахунку інтеграла
{
    return (sqrt(2*pow(x,3))+sqrt(x));
}

double Rectangles(int n,double a,double b)//Функція розрахунку інтеграла методом прямокутників
{
    double h,S,x;
    h=(b-a)/n;
    for(x = a; x <= b ;x = x + h)
    {
     S=S+Calc(x);
    }
    S=S*h;
    return S;
}
double Trapezoidal(int n,double a,double b)//Функція розрахунку інтеграла методом трапецій
{
   double h,S = 0,x;
   h=(b-a)/n;
   S=Calc(a)+Calc(b);
    for(x = a; x <= b ;x = x + h)
    {
    S=S+Calc(x);
    }
    S=S*h;
    return S;
}
double Simpson(int n,double a,double b)//Функція розрахунку інтеграла методом сімпсона
{
    double h,S = 0,SS = 0;
    int i = 0;
    h=((b-a)/n);
        for(i = 0; i <= n;i++)
        {
            if(i%2 != 0)
            {
              S=S+Calc(a+h*i);
            }
            if(i%2 == 0)
            {
              SS=SS+Calc(a+h*i);
            }
        }
        S=((b-a)/(3*n))*(Calc(a)+4*S+2*SS+Calc(b));
   return S;
}

int main()
{
/*
MY VARIANT 14
integral ot 0 do 3  (sqrt(2*pow(x,3))+sqrt(x))
*/
    int var,n,i,j=1;
    double h,d,x,S=0.0,SS=0.0,a,b;
   while(1)//нескінченний цикл 1 = true
   {
    printf("Choise method: \n");
    printf("1 - Method of rectangles\n2 - Method of trapezoidal\n3 - Simpson method\n4 - Usual method\n5 - Demo version(y = x^2)\n");
    scanf("%d",&var);
    switch(var)
    {
    case 1://Method of rectangles
        printf("Count of steps: \n");
        scanf("%d",&n);
        printf("lower limit: \n");
        scanf("%lf",&a);
        printf("upper border: \n");
        scanf("%lf",&b);
        for(j; j<=2;j++)
        {
              if(j==1)
              {
               S = Rectangles(n,a,b);
               n=n+2;
              }
            SS = Rectangles(n,a,b);
            if(fabs(S-SS)>0.00001 && fabs(S-SS)<0.001)//чи задовольняє похибка відповідь
            {
                SS = fabs(S-SS);
                Dump(S,SS,n);
                break;
            }
            else
            {
                j=0;//якзо похибка не задовольняє відповідь то цикл починається з початку
            }
        }
        break;
    case 2://Method of trapezoidal
        printf("Count of steps: \n");
        scanf("%d",&n);
        printf("lower limit: \n");
        scanf("%lf",&a);
        printf("upper border: \n");
        scanf("%lf",&b);
        for(j; j<=2;j++)
        {
              if(j==1)
              {
               S = Trapezoidal(n,a,b);
               n=n+2;
              }
            SS = Trapezoidal(n,a,b);
            if(fabs(S-SS)>0.00001 && fabs(S-SS)<0.001)
            {
                SS = fabs(S-SS);
                Dump(S,SS,n);
                break;
            }
            else
            {
                j=0;
            }
        }
        break;
 case 3://Simpson method
        do
        {
            printf("This method must have an even number of intervals \n");
            printf("Count of steps: \n");
            scanf("%d",&n);
        }
        while(n%2!=0);
        printf("lower limit: \n");
        scanf("%lf",&a);
        printf("upper border: \n");
        scanf("%lf",&b);

        for(j; j<=2;j++)
        {
              if(j==1)
              {
               S = Simpson(n,a,b);
               n=n+2;
              }
            SS = Simpson(n,a,b);
            if(fabs(S-SS)>0.00001 && fabs(S-SS)<0.001)
            {
                SS = fabs(S-SS);
                Dump(S,SS,n);
                break;
            }
            else
            {
                j=0;
            }
        }
        break;
    case 4://Usual method
        printf("lower limit: \n");
        scanf("%lf",&a);
        printf("upper border: \n");
        scanf("%lf",&b);
        S=((2*pow(a,2)*sqrt(2*a))/5)+((2*a*sqrt(a))/3);
        SS=((2*pow(b,2)*sqrt(2*b))/5)+((2*b*sqrt(b))/3);
        S=SS-S;//обрахунок інтеграла звичаним способом
        printf("S : %lf\n\n",S);
        break;
    case 5://Demo
        //y = x^2
        printf("My integral (0->3) y = x^2 \n");
        printf("Count of steps: \n");
        scanf("%d",&n);
        printf("lower limit: \n");
        scanf("%lf",&a);
        printf("upper border: \n");
        scanf("%lf",&b);
        printf("Calculator answer : 9\n");//порівнення відповіді калькулятора та відповідей всіх трьох методів
        //1
        h=(b-a)/n;
        for(x = a; x <= b ;x = x + h)
        {
          S=S+pow(x,2);
        }
        S=S*h;
        printf("Method of rectangles : %lf\n",S);
        //2
        h=(b-a)/n;
        S=pow(a,2)+pow(b,2);
        for(x = a; x <= b ;x = x + h)
        {
        S=S+pow(x,2);
        }
        S=S*h;
        printf("Method of trapezoidal : %lf\n",S);
        //3
        h=((b-a)/n);
        S = 0;
        for(i = 0; i <= n;i++)
        {
            if(i%2 != 0)
            {
              S=S+pow(a+h*i,2);
            }
            if(i%2 == 0)
            {
              SS=SS+pow(a+h*i,2);
            }
        }
        S=((b-a)/(3*n))*(pow(a,2)+4*S+2*SS+pow(b,2));
        printf("Simpson method : %lf\n\n",S);
        break;
    default:
        printf("No one variant\n");//якщо користувач не вибрав жодного з варіантів
        break;
    }
   }
    return 0;
}
