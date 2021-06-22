#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;

// Node segTreeNode
class segTreeNode {
public:
    int begin, end, sum;
    segTreeNode * left = NULL;
    segTreeNode * right = NULL;
    segTreeNode(int s, int e, int m):begin(s), end(e), sum(m) {}
};

class NumArray {
private:
    segTreeNode* buildSegTree(int begin, int end, vector<int>& nums) {
        // 若 begin = end，代表是 leaf。
        if (begin == end) {
            auto node = new segTreeNode(begin, begin, nums[begin]);
            return node;
        }  
        
        // 分割
        int mid = (begin + end) / 2;
        auto left  = buildSegTree(begin, mid, nums);
        auto right = buildSegTree(mid+1, end, nums);
        auto node = new segTreeNode(begin, end, left->sum + right->sum);
        node->left = left;
        node->right = right;
        return node;
    }

    void updateSegTree(segTreeNode* node, int index, int val) {
        if (node->begin == index && node->end == index) {
            node->sum = val;
            return;
        }
        
        int mid = (node->begin + node->end) / 2;
        if (index > mid)
            updateSegTree(node->right, index, val);
        else
            updateSegTree(node->left, index, val);
        node->sum = node->left->sum + node->right->sum;
    }

    int sumSegTree(segTreeNode* node, int left, int right) {
        if (node->begin == left && node->end == right)
            return node->sum;
        
        int mid = (node->begin + node->end) / 2;
        if (right <= mid)
            return sumSegTree(node->left, left, right);
        else if (left > mid)
            return sumSegTree(node->right, left, right);
        else
            return sumSegTree(node->left, left, mid) + 
                   sumSegTree(node->right, mid+1, right);
    }

public:
    segTreeNode* root = NULL;
    NumArray(vector<int>& nums) {
        root = buildSegTree(0, (int)nums.size()-1, nums);
    }
    
    void update(int index, int val) {
        updateSegTree(root, index, val);
    }

    int sumRange(int left, int right) {
        return sumSegTree(root, left, right);
    }
    void show() {
        segTreeNode * node = root;
        while (node->left != NULL) {
            cout << node->sum << endl;
            node = node->left;
        }
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

int main() {
    vector<int> nums = {-1, 4, 2, 0, 5};
    NumArray arr = NumArray(nums);
    arr.update(1, 3);
    cout << arr.sumRange(0, 2) << endl;
    return 0;
}