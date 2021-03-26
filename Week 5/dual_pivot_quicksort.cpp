#include <iostream>

using namespace std;

class quicksort
{
    public:
    int *a;
    int num;
    void sort(int *a, int lo, int hi)
    {
        if (hi <= lo)
            return;

        // Make sure a[lo] <= a[hi]
        if (a[hi] < a[lo])
            swap(a[hi], a[lo]);

        //
        int lt = lo + 1, gt = hi - 1;
        int i = lo + 1;

        while (i <= gt)
        {
            if (a[i] < a[lo])
            {
                swap(a[lt], a[i]);
                lt++;
                i++;
            }

            else if (a[hi] < a[i])
            {
                swap(a[i], a[gt]);
                gt--;
            }

            else
                i++;
        }
        lt--;
        swap(a[lo], a[lt]);

        gt++;
        swap(a[hi], a[gt]);

        // recursively sort three subarrays
        sort(a, lo, lt - 1);

        if (a[lt] < a[gt])
            sort(a, lt + 1, gt - 1);

        sort(a, gt + 1, hi);
    }

    void display()
    {
        for (int i = 0; i < num; i++)
            cout << a[i] << " ";
    }

    void start()
    {
        cout<<"Enter number of elements: ";
        cin>>num;
        cout<<"Enter the elements: ";
        for(int i=0; i<num; i++)
            cin>>a[i];

        sort(a, 0, num-1);
    }
};

int main()
{
    quicksort obj1;
    obj1.start();
    cout<<"Sorted array: ";
    obj1.display();

    return 0;
}