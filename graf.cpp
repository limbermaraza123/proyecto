#include <iostream>    //std::cout
#include <algorithm>  //std::min
#define COL 40
#define FIL 40
#define infinito 32767

using namespace std;

int main(){
     int min;
     int m[FIL][COL];
     int i,j,filas,columnas;
     filas=columnas=j=i=0;//inicializando las variables
     cout<<"Digite el numero de filas :";
     cin>>filas;//el numero de filas
     cout<<"Digite el numero de columnas : ";
     cin>>columnas;//numero de columnasmatriz objeto;
     for(int i=0;i<filas;i++)
      {
        for(int j=0;j<columnas;j++)
        {
            //cout<<"Digite el dato "<<"["<<i+1<<"]["<<j+1<<"] = ";
            if(i==j)
                m[i][j]=0;
            if(i<j)
                m[i][j]=2*i;
            if(i>j)
                m[i][j]=2*i-1;
            //cin>>m[i][j];
        }
            cout<<endl;
      }
     cout<<"Los datos de la matriz son"<<endl;
     for( int i=0;i<filas;i++)
      {
       for( int j=0;j<columnas;j++)
            {
             cout<<m[i][j]<<" ";
            }
          cout<<endl;
      }

     int s;
     for( int i=1;i<filas+1;i++)
      {
       for( int j=1;j<columnas+1;j++)
            {
            if(i!=j && m[i][j]!= infinito && m[j][i]!=infinito)
                 //std::cout<<"min(m[i][j]+m[j][i])=="<<std::min(m[i][j]+m[j][i])<< '\n';
                s=(m[i][j]+m[j][i]+m[i][i]+m[j][j]);
            }

      }cout<<"camino corto:"<<s;

    return 0;
}
