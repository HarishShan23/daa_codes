//C++ Program to find position of 1st -1
#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <algorithm>
#include <sstream>

using namespace std;

void method1(vector<int> vect)
{
    int num = -1, index;
    auto it = find(vect.begin(), vect.end(), num);
    if (it == vect.end()) 
    {
        cout << "\nMethod 1: -1 not present in the array";
    }
    else 
    {
        index = it - vect.begin();
        cout << "\nMethod 1: First -1 encountered at position: " << index;
    }
}

void method2(string &str, int flag)
{
    //cout<<"\n"<<str<<"\n";
    int length = str.length();
    int space_counter = 0;
    string str2 = "-1";
    char current;

    for(int i=0; i<length; i++)
    {
        current = str.at(i);
        if(current == ' ')
            space_counter++;
    }

    if(flag == 1)
        cout << "\nMethod 2: First -1 encountered at position: " << space_counter;
    else
        cout << "\nMethod 2: -1 is not present in the array";
}

void method3(int count, int flag)
{
    if(flag == 1)
        cout << "\nMethod 3: First -1 encountered at position: " << count;
    else
        cout << "\nMethod 3: -1 is not present in the array\n";
}

int main()
{
    int num, count = 0, flag = 0;
    vector<int> vect;
    string user_input;
    ostringstream ss;
    struct timespec start, current;
    clock_gettime(CLOCK_MONOTONIC, &start);
    clock_gettime(CLOCK_MONOTONIC, &current);
    //Get inputs for 10 seconds
    while(current.tv_sec - start.tv_sec <= 10)
    {
        cout<<"Please enter the input(except -1): ";
        cin>>num;
        if(num != -1)
        {
            count++;
            vect.push_back(num);
            ss << num;
            string temp = ss.str();
            user_input.append(temp);
            user_input.append(" ");
            ss.str("");
            ss.clear();
        }    
        else
            cout<<"-1 is invalid for first 10 seconds\n";  
        
        clock_gettime(CLOCK_MONOTONIC, &current);
    }

    cout<<"Can enter only -1. Else program will terminate\n";
    num = -1;
    while(num == -1)
    {
        cin>> num;
        if(num == -1)
        {
            flag = 1;
            vect.push_back(num);
            ss << num;
            string temp = ss.str();
            user_input.append(temp);
            ss.str("");
            ss.clear();
        }    
    }
    cout << "Program terminated";
    clock_gettime(CLOCK_MONOTONIC, &start);
    method1(vect);
    clock_gettime(CLOCK_MONOTONIC, &current);
    double time_taken; 
    time_taken = (current.tv_sec - start.tv_sec) * 1e9; 
    time_taken = (time_taken + (current.tv_nsec - start.tv_nsec)) * 1e-9; 
    time_taken = time_taken * 1000;
    cout << "\nTime taken for method 1 : " << time_taken << " microseconds"; 
    
    clock_gettime(CLOCK_MONOTONIC, &start);
    method2(user_input, flag);
    clock_gettime(CLOCK_MONOTONIC, &current);
    double time_taken2; 
    time_taken2 = (current.tv_sec - start.tv_sec) * 1e9; 
    time_taken2 = (time_taken + (current.tv_nsec - start.tv_nsec)) * 1e-9; 
    time_taken2 = time_taken2 * 1000;
    cout << "\nTime taken for method 2 : " << time_taken2 << " microseconds";

    clock_gettime(CLOCK_MONOTONIC, &start);
    method3(count, flag);
    clock_gettime(CLOCK_MONOTONIC, &current);
    double time_taken3; 
    time_taken3 = (current.tv_sec - start.tv_sec) * 1e9; 
    time_taken3 = (time_taken + (current.tv_nsec - start.tv_nsec)) * 1e-9; 
    time_taken3 = time_taken3 * 1000;
    cout << "\nTime taken for method 3 : " << time_taken3 << " microseconds";
}