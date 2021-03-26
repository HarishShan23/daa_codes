//Finding maximum element

#include<iostream>
using namespace std;

class findmax
{
    public:
        int n;
        int *arr;
        int count;
        void reset_count();
        int max1();
        int max2(int*, int, int);
        int max3(int*, int);
        findmax()
        {
            cout<<"Enter the number of elements: ";
            cin>>n;
            arr = new int[n];
            cout<<"Enter the elements: ";
            for(int i=0; i<n; i++)
                cin>>arr[i];
            count = 0;
        }
};

void findmax::reset_count()
{
    count = 0;
}

int findmax::max1()
{
    int max = arr[0];
    for(int i=1;i<n;i++)
    {
        if(arr[i]>max)
            max = arr[i];
        count++;
    }
    return max;
}

int findmax::max2(int *arr, int start, int end)
{
    int max;
    if(start == end)
    {
        max = arr[end];
        count++;
    }    
    else
    {
        int mid = start + (end - start)/2;
        int left = max2(arr,start, mid);
        int right = max2(arr,mid+1, end);
        if ( left > right )
            max = left;
        else
            max = right; 
    }
    return max;
}


int findmax::max3(int *arr, int n)
{
    count++;
    return(n == 1)? arr[0]: max(arr[0], max3(arr+1, n-1));
}

int main()
{
    findmax obj1;
    cout<<"\nMaximum element(Method 1): "<<obj1.max1()<<"\n";
    cout<<"No. of comparisons(Method 1): "<<obj1.count<<"\n";
    obj1.reset_count();
    cout<<"\nMaximum element(Method 2): "<<obj1.max2(obj1.arr, 0, obj1.n)<<"\n";
    cout<<"No. of comparisons(Method 2): "<<obj1.count<<"\n";
    obj1.reset_count();
    cout<<"\nMaximum element(Method 3): "<<obj1.max3(obj1.arr, obj1.n)<<"\n";
    cout<<"No. of comparisons(Method 3): "<<obj1.count<<"\n\n";
}