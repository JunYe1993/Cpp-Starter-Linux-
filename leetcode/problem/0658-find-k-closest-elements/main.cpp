#include<iostream>
#include<vector>
#include<cstdlib> 

using namespace std;

class Solution {
    int getClosestIndex (vector<int>& arr, int x) {
        int min = 0, max = arr.size()-1;
        while (min+1 < max) {
            int mid = (min + max) / 2;
            cout << mid << endl;
            if (arr[mid] == x)
                return mid;
            else {
                if (arr[mid] > x) max = mid;
                else min = mid;
            }    
        }
        return min;
    }
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int start = getClosestIndex(arr, x);
        
        return {getClosestIndex(arr, x)};
    }
};

int main () {
    Solution sol;
    vector<int> arr;
    int k, x;

    k = 4; x = 301;
    arr = {1,2,300,400,410};
    for (auto&n:sol.findClosestElements(arr, k, x))
        cout << n << " ";
    cout << endl;

    return 0;
}