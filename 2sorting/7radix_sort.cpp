#include<iostream>
using namespace std;
int main()
{
    int nums[10]={69,45,2,86,139,268,158,34,8,76};
    int n=10;
    int passes=0;
    int max=*max_element(nums,nums+n);
    while(max!=0)
    {
        passes++;
        max/=10;
    }
    int div=1;
    while(passes>0)
    {
        int **bucket=new int *[10];
        for(int i=0;i<10;i++)
        {
            bucket[i]=new int [10];
        }
        int count[10]={0};
        for(int i=0;i<n;i++)
        {
            int digit=(nums[i]/div)%10;
            bucket[digit][count[digit]]=nums[i];
            count[digit]++;
        }
        int k=0;
        for(int i=0;i<10;i++)
        {
            int n=count[i];
            int j=0;
            while(j<n)
            {
                nums[k]=bucket[i][j];
                k++;
                j++;
                count[i]--;
            }
        }
        div=div*10;
        passes--;
    }
    for(int i=0;i<n;i++)
    {
        cout<<nums[i]<<" ";
    }
}