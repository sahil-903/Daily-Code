class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int col=matrix[0].size();
        int dp[rows][col+2];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=col;i++)
        {
            dp[0][i]=matrix[0][i-1];
        }
        for(int i=0;i<rows;i++)
        {
            dp[i][0]=INT_MAX;
            dp[i][col+1]=INT_MAX;
        }

        for(int i=1;i<rows;i++)
        {
            for(int j=1;j<=col;j++)
            {
                int minbaju= min(dp[i-1][j-1],dp[i-1][j]);
                minbaju=min(minbaju,dp[i-1][j+1]);
                dp[i][j]=matrix[i][j-1]+minbaju;
            }
        }
        int mn=INT_MAX;
        for(int i=1;i<=col;i++)
        {
            mn=min(mn,dp[rows-1][i]);
        }
        return mn;
    }
};
