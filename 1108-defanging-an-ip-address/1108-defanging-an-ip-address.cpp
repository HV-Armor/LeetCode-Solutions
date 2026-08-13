class Solution {
public:
    string defangIPaddr(string address) {
        int i=0;
        string ans;
        while(i<address.size()){
            if(address[i]=='.'){
                ans+="[.]";
            }
            else{
                ans+=address[i];
            }
            i++;
        }
        return ans;
    }
};