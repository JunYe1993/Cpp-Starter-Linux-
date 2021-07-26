#include<iostream>
#include<vector>
#include<queue>

using namespace std;

// class MedianFinder {
//     vector<int> nums;
//     bool is_even = true;
// public:
//     /** initialize your data structure here. */
//     MedianFinder() {}
//     
//     void addNum(int num) {
//         auto it = nums.begin();
//         if (nums.empty() || nums.back() <= num) nums.push_back(num);
//         else if (num <= nums[0]) nums.insert(it, num);   
//         else {
//             int max = nums.size()-1;
//             int min = 0;
//             while ( min < max ) {
//                 int mid = (max+min)/2;
//                 if (mid == min) break;
//                 if (num > nums[mid]) min = mid;
//                 else max = mid;
//             }
//             nums.insert(it+max, num);
//         }
//         is_even = !is_even;
//     }
//     
//     double findMedian() {
//         int size = nums.size();
//         return !is_even ? nums[size/2]:((double)nums[size/2]+(double)nums[size/2-1])/2.0;
//     }
// };

class MedianFinder {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int> maxHeap;
    bool is_even = true;
public:
    /** initialize your data structure here. */
    MedianFinder() {}
    
    void addNum(int num) {
        if (maxHeap.empty() || maxHeap.top() > num) maxHeap.push(num);
        else minHeap.push(num);
        is_even = !is_even;

        int gap = maxHeap.size()-minHeap.size();
        if (gap > 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (gap < 0) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        } 
    }
    
    double findMedian() {
        return is_even ? (minHeap.top()+maxHeap.top())/2.0 : maxHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main() {
    MedianFinder finder;
    // cout << finder.findMedian() << endl;
    // finder.addNum(-1);
    // cout << finder.findMedian() << endl;
    // finder.addNum(-2);
    // cout << finder.findMedian() << endl;
    // finder.addNum(-3);
    // cout << finder.findMedian() << endl;
    // finder.addNum(-4);
    // cout << finder.findMedian() << endl;
    finder.addNum(1);
    cout << finder.findMedian() << endl;
    finder.addNum(2);
    cout << finder.findMedian() << endl;
    finder.addNum(3);
    cout << finder.findMedian() << endl;
    finder.addNum(4);
    cout << finder.findMedian() << endl;
    finder.addNum(5);
    cout << finder.findMedian() << endl;
    finder.addNum(6);
    cout << finder.findMedian() << endl;
    finder.addNum(7);
    cout << finder.findMedian() << endl;
    finder.addNum(8);
    cout << finder.findMedian() << endl;
    finder.addNum(9);
    cout << finder.findMedian() << endl;
    finder.addNum(4);
    finder.addNum(5);
    finder.addNum(6);
    finder.addNum(7);
    finder.addNum(8);
    finder.addNum(9);
    finder.addNum(-1);
    finder.addNum(-2);
    finder.addNum(-3);
    finder.addNum(-4);
    finder.addNum(0);
    finder.addNum(-1);
    finder.addNum(3);
    return 0;
}