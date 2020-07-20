# ft\_printf
************
# :fire: Mandatory Part

### :bulb: cspdiuxX%

#### Conversions
%c -> Print character value :heavy_check_mark:   
%s -> Print string value :heavy_check_mark:   
%p -> Print pointer address value in hexadecimal :heavy_check_mark:   
%d -> Print integer value as a signed decimal number :heavy_check_mark:   
%i -> Same as %d :heavy_check_mark:   
%u -> Print integer value as a decimal number without sign :heavy_check_mark:   
%x -> Print integer value in hexadecimal number without sign, 10\~15 is  'a'\~'f' :heavy_check_mark:   
%X -> Print integer value in hexadecimal number without sign, 10\~15 is  'A'\~'F' :heavy_check_mark:   
%% -> % after % prints "%" :heavy_check_mark:   


### :bulb: flag '- 0 . \*'

형식 문자열에는 형식 태그(format tag)라 불리는 것이 추가적으로 들어갈 수 있는데, 이는 이에 대응하는 인자를 형식 태그가 지정한 형태로 치환되어 출력된다.
따라서, 형식 문자열 다음으로 오는 인자들의 개수는 반드시 형식 문자열 속의 태그의 개수보다 같거나 많아야 한다.

```
% \[플래그(flag)] \[폭(width)] \[.정밀도] \[크기(length)] 서식 문자(specifier)
```

\'-' -> Left-justify within the given field width; Right justification is the default (see width sub-specifier).
'0' -> Left-pads the number with zeroes (0) instead of spaces, where padding is specified (see width sub-specifier).
'\*' -> (폭 지정자) 폭을 형식 문자열에 지정해서 받지 않지만, 그 대신에 형식 문자열 뒤에 오는 인자들에 넣어서 받는다.
이 때, 이는 정수 값이여야 하며 폭을 지정하는 변수 뒤에 출력할 데이터가 위치하면 된다
'.' -> (정밀도 지정자) 형식 문자열에서 정밀도를 나타내지는 않지만 뒤에 인자로 정밀도 값을 준다. 이 때 인자는 형식 태그가 적용되는 데이터 앞에 있어야 한다.


### :bulb: 기존 printf 함수 동작 결과 실험
[printf 동작결과로 바로가기](https://github.com/feldblume5263/42_cursus/tree/master/3_ft_printf/tools/test_printf_case)
