//Finding prime factors

#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

class prime_factors
{
    public:
    int n;
    vector<int> pf1;
    vector<int> primefactor(int);

    prime_factors()
    {
        cout<<"Enter the number: ";
        cin>>n;
        pf1 = primefactor(n);
        cout<<"The prime factors are: ";
        for(int i=0; i<pf1.size();i++)
            cout<<pf1[i]<<" ";
    }
    void find_pf();
};

vector<int> prime_factors::primefactor(int n)
{
    vector<int> arr;
    if(n==0 || n==1)
    {
        cout<<"\nEnter number greater than 1";
        exit(0);
    }
    if(n%2 == 0)
    {
        arr.push_back(2);
    }
    while(n%2 == 0)
    {
        n = n/2;
    }
    for(int i=3; i<= sqrt(n); i+=2)
    {   
        if(n%i == 0)
        {
            arr.push_back(i);
        }
        while(n%i == 0)
        {
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
    prime_factors obj1;
    
}

