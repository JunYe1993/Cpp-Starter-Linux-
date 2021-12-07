#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    vector<int> findNumOfValidWords (vector<string>& words, vector<string>& puzzles) {

        // Using map for not being double calculate
        unordered_map<int, vector<int>> map;
        
        vector<int> letterBitMask;
        for (int i = 0; i < 26; ++i) {
            letterBitMask.push_back((1 << i));
            map[i] = vector<int>();
        }

        for (auto&s:words) {
            int bitMask = 0;
            unordered_set<int> wordset;
            for (auto & c : s) {
                bitMask |= letterBitMask[c-'a'];
                wordset.insert(c-'a');
            }
            for (auto & n : wordset) map[n].push_back(bitMask);
        }

        vector<int> res;
        for (auto & puzzle : puzzles) {
            int curRes = 0;
            int puzzleBitMask = 0;
            for (auto & c : puzzle) puzzleBitMask |= letterBitMask[c-'a'];
            for (auto & wordBitMask : map[puzzle[0]-'a'])
                if ((wordBitMask & puzzleBitMask) == wordBitMask)
                    ++curRes;
            res.push_back(curRes);
        }
            
        return res;
    }

    // Boost version
    vector<int> findNumOfValidWordsQQ (vector<string>& words, vector<string>& puzzles) {
        
        // Change Map to Bit Mask
        vector<int> letterBitMask;
        for (int i = 0; i < 26; ++i) 
            letterBitMask.push_back((1 << i));

        vector<int> wordsBitMask;
        int size = words.size();
        for (auto&s:words) {
            int bitMask = 0;
            for (auto&c : s) bitMask |= letterBitMask[c-'a'];
            wordsBitMask.push_back(bitMask);
        }

        vector<int> res;
        for (auto & puzzle : puzzles) {
            int bitMask = 0;
            int curRes = 0;
            for (auto & c : puzzle) 
                bitMask |= letterBitMask[c-'a'];
            
            for (int i = 0; i < size; ++i) {
                if (!(wordsBitMask[i] & letterBitMask[puzzle[0]-'a'])) continue;
                if ((bitMask & wordsBitMask[i]) == wordsBitMask[i]) ++curRes;
            }
            res.push_back(curRes);
        }

        return res;
    }

    // Intuitive solve
    vector<int> findNumOfValidWordsQ (vector<string>& words, vector<string>& puzzles) {
        
        vector<unordered_map<char, bool>> wordsMap;
        int wsize = words.size();
        for (auto&s:words) {
            unordered_map<char, bool> tempMap;
            for (auto&c:s) tempMap[c] = true;
            wordsMap.push_back(tempMap);
        }

        vector<int> res;
        for (auto&puzzle:puzzles) {
            int curRes = 0;
            cout << "puzzle = " << puzzle << endl;
            for (int i = 0; i < wsize; ++i) {
                if (wordsMap[i].find(puzzle[0]) == wordsMap[i].end()) {
                    continue;
                }
                ++curRes;
                unordered_map<char, bool> tempMap;
                for (auto&c:puzzle) tempMap[c] = true;
                for (auto&m:wordsMap[i])
                    if (!tempMap[m.first]) {
                        --curRes;
                        break;
                    }
            }
            res.push_back(curRes);
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<string> words, puzzles;

    words = {"aaaa","asas","able","ability","actt","actor","access"};
    puzzles = {"aboveyz","abrodyz","abslute","absoryz","actresz","gaswxyz"};
    for (auto&n:sol.findNumOfValidWords(words, puzzles))
        cout << n << " ";
    cout << endl;
    words = {"apple","pleas","please"};
    puzzles = {"aelwxyz","aelpxyz","aelpsxy","saelpxy","xaelpsy"};
    for (auto&n:sol.findNumOfValidWords(words, puzzles))
        cout << n << " ";
    cout << endl;
    words = {"aebd","cbdjegehgfcefbgceifdcjcbhdbbhhdi","bbcaehdgdghgaaghdbdg","fhgjegdagiadgdhaeicgjgifabadjdfe","gcadacg","efhjdffcaih","cgfjcdddabcdafjhcafieiadgebdeicbjjifgjbaf","cbfhbdaiajhdefgjefjibefjaahgdachhfge","cjejijcibgigceefidhcgbbdgg","jaedgdggbajbbibifadjeddbff","chdihgafjgfeaeefdigfeifjaihcg","giicgbjeah","bagcfechdabicgbidbceggjfedaabfibhcieefjhj","gbagbjhdjjdgifgaciehfjabi","ehheaajfbjdhabbjafeid","biajeeagdecjigefgidc","fejfdfeghbbdfc","bfbfffe","digd","bciabjhf"};
    puzzles = {"axtniqf","xsdlyik","ldsimca","ptvdamy","djihgak","xencovd","rbwpugz","xvsbpmj","epfhmxs","fshonmc"};
    for (auto&n:sol.findNumOfValidWords(words, puzzles))
        cout << n << " ";
    cout << endl;
    words = {};
    
    return 0;
}