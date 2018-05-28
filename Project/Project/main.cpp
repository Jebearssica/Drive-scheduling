#include<random>
#include<cmath>
#include"Queue.h"
using namespace std;

//�ṹ


//��ʼ��ȫ�ֱ���
bool Move_Dir = true;         //�Ʊ۷���trueΪ�� falseΪ�⣩
int Now_Cylinder = 0;         //��ǰ����
int Now_Phy = 0;              //��ǰ�����¼
int Now_Track = 0;            //��ǰ�ŵ�
IO_Table *Now;                //��ǰִ�еĽ���
Queue *Order;                 //���̵ȴ������׶���
Queue *Nail;                  //���̵ȴ�����ĩ����

bool Judge_Order() {
  char judge;
  cout << "Continue? Y/N" << endl;
  cin >> judge;
  if (judge == 'y'||judge == 'Y')
    return true;
  else
    return false;
}

//ģ�⡰�������󡱹���
void Accept_Order(Queue *tmp) {
  string Name;
  IO_Table *Table;
  IO_Table *Table_For_Head;
  Queue *tmp_Next;
  int Cylinder, Track, Phy_Address;
  if (Judge_Order()) {
    if (tmp == NULL) {        //����ͷ�ڵ�
      Table_For_Head = new IO_Table("Head", 0, 0, 0);
      tmp = new Queue(Table_For_Head, NULL, tmp);
    }
    cout << "��������� ���� �ŵ� ��ַ��" << endl;
    cin >> Name;
    cin >> Cylinder >> Track >> Phy_Address;
    Table = new IO_Table(Name, Cylinder, Track, Phy_Address);     //����IO��
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
  //����������̵�
  //���Ʋ���Small 1��С��������� -1������������С
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

//ͨ���ŵ�ɸѡ
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
//����true ������ڴ��ڻ�С�ڵ� false ������
bool Judge_For_MaxMin(int Small, int Cylinder) {//ͬ��small 1��С��������� -1������������С
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
  //��ʼ��
  float flag = 0;
  IO_Table *Table = NULL;
  while (true) {
    //���������
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