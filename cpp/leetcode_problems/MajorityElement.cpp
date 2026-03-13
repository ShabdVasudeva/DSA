#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// TimeComplexity: O(n²), SpaceComplexity: O(1)
int bruteForce(vector<int>& arr) {
    int f = 0;
    for(int i=0; i<arr.size(); i++) {
        for(int j=0; j<arr.size(); j++) {
            if(arr[i]==arr[j]) f++;
        }
        if(f > arr.size()/2) return arr[i];
    }
    return -1;
}

// TimeComplexity: O(n), SpaceComplexity: O(n)
int betterApproach(vector<int>& arr) {
    unordered_map<int, int> map;
    for(int i=0; i<arr.size(); i++) {
        map[arr[i]]++;
        if(map[arr[i]] > arr.size()/2) return arr[i];
    }
    return -1;
}

// TimeComplexity: O(n), SpaceComplexity: O(1)
int boyerMooreAlgorithm(vector<int>& arr) {

}

int main(){
    vector<int> arr = {1,2,3,1,1};
    cout << "BruteForce: " << bruteForce(arr) << "\n";
    cout << "BetterApproach: " << betterApproach(arr) << "\n";
    cout << "BoyerMooreAlgorithm: " << boyerMooreAlgorithm(arr) << "\n";
    return 0;
}