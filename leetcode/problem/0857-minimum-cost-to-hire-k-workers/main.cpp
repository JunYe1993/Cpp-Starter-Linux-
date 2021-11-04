#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_set>
#include <queue>
#include <cfloat>

using namespace std;

class Solution {
    struct payment {
        int quality;
        double ratio;
    };

public:
    double mincostToHireWorkers (vector<int>& quality, vector<int>& wage, int k) {
        
        // Rule :
        // offer_x / offer_y = quality_x / quality_y
        
        // Goal : Find minimum cost with k workers
        // Minimum cost = at least one worker is paid equal to his expected wage among k workers.

        // Assume that one highest CP worker name is "idiot"
        // offer_x / offer_idiot = quality_x / quality_idiot
        // offer_x = quality_x * (offer_idiot / quality_idiot)
        // offer_x = quality_x * ratio_idiot (wage_idiot / quality_idiot)
        // offer_x + offer_y + offer_z = (quality_x + quality_y + quality_z) * ratio_idiot
        // 1. cost = quality_sum * ratio_idiot

        // Another condition
        // offer_x >= wage_x
        // quality_x * ratio_idiot >= wage_x
        // ratio_idiot >= wage_x / quality_x
        // ratio_idiot >= ratio_x
        // 2. ratio_idiot will be biggest ratio among k workers (that's why he is idiot)


        // Every one can be that idiot among k.
        int size = quality.size();
        vector<struct payment> ratios;
        for (int i = 0; i < size; ++i)
            ratios.push_back({quality[i], (double)wage[i]/(double)quality[i]});

        // Sort, so when we iterate the vector will always get ratio_idiot (biggest one)
        sort(ratios.begin(), ratios.end(), [](struct payment& a, struct payment& b){
            return a.ratio < b.ratio;});

        // Keep track qualitySum (quality_x + quality_y + quality_z)
        // Use a container for k workers. 
        // When container.size == k, then calculate cost, and find the minimum.
        double res = DBL_MAX, qualitySum = 0;
        priority_queue<int> pq;

        for (auto it : ratios) {
            // track qualitySum
            qualitySum += it.quality;
            pq.push(it.quality);
            // The cost = quality_sum * ratio_idiot (which is ascending)
            // So to get minimum cost = kick the biggest quality worker out.
            // That is the reason why container is heap (priority_queue)
            if ((int) pq.size() > k) {
                qualitySum -= pq.top();
                pq.pop();
            }

            if ((int) pq.size() == k) 
                res = min(res, qualitySum * it.ratio);
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> quality, wage;
    int k;

    k = 2;
    wage = {70,50,30};
    quality = {10,20,5};
    cout << sol.mincostToHireWorkers(quality, wage, k) << endl;
    k = 3;
    wage = {4,8,2,2,7};
    quality = {3,1,10,10,1};
    cout << sol.mincostToHireWorkers(quality, wage, k) << endl;
    
    
    return 0;
}