// Program to find minimum and second minimum in max heap

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class yudodis
{
public:
    vector<int> nums;
    int num;
    void find_min()
    {
        int first = INT_MAX, second = INT_MAX;

        for (int i = nums.size() / 2; i < nums.size(); i++)
        {
            if (nums[i] < first)
            {
                second = first;
                first = nums[i];
            }

            else if (nums[i] < second && nums[i] != first)
                second = nums[i];
        }

        if (second == INT_MAX)
            cout << "There is no second smallest element\n";

        else
        {
            cout << "Smallest element is: " << first;
            cout << "\nSecond Smallest element is: " << second;
        }
    }

    yudodis()
    {
        int temp;
        cout << "Enter the number of elements: ";
        cin >> num;

        cout << "Enter the elements: \n";
        for (int i = 0; i < num; i++)
        {
            cin >> temp;
            nums.push_back(temp);
        }
        make_heap(nums.begin(), nums.end());
        find_min();
    }
};

int main()
{
    yudodis weded;
    return 0;
}