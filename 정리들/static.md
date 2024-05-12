## static
##### static
* 변수와 함수에 대한 기억 부류의 한 종류
  * 프로그램 시작될 때 생성, 종료 시 소멸
* static 멤버
  * 똑같이 **프로그램 시작 시 생성**
  * **클래스 당 하나만** 생성
  * 클래스의 **모든 객체들이 공유**하는 멤버
* noon-statice 멤버
  * **객체가 생성될 때** 생성
  * 객체마다 **객체 내에** 생성
  * 인스턴스 멤버라고도 불림
* static 멤버 선언
* (변수타입) (클래스)::(변수 이름) = (초기화);
```
class Person {
public:
  double money; // 개인 소유의 돈
  void addMoney(int money) {
    this->money += money;
  }

  static int sharedMoney; // 공금
  static void addShared(int n) {
    sharedMoney += n;
  }
};

int Person::sharedMoney = 10; // sharedMoney를 10으로 초기화

```
* 주의사항
  * static 멤버 함수는 non-statice 멤버에 접근 불가
  * non-static 함수는 모두 접근 가능
```
class Person { 
  public: double money; // 개인 소유의 돈 
  static int sharedMoney; // 공금
   .... 
  int total() { // non-static 함수는 non-static이나 static 멤버에 모두 접근 가능 
    return money + sharedMoney; 
  }
 }; 
```
