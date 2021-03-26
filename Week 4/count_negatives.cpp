#include<iostream>
using namespace std;

class findneg_2 
{
    public:
    int neg_2(int arr[], int left, int right)
    {
        if(left > right)
            return 0;

        if(left == right)
        {
            if(arr[left] < 0)
                return 1;
            else
                return 0;
        }
        
        int mid = (left+right)/2;

        int count1 = neg_2(arr, left, mid);
        int count2 = neg_2(arr, mid+1,right);
    
        return count1+count2;
    }
};

class findneg_3
{
    public:
    int neg_3(int arr[], int left, int right)
    {
        if(left > right)
            return 0;
        
        if(left == right)
        {
            if(arr[left] < 0)
                return 1;
            else
                return 0;
        }

        int mid1 = left+(right-left)/3;
        int mid2 = right-(right-left)/3;

        int count1 = neg_3(arr, left, mid1-1);
        int count2 = neg_3(arr, mid1, mid2-1);
        int count3 = neg_3(arr, mid2, right);
    
        return count1+count2+count3;
    }
};

class findneg : public findneg_2,public findneg_3
{
    public:
    int* arr;
    int num;
    int result;
    void start()
    {
        cout<<"Enter number of elements: ";
        cin>>num;
        arr = new int[num];
        cout<<"Enter the elements: ";
        for(int i=0;i<num;i++)
            cin>>arr[i];
    }
};

int main()
{
    findneg obj;
    obj.start();
    cout<<"2-Way method: "<<obj.neg_2(obj.arr,0,obj.num-1)<<'\n';
    cout<<"3-Way method: "<<obj.neg_3(obj.arr,0,obj.num-1)<<'\n';
    return 0;
}