#include<random>
#include<cmath>
#include"IO_Table.h"
using namespace std;

//�ṹ
struct Queue {
  IO_Table *Head = NULL;            //�洢�Ľ���
  Queue *Front = NULL;
  Queue *Next = NULL;               //ʹ������������һ����ַ
  Queue(IO_Table *a, Queue *b, Queue*c) {    //���캯��
    this->Head = a;
    this->Front = b;
    this->Next = c;
  }
  Queue() {
    this->Head = NULL;
    this->Front = this->Next = NULL;
  }
};

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
  if (judge == 'y'&&judge == 'Y')
    return true;
  else
    return false;
}

//ģ�⡰�������󡱹���
void Accept_Order(Queue *tmp) {
  string Name;
  IO_Table *Table;
  int Cylinder, Track, Phy_Address;
  if (Judge_Order()) {
    cout << "��������� ���� �ŵ� ��ַ��" << endl;
    cin >> Name;
    cin >> Cylinder >> Track >> Phy_Address;
    Table = new IO_Table(Name, Cylinder, Track, Phy_Address);     //����IO��
    tmp->Next = new Queue(Table, tmp, NULL);
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
    default_random_engine e;
    uniform_real_distribution<float> u(0.0, 1.0);
    flag = u(e);
    if (flag > 0.5) {
      Run_Driven();
    }
    else {
      Accept_Order(Nail);
    }
    if (!Judge_Order())
      break;
  }
}