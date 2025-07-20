---
Team: Round2 theory

Author: 주률

Title: Bit-String Flicking
---
<!--
1. 설명 조금 더 공식적인 언어로 작성할 것. (맞춤법 확인할 것)
2. 문제 / 풀이 포함할 것.
-->
# Theory 에 대한 배경 설명

1. Bit strings

    Bit strings (strings of binary digits) are frequently manipulated bit-by-bit using the logical operators NOT, AND, OR, and XOR. Bits strings are manipulated as a unit using SHIFT and CIRCULATE operators

    먼저 or은 주어진 각 위치에 둘중에 하나라도 1일때 1을 출력하는 것이다.
    예시(:10001 or 10110 이때 출력되는 값은 10111이다.)
    
    다음으로 and는 주어진 각 위치의 두문자가 둘다. 1일 때 1을 출력하는 것이다.
    예시(:101110 and 010101 이때 출력되는 값은 00100이다.)

    또한 not 이라는 개념이 있는데 이 not 은 한줄의 받은 문자에 1과 0을 바꾸면 된다.
    (예시:101110 을 not 시키면 010001이 되는 것이다.)


    마지막으로 xor 이다. 이 개념은 or 시킨 값에 not을 붙이는 것과 같다.
    (예시:101001 xor 101101 일때 010010이 출력 되는 것이다.)

    그리고 여기에는 shift라는 개념이 있는데
    L-shift는 주어진 문자를 왼쪽으로 한칸 씩 움직이는 것이다.(예시:01001를 L-shift1
    하면 10010 이되는것이다.)

    R-shift는 주어진 문자를 왼쪽으로 한칸 씩 움직이는 것이다.(예시:01101를 R-shift1
    하면 11010 이되는것이다.)


2. Theory가 왜 생겼는지
  Bit-String fliking은 논리 연산자,쉼트 연산자를 사용하여 비트 스트링을 조작하는 과정이다.
  .한마디로 이것은 컴퓨터안에서 계산을 할때 필요한 요소들이라고 볼수있다.

3. 어느 곳에 사용하게 되는지
이것은 컴퓨터가 계산을 할때 필요한 요소이다. 그리고 이 bit-string은 0과1로 이루어진 이루어진 이진수의 연속적인 나열이다. 컴퓨터는 이러한 이진수 체계를 통해 모든 데이터를 처리하고 저장한다. 따라서 이 bit-string은 커퓨터과학의 근간을 이루는 핵심요소인 샘이다

# 설명
<dl><dd><dl><dd><table class="wikitable" style="text-align: center">

