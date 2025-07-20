#include <iostream>
using namespace std;

int main() {
  /**
   * 얕은 복사
   * 메모리 주소를 복사하고 두 포인터는 같은 주소를 가리킴
   * "참조만 복사되었다"
   */
  // int *a = new int(3);
  // int *b = a;
  // *a = 5;
  // cout << "a: " << *a << endl;
  // cout << "b: " << *b << endl;

  // delete a;
  // 이후 b를 사용하게되면 b는 삭제된 a를 가리키고있기 때문에 dangling pointer가 됨

  /**
   * 깊은 복사
   * 새로운 공간을 가리키고 해당 포인터의 값만 복사
   */
  int *a = new int(3);
  int *b = new int(*a);
  *a = 5;

  cout << "a: " << *a << endl;
  cout << "b: " << *b << endl;

  delete a;
  delete b;
}