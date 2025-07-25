#include <iostream>
#include <string.h>
using namespace std;

class String {
  public:
    String() {
      strData = NULL;
      len = 0;
    }

    String(const char *str) {
      len = strlen(str);
      strData = new char[len + 1];
      strcpy(strData, str);
    }

    String(const String &rhs) {
      len = rhs.len;
      strData = new char[len + 1];
      strcpy(strData, rhs.strData);
    }

    ~String() {
      if (strData) {
        delete[] strData;
      }
    }

    String &operator=(const String &rhs) {
      if (this != &rhs) {
        len = rhs.len;
        delete[] strData;
        strData = new char[len + 1];
        strcpy(strData, rhs.strData);
      }
      return *this;
    }

    const char *GetStrData() const {
      if (strData) return strData;
      return "";
    }
    int GetLen() const {
      return len;
    }

  private:
    char *strData;
    int len;
};

String getName() {
  String res("Doodle");
  return res;
}

int main() {
  String a;
  a = getName();
  cout << a.GetStrData() << endl;
}