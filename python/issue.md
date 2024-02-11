# CHEATING IS BAD
This writeup is for intellectual purposes only, and should not be used to cheat on the BWSI Python Core course homework.

The grader uses a single, hardcoded key in order to grade each problem:
```py
from hashlib import sha224

__seed__ = ["cesarcipher", "keywordcipher"]

#...

def grade_keyword_cipher(student_func: Callable[[str, str], str]):
    # ...
    print_passed(sha224(str.encode(__seed__[1])).hexdigest())
```

What this means is that you can just view the source of the function the grader calls (in this case, `grade_keyword_cipher`), find the seed, and then run `print(sha224(str.encode({KEY})).hexdigest())`, prepend "bw", and then submit that. It's entirely academic dishonesty, but it's very easy to do (and, in my opinion, to fix).

A way to make this much harder would be to use the *output* of the function on some unreasonably large input (also, not include the real solution function in the grader, just hardcoded input/output for some test cases). What this would look like:

```py
from hashlib import sha224

#...

testcases = [
    (("test", "test"), "idk the answer for this one"),
    (("cogworks 2018", "python"), "or for this one"),
    (("perl rocks", "my key"), "...you guessed it."),
]

def grade_keyword_cipher(student_func: Callable[[str, str], str]):
    # check if student_func(input) = output for every (input, output) in testcases
    # blah blah blah, no major code changes

    # at the end, use some large test case with no solution in the source code... it'll most likely be solved, if similar enough to the test cases:
    print_passed(sha224(str.encode(student_func("this really really long string that can't be easily solved without actually writing the function")).hexdigest())
```

However, this would *technically* be able to fail and trick students... basically, the large end test case would have to be similar *enough* to the real test cases? That is, it shouldn't introduce any new edge cases not tested by the other test cases.

Eh, I don't know. I have too much free time sometimes, lol. That does it for my two cents.