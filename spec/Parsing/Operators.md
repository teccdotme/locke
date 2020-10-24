---
parent: Lexing
grand_parent: Specification
---

# Operators

## Arithmetic

A sequence of characters that take two inputs of any type,
and gives an output of any type.

> Template:
> ```<input1> <operator> <input2>```

List of arithmetic operators:

* Addition `+`, `plus`

  ```locke
  6 + 10 = 16
  "Hello, " + "world!" = "Hello, world!"
  "The meaning of life is " + 42 = "The meaning of life is 42"
  "Math in strings; " + 9 + 8 = "Math in strings: 98 "
  ```

* Subtraction `-`, `minus`

  ```locke
  24 - 11 = 13
  "Characters" - "a" = "Chrcters"
  "123456" - 3 = "123"
  3 - "69123" = ERROR
  ```

* Multiplication `*`, `times`

  ```locke
  2 * 6 = 12
  -1 * 3 = -3
  "E" * 6 = "EEEEEE"
  ```

* Division `/`, `div`

  ```locke
  1 / 3 = 0.3333333
  
  ```

* Exponentiation `**`, `pow`

## Bitwise

Bitwise operators are those that intend to work with multiple or individual bits, usually in numbers.

### Logic gates

>**NOTE**
>
>To get a logic gates inverted complement, put `!` or `not` before the operator.

* And `&`, `and`

  ```locke
  29 and 22 = 20
  21 (0b10101) & 11 (0b1011) = 1 (0b00001)
  ```

* Or `|`, `or`

  ```locke
  13 or 70 = 79
  26 (0b11010) | 4 (0b0100) = 30 (0b11110)
  ```

* Xor `^`, `xor`

  ```locke
  10 xor 3 = 9
  10 (0b1010) ^ 14 (0b1110) = 4 (0b0100)
  ```

### Shifts

* Shift right `>>`, `shiftr`

* Shift left `<<`, `shiftl`

## Iterator

Iterator operators are those that are to be used with values that can be iterated over, such as arrays or maps.

In this context, there are a few variables:

* `k` is a key, which can be of any type.
* `v` is a value, which is mapped to a key.
* `itr` is an iterator of any type.

### General data

* Accessor `[k]`

  ```locke
  [1, 2, 3][1] = 2
  ```

* Length `itr.length`

  ```locke
  [1, 2, 3].length = 3
  ```
