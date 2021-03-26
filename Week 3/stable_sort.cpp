//Ternary array arrangement
#include <bits/stdc++.h>
using namespace std;

class TernaryArr
{
    int num;
    int *arr;

    public:

    TernaryArr()
    {
        int temp;
        cout<<"Enter number of elements: ";
        cin>>num;
        arr = new int[num];

        for(int i=0;i<num;)
        {
            cout<<"Enter "<<"element number "<<i+1<<": ";
            cin>>temp;
            if(temp == 0 || temp == 1 || temp == 2)
                arr[i++] = temp;

            else
                cout<<"Only 0's, 1's and 2's are allowed (This value was ignored)\n";
        }
    }

    void method1() //Theta(n)
    {
        vector<int> v0,v1,v2;

        for(int i=0;i<num;i++)
        {
            if(arr[i]==0)
                v0.push_back(arr[i]);
            
            if(arr[i]==1)
                v1.push_back(arr[i]);

            if(arr[i]==2)
                v2.push_back(arr[i]);
        }

        v0.insert(v0.end(),v1.begin(),v1.end());
        v0.insert(v0.end(),v2.begin(),v2.end());

        for (int i = 0; i < v0.size(); i++) 
            cout<<v0[i]<<" ";
        cout<<"\n"; 
    }

    void method2() //O(n)
    {
        int count_0 = 0, count_1 = 0;
        int finarr[num];
        int *ptr0,*ptr1,*ptr2;

        for(int i=0;i<num;i++)
        {
            if(arr[i]==0)
                count_0++;
            
            if(arr[i]==1)
                count_1++;

        }

        ptr0 = finarr;
        ptr1 = &finarr[count_0];
        ptr2 = &finarr[count_0 + count_1];

        for(int i=0;i<num;i++)
        {
            if(arr[i]==0)
            {
                *ptr0 = arr[i];
                ptr0++;
            }
            if(arr[i]==1)
            {
                *ptr1 = arr[i];
                ptr1++;
            }
            if(arr[i]==2)
            {
                *ptr2 = arr[i];
                ptr2++;
            }
        }
        
        for (int i = 0; i < num; i++) 
            cout<<finarr[i]<<" ";
        cout<<"\n";
    }

    void method3() //O(n^2)
    {
        for (int i = 0; i < num-1; i++)
        {
            for (int j = 0; j < num-i-1; j++)
                if (arr[j] > arr[j+1]) 
                    swap(arr[j], arr[j+1]); 
        }

        for (int i = 0; i < num; i++) 
            cout<<arr[i]<<" ";
        cout<<"\n";
    }
};

int main()
{
    TernaryArr obj;

    cout<<"\nMethod1:\n";
    obj.method1();
    cout<<"\nMethod2:\n";
    obj.method2();
    cout<<"\nMethod3:\n";
    obj.method3();

    return 0;
}