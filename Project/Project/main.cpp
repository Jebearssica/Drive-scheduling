#include<random>
#include<iostream>
#include"IO_Table.h"
using namespace std;
void Run_Driven() {

}
void Select_By_Cylinder(bool Small,IO_Table *Table) {
  int minus = 0, sum = 0;
  if (Small) {          //����С�ڵ����ֵ
    for (size_t i = 0; i < Table->length(); i++) {
      if (abs(Table[i] - Now_Cylinder)>minus) {
        
      }
    }
  }
}
void Accept_Order(IO_Table *Table) {
  //ģ�⡰�������󡱹���

  if (Has_Order) {
    string Name;
    int Phy_Address;
    cout << "��������� ��ַ��" << endl;
    cin >> Name >> Phy_Address;
    Table = new IO_Table(Name, Phy_Address);     //����IO��
    bool Move_Dis = true;                       //����Ϊtrue
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
  //��ʼ��
  float flag = 0;
  IO_Table *Table = NULL;
  while (true) {
    //���������
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