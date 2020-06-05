#include <iostream>

using namespace std;

class Father {
public:
  Father(void) {
    cout << "Father" << endl;
  }

  ~Father() {
    cout << "~Father" << endl;
  }
};

class Sun : public Father{
public:
  Sun(void) {
    cout << "Sun" << endl;
  }

  ~Sun() {
    cout << "~Sun" << endl;
  }
};

class Father2 {
public:
  Father2(void) {
    cout << "Father2" << endl;
  }

  virtual ~Father2() {
    cout << "~Father2" << endl;
  }
};

class Sun2 : public Father2{
public:
  Sun2(void) {
    cout << "Sun2" << endl;
  }

  virtual ~Sun2() {
    cout << "~Sun2" << endl;
  }
};

int main(void)
{
  Sun sun;
  cout << "sun..........................." << endl;
  Father *father = new Sun;
  delete father;
  cout << "father..........................." << endl;

  Sun2 *sun2 = new Sun2;
  delete sun2;
  cout << "Sun2..........................." << endl;

  Father2 *father2 = new Sun2;
  delete father2;
  cout << "father2..........................." << endl;

  return 0;
}
