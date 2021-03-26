#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;


class Subsets 
{
    int no, temp, sum, flag = 0;
    vector<int> set;
    vector<vector<int>> subset;

    public:
    Subsets()
    {
        cout<<"\nEnter the number of elements: ";
        cin>>no;
        cout<<"\nEnter the elements(Duplicates will be excluded): ";
        for(int i=0; i<no; i++)
        {
            cin>>temp;
            set.push_back(temp);
        }
        cout<<"\nEnter the sum: ";
        cin>>sum;

        convertToSet();
        find_subsets();
    }

    void convertToSet()
    {
        std::set<int> newset(set.begin(), set.end());
        set.clear();
        std::copy(newset.begin(),newset.end(), std::back_inserter(set));
    }

    void display()
    {
        int count = 0;
        cout<<"\nSubsets: \n";
        for (int i = 0; i < subset.size(); i++)
        {   
            count = 0;
            for (int j = 0; j < subset[i].size(); j++)
                count += subset[i][j];
            if(count == sum)
            {
                flag = 1;
                cout<<"[ ";
                for (int j = 0; j < subset[i].size(); j++)
                    cout<<subset[i][j]<<" ";
                cout<<"]";            
                cout<<"\n";
            } 
        }
        if(flag == 0)
            {
                cout<<"\nNo subsets with matching sum found";
            }
    }

    void find_subsets()
    {
        vector<int> empty;
        subset.push_back(empty);

        for (int i=0; i<set.size(); i++)
        {
            vector<vector<int>> subsetTemp = subset; //Copy of original 2d vector

            for (int j=0; j<subsetTemp.size(); j++)
                subsetTemp[j].push_back(set[i]);  //Add set[i] to each element of subsetTemp
            for (int j=0; j<subsetTemp.size(); j++)
                subset.push_back(subsetTemp[j]);  //Add modified subsetTemp to original 2d vector
        }
        display(); 
    }
}; 

int main()
{
    Subsets obj;
    return 0;
}