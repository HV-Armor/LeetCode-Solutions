class Solution {
public:
    string sortVowels(string s) {
        vector<int> lower(26,0);
        vector<int> upper(26,0);
        for(int i=0;i<s.size();i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
                lower[s[i]-'a']++;
                s[i]='#';
            }
            else if(s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'){
                upper[s[i]-'A']++;
                s[i]='#';
            }
        }
        string ans;
        for(int i=0;i<26;i++){
            char ch ='A'+ i;
            while(upper[i]){
                ans+=ch;
                upper[i]--;
            }
        }
        for(int i=0;i<26;i++){
            char ch='a'+i;
            while(lower[i]){
                ans+=ch;
                lower[i]--;
            }
        }
        int f=0;
        int s1=0;
        while(s1<ans.size()){
            if(s[f]=='#'){
                s[f]=ans[s1];
                s1++;
            }
            f++;
        }
        return s;
    }
};