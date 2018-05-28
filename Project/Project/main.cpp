#include<random>
#include<cmath>
#include"Queue.h"
using namespace std;

//初始化全局变量
bool Move_Dir = true;         //移臂方向（true为里 false为外）
int Now_Cylinder = 0;         //当前柱面
int Now_Phy = 0;              //当前物理记录
int Now_Track = 0;            //当前磁道
IO_Table *Now;                //当前执行的进程
Queue *Order;                 //进程等待队列

bool Judge_Order() {
  char judge;
  cout << "Continue? Y/N" << endl;
  cin >> judge;
  if (judge == 'y'||judge == 'Y')
    return true;
  else
    return false;
}

//模拟“接受请求”过程
void Accept_Order() {
  string Name;
  IO_Table *Table;
  IO_Table *Table_For_Head;
  Node Insert;
  int Cylinder, Track, Phy_Address;
  if (Judge_Order()) {
    if (Order == NULL) {        //创立头节点
      Table_For_Head = new IO_Table("Head", 0, 0, 0);
      Order = new Queue(Table_For_Head, NULL, NULL);
    }
    cout << "输入进程名 柱面 磁道 地址名" << endl;
    cin >> Name;
    cin >> Cylinder >> Track >> Phy_Address;
    Table = new IO_Table(Name, Cylinder, Track, Phy_Address);    //创建IO表
    Insert.Data = Table;                                         //创建插入节点
    Order->Insert(Order->ReturnLength(), &Insert);                   //插入节点
  }
}
void Run_Driven() {
  Queue *Tmp_For_Delete;
  Node *Tmp = NULL;
  int position = 0;   //用于定位删除
  if (Order) {


    if (Now_Cylinder == Order->Return_Cylinder()) {
      Tmp = new Node();
      Tmp = Order->Select_By_Track(Now_Track);
    }
    else {
      if (Move_Dir == true) {
        if (Order->Judge_For_MaxMin(-1, Now_Cylinder)) {
          Tmp = Order->Select_By_Cylinder(-1, Now_Cylinder);
        }
        else {
          Move_Dir = false;
          Tmp = Order->Select_By_Cylinder(1, Now_Cylinder);
        }
      }
      else {
        if (Order->Judge_For_MaxMin(1, Now_Cylinder)) {
          Tmp = Order->Select_By_Cylinder(1, Now_Cylinder);
        }
        else {
          Move_Dir = false;
          Tmp = Order->Select_By_Cylinder(-1, Now_Cylinder);
        }
      }
    }
    /*run for the desk*/
    Tmp->Data->Print_Table(Move_Dir);
    /*delete the selecter to the table*/
    Order->Delete_Node(Tmp);
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
    default_random_engine e(time(NULL));
    uniform_real_distribution<float> u(0.0, 1.0);
    flag = u(e);
    if (flag > 0.5) {
      Run_Driven();
    }
    else {
      Accept_Order();
    }
    cout << "Run off the process" << endl;
    if (!Judge_Order())
      break;
  }
}