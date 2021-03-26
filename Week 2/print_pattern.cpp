#include<iostream>
using namespace std;

class pattern
{
    public:
    int n, i, j;
    void func1()
    {
        for(i=n; i>=1; i--)
        {
            for(j=1; j<=i; j++)
                cout<<j;
            cout<<"\n";
        }
    }

    void func2()
    {
        for(i=1; i<=n; i++)
        {
            for(j=1; j<i; j++)
                cout<<" ";

            for(j=i; j<=n; j++)
                cout<<j;
            cout<<"\n";
        }
    }

    void func3()
    {
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=i; j++)
                cout<<j;
            cout<<"\n";
        }
    }

    void func4()
    {
        for(i=n; i>=1; i--)
        {
            for(j=1; j<i; j++)
                cout<<" ";
            
            for(j=i; j<=n; j++)
                cout<<j;
            cout<<"\n";
        }
    }

    void func5()
    {
            
    }

    pattern()
    {
        cout<<"\nEnter the value of n: ";
        cin>>n;
    }
};



int main()
{
    pattern obj1;
    cout<<"\nPattern 1:\n\n";
    obj1.func1();
    cout<<"\nPattern 2:\n\n";
    obj1.func2();
    cout<<"\nPattern 3:\n\n";
    obj1.func3();
    cout<<"\nPattern 4:\n\n";
    obj1.func4();
    cout<<"\nPattern 5:\n\n";
    obj1.func5();
}