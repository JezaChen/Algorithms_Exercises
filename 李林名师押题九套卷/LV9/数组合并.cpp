#include <iostream>
using namespace std;
void merge(int *n1, size_t n1_size, int *n2, size_t n2_size, int *merged) {
    int i = 0, j = 0;
    for(int k = 0; k < n1_size + n2_size; k++){
        if(i == n1_size){
            merged[k] = n2[j++];
        }
        else if(j == n2_size){
            merged[k] = n1[i++];
        }
        else{
            if(n1[i] < n2[j])
                merged[k] = n1[i++];
            else
                merged[k] = n2[j++];
        }
    }
}
int main() {
    int M;
    cin>>M;
    while(M--) {
        int N1, N2;
        cin>>N1>>N2;
        int *n1 = new int[N1], *n2 = new int[N2];
        for(int i=0; i<N1; i++) {
            cin>>n1[i];
        }
        for(int i=0; i<N2; i++) {
            cin>>n2[i];
        }
        int *merged = new int[N1+N2];
        //合并两个数组
        merge(n1, N1, n2, N2, merged);
        //输出合并后的数组
        for(int i=0; i<N1+N2; i++)
            cout<<merged[i]<<(i==N1+N2-1?'\n':' ');
        delete [] n1;
        delete [] n2;
        delete [] merged;
    }
    return 0;
}
