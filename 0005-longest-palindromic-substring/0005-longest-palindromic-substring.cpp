class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        int st=0,ml=1;
        bool dp[n][n];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)
            dp[i][i]=1;
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                dp[i][i+1]=1;
                st=i;
                ml=2;
            }
        }
        for(int k=3;k<=n;k++){
            for(int i=0;i+k-1<n;i++){
                if(s[i]==s[i+k-1] && dp[i+1][i+k-2]){
                    dp[i][i+k-1]=1;
                    st=i;
                    ml=k;
                }
            }
        }
        return s.substr(st,ml);
    }
};