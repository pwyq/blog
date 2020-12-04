---
title: Finding the order of packaging.version notations
date: 2020-02-15
categories:
    - tech
tags:
    - life
    - python
    - pyqt
---

I have been working on a automation+viewer GUI for a game with `PyQt` (open source here: [WGViewer](https://github.com/WarshipGirls/WGViewer)).

Thinking of it may be the time to release an early beta version, I found a [third-party package, packaging.version](https://packaging.pypa.io/en/latest/version.html), for versioning.
Nevertheless, the documentation was ambiguous regarding what version number is valid as `version.Version` and what is invalid as `version.LegacyVersion`,
let alone conspicuously providing the order of versioning.
Granted, the post would not be made if it were merely comparing version of some integers.
In fact, there are numerous string notations that can be considered as valid `version.Version`.
I tried to find as much information as possible from the documentation, plus testing via iterating through the alphabet, and following valid notations are found:

```
a, b, c, r, beta, dev, pre, post, rev
```

One might guess the order by intuition; yet in order to be certain, I decided to write a script to test.
Fortunately, one can compare the order using `version.parse(ver_name_a) < version.parse(ver_name_b)`.
Since the aforementioned package is written in Python, the tool I use to determine the order is also Python.

For the first version, I simply did a 1-pass iteration and determine the order from terminal output.

```Python
from packaging import version
l = 0
r = 1
nota = ['a','b','c','r','beta','dev','pre','post', 'rev']
while True:
    res = version.parse(nota[l]) < version.parse(nota[r])
    print(nota[l], nota[r], res)
    r += 1
    if r == len(nota):
        l += 1
        r = l+1
        print('\n')
    if r == len(nota):
        break
```

As soon as I started manually examine the order one by one,
I realize this is not only prone to human error but also not scalable.

I then started refactoring the script to automatically determine the order.
I had a failed attempt by using a list to store the result.
The idea was to find the amount of elements that are greater (let call it `count-great`) than current element,
then assign current element to the equivalent value (serve as index) of `count-great` of the list.
However, this was thwarted by overlapping issue.
After identifying the issue, I tried adding a boolean lock, along with `list.insert()`, to fix the problem.
Nonetheless, the problem grew as twice fast as the debugging code grew. Following code snippet are the failed attempt:

```Python
i=0
j=0
res = [0] * len(nota)
lock = False
locks = []
count = 0
offset = 0
while True:
    print(i, j, res)
    r = version.parse(nota[i]) < version.parse(nota[j])
    print(nota[i], nota[j], r)
    if r is True:
        count += 1
    else:
        if i != j and i not in locks and version.parse(nota[i]) == version.parse(nota[j]):
            lock = True

    j += 1
    if j == len(nota):                                  # NOT
        if lock is True:                                #
            res.insert(count, nota[i])                  # WORKING
            locks.append(i)                             #
            lock = False                                # AT 
            #offset += 1                                #
        #else:                                          # ALL
        res[count] = nota[i]                            # !
        print(nota[i], count)                           # !
        i += 1                                          # !
        j = 0
        print('\n')
        if i == len(nota):
            break
        count = offset

print(res)
print(locks)
```


Finally, I did recall some hacks, from a distant memory, through LeetCoding.
This time, I used a dict to store the pair of (notation, count-great).
After that, it only requires a `sort` call to finish the job:

```Python
i=0
j=0
res = {}
count = 0
while True:
    r = version.parse(nota[i]) < version.parse(nota[j])
    if r is True:
        count += 1
    j+=1
    if j == len(nota):
        res[nota[i]] = count
        i+=1
        j=0
        if i==len(nota):
            break
        count = 0

sort_res = sorted(res.items(), key = lambda x:x[1])

o = ""
i = 0
while True:
    o += sort_res[i][0]
    if i == len(sort_res) - 1:
        break
    if sort_res[i][1] == sort_res[i+1][1]:
        o += " = "
    elif sort_res[i][1] < sort_res[i+1][1]:
        o += " > "
    i += 1

print(nota)
print(o)
```

The final result for the order of `packaging.version` notation is:

```
(any int) > rev > r > post > c = pre > beta > b > a > dev
```

There even exists an equal version notation! What a surprise!
