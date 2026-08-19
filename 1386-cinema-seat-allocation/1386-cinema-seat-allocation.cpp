class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& rS) {
        int total_seat=n<<1;
        unordered_map<int,tuple<bool,bool,bool>>r;
        for(int i=0;i<rS.size();i++)
        {
            int row=rS[i][0];
            int seat=rS[i][1];

            if(seat>=2 &&seat<=5) get<0>(r[row])=true;
            if(seat>=4 &&seat<=7) get<1>(r[row])=true;
            if(seat>=6 &&seat<=9) get<2>(r[row])=true;
        }
            for(auto& [key,val]:r){
              auto& [l,m,rr]=val;

                 if(l==1&&m==1&&rr==1) total_seat -=2;
                  else if(l||m||rr) total_seat -=1;
             }
    return total_seat;
    }
};