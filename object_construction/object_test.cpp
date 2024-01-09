// Part two

//header file with class
#include <iostream>

class DynArray {

public:
  DynArray() : ptr(0), cap(0) {};
  DynArray(int);
  ~DynArray();
  DynArray(const DynArray&); //copy
  DynArray& operator=(DynArray);
  void swap(DynArray&);

private:
  int* ptr;
  int cap;
  
};

//=================================================

//function implementations

DynArray::DynArray(int num){
  std::cout << "Called int constructor" << std::endl;
  if (num < 0) return;
  cap = num;
  ptr = new int[cap];
}

DynArray::~DynArray(){
  std::cout << "Called destructor" << std::endl;
  delete[] ptr;
}

DynArray::DynArray(const DynArray& original){
  std::cout << "Called copy constructor" << std::endl;
  cap = original.cap;
  ptr = new int[cap];
  for (int i = 0; i < cap; ++i)
    ptr[i] = original.ptr[i];
}

DynArray& DynArray::operator=(DynArray rhs){
  std::cout << "Called assignment operator" << std::endl;
  swap(rhs);
  return *this;
}

void DynArray::swap(DynArray& rhs){
  int* temp = ptr;
  ptr = rhs.ptr;
  rhs.ptr = temp;
  int ctemp = cap;
  cap = rhs.cap;
  rhs.cap = ctemp;
}

//====================================================

//int main
int main(){
  DynArray two(21);
  DynArray three(2);
  
  DynArray one(two);
  three = two;
}
