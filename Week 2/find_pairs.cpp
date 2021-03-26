//Program to find pairs such that sum is equal to the given number
#include <iostream>
#include <bits/stdc++.h>
#include <sys/time.h> 
#include <fstream>

using namespace std;

// Two-pointer method
bool method1(int arr[], int size,int sum)
{
    int front, rear;
    sort(arr, arr + size);

    front = 0;
    rear = size - 1;
    while (front < rear) 
    {
        if (arr[front] + arr[rear] == sum)
            return 1;
        else if (arr[front] + arr[rear] < sum)
            front++;
        else
            rear--;
    }
    return 0;
}
 
// Hashing method
int method2(int arr[], int size, int sum)
{
    unordered_set<int> hash;
    int flag = 0;
    for (int i = 0; i < size; i++) 
    {
        int temp = sum - arr[i];
        if (hash.find(temp) != hash.end())
        {
            return 1;
        }   
        hash.insert(arr[i]);
    }
    return -1;
}

//Brute force method
int method3(int arr[], int n, int x)
{
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(arr[i] + arr[j] == x)    
                return 1;
        }
    }
    return -1; 
}

void generator()
{
    int sum, count = 50, size = 1000;
    struct timespec start, end;
    double time_taken, time_taken2, time_taken3; 
    int* randArray = new int[size];
    for(int i=0;i<size;i++)
    {
        randArray[i]=rand();
    }   
    std::ofstream myfile;
    myfile.open("Data.csv");
    myfile << "All data recorded in microseconds\n";
    myfile << "Method 1,Method 2,Method 3,Sum,\n";
    while(count)
    {
        sum = rand();

        //Method 1
        clock_gettime(CLOCK_MONOTONIC, &start); 
        method1(randArray, 1000, sum);
        clock_gettime(CLOCK_MONOTONIC, &end); 
        time_taken = (end.tv_sec - start.tv_sec) * 1e9; 
        time_taken = (time_taken + (end.tv_nsec - start.tv_nsec)) * 1e-9; 
        time_taken = time_taken * 1000;

        //Method 2
        clock_gettime(CLOCK_MONOTONIC, &start); 
        method2(randArray, 1000, sum);
        clock_gettime(CLOCK_MONOTONIC, &end); 
        time_taken2 = (end.tv_sec - start.tv_sec) * 1e9; 
        time_taken2 = (time_taken2 + (end.tv_nsec - start.tv_nsec)) * 1e-9; 
        time_taken2 = time_taken2 * 1000;

        //Method 3
        clock_gettime(CLOCK_MONOTONIC, &start);
        method3(randArray, 1000, sum);
        clock_gettime(CLOCK_MONOTONIC, &end); 
        time_taken3 = (end.tv_sec - start.tv_sec) * 1e9; 
        time_taken3 = (time_taken3 + (end.tv_nsec - start.tv_nsec)) * 1e-9; 
        time_taken3 = time_taken3 * 1000;

        myfile << time_taken << "," << time_taken2 << "," << time_taken3 << "," << sum <<"\n";
        count--;
    }
    myfile.close();
}


int main()
{
    int num, sum;
    cout<<"\nEnter the size of the array: ";
    cin>>num;
    int* arr = new int[num];
    cout<<"Enter the elements: ";
    for(int i=0; i<num; i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter sum to find: ";
    cin>>sum;
    
    //Method 1
    struct timespec start, end; 
    clock_gettime(CLOCK_MONOTONIC, &start); 
    if(method1(arr, num, sum))
        cout << "\nMethod 1: Yes";
    else
        cout << "\nMethod 1: No";
    clock_gettime(CLOCK_MONOTONIC, &end); 
    double time_taken; 
    time_taken = (end.tv_sec - start.tv_sec) * 1e9; 
    time_taken = (time_taken + (end.tv_nsec - start.tv_nsec)) * 1e-9; 
    time_taken = time_taken * 1000;
    cout << "\nTime taken for method 1 : " << time_taken << " microseconds"; 

    //Method 2 
    clock_gettime(CLOCK_MONOTONIC, &start); 
    if(method2(arr, num, sum) == 1)
        cout << "\nMethod 2: Yes";
    else
        cout << "\nMethod 2: No";
    clock_gettime(CLOCK_MONOTONIC, &end); 
    double time_taken2; 
    time_taken2 = (end.tv_sec - start.tv_sec) * 1e9; 
    time_taken2 = (time_taken2 + (end.tv_nsec - start.tv_nsec)) * 1e-9; 
    time_taken2 = time_taken2 * 1000;
    cout << "\nTime taken for method 2 : " << time_taken2 << " microseconds";

    //Method 3
    clock_gettime(CLOCK_MONOTONIC, &start);
    if(method3(arr, num, sum) == 1)
        cout << "\nMethod 3: Yes";
    else
        cout << "\nMethod 3: No";
    clock_gettime(CLOCK_MONOTONIC, &end); 
    double time_taken3; 
    time_taken3 = (end.tv_sec - start.tv_sec) * 1e9; 
    time_taken3 = (time_taken3 + (end.tv_nsec - start.tv_nsec)) * 1e-9;
    time_taken3 = time_taken3 * 1000; 
    cout << "\nTime taken for method 3 : " << time_taken3 << " microseconds";

    //Data generator
    generator();

}
    
