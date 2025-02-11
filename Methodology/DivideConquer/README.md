# Divide and Conquer
크고 방대한 문제를 조금씩 조금씩 나눠가면서 용이하게 풀 수 있는 문제 단위로 나눈 다음 그것들을 다시 합쳐 해결하자는 개념										
## Approach
1. Divide
    - 문제를 더 이상 분할할 수 없을 때까지 동일한 유형의 여러 sub-problem 으로 쪼갬.
2. Conquer
    - 쪼개진 sub-problem 을 해결.
3. Combine
    - 해결한 sub-problem 의 결과를 원래 문제에 대한 결과로 조합.

분할 정복법은 재귀적으로 자신을 호출하면서 그 연산의 단위를 조금씩 줄어가는 방식

```cpp
function(problem){
    if(problem 이 더 이상 분할 불가능){
        problem 해결
        return 결과
    }
    else{
        problem 을 sub-pb1, sub-pb2 로 분할
        function(sub-pb1)
        function(sub-pb2)
        return sub-pb1 과 sub-pb2 로 구한 결과 조합 반환
    }
}
```

