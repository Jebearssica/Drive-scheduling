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
    std::cout << "错误地址" << std::endl;
    return;
  }
  else {
    for (int i = 0; i < position; i++) {    //寻址
      tmp = tmp->Next;
    }
    if (insert == NULL) {      //Node tmp == NULL 则为删除缩在位置的节点
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

Queue::Queue(IO_Table *a, Node *b, Node *c) {    //构造函数
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
