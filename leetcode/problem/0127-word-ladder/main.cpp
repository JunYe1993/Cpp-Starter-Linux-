#include <iostream>
#include <string>
#include <vector>
#include <climits>


using namespace std;

class Solution {

    bool isTransformable (string& a, string& b) {    
        int count = a.size();
        auto ait = a.begin();
        auto bit = b.begin();
        for (; ait != a.end(); ++ait, ++bit) {
            if (*ait == *bit)
                --count;
        }
        return (count == 1) ? true : false;
    }

public:
    int ladderLength (string beginWord, string endWord, vector<string>& wordList) {
        
        int targetIndex = -1;
        int size = wordList.size();
        for (int i = 0; i < size; ++i)
            if (wordList[i] == endWord)
                targetIndex = i;
        if (targetIndex < 0) return 0;
            
        vector<vector<int>> map(size, vector<int>());
        for (int i = 0; i < size; ++i)
            for (int j = i+1; j < size; ++j)
                if (isTransformable(wordList[i], wordList[j])) {
                    map[i].push_back(j);
                    map[j].push_back(i);
                }

        vector<int> dp (size, -1);
        vector<int> queue;
        for (int i = 0; i < size; ++i)
            if (isTransformable(beginWord, wordList[i])) {
                if (i == targetIndex) return 2;
                dp[i] = 2;
                queue.push_back(i);
            }
        if (map[targetIndex].empty()) return 0;
                
        int curStep = 2;
        while (!queue.empty()) {
            ++curStep;
            // cout << "curStep : " << curStep << ", size : " << (int)queue.size() << endl;
            vector<int> tmpQueue = {};
            for (auto&cur:queue) {
                // cout << " cur = " << cur << " ";
                for (auto&next:map[cur]) {
                    if (next == targetIndex) return curStep;
                    if (dp[next] == -1) {
                        dp[next] = curStep;
                        tmpQueue.push_back(next);
                    }
                        
                }
            }
            // cout << endl;
            queue = tmpQueue;
            
        }        

        return 0;    
    }
};

