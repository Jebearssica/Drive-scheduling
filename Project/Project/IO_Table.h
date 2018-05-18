#pragma once
#include<string>
#include<iostream>
#include<iomanip>
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
  void Print_Table(bool direction);
  int Return_Cylinder();
  IO_Table();
  IO_Table(std::string name, int cylinder, int track, int phy);
  ~IO_Table();
};

