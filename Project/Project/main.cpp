#include<random>
#include<cmath>
#include"Queue.h"
using namespace std;

//结构


//初始化全局变量
bool Move_Dir = true;         //移臂方向（true为里 false为外）
int Now_Cylinder = 0;         //当前柱面
int Now_Phy = 0;              //当前物理记录
int Now_Track = 0;            //当前磁道
IO_Table *Now;                //当前执行的进程
Queue *Order;                 //进程等待队列首队列
Queue *Nail;                  //进程等待队列末队列

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
void Accept_Order(Queue *tmp) {
  string Name;
  IO_Table *Table;
  IO_Table *Table_For_Head;
  Queue *tmp_Next;
  int Cylinder, Track, Phy_Address;
  if (Judge_Order()) {
    if (tmp == NULL) {        //创立头节点
      Table_For_Head = new IO_Table("Head", 0, 0, 0);
      tmp = new Queue(Table_For_Head, NULL, tmp);
    }
    cout << "输入进程名 柱面 磁道 地址名" << endl;
    cin >> Name;
    cin >> Cylinder >> Track >> Phy_Address;
    Table = new IO_Table(Name, Cylinder, Track, Phy_Address);     //创建IO表
    tmp = new Queue(Table, tmp, NULL);
    tmp->Next->Front = tmp;
    Nail = tmp->Next;
    delete Table;
  }
}
Queue* Select_By_Cylinder(int Small, int Cylinder) {
  int minus = 0, sum = INT16_MAX;
  Queue *tmp = Order;
  Queue *result = Order;
  //搜索距离最短的
  //控制参数Small 1：小于中搜最大 -1：大于中搜最小
  while (tmp) {
    minus = Small * (tmp->Head->Return_Cylinder() - Cylinder);
    if (minus > 0) {
      continue;
    }
    else {
      if (sum > abs(minus)) {
        sum = abs(minus);
        result = tmp;
      }
    }
    tmp = tmp->Next;
  }
  return result;

}

//通过磁道筛选
Queue* Select_By_Track(int Track) {
  Queue *tmp = Order;
  Queue *Result = NULL;
  int minus = INT16_MAX;
  while (tmp) {
    if (minus > abs(Track - tmp->Head->Return_Track())) {
      minus = abs(Track - tmp->Head->Return_Track());
      Result = new Queue();
      Result = tmp;
    }
    tmp = tmp->Next;
  }
  return Result;
}
//返回true 代表存在大于或小于的 false 不存在
bool Judge_For_MaxMin(int Small, int Cylinder) {//同理small 1：小于中搜最大 -1：大于中搜最小
  Queue *tmp = Order;
  while (tmp) {
    if (Small*(Cylinder - tmp->Head->Return_Cylinder()) > 0) {
      return true;
    }
    else {
      tmp = tmp->Next;
    }
  }
  return false;
}
void Run_Driven() {
  Queue *Tmp_For_Delete;
  Queue *Tmp;
  if (Order) {


    if (Now_Cylinder == Order->Head->Return_Cylinder()) {
      Tmp = Select_By_Track(Now_Track);
    }
    else {
      if (Move_Dir == true) {
        if (Judge_For_MaxMin(-1, Now_Cylinder)) {
          Tmp = Select_By_Cylinder(-1, Now_Cylinder);
        }
        else {
          Move_Dir = false;
          Tmp = Select_By_Cylinder(1, Now_Cylinder);
        }
      }
      else {
        if (Judge_For_MaxMin(1, Now_Cylinder)) {
          Tmp = Select_By_Cylinder(1, Now_Cylinder);
        }
        else {
          Move_Dir = false;
          Tmp = Select_By_Cylinder(-1, Now_Cylinder);
        }
      }
    }
    /*run for the desk*/
    Tmp->Head->Print_Table(Move_Dir);
    /*delete the selecter to the table*/
    Tmp_For_Delete = Tmp;
    Tmp->Front->Next = Tmp->Next;
    Tmp->Next->Front = Tmp->Front;
    delete Tmp_For_Delete;
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
      Accept_Order(Nail);
    }
    cout << "Run off the process" << endl;
    if (!Judge_Order())
      break;
  }
}