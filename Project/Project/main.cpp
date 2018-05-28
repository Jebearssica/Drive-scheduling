#include<random>
#include<cmath>
#include"Queue.h"
using namespace std;

//��ʼ��ȫ�ֱ���
bool Move_Dir = true;         //�Ʊ۷���trueΪ�� falseΪ�⣩
int Now_Cylinder = 0;         //��ǰ����
int Now_Phy = 0;              //��ǰ�����¼
int Now_Track = 0;            //��ǰ�ŵ�
IO_Table *Now;                //��ǰִ�еĽ���
Queue *Order;                 //���̵ȴ�����

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
void Accept_Order() {
  string Name;
  IO_Table *Table;
  IO_Table *Table_For_Head;
  Node Insert;
  int Cylinder, Track, Phy_Address;
  if (Judge_Order()) {
    if (Order == NULL) {        //����ͷ�ڵ�
      Table_For_Head = new IO_Table("Head", 0, 0, 0);
      Order = new Queue(Table_For_Head, NULL, NULL);
    }
    cout << "��������� ���� �ŵ� ��ַ��" << endl;
    cin >> Name;
    cin >> Cylinder >> Track >> Phy_Address;
    Table = new IO_Table(Name, Cylinder, Track, Phy_Address);    //����IO��
    Insert.Data = Table;                                         //��������ڵ�
    Order->Insert(Order->ReturnLength(), &Insert);                   //����ڵ�
  }
}
void Run_Driven() {
  Queue *Tmp_For_Delete;
  Node *Tmp = NULL;
  int position = 0;   //���ڶ�λɾ��
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
      Accept_Order();
    }
    cout << "Run off the process" << endl;
    if (!Judge_Order())
      break;
  }
}