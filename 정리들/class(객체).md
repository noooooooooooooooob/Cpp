# 연산자
*  ?
> (a>b)?a:b
>  a > b -> **a**
>  a <= b -> **b**

# 객체

 * #### 캡슐화(encapsulation)
   * 객체의 본질적인 특성 &nbsp;&nbsp;&nbsp; **ex)** 캡슐, 리모컨, 냉장고....etc
   * 외부와의 인터페이스를 위해 객체의 일부분 공개
* #### 클래스
  * 객체를 만들어내기 위해 정의된 설계도
  * 클래스는 **객체 아님**
  * 하나의 클래스 틀로 여러개의 객체 생성 가능


* ###### 클래스 작성
  * 멤버변수 & 멤버 함수
  * 클래스 선언부 & 클래스 구현부
  * ###### 클래스 선언부
     * 멤버변수 & 멤버함수 선언
       * 멤버 변수는 초기화 불가능
    * 멤버에 대한 접근 권한
      * private, public, protected 중 하나
      * 디폴트는 private
```
#include <iostream> 
using namespace std; 

class Circle {
public:
    int radius; 
    double getArea(); 
}; 

double Circle::getArea() {
    return 3.14*radius*radius;
}

int main() {
    Circle donut; 
    donut.radius = 1; // donut 객체의 반지름을 1로 설정
    double area = donut.getArea(); // donut 객체의 면적 알아내기
    cout << "donut 면적은 " << area << endl;

    Circle pizza; 
    pizza.radius = 30; // pizza 객체의 반지름을 30으로 설정
    area = pizza.getArea(); // pizza 객체의 면적 알아내기
    cout << "pizza 면적은 " << area << endl;
}
```

* 객체 이름 및 객체 생성   
```
Circle donut; //이름이 donut인 Circle 객체 생성
```
* 객체의 멤버 변수 접근
```
donut.radius = 1;// donut의 radius 값을 1로 설정
```
* 객체의 멤버 함수 접근
```
double area = donut.getArea();//donut 객체의 getArea 불러오기
```
* ##### 생성자
  * 객체가 생성되는 시점에 자동으로 호출되는 멤버 함수
  * 클래스 이름과 동일한 멤버함수
  * **리턴 타입 X**
  ```
  class Circle{
    Circle();
    Circle(int r);
  }
  ```
  * 객체가 필요한 초기화를 위해 존재
  * 객체 생성 시 **오직 한 번만** 호출
  * 생성자는 **중복 가능**
* ##### 소멸자
  * 객체가 **소멸되는 시점**에 자동으로 호출되는 함수
  * **오직 한 번만** 자동 호출, **임의 호출 X**
  * 객체 메모리 소멸 직전 호출됨
```
  class Circle{
    Circle();
    Circle(int r);
    ...
    ...
    ~Circle();
  }
```
  * 리턴 타입 X
  * **중복 불가능**
  * 매개변수 X
  ```
  class Circle {
  public:
    int radius; 
    Circle(); 
    Circle(int r); 
    ~Circle(); 
    double getArea(); 
  }; 
  
  Circle globalDonut(1000);
  Circle globalPizza(2000);
  
  void f() {
    Circle fDonut(100);
    Circle fPizza(200);
  }
  
  int main() {
    Circle mainDonut;
    Circle mainPizza(30);
    f();
  }
  
  출력
  반지름 1000 원 생성
  반지름 2000 원 생성
  반지름 1 원 생성
  반지름 30 원 생성
  반지름 100 원 생성
  반지름 200 원 생성
  반지름 200 원 소멸
  반지름 100 원 소멸
  반지름 30 원 소멸
  반지름 1 원 소멸
  반지름 2000 원 소멸
  반지름 1000 원 소멸
  ```

  전역 -> 지역 -> 함수

  * ##### 접근 지정자 (private, public, protected)
    *  목적
       *  멤버 변수에 대한 보호
       *  다른 클래스나 객체에서 접근할 수 없도록 보호
       *  일부 멤버는 외부에 접근 허용 
    * private
      * 동일한 클래스의 멤버 함수에만 제한
      * donut.radius=5; -> 불가능 
      * 멤버변수에 추천
    * public
      * 모든 곳에서 접근 가능
      * 되도록 추천 X
    * protected
      * 클래스 자신과 상속받은 자식 클래스만 허용
  * ##### 헤더 파일 (.h)
    * 클래스마다 분리 저장 가능
    * 클래스 선언부
      * 헤더파일(.h)
    * 클래스 구현부
      * cpp 파일에 저장
      * 헤더파일 include 필요
  * 클래스 중복 해결
  ```
  #ifndef CIRCLE_H
  #define CIRCLE_H
  
  class Circle {
  private:
    int radius;
  public:
    Circle(); 
    Circle(int r); 
    double getArea();
  }; 
  
  #endif
  
  ...
  ...
  ...
  
  #include <iostream> 
  using namespace std; 
  
  #include "Circle.h"
  #include "Circle.h" // 컴파일 오류 없음
  #include "Circle.h"
  
  int main() {
    ...........
  }
  
  ```

  * ##### 객체 포인터
```
class Circle {
    int radius; 
public:
    Circle() {	radius = 1; }
    Circle(int r)  { radius = r; }
    double getArea(); 
}; 

double Circle::getArea() {
    return 3.14*radius*radius;
}


...
...


int main() {
    Circle donut;

    // 객체 이름으로 멤버 접근
    cout << donut.getArea() << endl;

    // 객체 포인터로 멤버 접근
    Circle *p;
    p = &donut;
}

```
  *  ###### 객체 배열
     *  Circle c[3];
     *  **매개 변수가 없는 생성자 호출**
     *  배열의 반대 순서로 소멸
     ```
     int main() {
        Circle circleArray[3]; 										// (1) Circle 객체 배열 생성
     
        // 배열의 각 원소 객체의 멤버 접근
        circleArray[0].setRadius(10); 							// (2)
        circleArray[1].setRadius(20);
        circleArray[2].setRadius(30);
     }
         Circle *p; 															// (3)
        p = circleArray; 												// (4)
        for(int i=0; i<3; i++) { 	// 객체 포인터로 배열 접근
            cout << "Circle " << i << "의 면적은 " << p->getArea() << endl;
            p++; 															// (5)
        }
     
     ```  

* 객체 배열 초기화
  * 각 원소마다 생성자 지정
    ```
    Circle circleArray[3] = { Circle(10), Circle(20), Circle() }; 
    
    ```
#### this 포인터
*  객체 자신 포인터
*  **멤버 함수 내에서만** 사용 가능
   ```
   class Sample {
   public:
    Sample* f() {
      ....
      return this; // 자기 자신을 리턴
    }
   };
   ``` 
*  **static** 멤버 함수에서 사용 불가
