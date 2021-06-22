#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

class Solution {
private:
    vector<int> primeList = {2, 3, 5, 7};
public:
    bool isPrime (int number){
        if (number < 2) return false;
        int lastPrime = primeList[primeList.size()-1];
        if (lastPrime*lastPrime > number) {
            for (int &prime : primeList) {
                if (prime*prime > number) 
                    break;    
                if (number % prime == 0)
                    return false;
            }
            return true;
        } else {
            int newNum = lastPrime;
            while (lastPrime*lastPrime <= number) {
                ++newNum;
                if (isPrime(newNum)) {
                    primeList.push_back(newNum);
                    lastPrime = newNum;
                    if (number%newNum == 0)
                        return false;
                }
            }
            return isPrime(number);
        }
    }
    void showPrimeList() {
        for (int &n : primeList)
            cout << n << " ";
        cout << endl;
    }
    vector<vector<int>> splitToPrimeNumber(string s) {
        vector<vector<int>> answer;
        
        int permutations = pow(2, s.size()-1);
        for (int i = 0; i < permutations; ++i) {
            vector<int> split;
            int temp = 0;
            for (size_t j = 0; j < s.size(); j++) {
                temp = temp*10 + s[j] - '0';   
                if ((i >> (s.size()-j-2))%2) {
                    split.push_back(temp);
                    temp = 0;
                }
            }
            split.push_back(temp);
            
            bool prime = true;
            for (auto &n: split) {
                // cout << n;
                // if (isPrime(n)) cout << " : Yes";
                // cout << endl;
                prime &= isPrime(n);
            }
            
            if (prime)
                answer.push_back(split);
        }
        for (auto &v: answer) {
            for (auto &n: v)
                cout << n << " ";
            cout << endl;
        }
        return answer;
    }
};

int main() {
    Solution sol = Solution();
    string number;

    // Test1
    cout << "3175" << endl;
    number = "3175";
    sol.splitToPrimeNumber(number);
    
    // Test2
    cout << "11373" << endl;
    number = "11373";
    sol.splitToPrimeNumber(number);
    return 0;
}