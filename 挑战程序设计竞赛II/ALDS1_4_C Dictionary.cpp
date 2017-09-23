#include <iostream>
#include <cstring>
#include <cstdio>
#define M 1046527

using namespace std;

char* H[M];
bool is_ever_existed[M];
bool is_existed[M];
int getChar(char x)
{
    switch(x)
    {
        case 'A': return 1;
        case 'C': return 2;
        case 'G': return 3;
        case 'T': return 4;
    }
    return 0;
}

long long getKey(char* str)
{
    long long result=0;
    for(int i=0;i<strlen(str);i++)
    {
        result*=10;
        result+=getChar(str[i]);
    }
    return result;
}

int h1(int key) {return key%M;}
int h2(int key) {return 1+(key%(M-1));}

bool find(char* str)
{
    long long key=getKey(str);
    for(int i=0;;i++)
    {
        int loc=(h1(key)+i*h2(key));
        if(loc>=M) return false;
        if(is_ever_existed[loc]==false) return false;
        if(is_existed[loc])
              if(strcmp(H[loc],str)==0) return true;
    }
}

bool insert(char* str)
{
    long long key=getKey(str);
    for(int i=0;;i++)
    {
        int loc=(h1(key)+i*h2(key));
        if(is_existed[loc]==false)
        {
            H[loc] = str;
            is_existed[loc]=true;
            is_ever_existed[loc]=true;
            return true;
        }
        else if(strcmp(H[loc],str)==0) return false;
    }

}
bool remove(char* str)
{
    long long key=getKey(str);
    for(int i=0;;i++)
    {
        int loc=(h1(key)+i*h2(key));
        if(strcmp(H[loc],str)==0)
        {
            delete H[loc];
            H[loc]=NULL;
            is_existed[loc]=false;
            return true;
        }
        else if(is_ever_existed[loc]==false) return false;
    }
}
int main()
{
    int pick;
    scanf("%d",&pick);
    for(int i=0;i<pick;i++)
    {
        char* order=new char[10];
        char* t=new char[1000];
        scanf("%s %s",order,t);
        if(strcmp(order,"insert")==0)
            insert(t);
        else if(strcmp(order,"find")==0)
        {
            if(find(t)==true) cout<<"yes"<<endl;
            else cout<<"no"<<endl;
        }
        else if(strcmp(order,"delete")==0)
            remove(t);
    }
}