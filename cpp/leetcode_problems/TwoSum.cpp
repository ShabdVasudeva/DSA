#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> bruteForce(vector<int>& arr, int target) {
    for(int i=0; i<arr.size(); i++) {
        for(int j=i+1; j<arr.size(); j++) {
            int sum = arr[i] + arr[j];
            if (sum == target) return {i, j};
        }
    }
    return {-1, -1};
}

vector<int> betterApproach(vector<int>& arr, int target) {
    vector<pair<int, int>> nums;
    for(int i=0; i<arr.size(); i++) {
        nums.push_back({arr[i], i});
    }
    sort(nums.begin(), nums.end());
    int st = 0, end = arr.size()-1;
    while (st < end) {
        int sum = nums[st].first + nums[end].first;
        if(sum == target) {
            return {nums[st].second, nums[end].second};
        } else if (sum < target) {
            st++;
        } else {
            end--;
        }
    }
    return {-1, -1};
}

vector<int> hashing(vector<int>& arr, int target) {
    unordered_map<int, int> map;
    for(int i=0; i<arr.size(); i++) {
        int first = arr[i];
        int second = target - first;
        if(map.find(second) != map.end()) {
            return {i, map[second]};
        }
        map[first] = i;
    }
    return {-1, -1};
}

void traversal(vector<int>& arr) {
    for(int i=0; i<arr.size(); i++) {
        if(i == arr.size()-1) {
            cout << arr[i] << "\n";
        } else {
            cout << arr[i] << ", ";
        }
    }
}

int main(){
    vector<int> arr = {2,7,11,15};
    int target = 9;
    vector<int> bF = bruteForce(arr, target);
    vector<int> bA = betterApproach(arr, target);
    vector<int> H = hashing(arr, target); // bestest
    cout << "BruteForce: "; traversal(bF);
    cout << "BetterApproach: "; traversal(bA);
    cout << "Hashing: "; traversal(H);
    return 0;
}