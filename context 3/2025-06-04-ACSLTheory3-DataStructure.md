---
Team : Theory3
Author : 윤지환
Title : Deta Structure
---

<!--
    1. 존댓말 말고 평어체 사용할 것.
    2. 각 data structure의 그림 활용할 것. 
    3. format BooleanAlgebra.md 와 맞출 것. 
-->

# Data Structure
Deta Structure는 말 그대로 데이터를 저장하고, 사용하기 위해 만들어진 이론입니다.
## Stack
```
스택은 PUSH와 POP라는 두 가지 명령을 포함합니다. PUSH("A") 형식의 명령은 "A" 항목를 스택의 맨 위에 놓습니다. "X = POP()" 명령은 스택에서 맨 위의 항목을 제거하고 그 값을 변수 X에 저장합니다.
```
## Queue
```
항목이 맨 위가 아닌 맨 아래에서 제거되는 것을 빼면 큐는 스택처럼 작동합니다. PUSH("A") 형식의 명령은 "A" 키를 큐 맨 위에에 놓습니다. "X = POP()" 명령은 큐 맨 아래에서 항목을 제거하고 그 값을 변수 X에 저장합니다.
```
## Binary Tree
```
Tree에서는 다음과 같은 용어들을 이해해야합니다. 
먼저 Node는 저 정보 하나하나를 의미합니다. 
Root는 Tree의 맨 위 Node입니다. 여기서는 A가 Root입니다. 
Child Node는 Parent Node 바로 아래로 연결되어 있는 Node입니다. 
Leaf Node는 Tree의 모든 가지에서 가장 낮은 노드입니다. 
Siblings는 같은 부모를 가진 Node입니다.

Binary Tree는 세 부분으로 구성된 Node로 구성됩니다
정보 
Left Child Node과의 연결
Right Child Node과의 연결 
모든 Node의 정보는 항상 Left Child Node의 정보보다 크거나 같고 Right Child Node의 정보보다는 작다는 규칙을 가지고 있다.

    그러므로, 정교한 알고리즘을 통해 균형 잡힌 Tree를 유지할 수 있다.
Binary Tree는 어떤 순서로든 많은 작업을 지원할 수 있고 필요에 따라 노드를 도입하거나 제거할 수 있는 "동적" 데이터 구조입니다.
```
#