#include <iostream>
#include <string.h>
using namespace std;

class String {
  public:
    String() {
      cout << "String() : " << this << endl;
      strData = NULL;
      len = 0;
    }

    String(const char *str) {
      cout << "String(const char*) : " << this << endl;
      len = strlen(str);
      alloc(len);
      strcpy(strData, str);
    }

    String(const String &rhs) {
      cout << "String(const String&) : " << this << endl;
      len = rhs.len;
      alloc(len);
      strcpy(strData, rhs.strData);
    }

    ~String() {
      cout << "~String() : " << this << endl;
      release();
      strData = NULL;
    }

    String &operator=(const String &rhs) {
      cout << "String &operator=(const String&) : " << this << endl;
      if (this != &rhs) {
        release();
        len = rhs.len;
        alloc(len);
        strcpy(strData, rhs.strData);
      }
      return *this;
    }

    const char *GetStrData() const {
      return strData;
    }
    int GetLen() const {
      return len;
    }

  private:
    void alloc(int len) {
      strData = new char[len + 1];
      cout << "strData 할당됨 : " << (void*)strData << endl; 
    }

    void release() {
      if (strData) cout << "strData 해제됨 : " << (void*)strData << endl;
      delete[] strData;
    }

    char *strData;
    int len;
};

String getName() {
  cout << "======= 2 =======" << endl;
  String res("Doodle");
  cout << "======= 3 =======" << endl;
  return res;
}

int main() {
  String a;
  cout << "======= 1 =======" << endl;
  a = getName();
  cout << "======= 4 =======" << endl;
}