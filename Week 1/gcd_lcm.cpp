//Finding GCD and LCM of two numbers

#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;

class calculator
{
    public:
    int num1, num2, lcm, gcd ;
    vector<int> pf1;
    vector<int> pf2;
    vector<int> dest;
    void method1();
    int method2(int , int );
    void method3();
    vector<int> primefactor(int );
    calculator()
    {
        cout<<"Enter the first number: ";
        cin>>num1;
        cout<<"Enter the second number: ";
        cin>>num2;
        gcd = 1;
    }
    void euclids_method()
    {
        gcd = method2(num1, num2);
        lcm = (num1*num2)/gcd;
        cout<<"The gcd of the two numbers is(Method 2): "<<gcd<<"\n";
        cout<<"The lcm of the two numbers is(Method 2): "<<lcm<<"\n";
    }
};

void calculator::method1()
{
    int a, b, c;
    a = (num1 > num2) ? num1 : num2;
    b = (num1 < num2) ? num1 : num2;

    for(int i = b; i>=1 ; i--)
        if(a%i == 0 && b%i == 0)
        {
            gcd = i;
            break;
        }

    lcm = (num1*num2)/gcd;

    cout<<"The gcd of the two numbers is(Method 1): "<<gcd<<"\n";
    cout<<"The lcm of the two numbers is(Method 1): "<<lcm<<"\n";
}

int calculator::method2(int num1, int num2)
{
    if(num2 == 0)
        return num1;
    return method2(num2, num1 % num2);
}

void calculator::method3()
{
    pf1 = primefactor(num1);
    pf2 = primefactor(num2);
    set_intersection(pf1.begin(), pf1.end(), pf2.begin(), pf2.end(), back_inserter(dest));
    gcd = 1;
    for(int i=0; i<dest.size();i++)
        gcd *= dest[i];
    
    lcm = (num1*num2)/gcd;
    cout<<"The gcd of the two numbers is(Method 3): "<<gcd<<"\n";
    cout<<"The lcm of the two numbers is(Method 3): "<<lcm;
}

vector<int> calculator::primefactor(int n)
{
    vector<int> arr;
    if(n==0 || n==1)
    {
        cout<<"\nEnter number greater than 2";
        exit(0);
    }
    while(n%2 == 0)
    {
        n = n/2;
        arr.push_back(2);
    }
    for(int i=3; i<= sqrt(n); i+=2)
    {   
        while(n%i == 0)
        {
            arr.push_back(i);
            n = n/i;
        }
    }
    if(n > 2)
    {
        arr.push_back(n);
    }    
    return arr;
}   

int main()
{
    calculator obj1;
    cout<<'\n';
    obj1.method1();
    cout<<'\n';
    obj1.euclids_method();
    cout<<'\n';
    obj1.method3();
    cout<<"\n\n";
    return 0;
}