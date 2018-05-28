#pragma once
#include"IO_Table.h"
struct Node {
  IO_Table *Data;
  Node *Front;
  Node *Next;
  Node(IO_Table *data) {
    this->Data = data;
  }
  Node();
};
class Queue {
private:
  Node * Root;               //头指针
public:
  int ReturnLength();
  void Insert(int position, Node *insert);
  Node* Select_By_Cylinder(int Small, int Cylinder);
  Node* Select_By_Track(int Track);
  bool Judge_For_MaxMin(int Small, int Cylinder);
  int Return_Cylinder();
  void Delete_Node(Node *Delete);
  Queue();
  Queue(IO_Table *a, Node *b, Node *c);  //构造函数
  ~Queue();
};




