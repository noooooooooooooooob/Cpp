## 함수 오버라이딩(overriding)
* ##### 가상 함수(virtual function)
  * virtual 키워드로 선언된 함수
  * 동적 바인딩 지시어
    ```
    class Base {
    public:
      virtual void f(); // f()는 가상 함수
    };
    
    ```
* ##### 함수 오버라이딩(function overriding)
  * 파생 클래스에서 기본 클래스의 가상 함수와 **동일한** 이름의 함수 선언
  * 함수 재정의 라고도 함
  * **다형성**의 한 종류
* ##### 동적 바인딩
  * 기본 클래스에 대한 포인터로 가상 함수 호출
    ```
    #include <iostream>
    using namespace std;
    
    class Shape {
    public:
      void paint() { 
        draw(); 
      }
      virtual void draw() { 
        cout << "Shape::draw() called" << endl; 
      }
    };
    
    class Circle : public Shape {
    public:
      virtual void draw() { 
        cout << "Circle::draw() called" << endl;
      }
    };
    
    int main() {
      Shape *pShape = new Circle(); // 업캐스팅
      pShape->paint(); 
      delete pShape; 
    }
    // Circle::draw called
    ```
  
  * 오버라이딩의 조건
    * 함수 이름, 매개변수 타입과 개수, 리턴 타입 일치
* 범위 지정 연산자( :: )
  ```
  class Shape {
  public:
    virtual void draw() { 
      ...
    }
  };
  
  class Circle : public Shape {
  public:
    virtual void draw() { 
      Shape::draw(); // 기본 클래스의 draw()를 실행한다.
        .... // 기능을 추가한다.
    }
  };
  ```
* #### 가상 소멸자
  * 소멸자를 virtual 키워드로 선언
  * 소멸자 호출 시 동적 바인딩 발생
* #### 순수 가상 함수(pure virtual function)
  * 함수의 **코드가 없고 선언만 있는** 가상 멤버 함수
  ```
  class Shape {
  public:
    virtual void draw()=0; // 순수 가상 함수 선언
  };
  ```
* 추상 클래스
  * **최소 하나의 순수 가상 함수**를 가진 클래스
  * 온전한 클래스가 아니므로 **객체 생성 불가능**
  *  포인터는 선언 가능
  * 상속에서 기본 클래스의 역할을 하기 위함
  * 추상 클래스를 단순 상속 시 자동 추상 클래스
  * 순수 가상 함수를 오버라이딩 시 추상 클래스가 아님
```
class Shape {
public:
  virtual void draw() = 0;
};

class Circle : public Shape {  // 추상 클래스
public:
  string toString() { return "Circle 객체"; }
};

class Rect : public Shape {  // 추상 클래스 아님 
public:
  virtual void draw() {
    cout << "Rect";
  }
  string toString() { return "Rect 객체"; }
};

```
