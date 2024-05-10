
# std 

* std::cout << "출력할 내용"
```
int main(){
    std::cout<< "Hello World";
    return 0;
}

//출력

Hello World
```


_<< :: 스트림 삽입 연선자 (stream insertion operator)_   


> ostream 클래스에 구현됨
* std::cin>>"입력받을 내용"
```
int main(){
    int a;
    std::cout << "출력할 정수 = " << std::endl;
    std::cin >> a;
    std::cout << a;
    return 0;
}

//출력
출력할 정수 = ${\textsf{\color{green}6}}$
6

```


* 입력 버퍼 내장
* **Enter** 키가 입력될 때까지 입력된 키를 입력 버퍼에 저장
_\>> :: 스트림 추출 연선자 (stream extraction operator)_   
> iostream 헤더파일에 스트림 추출 연산자로 재정의됨



# namespace

* ##### 이름(*identifier*) 충돌이 발생하는 경우
   * 여러 명이 프로젝트를 개발하는 경우    
   **->** 해결하는데 많은 시간 소요   



* ##### *namespace* 키워드
   * 2003년 새로운 *ANSI* C++ 표준에서 도입
   * 개발자가 자신만의 이름 공간 생성 가능   
  


```
#include <iostream>

using namespace std; // std 안 붙여도 사용 가능

int main(){
    int a;
    cout << "출력할 정수 = " << endl;
    cin >> a;
    cout << a;
    return 0;
} 
```   
 
  

```
namespace kitae{ //kitae 라는 이름 공간 생성
// 이 곳에 선언된 모든 이름은 kitae 이름 공간에 생성된 이름
}
```

```
namespace mike {
    int f();
    int g();
}


#include "mike.h"

namespace kitae{
    int f();
    void m();
}

void m() {
        f();
        mike::f();
    }

```

* ##### std   
    ANSI C++표준에서 정의한 이름공간 중 하나

# 문자열
* ##### 문자열 표현 방식 2가지
   *  **\0** 로 끝나는 문자 배열
   ```
   char name[6]={'G','r','a','c','e','\0'};
   ``` 
   * **\<string>** 클래스 이용   
    ```
    #include <cstring> or
    #include <string.h>

    int n = strlen("hello");
    ```   
    * \<cstring>이 더 바람직   




* 문자열 입력
```
#include <iostream>
#include <cstring> // strcmp 함수 사용
using namespace std;

int main() {
    char password[11];
    cout << "프로그램을 종료하려면 암호를 입력하세요." << endl;
    while(true) {
        cout << "암호>>";
        cin >> password;
        if(strcmp(password, "C++") == 0) {
            cout << "프로그램을 정상 종료합니다." << endl;
            break;
        }
        else 
            cout << "암호가 틀립니다~~" << endl;
    }
}

출력

프로그램을 종료하려면 암호를 입력하세요.
암호>>${\textsf{\color{green}Java}}$
암호가 틀립니다~~
암호>>${\textsf{\color{green}C}}$
암호가 틀립니다~~
암호>>${\textsf{\color{green}C++}}$
프로그램을 정상 종료합니다.
```


* ##### **cin.getline()**
  * cin.getline(char buf[],int size,char delimitChar)
  * buf에 최대 size-1개의 문자입력
  * delimitChar 만나면 입력 중단 (디폴트는 Enter)
```
#include <iostream>
using namespace std;

int main() {
    cout << "주소를 입력하세요>>";

    char address[100]; 
    cin.getline(address, 100, '\n'); // 키보드로부터 주소 읽기

    cout << "주소는 " << address << "입니다\n"; // 주소 출력
}

출력

주소를 입력하세요>>${\textsf{\color{green}컴퓨터시 프로그램구 C++동 스트링 1-1}}$
주소는 컴퓨터시 프로그램구 C++동 스트링 1-1입니다

```

* ##### string 클래스
  * C++ 표준 클래스
  * 문자열의 크기에 따른 제약 X
  * **객체 지향적**
  * #inclue\<string> 


```
#include <iostream>
#include <string> 
using namespace std;

int main() {
    string song("Falling in love with you"); // 문자열 song
    string elvis("Elvis Presley"); // 문자열 elvis
    string singer; // 문자열 singer

    cout << song + "를 부른 가수는"; // + 로 문자열 연결
    cout << "(힌트 : 첫글자는 " << elvis[0] << ")?";  // [] 연산자 사용

    getline(cin, singer); // 문자열 입력
    if(singer == elvis)  // 문자열 비교
            cout << "맞았습니다.";
    else
            cout << "틀렸습니다. "+ elvis + "입니다." << endl; // +로 문자열 연결
}

출력
Falling in love with you를 부른 가수는(힌트 : 첫글자는 E)?${\textsf{\color{green}Elvis Pride}}$Elvis Pride
틀렸습니다. Elvis Presley입니다.

```