<tbody><tr>
<th><span style="opacity: 1;"><span class="MathJax_Preview" style="display: none;"></span><span class="MathJax" id="MathJax-Element-3-Frame" tabindex="0" style=""><nobr><span class="math" id="MathJax-Span-7" style="width: 0.74em; display: inline-block;"><span style="display: inline-block; position: relative; width: 0.57em; height: 0px; font-size: 126%;"><span style="position: absolute; clip: rect(1.874em, 1000.51em, 2.667em, -999.997em); top: -2.491em; left: 0em;"><span class="mrow" id="MathJax-Span-8"><span class="mi" id="MathJax-Span-9" style="font-family: MathJax_Math-italic;">x</span></span><span style="display: inline-block; width: 0px; height: 2.497em;"></span></span></span><span style="display: inline-block; overflow: hidden; vertical-align: -0.068em; border-left: 0px solid; width: 0px; height: 0.718em;"></span></span></nobr></span><script type="math/tex" id="MathJax-Element-3">x</script></span>
</th>
<th><span style="opacity: 1;"><span class="MathJax_Preview" style="display: none;"></span><span class="MathJax" id="MathJax-Element-4-Frame" tabindex="0" style=""><nobr><span class="math" id="MathJax-Span-10" style="width: 0.683em; display: inline-block;"><span style="display: inline-block; position: relative; width: 0.513em; height: 0px; font-size: 126%;"><span style="position: absolute; clip: rect(1.874em, 1000.51em, 2.894em, -999.997em); top: -2.491em; left: 0em;"><span class="mrow" id="MathJax-Span-11"><span class="mi" id="MathJax-Span-12" style="font-family: MathJax_Math-italic;">y<span style="display: inline-block; overflow: hidden; height: 1px; width: 0.003em;"></span></span></span><span style="display: inline-block; width: 0px; height: 2.497em;"></span></span></span><span style="display: inline-block; overflow: hidden; vertical-align: -0.354em; border-left: 0px solid; width: 0px; height: 0.932em;"></span></span></nobr></span><script type="math/tex" id="MathJax-Element-4">y</script></span>
</th>
<th><b>not</b> <span style="opacity: 1;"><span class="MathJax_Preview" style="display: none;"></span><span class="MathJax" id="MathJax-Element-5-Frame" tabindex="0" style=""><nobr><span class="math" id="MathJax-Span-13" style="width: 0.74em; display: inline-block;"><span style="display: inline-block; position: relative; width: 0.57em; height: 0px; font-size: 126%;"><span style="position: absolute; clip: rect(1.874em, 1000.51em, 2.667em, -999.997em); top: -2.491em; left: 0em;"><span class="mrow" id="MathJax-Span-14"><span class="mi" id="MathJax-Span-15" style="font-family: MathJax_Math-italic;">x</span></span><span style="display: inline-block; width: 0px; height: 2.497em;"></span></span></span><span style="display: inline-block; overflow: hidden; vertical-align: -0.068em; border-left: 0px solid; width: 0px; height: 0.718em;"></span></span></nobr></span><script type="math/tex" id="MathJax-Element-5">x</script></span>
</th>
<th><span style="opacity: 1;"><span class="MathJax_Preview" style="display: none;"></span><span class="MathJax" id="MathJax-Element-6-Frame" tabindex="0" style=""><nobr><span class="math" id="MathJax-Span-16" style="width: 0.74em; display: inline-block;"><span style="display: inline-block; position: relative; width: 0.57em; height: 0px; font-size: 126%;"><span style="position: absolute; clip: rect(1.874em, 1000.51em, 2.667em, -999.997em); top: -2.491em; left: 0em;"><span class="mrow" id="MathJax-Span-17"><span class="mi" id="MathJax-Span-18" style="font-family: MathJax_Math-italic;">x</span></span><span style="display: inline-block; width: 0px; height: 2.497em;"></span></span></span><span style="display: inline-block; overflow: hidden; vertical-align: -0.068em; border-left: 0px solid; width: 0px; height: 0.718em;"></span></span></nobr></span><script type="math/tex" id="MathJax-Element-6">x</script></span> <b>and</b> <span style="opacity: 1;"><span class="MathJax_Preview" style="display: none;"></span><span class="MathJax" id="MathJax-Element-7-Frame" tabindex="0" style=""><nobr><span class="math" id="MathJax-Span-19" style="width: 0.683em; display: inline-block;"><span style="display: inline-block; position: relative; width: 0.513em; height: 0px; font-size: 126%;"><span style="position: absolute; clip: rect(1.874em, 1000.51em, 2.894em, -999.997em); top: -2.491em; left: 0em;"><span class="mrow" id="MathJax-Span-20"><span class="mi" id="MathJax-Span-21" style="font-family: MathJax_Math-italic;">y<span style="display: inline-block; overflow: hidden; height: 1px; width: 0.003em;"></span></span></span><span style="display: inline-block; width: 0px; height: 2.497em;"></span></span></span><span style="display: inline-block; overflow: hidden; vertical-align: -0.354em; border-left: 0px solid; width: 0px; height: 0.932em;"></span></span></nobr></span><script type="math/tex" id="MathJax-Element-7">y</script></span>
</th>
<th><span style="opacity: 1;"><span class="MathJax_Preview" style="display: none;"></span><span class="MathJax" id="MathJax-Element-8-Frame" tabindex="0" style=""><nobr><span class="math" id="MathJax-Span-22" style="width: 0.74em; display: inline-block;"><span style="display: inline-block; position: relative; width: 0.57em; height: 0px; font-size: 126%;"><span style="position: absolute; clip: rect(1.874em, 1000.51em, 2.667em, -999.997em); top: -2.491em; left: 0em;"><span class="mrow" id="MathJax-Span-23"><span class="mi" id="MathJax-Span-24" style="font-family: MathJax_Math-italic;">x</span></span><span style="display: inline-block; width: 0px; height: 2.497em;"></span></span></span><span style="display: inline-block; overflow: hidden; vertical-align: -0.068em; border-left: 0px solid; width: 0px; height: 0.718em;"></span></span></nobr></span><script type="math/tex" id="MathJax-Element-8">x</script></span> <b>or</b> <span style="opacity: 1;"><span class="MathJax_Preview" style="display: none;"></span><span class="MathJax" id="MathJax-Element-9-Frame" tabindex="0" style=""><nobr><span class="math" id="MathJax-Span-25" style="width: 0.683em; display: inline-block;"><span style="display: inline-block; position: relative; width: 0.513em; height: 0px; font-size: 126%;"><span style="position: absolute; clip: rect(1.874em, 1000.51em, 2.894em, -999.997em); top: -2.491em; left: 0em;"><span class="mrow" id="MathJax-Span-26"><span class="mi" id="MathJax-Span-27" style="font-family: MathJax_Math-italic;">y<span style="display: inline-block; overflow: hidden; height: 1px; width: 0.003em;"></span></span></span><span style="display: inline-block; width: 0px; height: 2.497em;"></span></span></span><span style="display: inline-block; overflow: hidden; vertical-align: -0.354em; border-left: 0px solid; width: 0px; height: 0.932em;"></span></span></nobr></span><script type="math/tex" id="MathJax-Element-9">y</script></span>
</th>
<th><span style="opacity: 1;"><span class="MathJax_Preview" style="display: none;"></span><span class="MathJax" id="MathJax-Element-10-Frame" tabindex="0" style=""><nobr><span class="math" id="MathJax-Span-28" style="width: 0.74em; display: inline-block;"><span style="display: inline-block; position: relative; width: 0.57em; height: 0px; font-size: 126%;"><span style="position: absolute; clip: rect(1.874em, 1000.51em, 2.667em, -999.997em); top: -2.491em; left: 0em;"><span class="mrow" id="MathJax-Span-29"><span class="mi" id="MathJax-Span-30" style="font-family: MathJax_Math-italic;">x</span></span><span style="display: inline-block; width: 0px; height: 2.497em;"></span></span></span><span style="display: inline-block; overflow: hidden; vertical-align: -0.068em; border-left: 0px solid; width: 0px; height: 0.718em;"></span></span></nobr></span><script type="math/tex" id="MathJax-Element-10">x</script></span> <b>xor</b> <span style="opacity: 1;"><span class="MathJax_Preview" style="display: none;"></span><span class="MathJax" id="MathJax-Element-11-Frame" tabindex="0" style=""><nobr><span class="math" id="MathJax-Span-31" style="width: 0.683em; display: inline-block;"><span style="display: inline-block; position: relative; width: 0.513em; height: 0px; font-size: 126%;"><span style="position: absolute; clip: rect(1.874em, 1000.51em, 2.894em, -999.997em); top: -2.491em; left: 0em;"><span class="mrow" id="MathJax-Span-32"><span class="mi" id="MathJax-Span-33" style="font-family: MathJax_Math-italic;">y<span style="display: inline-block; overflow: hidden; height: 1px; width: 0.003em;"></span></span></span><span style="display: inline-block; width: 0px; height: 2.497em;"></span></span></span><span style="display: inline-block; overflow: hidden; vertical-align: -0.354em; border-left: 0px solid; width: 0px; height: 0.932em;"></span></span></nobr></span><script type="math/tex" id="MathJax-Element-11">y</script></span>


