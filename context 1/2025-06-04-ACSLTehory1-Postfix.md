---

Team: R2Theory

Author: Sungtaewoo

Title: POSTFIX

---

<!--
1. image file 첨부할 것. 
2. 한국어로 작성할 것. 
3. 소제목, 대제목 포함하여 작성할 것. 
4. 문제 / 풀이 나눠서 작성 할 것. 
-->

[Intermediate] 2021-2022 ACSL R1 Coding Fibonacci Clock
>

    ACSL’s version of Philippe Chretien’s “Fibonacci Clock” displays time by changing the colors displayed in 5 squares, whose side lengths correspond to the first 5 Fibonacci numbers (1, 1, 2, 3, and 5). Given the colors of the squares on the clock face, you must output the time that is represented in hh:mm format. The colors will be given to you as 5 individual characters representing the lower 1x1square, the upper 1x1 square, the 2x2 square, the 3x3 square, and the 5x5 square in that order. 

    
    Red squares are used to represent only hours and green squares are used to represent only minutes. Blue squares are used to represent both hours and minutes. White squares are ignored. To find the current hour, add the values of the red and blue squares. To find the current minutes, add the values of the green and blue squares and multiply by 5 so that the number of minutes and seconds are in intervals of 5 between 0 and 60 inclusive.


    However, if the number of minutes is 60, change it to the next hour with 0 minutes and if the number of hours is 12 or more, change it to a valid time from 00:00 to 11:55. For example, 09:60 would become 10:00 and 12:60 would be 01:00.


    The clock in the picture above is displaying 08:50. The hours are represented by the red 1x1, blue 2x2, and blue 5x5 squares (1+2+5=8). The minutes are represented by the blue 2x2, the green 3x3, and the blue 5x5 squares (2+3+5=10, and 10*5=50).

    The example at the left which uses the inputted characters R, W, G, B, G displays the time 04:50. The hours are represented by the 1x1 red square and the 3x3 blue square: 1+3=4. The minutes are represented by the 2x2 green, the 3x3 blue, and the 5x5 green squares: (2+3+5)*5 = 50. The example at the right which uses the inputted characters W, B, B, G, R displays the time 08:30. The hours are 1+2+5=8 and the minutes are (1+2+3)*5=30.

![alt text](image-1.png)
 
    Input >

    5 uppercase letters (R, W, B, or G) that represent the colors of the lower 1x1, the upper 1x1, the 2x2, the 3x3, and finally the 5x5 square, in that order. We guarantee that the input will represent a valid time from 00:00 to 11:55

    Output >

    Print the time in hours and minutes formatted as hh:mm

    개념 정리 > 

    Did you understand it? 
    It is hard to understand because it is English, but let's go!
    Today we will solve this problem with "_dict_".
    >

        Dictionary >

        thisdict = {
            "brand": "Ford",
            "model": "Mustang",
            "year": 1964
        }
        
        Dictionaries are used to store data values in key:value pairs.
        A dictionary is a collection which is ordered* changeable and do not allow duplicates.

        If you type "_print(thisdict["brand"])_"(key)
        then you can get _"Ford"_(value)


    문제풀이 >

    (input : R W G B G)

    List = list(map(str,input().split()))
    (R W G B G > ['R', 'W', 'G', 'B', 'G'])

    n = 0 (count how many 'for loops' looped)

    s = 0 (the size of boxes)

    t = 0 (total time)

    for i in List: (it is called 'for loops'.
                    In first loop 'i' = 'List[0]' and take a loop,
                    in Second 'i' = 'List[1]' and take a loop.
                    Like this, it takes five loops if len(List) = 5.)

        dict = {
            0 : 1,
            1 : 1,
            2 : 2,
            3 : 3,
            4 : 5
        }
        s = dict[n] (if n = 0, then s = 1)

        dict2 = {
            "R" : t + s*60,
            "W" : t,
            "B" : t + s*65,
            "G" : t + s*5
        }
        t = dict2[i] (if i = "R", then t = t + s*60)
        n=n+1
    hh = int(t/60) (# hours)
    mm = str(t%60) (# minutes)
    print(str("%02d"%hh) + ":" + mm) (hours : minutes)
                                     ("%02d"%hh >
                                      if hh = 5, then hh > 05)


