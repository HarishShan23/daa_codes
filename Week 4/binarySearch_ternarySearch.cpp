#include <iostream>
#include <algorithm>
using namespace std; 

class binarySearch
{
    public:
    int binarySearch_recursive(int arr[], int left, int right, int x) 
    { 
        if (right >= left) 
        { 
            int mid = (left+right)/2; 
            if (arr[mid] == x) 
                return mid; 

            if (arr[mid] > x) 
                return binarySearch_recursive(arr, left, mid - 1, x); 

            else
                return binarySearch_recursive(arr, mid + 1, right, x); 
        } 

        return -1; 
    } 

    int binarySearch_iterative(int arr[], int left, int right, int x) 
    { 
        while (left <= right) 
        { 
            int mid = (left+right)/2; 
    
            if (arr[mid] == x) 
                return mid; 
    
            if (arr[mid] < x) 
                left = mid + 1; 
    
            else
                right = mid - 1; 
        } 
    
        return -1; 
    }
}; 

class ternarySearch
{
    public:
    int ternarySearch_recursive(int arr[], int left, int right, int x)
    {
        if (right >= left) 
        {
            int mid1 = left+(right-left)/3;
            int mid2 = right-(right-left)/3;
    
            if (arr[mid1] == x) 
                return mid1;
            if (arr[mid2] == x) 
                return mid2;

            if (x < arr[mid1]) 
                return ternarySearch_recursive(arr, left, mid1 - 1, x);
            
            else if (x > arr[mid2]) 
                return ternarySearch_recursive(arr, mid2 + 1, right, x);
            
            else 
                return ternarySearch_recursive(arr, mid1 + 1, mid2 - 1, x);
        }
    
        return -1;
    }

    int ternarySearch_iterative(int arr[], int left, int right, int x)
    {
        while (right >= left) 
        {
            int mid1 = left+(right-left)/3;
            int mid2 = right-(right-left)/3;
    
            if (arr[mid1] == x) 
                return mid1;

            if (arr[mid2] == x) 
                return mid2;
    
            if (x < arr[mid1]) 
                right = mid1 - 1;

            else if (x > arr[mid2]) 
                left = mid2 + 1;

            else 
            {
                left = mid1 + 1;
                right = mid2 - 1;
            }
        }

        return -1;
    }
};

class Search : public binarySearch,public ternarySearch
{
    public:
    int* arr;
    int num;
    int key,res;
    void start()
    {
        cout<<"Enter number of elements: ";
        cin>>num;
        arr = new int[num];
        cout<<"Enter the elements: ";
        for(int i=0;i<num;i++)
            cin>>arr[i];
        sort(arr,arr + num);
        cout<<"Enter element to search: ";
        cin>>key;

        cout<<"binarySearch_iterative: ";
        res = binarySearch_iterative(arr,0,num-1,key);
        if(res == -1)
            cout <<"Element not found!!!\n";
        else
            cout<<"Element found at index "<<res<<'\n';

        cout<<"binarySearch_recursive: ";
        res = binarySearch_recursive(arr,0,num-1,key);
        if(res == -1)
            cout <<"Element not found!!!\n";
        else
            cout<<"Element found at index "<<res<<'\n';

        cout<<"ternarySearch_iterative: ";
        res = ternarySearch_iterative(arr,0,num-1,key);
        if(res == -1)
            cout <<"Element not found!!!\n";
        else
            cout<<"Element found at index "<<res<<'\n';

        cout<<"ternarySearch_recursive: ";
        res = ternarySearch_recursive(arr,0,num-1,key);
        if(res == -1)
            cout <<"Element not found!!!\n";
        else
            cout<<"Element found at index "<<res<<'\n';
    }
};

int main() 
{
    Search obj;
    obj.start();
    return 0;
} 
