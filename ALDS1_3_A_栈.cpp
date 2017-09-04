#include <iostream>
#include <stack>
#include <cstring>

using namespace std;
stack<int> numbers;

int main() {
    bool backtrack=false;
    char* str=new char[1000];
    cin.getline(str,1000);

        int pointer=0;
        int n=0;
        while(pointer!=strlen(str))
        {
            if(str[pointer]>='0'&&str[pointer]<='9')
            {
                n*=10;
                n+=str[pointer]-'0';
                backtrack=false;
            }
            else if(str[pointer]==' ')
            {
                if(backtrack==false)
                {
                    numbers.push(n);
                    n = 0;
                }
            }
            else
            {
                int result;
                int n1,n2;
                n2=numbers.top();numbers.pop();
                n1=numbers.top();numbers.pop();
                switch(str[pointer])
                {
                    case'+':result=n1+n2;
                        break;
                    case'-':result=n1-n2;
                        break;
                    case'*':result=n1*n2;
                        break;
                    case '/':result=n1/n2;
                        break;
                }
                numbers.push(result);
                backtrack=true;
            }

            pointer++;
        }
        cout<<numbers.top()<<endl;
        numbers.pop();


    return 0;
}