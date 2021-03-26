#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <chrono>
#define THRESHOLD 20

using namespace std;
using namespace std::chrono;

class allSorts
{
public:
    void insertion_sort(int arr[], int left, int right)
    {
        int i, j, key;

        for (j = left + 1; j <= right; j++)
        {
            key = arr[j];
            i = j - 1;

            while (i >= left && arr[i] > key)
            {
                arr[i + 1] = arr[i];
                i = i - 1;
            }
            arr[i + 1] = key;
        }
    }

    void selection_sort(int arr[], int left, int right)
    {
        int min_idx;
        for (int i = left; i < right - 1; i++)
        {
            min_idx = i;

            for (int j = i + 1; j < right; j++)
                if (arr[j] < arr[min_idx])
                    min_idx = j;

            swap(arr[min_idx], arr[i]);
        }
    }

    void bubble_sort(int arr[], int left, int right)
    {
        for (int i = left; i < right; i++)
        {
            for (int j = left; j < right - i + left; j++)
                if (arr[j] > arr[j + 1])
                    swap(arr[j], arr[j + 1]);
        }
    }
};

class merge_methods : public allSorts
{
public:
    int *arr;
    int size;

    void merge(int arr[], int left, int mid1, int mid2, int right)
    {
        int n1 = mid1 - left;
        int n2 = mid2 - mid1;
        int n3 = right - mid2;
        int i = 0, j = 0, l = 0, k = 0;
        int L[n1];
        int M[n2];
        int R[n3];

        memcpy(L, arr + left, n1 * sizeof(int));
        memcpy(M, arr + mid1, n2 * sizeof(int));
        memcpy(R, arr + mid2, n3 * sizeof(int));

        while((i < n1) && (j < n2) && (k < n3))
        {
            if(L[i] < M[j])
            {
                if(L[i] < R[k])
                    arr[l++] = L[i++];
                
                else
                    arr[l++] = R[k++];
            }

            else
            {
                if(M[j] < R[k])
                    arr[l++] = M[j++];
                
                else
                    arr[l++] = R[k++];
            }
        }
        
        while((i < n1) && (j < n2))
        {
            if(L[i] < M[j])
                arr[l++] = L[i++];

            else
                arr[l++] = M[j++];
        }

        while((j < n2) && (k < n3))
        {
            if(M[j] < R[k])
                arr[l++] = M[j++];

            else
                arr[l++] = R[k++];
        }

        while((i < n1) && (k < n3))
        {
            if(L[i] < R[k])
                arr[l++] = L[i++];

            else
                arr[l++] = R[k++];
        }

        while(i < n1)
            arr[l++] = L[i++];

        while(j < n2)
            arr[l++] = M[j++];

        while(j < n3)
            arr[l++] = R[k++];

    }

    void merge_insertionsort(int arr[], int left, int right)
    {
        if (right - left == 1)
            return;

        if (right - left + 1 < THRESHOLD)
            insertion_sort(arr, left, right);

        else
        {
            int mid1 = left + (right - left) / 3;
            int mid2 = right - (right - left) / 3;
            merge_insertionsort(arr, left, mid1);
            merge_insertionsort(arr, mid1, mid2);
            merge_insertionsort(arr, mid2, right);
            merge(arr, left, mid1, mid2, right);
        }
    }

    void merge_selectionsort(int arr[], int left, int right)
    {
        if (left >= right)
            return;

        if (right - left < THRESHOLD)
            selection_sort(arr, left, right);

        else
        {
            int mid1 = left + (right - left) / 3;
            int mid2 = right - (right - left) / 3;
            merge_selectionsort(arr, left, mid1);
            merge_selectionsort(arr, mid1, mid2);
            merge_selectionsort(arr, mid2, right);
            merge(arr, left, mid1, mid2, right);
        }
    }

    void merge_bubblesort(int arr[], int left, int right)
    {
        if (left >= right)
            return;

        if (right - left + 1 < THRESHOLD)
            bubble_sort(arr, left, right);

        else
        {
            int mid1 = left + (right - left) / 3;
            int mid2 = right - (right - left) / 3;
            merge_bubblesort(arr, left, mid1);
            merge_bubblesort(arr, mid1, mid2);
            merge_bubblesort(arr, mid2, right);
            merge(arr, left, mid1, mid2, right);
        }
    }

    void display()
    {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    void start()
    {
        size = 1000;
        arr = new int[size];

        srand(time(NULL));
        for (int i = 0; i < size; i++)
        {
            arr[i] = rand()%100;
        }
    }
};

int main()
{
    merge_methods obj1, obj2, obj3;
    obj1.start();
    auto start = high_resolution_clock::now();
    obj1.merge_bubblesort(obj1.arr, 0, obj1.size - 1);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << "Sorted array using bubble sort: " << duration.count() << endl;
    //obj1.display();

    obj2.start();
    auto start2 = high_resolution_clock::now();
    obj2.merge_insertionsort(obj2.arr, 0, obj2.size - 1);
    auto end2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(end2 - start2);
    cout << "Sorted array using insertion sort: " << duration2.count() << endl;
    //obj2.display();

    obj3.start();
    auto start3 = high_resolution_clock::now();
    obj3.merge_selectionsort(obj3.arr, 0, obj3.size);
    auto end3 = high_resolution_clock::now();
    auto duration3 = duration_cast<microseconds>(end3 - start3);
    cout << "Sorted array using selection sort: " << duration3.count() << endl;
    //obj3.display();

    return 0;
}