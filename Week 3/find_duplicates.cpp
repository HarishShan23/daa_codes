//Program to find duplicates in an array
#include <bits/stdc++.h>
using namespace std;

class findDuplicates
{
    int len;
    int *arr;
    bool ifPresent;
    vector<int> al;

    public:

    findDuplicates()
    {
        cout<<"Enter number of elements: ";
        cin>>len;

        arr = new int[len];

        cout<<"Enter elements:\n";
        for(int i=0;i<len;i++)
            cin>>arr[i];
    }

    void method1() //O(n^2)
    {
        
        ifPresent = false;
    
        for(int i = 0; i < len - 1; i++)
        {
            for(int j = i + 1; j < len; j++)
            { 
                if (arr[i] == arr[j])
                {
                    auto it = find(al.begin(),al.end(), arr[i]);
                                        
                    if (it != al.end()) 
                        break;

                    else
                    {
                        al.push_back(arr[i]);
                        ifPresent = true;
                    }
                }
            }
        }
        display();
    }

    void display()
    {
        if (ifPresent == true)
        {
            cout<<"Duplicates: ";

            for(int i = 0; i < al.size(); i++)
                cout << al[i] << " ";
            
            cout << '\n';
        }

        else
            cout << "No duplicates present in array";
    }

    void method2() //O(n)
    {
        unordered_map<int, int> freq;
        for (int i=0; i<len; i++)
            freq[arr[i]]++;
    
        ifPresent = false;
        
        cout<<"Duplicates: ";
        for (auto itr : freq)
        {
            if (itr.second > 1)
            {
                cout << itr.first << " ";
                ifPresent = true;
            }
        }

        if (ifPresent == false)
            cout << "Not present";
    }
};
 
int main()
{
    findDuplicates obj;
    cout<<"\nMethod1:\n";
    obj.method1();
    cout<<"\nMethod2:\n";
    obj.method2();
 
    return 0;
}