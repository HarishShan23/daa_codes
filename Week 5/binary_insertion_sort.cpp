//C++ program to implement Binary Insertion Sort

#include <iostream>

using namespace std;

class BinaryInsertionSort
{
public:
    int *arr;
    int num;
    void InsertionSort(int arr[], int n)
    {
        for (int i = 1; i < n; i++)
        {
            int key = arr[i];
            int loc = binarySearch(arr, 0, i - 1, key);

            for (int j = i - 1; j >= loc; j--)
                arr[j + 1] = arr[j];

            arr[loc] = key;
        }
    }

    int binarySearch(int arr[], int left, int right, int x)
    {
        if (right <= left)
            return (x > arr[left]) ? (left + 1) : left;

        if (right >= left)
        {
            int mid = (left + right) / 2;

            if (arr[mid] == x)
                return mid;

            if (arr[mid] > x)
                return binarySearch(arr, left, mid - 1, x);

            else
                return binarySearch(arr, mid + 1, right, x);
        }

        return -1;
    }

    void display()
    {
        cout<<"Sorted array: ";
        for (int i = 0; i < num; i++)
        printf("%d ", arr[i]);
    }

    void start()
    {
        cout<<"Enter number of elements: ";
        cin>>num;
        arr = new int[num];

        cout<<"Enter the elements: ";
        for (int i = 0; i < num; i++)
            cin>>arr[i];

        InsertionSort(arr, num);
    }

};

int main()
{
    BinaryInsertionSort obj1;
    obj1.start();
    obj1.display();
    return 0;
}