#include "IO_Table.h"

void IO_Table::Print_Table(bool direction) {
  std::cout << std::setw(7) << this->Process_Name <<
    std::setw(3) << this->Cylinder_Number <<
    std::setw(3) << this->Physical_Number;
  if (direction)
    std::cout << "Àï" << std::endl;
  else
    std::cout << "Íâ" << std::endl;
}

int IO_Table::Return_Cylinder() {
  return this->Cylinder_Number;
}

int IO_Table::Return_Track() {
  return this->Track_Number;
}
IO_Table::IO_Table()
{
}

IO_Table::IO_Table(std::string name, int cylinder, int track, int phy) {
  this->Process_Name = name;
  this->Cylinder_Number = cylinder;
  this->Track_Number = track;
  this->Physical_Number = phy;
}

IO_Table::~IO_Table()
{
}
