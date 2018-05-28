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
      delete tmp;
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
