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
  //搜索距离最短的
  //控制参数Small 1：小于中搜最大 -1：大于中搜最小
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

//返回true 代表存在大于或小于的 false 不存在
// 同理small 1：小于中搜最大 - 1：大于中搜最小
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
