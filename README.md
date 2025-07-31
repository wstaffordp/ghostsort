### GhostSort

---

![GhostSort](https://repository-images.githubusercontent.com/1028625871/c741aa45-92ca-4d39-a436-c222ffa2b5be "GhostSort")

---

GhostSort is an extremely-fast, in-place, space-constrained sorting algorithm with both stable and unstable variants that replace all variants of Insertion Sort without using auxiliary memory for subarrays.

The license is public domain. Anyone is free to use it for any purpose without restriction. It has no warranty.

---

`ghostsort_unstable()` is an unstable sorting function that sorts elements in ascending order.

It accepts the following 2 arguments in left-to-right order.

1. `elements_count` is the count of elements in `elements`.
2. `elements` is the array of elements to sort.

The return value data type is `void`.

The code structure resembles a normal (n / 2) Shell Sort, so it neither pre-calculates decrementing sequences nor stores decrementing sequences in an auxiliary array.

Each sorting instance calculates a decrementing sequence of gaps with `gap = (gap >> 5) + (gap >> 3)` where `gap` is initially assigned the same value as `elements_count`. It adapts to all sorting scenarios gracefully and outperforms all variants of Shell Sort by emulating pseudorandomness in quasi-linear decrement sequences that each have an optimal subsequent `gap` distance.

Furthermore, the following table demonstrates that `gap > 15` prevents `gap` from reaching either `0` or `1` in every possible sequence.

```
Gap   Result

0     0
1     0
2     0
3     0
4     0
5     0
6     0
7     0
8     1
9     1
10    1
11    1
12    1
13    1
14    1
15    1
16    3
17    3
18    3
```

As a result, arrays of all sizes fall through to a final pass of a unique Insertion Sort variant that sorts quickly by reusing `gap` in a similar context to prevent subtraction operations in comparisons.

In conclusion, the unstable variant of GhostSort provides performance enhancements as an ideal alternative to all Shell Sort variants in all sorting scenarios.

---

The stable variant of GhostSort is coming soon.
