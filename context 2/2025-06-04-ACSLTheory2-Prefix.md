---

Team: Team 2

Author: Kim Mugyeol

Title: Prefix

---

<!--
    1. 문제 / 풀이 포함 할 것. 
-->
# Prefix
## Prefix Expressions (Polish Notation)
Prefix는 Polish notation으로도 알려져 있다, 그리고 이 표기법은 부호와 연산자가 앞으로 간다다. 이 표기법은 부호가 중간에 들어가는 일반 표기법과 다르다.

Prefix Expression에서는 연산자가 먼저 쓰이고, 그 뒤에 피연산자가 옵니다. 예를 들어, 중위 표현식 $a+b$는 접두사 표기법으로 $+ab$로 작성된다.

## Evaluating Prefix Expressions
Prefix Expression을 평가하는 것은 중첩 괄호가 많거나 스택 기반 프로그래밍 언어를 사용할 때와 같은 특정 상황에서 유용할 수 있다.
## Advantage & Disadvatage
### Advantages of Prefix Expressions
괄호는 필요 없으며, 연산자가 항상 피연산자보다 앞에 위치한다. 스택 기반 알고리즘을 사용하면 구문 분석 및 평가가 더 쉽다. 중첩된 괄호가 많은 표현을 다룰 때와 같이 특정 상황에서 더 효율적일 수 있다.
### Disadvantages of Prefix Expressions
사람이 읽고 이해하기 어려울 수 있다. 삽입 표기법만큼 일반적으로 사용되지 않다.
## Prefix to Infix
다음 단계의 순서는 __(3∗4 82)(7−5)__ 를 Prefix에서 Infix로 바꾸는 과정을을 보여준다:


$↑ + * 3 4 / 8 2 – 7 5$

$↑ + (3*4) / 8 2 – 7 5$

$↑ + (3*4) (8/2) – 7 5$

$↑ (3*4)+(8/2) - 7 5$

$↑ ((3*4)+(8/2)) (7-5)$

$(((3*4)+(8/2))↑(7-5))$