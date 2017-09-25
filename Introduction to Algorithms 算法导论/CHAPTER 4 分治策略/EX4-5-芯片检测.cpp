#include <iostream>
#include <vector>
using namespace std;

class chip  //芯片用类来封装
{
private:
    bool working_well;  //好坏状态不可见，符合题目要求
public:
    unsigned id;
    chip(unsigned id, bool working_well):id(id), working_well(working_well) {}
    friend bool test (const chip& A, const chip& B)
    {
        return A.working_well==B.working_well;
    }
};

int TEST_FUNCTION (vector<chip> & V)
{
    if(V.size()==0) return -1; //退化情况，没有芯片，只用于奇数情况，此时抽取出来的那一个必为好的芯片
    if(V.size()==1) return V[0].id; //退化情况，只有一个芯片，那肯定是好的
    if(V.size()==2)
    {
        if(test(V[0],V[1])==false) return -1; //若结果不对，意味着好芯片比坏芯片多一个，用于奇数情况
        else return V[0].id; //否则必为好的芯片
    }
    if(V.size()%2) //奇数情况
    {
        vector<chip> VN;
        chip RES = V[0]; //选取一个出来，凑成偶数
        V.erase(V.begin());
        //开始分组检验
        for(int i=0;i<V.size()/2;i++)
        {
            if(test(V[i],V[i+1]))
                VN.push_back(V[i]); //将结果是双方都是好的组找出一个加入下一次递归的集合中
        }
        int r=TEST_FUNCTION(VN);
        if(r!=-1) return r;
        else return RES.id;
    }
    else  //偶数情况，直接分组检测即可
    {
        vector<chip> VN;
        for(int i=0;i<V.size()/2;i++)
        {
            if(test(V[i],V[i+1]))
                VN.push_back(V[i]);
        }
        return TEST_FUNCTION(VN);
    }
}

int main()
{
    vector<chip> V;
    int n;
    while(cin>>n)
    {
        for(int i=0;i<n;i++)
        {
            unsigned id; bool is_well;
            cin>>id>>is_well;
            V.push_back(chip(id,is_well));
        }
        int r=TEST_FUNCTION(V);
        cout<<r<<endl;
        V.clear();
    }
}