#pragma once
#include"IO_Table.h"
struct Node {
  IO_Table *Data;
  Node *Front;
  Node *Next;
};
class Queue {
private:
  Node * Root;               //ͷָ��
public:
  int ReturnLength();
  void Insert(int position, Node *insert);
  Queue();
  Queue(IO_Table *a, Node *b, Node *c);  //���캯��
  ~Queue();
};




