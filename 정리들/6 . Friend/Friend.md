
## Friend
* 프렌드 함수
  * 전역 함수
  * 다른 클래스의 멤버 함수
  * 클래스의 모든 멤버를 접근할 수 있음
* 프렌드 선언 종류 3가지
  * 외부 함수를 Rect 클래스에 프렌드로 선언
```
class Rect { // Rect 클래스 선언
  ...
  friend bool equals(Rect r, Rect s);
};
```
  * 다른 클래스에 멤버 함수를 프렌드로 선언 
```
class Rect {
  .............
  friend bool RectManager::equals(Rect r, Rect s);
};
```

*  모든 멤버 함수를 다른 클래스에 프렌드로 선언  
```
class Rect {
  .............
  friend RectManager; 
};

```

