/*  Вариант 18
В массиве А(N,М) столбец с минимальным количеством нечетных
элементов переставить на последнее место.*/

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
const int m=5;
void myinput(int A[][m],int n)
    {
        srand(time(0));
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++)
            {
                A[i][j]=rand()%30-5;
            }
    }
void myoutput(int A[][m],int n)
    {
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<m; j++)
            {
                cout.width(4);
                cout << A[i][j];
            }
            cout << endl << endl;
        }
    }
int nechet(int A[][m],int n)
{
    int k=0;
    int num=0;
    int ncol=0;
    for(int i=0; i<n; i++)
    {
        if (abs(A[i][0])%2==1)
        {
            num++;
        }
    }
    for (int j=1; j<m; j++)
    {
        for (int i=0; i<n; i++)
        {
            if (abs(A[i][j])%2==1)
            {
                k++;
            }
        }
        if (k<num)
        {
            num=k;
            ncol=j;
        }
        k=0;
    }
    return ncol;
}
void perestanovka(int A[][m],int n, int ncol)
{
    int temp;
    for (int i=0; i<n; i++)
    {
        for (int j=ncol; j<m-1; j++)
        {
            temp=A[i][j];
            A[i][j]=A[i][j+1];
            A[i][j+1]=temp;
        }
    }
}
int main()
{
    const int n=6;
    int M[n][m];
    myinput(M,n);
    cout << "Source array:" << endl << endl;
    myoutput(M,n);
    int t=nechet(M,n);
    perestanovka(M,n,t);
    cout << endl << "Obtained array:" << endl << endl;
    myoutput(M,n);
    return 0;
}
