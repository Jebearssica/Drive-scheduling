#pragma once
#include<string>
const int CYLINDERMAX = 200;
const int TRACKMAX = 20;
class IO_Table
{
private:
  std::string Process_Name;
  int Cylinder_Number;
  int Track_Number;
  int Physical_Number;
public:
  IO_Table();
  ~IO_Table();
};

