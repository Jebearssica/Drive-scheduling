#include<random>
#include<iostream>
#include"IO_Table.h"
using namespace std;
void Run_Driven() {

}
void Select_By_Cylinder(bool Small,IO_Table *Table) {
  int minus = 0, sum = 0;
  if (Small) {          //搜索小于的最大值
    for (size_t i = 0; i < Table->length(); i++) {
      if (abs(Table[i] - Now_Cylinder)>minus) {
        
      }
    }
  }
}
void Accept_Order(IO_Table *Table) {
  //模拟“接受请求”过程

  if (Has_Order) {
    string Name;
    int Phy_Address;
    cout << "输入进程名 地址名" << endl;
    cin >> Name >> Phy_Address;
    Table = new IO_Table(Name, Phy_Address);     //创建IO表
    bool Move_Dis = true;                       //里移为true
    int Now_Cylinder = 0, Now_Phy = 0;

    if (Now_Cylinder == Queue[i].Cylinder_Number) {
      return i;
    }
    else {
      if (Move_Dis == true) {
        if (Has_Big()) {
          Select_By_Cylinder();
        }
        else {
          Move_Dis = false;
          Select_By_Cylinder();
        }
      }
      else {
        if (Has_Small()) {
          Select_By_Cylinder();
        }
        else {
          Mov_Dis = false;
          Select_By_Cylinder();
        }
      }
    }
    Table = new IO_Table(Now_Cylinder, Now_Phy);
    /*run for the desk

    */
    /*delete the selecter to the table
    
    */
  }
  else {
    return;
  }
}
int main() {
  //初始化
  float flag = 0;
  IO_Table *Table = NULL;
  while (true) {
    //生成随机数
    char Judge;
    default_random_engine e;
    uniform_real_distribution<float> u(0.0, 1.0);
    flag = u(e);
    if (flag > 0.5) {
      Run_Driven();
    }
    else {
      Accept_Order();
    }
    cout << "Continue? Y/N" << endl;
    cin >> Judge;
    if (Judge != 'Y' || Judge != 'y')
      break;
  }
}