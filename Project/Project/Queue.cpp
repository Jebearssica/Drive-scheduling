#include "Queue.h"

int Queue::ReturnLength() {
  int count = 1;
  Node *tmp = this->Root;
  while (tmp->Next != NULL) {
    tmp = tmp->Next;
    count++;
  }
  return count;
}
void Queue::Insert(int position, Node *insert) {
  Node *tmp = this->Root;
  if (position > this->ReturnLength() || position < 0) {
    std::cout << "�����ַ" << std::endl;
    return;
  }
  else {
    for (int i = 0; i < position; i++) {    //Ѱַ
      tmp = tmp->Next;
    }
    if (insert == NULL) {      //Node tmp == NULL ��Ϊɾ������λ�õĽڵ�
      tmp->Front = tmp->Next;
      delete tmp->Data;
    }
    else {
      tmp->Next->Front = insert;
      insert->Next = tmp->Next->Front;
      tmp->Next = insert;
      insert->Front = tmp;
    }
    return;
  }
}

Node* Queue::Select_By_Cylinder(int Small, int Cylinder) {
  int minus = 0, sum = INT16_MAX;
  Node *tmp = this->Root;
  Node *result = NULL;
  //����������̵�
  //���Ʋ���Small 1��С��������� -1������������С
  while (tmp->Next) {
    minus = Small * (tmp->Data->Return_Cylinder() - Cylinder);
    if (minus > 0) {
      continue;
    }
    else {
      if (sum > abs(minus)) {
        sum = abs(minus);
        result = new Node();
        result = tmp;
      }
    }
    tmp = tmp->Next;
  }
  return result;
}

Node* Queue::Select_By_Track(int Track) {
  Node *tmp = this->Root;
  Node *Result = NULL;
  int minus = INT16_MAX;
  while (tmp) {
    if (minus > abs(Track - tmp->Data->Return_Track())) {
      minus = abs(Track - tmp->Data->Return_Track());
      Result = new Node();
      Result = tmp;
    }
    tmp = tmp->Next;
  }
  return Result;
}

//����true ������ڴ��ڻ�С�ڵ� false ������
// ͬ��small 1��С��������� - 1������������С
bool Queue::Judge_For_MaxMin(int Small, int Cylinder) {
  Node *tmp = this->Root;
  while (tmp) {
    if (Small*(Cylinder - tmp->Data->Return_Cylinder()) > 0) {
      return true;
    }
    else {
      tmp = tmp->Next;
    }
  }
  return false;
}

int Queue::Return_Cylinder() {
  return this->Root->Data->Return_Cylinder();
}

void Queue::Delete_Node(Node *Delete) {
  Node *tmp = this->Root;
  while (tmp) {
    if (tmp == Delete) {
      tmp->Front->Next = tmp->Next;
      tmp->Next->Front = tmp->Front;
      delete tmp->Data;
      tmp = NULL;
    }
    else {
      tmp = tmp->Next;
    }
  }
}

Queue::Queue(IO_Table *a, Node *b, Node *c) {    //���캯��
  this->Root->Data = a;
  this->Root->Front = b;
  this->Root->Next = c;
}

Queue::Queue()
{
}


Queue::~Queue()
{
}
