/*
给定一个字符串数组 words，找到 length(word[i]) * length(word[j]) 的最大值，并且这两个单词不含有公共字母。
你可以认为每个单词只包含小写字母。如果不存在这样的两个单词，返回 0。
输入: ["abcw","baz","foo","bar","xtfn","abcdef"]
输出: 16 
解释: 这两个单词为 "abcw", "xtfn"。
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int len = words.size();
        if(len <= 1)
            return 0;
        int max = 0;
        for (int i=0; i < len-1; i++){
            for(int j = i+1; j < len; j++){
                if(checkSameWord(words[i], words[j])){
                    int a = words[i].length();
                    int b = words[j].length();
                    if(a*b > max)
                        max = a*b;
                }
            }
           
        }
        return max;
    }

    bool checkSameWord(string s1 , string s2){
        int a[128] = {0}, b[128] = {0};//两个数组，分别存两个字符串中的字符，下标就对应字符的ASCII码
        for (auto i : s1){
            a[i]++;
            // cout<<i<<a[i];
        }

        for (auto j : s2)
            b[j]++;
        for (int k = 0; k < 128; k++)
        {
            // cout<<a[k]<<' '<<b[k]<<endl;
            if(a[k] != 0 && b[k] != 0)
                return 0;
        }
        return 1;
    }
};

int main(){
    Solution s;
    vector<string> ws {"abcw","baz","foo","bar","xtfn","abcdef"};
    int ma = s.maxProduct(ws);
    cout<<ma<<"?? "<<s.checkSameWord("xtfn", "abcde")<<endl;
    return 0;
}