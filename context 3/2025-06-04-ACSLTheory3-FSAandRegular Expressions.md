---

Team: Problom Solving3

Author: Philip

Title: FSAs and Regular Expressions

---

<!--
    1. Images 첨부팔 것. 
    2. 예시문제 풀이 포함시킬 것. 
-->

# Theory 설명
## FSA (Finite State Automaton)가 무었인가?
Finite State Machine (FSM)이라는 이름으로도 불리는다. 주어진 시간에 유한한 수의 상태 중 하나에 있을 수 있는 기계인데, FSA은 일부 입력에 대한 응답으로 한 상태에서 다른 상태로 변경될 수 있다. 이러한 변경을 전환이라고 한다.
겼을까?
## FSA는 왜 생겼을까?
쉬운 개념의 적립, 각상태와 형태가 코드가 아닌 도표로 나타내면서 AI의 개념을 프로그래머 이외에 기획자 또는 제 3자가 쉽게 확인,설계가 가능할 수 있기 때문이다. 
그리고 정해진 룰이 있기때문에 프로그래머입장에서 코딩을 하면서 조금더 안전성이 높은 코드를 만들어낼수 있다.그리고 각각의 상태는 나뉘어져있기때문에 새로운 상태의 추가 삭제가 용의하다.
## FSA는 어느 곳에 사용할까?
컴퓨터 프로그램과 순차 논리 회로를 설계하는 데 사용되는 수학적 모델이다.



# Basics: FSAs(Finite State Automaton)와 RE(Regular Expressions)의 이론

<p>
아래는 x와 y로 구성된 문자열을 만드는데에 사용되는 FSA의 그림이다.
</p>

![alt text](image-2.png)

<p>
위의 FSA에는 세 개의 상태가 있다: A, B, C. 초기 상태는 A이고 최종 상태는 C이다. 상태 A에서 B로 이동하는 유일한 방법은 <i>x</i>를 <i>보는 것</i>입니다. B 상태에 도착하면 두 가지 이동방법이 있다: y 문자를 보면 FSA는 C로 갈 수 있도록 만들고, x 문자를 보면 B로 돌아갈 수 있다. 상태 C는 최종 상태이므로, 문자열 입력이 완료되고 FSA가 C에 있으면 입력 문자열은 FSA에 의해 <i>수용되었다</i>고 한다. 상태 C에서 추가로 y 문자를 보게 되면 기계는 상태 C에 남아 있다. 위의 FSA는 하나 이상의 x 다음에 하나 이상의 y로 구성된 문자열(예: xy, xxy, xxxyy, xyyy, xxyyyy)을 수용한다.
</p>

<p>
Regular Expression(RE)은 FSA의 대수적 표현이다. 예를 들어, 위에 주어진 첫 번째 FSA에 해당하는 Regular Expression은 xx*yy*이다.
</p>

<p>
Regular Expression은 아래의 규칙들을 따른다.
</p>
<dd>1.널 문자열(λ)은 Regular Expression이다다.</dd>
<dd>2. input에 문자열 a가 포함되어 있다면, 그것은 Regular Expression이다.</dd>
<dd>3. 만약 a와 b가 모두 Regular Expression이라면 아래 규칙을 따르는 Regular Expression이 된다.
<dl><dd>a. CONCATENATION. "ab" (a와 b를 연결).</dd>
<dd>b. UNION. "aUb" 혹은 "a|b" (a 혹은 b).</dd>
<dd>c. CLOSURE. "a*" (a를 0번 이상 반복). 그냥 Kleene Star라고도 부른다.</dd></dl></dd></dl>

<p>
Regular Expression의 우선순위는 다음과 같다: Kleene Star, concatenation, 그리고 union. 수학과 마찬가지로 괄호를 사용하여 하위 표현식을 그룹화할 수 있다. 예를 들어, "dca*b"는 문자열 dcb, dcab, dcaab 등을 생성하는 반면, "d(ca)*b"는 문자열 db, dcab, dcacab, dcacacab 등을 생성할 수 있다.
</p>

<p>
Regular Expression이 있으면, 기계적으로 해당 Regular Expression이 생성하는 문자열을 수용하는 FSA를 구축할 수 있다. 반대로, FSA가 있다면, 우리는 FSA가 구문 분석할 수 있는 문자열을 설명하는 Regular Expression을 개발할 수 있다.
</p>

## Regular Expression Identities

<table class="wikitable">

<tbody><tr>
<td>Regular Expression에서 
그냥 공식처럼 외우면 쓸 수 있는 것들
</td></tr>
<td>1.  (a*)*  = a*
</td></tr>
<tr>
<td>2.  aa*    = a*a
</td></tr>
<tr>
<td>3.  aa* U λ  = a*
</td></tr>
<tr>
<td>4.  a(b U c) = ab U ac
</td></tr>
<tr>
<td>5.  a(ba)* = (ab)*a
</td></tr>
<tr>
<td>6.  (a U b)* = (a* U b*)*
</td></tr>
<tr>
<td>7.  (a U b)* = (a*b*)*
</td></tr>
<tr>
<td>8.  (a U b)* = a*(ba*)*
</td></tr></tbody></table>

