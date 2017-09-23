#include <iostream>

using namespace std;
static const int MAX = 2000;
static const int INF = -99999999; //负无穷

int A[MAX];
int find_max_crossing_subarray(int lo, int hi, int mid,int& maxLeft, int& maxRight) //寻找跨过中点的最大子数组
{
    int left_sum = INF;
    int sum = 0;
    for(int i = mid; i >= lo; i--)
    {
        sum += A[i];
        if(left_sum < sum)
        {
            left_sum = sum;
            maxLeft = i;
        }
    }
    int right_sum = INF;
    sum=0;
    for(int i = mid+1; i < hi; i++)
    {
        sum += A[i];
        if(right_sum < sum)
        {
            right_sum = sum;
            maxRight = i;
        }

    }
    return left_sum + right_sum;
}
int find_maxSubArr(int lo, int hi,int& maxLeft, int& maxRight)
{
    if(lo == hi-1) return A[lo]; //base case
    int mid = (lo + hi)>>1;
    int leftLow, leftHigh, rightLow, rightHigh, crossLow, crossHigh;
    //递归寻找
    int leftSum = find_maxSubArr(lo, mid, leftLow, leftHigh);
    int rightSum = find_maxSubArr(mid, hi, rightLow, rightHigh);
    int crossSum = find_max_crossing_subarray(lo, hi, mid, crossLow, crossHigh);
    //判断三者的大小关系
    if(leftSum >= rightSum && leftSum >= crossSum) { maxLeft = leftLow; maxRight = leftHigh; return leftSum;}
    if(rightSum >= leftSum && rightSum >= crossSum) { maxLeft = rightLow; maxRight= rightHigh; return rightSum;}
    else { maxLeft = crossLow; maxRight = crossHigh; return crossSum; }
}
int main()
{
    int n;
    while(cin>>n)
    {
        for(int i=0; i<n; i++) cin>>A[i];
        int maxLeft; int maxRight;
        int result = find_maxSubArr(0, n, maxLeft, maxRight);
        cout<<"lo= "<<maxLeft<<"   "<<"hi= "<<maxRight<<endl;
        cout<<"MAX SUBARR SUM= "<<result<<endl;
    }
}