#include <iostream>

using namespace std;

struct Matrix
{
    int **data;
    int n;
    int lx, ly, rx, ry;//左上角和右上角的xy坐标

    Matrix(int _n):n(_n)
    {
        data = new int*[n];
        for(int i=0; i<n; i++) data[i] = new int [n];
        lx = 0; ly = 0; rx = n-1; ry= n-1;
    }
    Matrix(const Matrix& M, int lx, int ly, int rx, int ry):lx(lx),ly(ly),rx(rx),ry(ry) {data = M.data; n = M.n/2;} //用于切割矩阵的构造函数
    Matrix(const Matrix& M) {data=M.data; n=M.n; lx=M.lx; ly= M.ly; rx=M.rx; ry=M.ry;}
    void print()
    {
        for(int i=0 ;i<n ;i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (j) cout << ' ';
                cout << data[j][i];
            }
            cout<<endl;
        }
    }
    Matrix& operator = (const Matrix& A)
    {
        for(int i=lx, i0=0;i<=rx;i++,i0++)
        {
            for(int j=ly, j0=0;j<=ry;j++, j0++)
            {
                data[i][j] = A.data[i0][j0];
            }
        }
        return *this;
    }
    friend Matrix operator + (const Matrix& A, const Matrix& B)
    {
        Matrix C(A.n);
        int i=0,j=0;
        for(int Ai=A.lx, Bi=B.lx; Ai<=A.rx && Bi<=B.rx; Ai++, Bi++) //注意A, B矩阵的坐标并不对等，要分别对待
        {
            for (int Aj = A.ly, Bj = B.ly; Aj <= A.ry && Bj <= B.ry; Aj++, Bj++)
            {
                C.data[i][j]=A.data[Ai][Aj] + B.data[Bi][Bj];
                j++;
            }
            i++;j=0;
        }
        return C;
    }
    friend Matrix operator - (const Matrix& A, const Matrix& B)
    {
        Matrix C(A.n);
        int i=0,j=0;
        for(int Ai=A.lx, Bi=B.lx; Ai<=A.rx && Bi<=B.rx; Ai++, Bi++) //同上
        {
            for (int Aj = A.ly, Bj = B.ly; Aj <= A.ry && Bj <= B.ry; Aj++, Bj++)
            {
                C.data[i][j]=A.data[Ai][Aj] - B.data[Bi][Bj];
                j++;
            }
            i++;j=0;
        }
        return C;
    }
    friend Matrix operator* (const Matrix& A, const Matrix& B) //用Strassen方法重载乘法运算符
    {
        Matrix C(A.n);
        if(A.n == 1)  //base case
        {
            C.data[0][0] = A.data[A.lx][A.ly]*B.data[B.lx][B.ly];
            return C;
        }
        //切割矩阵
        Matrix A11(A, A.lx, A.ly, A.rx/2, A.ry/2);
        Matrix A12(A, A.rx/2+1, A.ly, A.rx, A.ry/2);
        Matrix A21(A, A.lx, A.ry/2+1, A.rx/2, A.ry);
        Matrix A22(A, A.rx/2+1, A.ry/2+1, A.rx, A.ry);
        Matrix B11(B, B.lx, B.ly, B.rx/2, B.ry/2);
        Matrix B12(B, B.rx/2+1, B.ly, B.rx, B.ry/2);
        Matrix B21(B, B.lx, B.ry/2+1, B.rx/2, B.ry);
        Matrix B22(B, B.rx/2+1, B.ry/2+1, B.rx, B.ry);
        Matrix C11(C, C.lx, C.ly, C.rx/2, C.ry/2);
        Matrix C12(C, C.rx/2+1, C.ly, C.rx, C.ry/2);
        Matrix C21(C, C.lx, C.ry/2+1, C.rx/2, C.ry);
        Matrix C22(C, C.rx/2+1, C.ry/2+1, C.rx, C.ry);
       // Matrix S1(A.n/2), S2(A.n/2), S3(A.n/2), S4(A.n/2), S5(A.n/2), S6(A.n/2), S7(A.n/2), S8(A.n/2), S9(A.n/2), S10(A.n/2);
        Matrix S1 = B12-B22;
        Matrix S2 = A11+A12;
        Matrix S3 = A21+A22;
        Matrix S4 = B21-B11;
        Matrix S5 = A11+A22;
        Matrix S6 = B11+B22;
        Matrix S7 = A12-A22;
        Matrix S8 = B21+B22;
        Matrix S9 = A11-A21;
        Matrix S10 = B11+B12;

        Matrix P1 = A11*S1;
        Matrix P2 = S2*B22;
        Matrix P3 = S3*B11;
        Matrix P4 = A22*S4;
        Matrix P5 = S5*S6;
        Matrix P6 = S7*S8;
        Matrix P7 = S9*S10;

        C11 = P5+P4-P2+P6;
        C12 = P1+P2;
        C21 = P3+P4;
        C22 = P5+P1-P3-P7;

        return C;
    }
};
int main()
{
    int n; cin>>n;
    cout<<"A= "<<endl;
    Matrix A(n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>A.data[j][i];
    cout<<"B= "<<endl;
    Matrix B(n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>B.data[j][i];

    cout<<"Result= "<<endl;
    Matrix C=A*B;
    C.print();

}