int main() {
    Solution sol = Solution();
    string beginWord, endWord;
    vector<string> wordList;
    
    beginWord = "hit";
    endWord   = "cog";
    wordList = {"hot","dot","dog","lot","log","cog"};
    cout << sol.ladderLength(beginWord, endWord, wordList) << endl;
    beginWord = "hit";
    endWord   = "cog";
    wordList = {"hot","dot","dog","lot","log"};
    cout << sol.ladderLength(beginWord, endWord, wordList) << endl;
    beginWord = "qa";
    endWord   = "sq";
    wordList = {"si","go","se","cm","so","ph","mt","db","mb","sb","kr","ln","tm","le","av","sm","ar","ci","ca","br","ti","ba","to","ra","fa","yo","ow","sn","ya","cr","po","fe","ho","ma","re","or","rn","au","ur","rh","sr","tc","lt","lo","as","fr","nb","yb","if","pb","ge","th","pm","rb","sh","co","ga","li","ha","hz","no","bi","di","hi","qa","pi","os","uh","wm","an","me","mo","na","la","st","er","sc","ne","mn","mi","am","ex","pt","io","be","fm","ta","tb","ni","mr","pa","he","lr","sq","ye"};
    cout << sol.ladderLength(beginWord, endWord, wordList) << endl;
    beginWord = "cet";
    endWord   = "ism";
    wordList = {"kid","tag","pup","ail","tun","woo","erg","luz","brr","gay","sip","kay","per","val","mes","ohs","now","boa","cet","pal","bar","die","war","hay","eco","pub","lob","rue","fry","lit","rex","jan","cot","bid","ali","pay","col","gum","ger","row","won","dan","rum","fad","tut","sag","yip","sui","ark","has","zip","fez","own","ump","dis","ads","max","jaw","out","btu","ana","gap","cry","led","abe","box","ore","pig","fie","toy","fat","cal","lie","noh","sew","ono","tam","flu","mgm","ply","awe","pry","tit","tie","yet","too","tax","jim","san","pan","map","ski","ova","wed","non","wac","nut","why","bye","lye","oct","old","fin","feb","chi","sap","owl","log","tod","dot","bow","fob","for","joe","ivy","fan","age","fax","hip","jib","mel","hus","sob","ifs","tab","ara","dab","jag","jar","arm","lot","tom","sax","tex","yum","pei","wen","wry","ire","irk","far","mew","wit","doe","gas","rte","ian","pot","ask","wag","hag","amy","nag","ron","soy","gin","don","tug","fay","vic","boo","nam","ave","buy","sop","but","orb","fen","paw","his","sub","bob","yea","oft","inn","rod","yam","pew","web","hod","hun","gyp","wei","wis","rob","gad","pie","mon","dog","bib","rub","ere","dig","era","cat","fox","bee","mod","day","apr","vie","nev","jam","pam","new","aye","ani","and","ibm","yap","can","pyx","tar","kin","fog","hum","pip","cup","dye","lyx","jog","nun","par","wan","fey","bus","oak","bad","ats","set","qom","vat","eat","pus","rev","axe","ion","six","ila","lao","mom","mas","pro","few","opt","poe","art","ash","oar","cap","lop","may","shy","rid","bat","sum","rim","fee","bmw","sky","maj","hue","thy","ava","rap","den","fla","auk","cox","ibo","hey","saw","vim","sec","ltd","you","its","tat","dew","eva","tog","ram","let","see","zit","maw","nix","ate","gig","rep","owe","ind","hog","eve","sam","zoo","any","dow","cod","bed","vet","ham","sis","hex","via","fir","nod","mao","aug","mum","hoe","bah","hal","keg","hew","zed","tow","gog","ass","dem","who","bet","gos","son","ear","spy","kit","boy","due","sen","oaf","mix","hep","fur","ada","bin","nil","mia","ewe","hit","fix","sad","rib","eye","hop","haw","wax","mid","tad","ken","wad","rye","pap","bog","gut","ito","woe","our","ado","sin","mad","ray","hon","roy","dip","hen","iva","lug","asp","hui","yak","bay","poi","yep","bun","try","lad","elm","nat","wyo","gym","dug","toe","dee","wig","sly","rip","geo","cog","pas","zen","odd","nan","lay","pod","fit","hem","joy","bum","rio","yon","dec","leg","put","sue","dim","pet","yaw","nub","bit","bur","sid","sun","oil","red","doc","moe","caw","eel","dix","cub","end","gem","off","yew","hug","pop","tub","sgt","lid","pun","ton","sol","din","yup","jab","pea","bug","gag","mil","jig","hub","low","did","tin","get","gte","sox","lei","mig","fig","lon","use","ban","flo","nov","jut","bag","mir","sty","lap","two","ins","con","ant","net","tux","ode","stu","mug","cad","nap","gun","fop","tot","sow","sal","sic","ted","wot","del","imp","cob","way","ann","tan","mci","job","wet","ism","err","him","all","pad","hah","hie","aim","ike","jed","ego","mac","baa","min","com","ill","was","cab","ago","ina","big","ilk","gal","tap","duh","ola","ran","lab","top","gob","hot","ora","tia","kip","han","met","hut","she","sac","fed","goo","tee","ell","not","act","gil","rut","ala","ape","rig","cid","god","duo","lin","aid","gel","awl","lag","elf","liz","ref","aha","fib","oho","tho","her","nor","ace","adz","fun","ned","coo","win","tao","coy","van","man","pit","guy","foe","hid","mai","sup","jay","hob","mow","jot","are","pol","arc","lax","aft","alb","len","air","pug","pox","vow","got","meg","zoe","amp","ale","bud","gee","pin","dun","pat","ten","mob"};
    cout << sol.ladderLength(beginWord, endWord, wordList) << endl;
    beginWord = "hog";
    endWord   = "cog";
    wordList = {"cog"};
    cout << sol.ladderLength(beginWord, endWord, wordList) << endl;

    return 0;
}