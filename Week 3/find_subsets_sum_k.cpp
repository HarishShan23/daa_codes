#include <iostream>
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
        cout<<"Enter the number of elements: ";
        cin>>no;
        cout<<"\nEnter the elements: ";
        for(int i=0; i<no; i++)
        {
            cin>>temp;
            set.push_back(temp);
        }
        cout<<"\nEnter the sum: ";
        cin>>sum;

        find_subsets();
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
    }

    void find_subsets()
    {
        vector<int> empty;
        subset.push_back(empty);

        for (int i=0; i<set.size(); i++)
        {
            vector<vector<int>> subsetTemp = subset;  //making a copy of given 2-d vector.

            for (int j=0; j<subsetTemp.size(); j++)
                subsetTemp[j].push_back( set[i] );   // adding set[i] element to each subset of subsetTemp. like adding {2}(in 2nd iteration  to {{},{1}} which gives {{2},{1,2}}.

            for (int j=0; j<subsetTemp.size(); j++)
                subset.push_back( subsetTemp[j] );  //now adding modified subsetTemp to original subset (before{{},{1}} , after{{},{1},{2},{1,2}}) 
        }
        
        display(); 
    }
}; 

int main()
{
    Subsets obj;
    
    return 0;
}