# Error-correcting code

An error-correcting code encodes a stream of binary digits (bits) for transmission over an unreliable channel such that (some) bit errors can not only be detected by the receiver, but can also be corrected.

example output:

```
1001100 decoded is 0100 (0 errors corrected)

1001110 decoded is 0100 (1 errors corrected)

100111011010010001110010101000011011001100 decoded is:
010000010111001001110100 (3 errors corrected)
which as text is 'Art'

00011000001001010001000001001100110011010011101101111110000101111001101100110010010101010100000000100110010000110101010011001101010100110011 decoded is:
01001001001000000110110001101111011101100110010100100000010000110010101100101011 (8 errors corrected)
which as text is 'I love C++'
```
