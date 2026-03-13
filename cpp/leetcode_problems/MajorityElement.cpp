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
    int num = arr[0]; 
    int freq = 0;
    for(int i=0; i<arr.size(); i++) {
        if(num == arr[i]){
            freq++;
        } else {
            freq--;
            if(freq == 0){
                num = arr[i]; freq++;
            }
        }
    }
    int count = 0;
    for(int i=0; i<arr.size(); i++) {
        if(num == arr[i]) {
            count++;
            if(count > arr.size()/2) return num;
        }
    }
    return -1;
}

int main(){
    vector<int> arr = {6,5,5};
    cout << "BruteForce: " << bruteForce(arr) << "\n";
    cout << "BetterApproach: " << betterApproach(arr) << "\n";
    cout << "BoyerMooreAlgorithm: " << boyerMooreAlgorithm(arr) << "\n"; // bestest
    return 0;
}

// OUTPUT:
/*
     *  Executing task: bash -c ./build/Debug/outDebug 

    BruteForce: 1
    BetterApproach: 1
    BoyerMooreAlgorithm: 1
     *  Terminal will be reused by tasks, press any key to close it. 
*/