## RegEx in Practice

<table class="wikitable" style="text-align: left">

<tbody><tr>
<th>Pattern
</th>
<th>Description
</th></tr>
<tr>
<th>|
</th>
<td>|는 or의 역할을 한다.  예를 들어, gray|grey는 "gray" 또는 "grey"로 사용할 수 있다.
</td></tr>
<tr>
<th>*
</th>
<td>별표는 앞의 요소가 0개 이상 반복됨을 나타낸낸다. 예를 들어, ab*c는 "ac", "abc", "abbc", "abbbc" 등으로 사용할 수 있다다.
</td></tr>
<tr>
<th>?
</th>
<td>물음표는 앞의 요소가 0개 또는 1개만 나타남을 나타낸다. 예를 들어, colou?r는 "color"와 "colour" 로 사용할 수 있다.
</td></tr>
<tr>
<th>+
</th>
<td>더하기 기호는 앞의 요소가 한 번 이상 나타남을 나타낸다. 예를 들어, ab+c는 "abc", "abbc", "abbbc" 등과 일치하지만 "ac"와는 일치하지 않는다.
</td></tr>
<tr>
<th>.
</th>
<td>그냥 조커카드다. .는 모든 문자로 사용할 수 있다. 예를 들어, a.b는 "a" 다음에 다른 문자, 그리고 "b"가 포함된 문자열(예: "a7b", "a&amp;b", "arb")과 일치하지만 "abbb"는 일치하지 않는다. 따라서 a.*b는 "a"와 "b" 사이에 0개 이상의 문자가 포함된 문자열과 일치합니다. 여기에는 "ab", "acb", "a123456789b"가 포함됩니다.
</td></tr>
<tr>
<th>[ ]
</th>
<td>대괄호는 대괄호 안에 포함된 단일 문자와 일치한다. 예를 들어 [abc]는 "a", "b" 또는 "c"와 일치하고, [a-z]는 "a"부터 "z"까지의 모든 소문자와 일치하는 범위를 지정한다. 이러한 형식을 혼합하여 사용할 수 있는데, [abcx-z]는 "a", "b", "c", "x", "y" 또는 "z"와 일치하며, [a-cx-z]도 마찬가지이다.
</td></tr>
<tr>
<th>[^ ]
</th>
<td>대괄호 안에 포함되지 않은 단일 문자와 일치한다. 그냥 의랑 반대라고 생각하면 된다. 예를 들어, [^abc]는 "a", "b", "c"를 제외한 모든 문자와 일치하고, [^a-z]는 "a"부터 "z"까지의 소문자를 제외한 모든 단일 문자와 일치한다. 마찬가지로, 리터럴 문자와 범위를 혼합하여 사용할 수 있다.
</td></tr>
<tr>
<th>( )
</th>
<td>
<p>괄호는 서브 표현을 뜻한다. 예를 들어 H(ä|ae?)ndel은 "Handel", "Händel", "Haendel"로 사용할 수 있다. 괄호 안에 있는 조건은 꼭 사용해야 한다.
</p>
</td></tr></tbody></table>


<br>

# 예시 문제
```
1. 아래 regular expression으로 만들 수 있는 문자열은?
a b * b a a * b a a

A. a b a b a a 
B. a a b b b a a a a b b a a 
C. a b a a a b b a a 
D. a b b b b a b a 
E. a b b b b a a a b a a
```

```
2. 아래 문자열중 주어진 regular expression가 으로 만들 수 없는 문자열은?

    [aeiou][p-t]*(s|er)

    A. tater / B. sorts / C. faster / D. plaques

    E. deer / F. rooster / G. hits / H. bursts


A. A, B, F 
B. B, D, F, G 
C. B, D 
D. D, F, H 
E. B, D, F 
```

```
3. 새로운 회사는 직원들이 자신의 전화번호와 내선번호를 선택할 수 있도록 하고 있다. 단, 다음 regular expression을 만족해야 한다: 

    1-321-[^05][0-9][^5]-[12][3-6][^7-9]8-[^0][2-6] 

    다음 중 사용 할 수 있는 전화번호와 내선번호는 무엇인가요?

a. 1-321-123-2348-11
b. 1-321-155-2368-96
c. 1-321-444-2448-44
d. 1-321-927-2408-84
e. 1-321-559-2328-13
f. 1-321-306-1366-62


A. a, f
B. b, c 
C. e, f 
D. c, d 
E. a, e
```


