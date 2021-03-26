// C++ program to merge two sorted arrays

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class mergearray
{
    public:
    vector<int> nums1, nums2;
    // O(m+n)
    void merge1(vector<int> nums1, int m, vector<int> nums2, int n)
    {
        vector<int> nums3;
        int i = 0, j = 0;
        while (i < m && j < n)
        {
            if (nums1[i] < nums2[j])
                nums3.push_back(nums1[i++]);

            else
                nums3.push_back(nums2[j++]);
        }

        while (i < m)
            nums3.push_back(nums1[i++]);

        while (j < n)
            nums3.push_back(nums2[j++]);

        for(int i=0; i<nums3.size(); i++)
            cout<<nums3[i]<<" ";
    }

    void merge2(vector<int> nums1, int m, vector<int> nums2, int n)
    {
        vector<int> nums3;
        for (int i = 0; i < m; i++)
            nums3.push_back(nums1[i]);

        if (nums2[0] < nums3[0])
        {
            nums3.insert(nums3.begin(), nums2[0]);
            m++;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (nums3[j] < nums2[i] && nums3[j + 1] >= nums2[i])
                {
                    int temp = nums2[i];
                    nums3.insert(nums3.begin() + j + 1, temp);
                    m++;
                    break;
                }
            }
        }

        for (int i = 0; i < nums3.size(); i++)
            cout << nums3[i] << " ";
    }

    void merge3(vector<int> nums1, int m, vector<int> nums2, int n)
    {
        int i = 0, j = 0, k = m - 1;

        while (i <= k && j < m)
        {
            if (nums1[i] <= nums2[j])
                i++;
            else
                swap(nums2[j++], nums1[k--]);
        }

        // Sort first array
        sort(nums1.begin(), nums1.end());

        // Sort second array
        sort(nums2.begin(), nums2.end());

        for (int i = 0; i < nums1.size(); i++)
            cout << nums1[i] << " ";

        for (int i = 0; i < nums2.size(); i++)
            cout << nums2[i] << " ";
    }

    void start()
    {
        nums1 = {10, 30, 50, 60, 70};
        int m = nums1.size();

        nums2 = {5, 20, 30, 40, 65, 80, 90, 120};
        int n = nums2.size();
    }
};

int main()
{
    mergearray obj1;
    obj1.start();
    int m = obj1.nums1.size();
    int n = obj1.nums2.size();
    cout<<"Method 1: ";
    obj1.merge1(obj1.nums1, m, obj1.nums2, n);

    cout<<"\nMethod 2: ";
    obj1.merge2(obj1.nums1, m, obj1.nums2, n);

    cout<<"\nMethod 3: ";
    obj1.merge3(obj1.nums1, m, obj1.nums2, n);

    return 0;
}