</th></tr>
<tr>
<th>0
</th>
<th>0
</th>
<td>1
</td>
<td>0
</td>
<td>0
</td>
<td>0
</td></tr>
<tr>
<th>0
</th>
<th>1
</th>
<td>1
</td>
<td>0
</td>
<td>1
</td>
<td>1
</td></tr>
<tr>
<th>1
</th>
<th>0
</th>
<td>0
</td>
<td>0
</td>
<td>1
</td>
<td>1
</td></tr>
<tr>
<th>1
</th>
<th>1
</th>
<td>0
</td>
<td>1
</td>
<td>1
</td>
<td>0
</td></tr></tbody></table></dd></dl></dd></dl>




<dl><dd><dl><dd><table class="wikitable" style="text-align: right">

<tbody><tr>
<th>x
</th>
<th>(LSHIFT-2 x)
</th>
<th>(RSHIFT-3 x)
</th>
<th>(LCIRC-3 x)
</th>
<th>(RCIRC-1 x)
</th></tr>
<tr>
<th>01101
</th>
<td>10100
</td>
<td>00001
</td>
<td>01011
</td>
<td>10110
</td></tr>
<tr>
<th>10
</th>
<td>00
</td>
<td>00
</td>
<td>01
</td>
<td>01
</td></tr>
<tr>
<th>1110
</th>
<td>1000
</td>
<td>0001
</td>
<td>0111
</td>
<td>0111
</td></tr>
<tr>
<th>1011011
</th>
<td>1101100
</td>
<td>0001011
</td>
<td>1011101
</td>
<td>1101101
</td></tr></tbody></table></dd></dl></dd></dl>
