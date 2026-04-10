#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> result;

void permutation(vector<int>& arr, int i)
{
    if (i == arr.size())
    {
        result.push_back(arr); return;
    }
    for (int idx=i; idx<arr.size(); idx++)
    {
        swap(arr[idx], arr[i]);
        permutation(arr, i+1);
        swap(arr[idx], arr[i]);
    }
}

vector<vector<int>> permute(vector<int>& nums)
{
    permutation(nums, 0);
    return result;
}

void print(vector<vector<int>>& arr)
{
    for(vector<int> i: arr)
    {
        cout << "[";
        for(int j=0; j<i.size(); j++)
        {
            cout << i[j];
            if (j < i.size()-1)
            {
                cout << ", ";
            }
            
        }
        cout << "]" << "\n";
    }
}

int main()
{
    vector<int> input = {1, 2, 3};
    vector<vector<int>> permutations = permute(input);

    print(permutations); // print the permutations.
    return 0;
}