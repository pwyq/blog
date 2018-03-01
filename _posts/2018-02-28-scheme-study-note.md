---
title: Study Note of Scheme
date: 2018-02-28
categories: 
    - study
tags:
    - Scheme
    - Note
    - Functional Programming
description: Study Note of Scheme programming language
---

_ ==> On Studying Process <== _

# The Ten Commandments
## The First commandment
When recurring on a list of atoms, _lat_, ask two questions about it: (_null? lat_) and __else__. When recurring on a number, _n_, ask two questions about it: (_zero? n_) and __else__. When recurring on a list of S-expressions, _l_, ask three questions bout it: (_null? l_), (_atom?_ (_car l_)), and __else__.

## The Second Commandment
Use _cons_ to build lists.

## The Third Commandment
When building a list, describe the first typical element, and then _cons_ it onto the natural recursion.

## The Fourth Commandment
Always change at least one argument while recurring. When recurring on a list of atoms, _lat_, use (_cdr lat_). When recurring on a number, _n_, use (_sub1 n_). And when recurring on a list of S-expressions, _l_, use (_car l_) and (_cdr l_) if neither (_null? l_) nor (_atom?_ (_car l_)) are true.

It must be changed to be closer to termination. The changing argument must be tested in the termination condition:  
when using _cdr_, test termination with _null?_ and  
when using _sub1_, test termination with _zero?_.

## The Fifth Commandment
When building a value with +, always use 0 for the value of the terminating line, for adding 0 does not change the value of an addition.

When building a value with x, always use 1 for the value of the terminating line, for multiplying by 1 does not change the value of a multiplication.

When building a value with _cons_, always consider () for the value of the terminating line.

## The Sixth Commandment
Simplify only after the function is correct.

## The Seventh Commandment
Recur on the _subparts_ that are of the same nature:
- On the sublists of a list.
- On the subxpressions of an arithmetic expression.

## The Eighth Commandment
Use help functions to abstract from representations.

## The Ninth Commandment
Abstract common patterns with a new function.

## The Tenth Commandment
Build functions to collect more than one value at a time.

# The Five Rules
## The Law of Car
The primitive _car_ is defined only for non-empty lists.

## The Law of Cdr
The primitive _cdr_ is defined only for non-empty lists. The _cdr_ of any non-empty list is always another list.

## The Law of Cons
The primitive _cons_ takes two arguments.  
The second argument to _cons_ must be a list.  
The result is a list.

## The Lwa of Null?
The primitive _null?_ is defined only for lists.

## The Law of Eq?
The primitive _eq?_ takes two arguments.  
Each must be a non-numeric atom.

# Chapter 1

1. `atom` is a string of characters, except with a left "(" or right ")" parenthesis.
2. `list` is a collection of `atom`(s) enclosed by parentheses.
3. All `atom`s are `S-expression`s.
4. All `list`s are `S-expression`s.

**e.g.**: How many `S-expression`s are in the `list`:  
(((how) are) ((you) (doing so)) far)  
and what are they?

**Ans**: Three, ((how) are), ((you) (doing so)), and far.

5. `null list` (or `empty list`) contains zero S-expressions enclosed by parentheses.
    `()`

6. _car_ is the first `atom` of the `list`.
7. There is no _car_ for an `atom`.
8. There is no _car_ for an `null list`.

refer to **The Law of Car**

9. "(_car l_)" is another way to ask for "the _car_ of the list _l_."
10. "cdr" is pronounced "could-er."

# Installation
```
# on Arch Linux
$ sudo pacman -Sy mit-scheme

# on Ubuntu Linux
$ sudo apt-get install mit-scheme -y
```

# Reference
[The Little Schemer](https://mitpress.mit.edu/books/little-schemer)
