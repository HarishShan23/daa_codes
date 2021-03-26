//Finding neither maximum nor minimum element

#include<iostream>
using namespace std;

class findnum
{
    public:
        int n;
        int *arr;
        int count;
        int max;
        int min;
        void func();
        findnum()
        {
            cout<<"Enter the number of elements: ";
            cin>>n;
            arr = new int[n];
            cout<<"Enter the elements: ";
            cin>>arr[0];
            max = arr[0];
            min = arr[0];
            count = 0;
            for(int i=1; i<n; i++)
            {
                cin>>arr[i];

                if(arr[i]>max)
                    max = arr[i];
                count++;

                if(arr[i]<min)
                    min = arr[i];
                count++;
            }
        }
};

void findnum::func()
{
    for(int i=0;i<n;i++)
    {
        if(arr[i] != max && arr[i] != min)
        {
            count += 2;
            cout<<"Number that is neither min nor max: "<<arr[i]<<"\n";
            break;
        }
        else    
            count++;
    }
    cout<<"Number of comparisons: "<<count;
}

int main()
{
    findnum obj1;
    obj1.func();
}