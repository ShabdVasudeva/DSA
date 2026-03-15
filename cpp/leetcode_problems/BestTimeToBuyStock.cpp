#include <iostream>
#include <vector>

using namespace std;

// Time Complexity: O(n), Space Complexity: O(1)
int maxProfit(vector<int> prices) {
    int maxProfit = 0;
    int bestBuy = prices[0];
    for(int i=1; i<prices.size(); i++) {
        int profit = prices[i] - bestBuy;
        maxProfit = max(maxProfit, profit);
        bestBuy = min(bestBuy, prices[i]);
    }
    return maxProfit;
}

int main() {
    vector<int> prices = {7,1,5,3,6,4};
    cout << "Maximum Profit: " << maxProfit(prices) << "\n";
    return 0;
}

//OutPut:
/*
     *  Executing task: bash -c ./build/Debug/outDebug 
    
    Maximum Profit: 5
     *  Terminal will be reused by tasks, press any key to close it.
*/