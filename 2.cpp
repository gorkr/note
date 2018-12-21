#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;

void display(vector<vector<int>> v){
  int len=v[0].size();
  for(int i=0;i<len;i++){
    for(int j=0;j<len;j++){
      cout<<v[i][j];
    }
      cout<<'\n';
  }
}

class RELATION_MATRIX{
public:
  RELATION_MATRIX(vector<vector<int>> v):m(v){
  vector<vector<int>> mc(len,vector<int>(len));//初始化逆矩阵
  vector<vector<int>> ix(len,vector<int>(len));//初始化单位矩阵
  for(int i=0;i<len;i++){
    for(int j=0;j<len;j++){
        mc[j][i]= m[i][j];
        if(i==j)ix[i][j]=1;
        else ix[i][j]=0;
    }
  }
};

  vector<vector<int>> get_mr();//返回自反闭包
  //void display();//输出矩阵
private:
  vector<vector<int>> m;//原矩阵
  vector<vector<int>> ix;//单位矩阵
  vector<vector<int>> mc;//逆矩阵
  int len=m[0].size();
};

vector<vector<int>> RELATION_MATRIX::get_mr(){
  //自反闭包运算
  vector<vector<int>> mr(len,vector<int>(len));
  for(int i=0;i<len;i++){
    for(int j=0;j<len;j++){
      //cout<<mr[i][j];
      //if((ix[i][j]==1)||(m[i][j]==1) mr[i][j] = 1;
      //else mr[i][j] = 0;
      //cout<<j;
      //mr[i][j] = int(ix[i][j]||m[i][j]);
      //cout<<j;
      // /cout<<mr[i][j];
    }
  }
    display(mr);
    return mr;
}

//void RELATION_MATRIX::display(){

//}

int main(){
  vector<vector<int>> v={{1,0,1,0},
                         {1,0,1,1},
                         {0,1,1,0},
                         {1,1,1,1}};
  RELATION_MATRIX mat(v);
  mat.get_mr();
  return 0;
}
