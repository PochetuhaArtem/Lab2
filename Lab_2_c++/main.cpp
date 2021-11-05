#include <iostream>
#include <math.h>

using namespace std;


class MyIntegral
{
public:
    void CinArguments()
    {
        cout<<"������� ��� �������: "<<endl;
        cout<<"1 - ����� ��������������� \n2 - ����� �������� \n3 - ����� �������� \n4 - ������� ����� \n5 - ������������ ������ ����� �� ������� � ��� ��������� ���������\n"<<endl;
        cin>>var;
        cout<<"������� ���������� ����������: "<<endl;
        cin>>n;
        cout<<"������� ������ �������: "<<endl;
        cin>>a;
        cout<<"������� ������� �������: "<<endl;
        cin>>b;
    }
    void Dump()
    {
        cout<<"�������: "<<var<<endl;
        cout<<"���������� ����������:"<<n<<endl;
        switch(var)
        {
            case 1:
            cout<<"S = "<<rectanglesMethod()<<endl;
            break;
            case 2:
            cout<<"S = "<<trapezoidalMethod()<<endl;
            break;
            case 3:
            cout<<"S = "<<simpsonMethod()<<endl;
            break;
            case 4:
            cout<<"S = "<<usualMethod()<<endl;
            break;
            case 5:
            DemoVer();
            break;
        }
    }
    double Calc(double x)
    {
       return (sqrt(2*pow(x,3))+sqrt(x));
    }
    double rectanglesMethod() //1
    {
        h=(b-a)/n;
        for(x = a; x <= b ;x = x + h)
        {
            S=S+Calc(x);
        }
        return S=S*h;
    }
    double trapezoidalMethod()  //2
    {
         h=(b-a)/n;
         S=(Calc(a)+Calc(b))/2;
         for(x = a; x <= b ;x = x + h)
         {
             S=S+Calc(x);
         }
         return S=S*h;
    }
    double simpsonMethod()  //3
    {
        if(n%2 != 0)
        {
            cout<<"This method must have an even number of intervals"<<endl;
            return 0;
        }
        h=((b-a)/n);
        for(int i = 0; i <= n;i++)
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
        return ((b-a)/(3*n))*(Calc(a)+4*S+2*SS+Calc(b));
    }
    double usualMethod()  //4
    {
        S=((2*pow(a,2)*sqrt(2*a))/5)+((2*a*sqrt(a))/3);
        SS=((2*pow(b,2)*sqrt(2*b))/5)+((2*b*sqrt(b))/3);
        return SS-S;
    }
    void DemoVer() //5
    {
        cout<<"�������� �������� : � = �^2 � �������� �� 0 �� 3"<<endl;
        cout<<"����� ���������� ������������� : 9"<<endl;
        //1
        h=(b-a)/n;
        for(x = a; x <= b ;x = x + h)
        {
          S=S+pow(x,2);
        }
        S=S*h;
        cout<<"����� ��������������� : "<<S<<endl;
        //2
        h=(b-a)/n;
        S=pow(a,2)+pow(b,2);
        for(x = a; x <= b ;x = x + h)
        {
        S=S+pow(x,2);
        }
        S=S*h;
        cout<<"����� �������� : "<<S<<endl;
        //3
        h=((b-a)/n);
        for(int i = 0; i <= n;i++)
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
        cout<<"����� �������� : "<<S<<endl;
    }
protected:
    int var,n;
    double h,d,x,S=0,SS=0,a,b;
};

int main()
{
    setlocale(LC_ALL, "Russian");
    MyIntegral integral;
    integral.CinArguments();
    integral.Dump();
    return 0;
}
