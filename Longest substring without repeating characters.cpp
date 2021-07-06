class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //we are going to use map for this problem
        //whenever we arrive at an element that has been reached before then
        //left pointer shifts one ahead of the prv posn stored in the map
        int n=s.size(),left=0,right=0,i,mx=0;
        map<char,int> mp;
        
        while(right<n){
            if(mp[s[right]]==0)
                mp[s[right]]=right+1;
                
            else {
                
                if((mp[s[right]]-1)>=left){  //THIS is an important condition, char will only considered as repeating if its previous posn comes under 
                                             //the current segment length (i.e. inside [left , right] segment)
             
                  //breaking point
                   mx=max(mx,right-left);
                 
                   left=mp[s[right]];
                    
                }
                
                //now the last position is updated
                mp[s[right]]=right+1;
            }
            
            if(right==(n-1))         //breaking point
               mx=max(mx,((right-left)+1));
                
                
            right++;    
        }
        
        return mx;
    }
};
