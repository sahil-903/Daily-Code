class Solution {
  public:
    int splitArray(int arr[] ,int N, int k) {
        // code here
        int mx=0,sum=0,ans=0;
        for(int i=0;i<N;i++)
        {
            mx=max(mx,arr[i]);
            sum+=arr[i];
        }
        int low=mx,high=sum;
        while(low<=high)
        {
            int mid=(low+high)/2;
            int count=1,s=0;
            for(int i=0;i<N;i++)
            {
                s+=arr[i];
                if(s>mid)
                {
                    count++;
                    s=arr[i];
                }
            }
            if(count>k)
            {
                low=mid+1;
            }
            else
            {
                ans=mid;
                high=mid-1;
            }
        }
        return ans;
        
    }
};
