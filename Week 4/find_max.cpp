#include <iostream>

using namespace std;

class max_1
{
public:
    int findmax_1(int arr[], int n)
    {
        int max = arr[0];
        for (int i = 1; i <= n; i++)
            if (arr[i] > max)
                max = arr[i];

        return max;
    }
};

class max_2
{
public:
    int findmax_2(int arr[], int left, int right)
    {
        if (left == right)
            return arr[left];

        int mid = (left + right) / 2;

        int max1 = findmax_2(arr, left, mid);
        int max2 = findmax_2(arr, mid + 1, right);

        return max1 > max2 ? max1 : max2;
    }
};

class max_3
{
public:
    int findmax_3(int arr[], int left, int right)
    {

        if (right - left == 1)
            return arr[left];

        if (right - left == 2)
            return max(arr[left], arr[left + 1]);

        if (right - left == 3)
        {
            int max1 = arr[left];
            int max2 = arr[left + 1];
            int max3 = arr[left + 2];

            return max(max1, max(max2, max3));
        }

        int diff = (right - left) / 3;
        int mid1 = left + diff;
        int mid2 = right - diff;

        int max1 = findmax_3(arr, left, mid1);
        int max2 = findmax_3(arr, mid1, mid2);
        int max3 = findmax_3(arr, mid2, right);

        return max(max1, max(max2, max3));
    }
};

class max_k
{
public:
    int findmax_k(int arr[], int left, int right, int k)
    {

        if (left == right)
            return arr[left];

        if (left > right)
            return INT_MIN;

        int mid[k];
        int chunk_size = (right - left + 1) / k;
        if (chunk_size == 0)
            chunk_size = 1;

        mid[0] = left + chunk_size - 1;
        for (int i = 1; i < k; i++)
        {
            if (i > (right - left))
                mid[i] = mid[0];
            else
                mid[i] = mid[i - 1] + chunk_size;
        }

        int max1 = findmax_k(arr, left, mid[0], k);
        int res = max1;

        for (int i = 0; i < k - 1; i++)
        {
            int max2 = findmax_k(arr, mid[i] + 1, mid[i + 1], k);
            res = max(res, max2);
        }

        int max3 = findmax_k(arr, mid[k - 2] + 1, right, k);

        return max(res, max3);
    }
};

class find_max : public max_1, public max_2, public max_3, public max_k
{
public:
    int *arr;
    int num;
    int key, res, k;
    void start()
    {
        cout << "Enter number of elements: ";
        cin >> num;
        arr = new int[num];
        cout << "Enter the elements: ";
        for (int i = 0; i < num; i++)
            cin >> arr[i];
        cout << "Enter the value of k: ";
        cin >> k;
    }
};

int main()
{
    find_max obj;
    obj.start();
    cout << "1-way Method: " << obj.findmax_1(obj.arr, obj.num - 1) << "\n";
    cout << "2-way Method: " << obj.findmax_2(obj.arr, 0, obj.num - 1) << "\n";
    cout << "3-way Method: " << obj.findmax_3(obj.arr, 0, obj.num) << "\n";
    cout << "k-way Method: " << obj.findmax_k(obj.arr, 0, obj.num-1,obj.k) << "\n";
}