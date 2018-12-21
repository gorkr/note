#include<iostream>
using namespace std;
int main(){
  int value(0),num(50);
  while(num<=100){
    value+=num;
    num++;
  }
  cout<<value<<endl;
  return 0;
}
