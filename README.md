# Parentheses string
## Description

The goal is to convert the original string to a new string, where each character is replaced by the character `“(”` if the character occurs only once, or by `“)“` if the character occurs more than once. The program should ignore capital letters when detecting duplicates (i.e. "A" and "a" are the same character).

The task solution was written using the C++ language.

Example input and output data:
```
"din"      =>  "((("
"recede"   =>  "()()()"
"Success"  =>  ")())())"
"(( @"     =>  "))(("
```
To convert a string, two implementation options were written - conversion in place by `convertToParenthesesString` function (changing the string passed by reference) and conversion with the return of a new string - `getParenthesesString` function. The program also provides a function `makeTests` for testing the conversion on random data.
