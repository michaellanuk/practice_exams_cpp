# Pig Latin

Pig Latin1 is an elegant but archaic pseudo-language that was first spoken in the Middle Ages. 
Invented by commoners so that they could sound as fancy as their lords, it is based on manipulating 
the letters of English words so that they sound like Latin words in plural feminine form 
(i.e. they end in an “ay” sound).

Any English word may be changed into its Pig Latin equivalent as follows:
1. If the word begins with a vowel, add “way” to it. For example, Pig Latin for apple is
appleway.
2. If the word begins with a letter that is not a vowel, find the first occurence of a vowel, 
move all the characters before the vowel to the end of the word, and add “ay”. For example, 
grape becomes apegray and strong becomes ongstray.
3. If the word contains no vowels just add “ay” to it.
4. For the purposes of this exercise the vowels are a, e, i, o, u and y; but y is only considered 
a vowel if it is not the first or last letter of the word. So yeti becomes etiyay, my becomes myay 
and crying becomes yingcray.
5. If the word begins with a character that is a digit, leave the word as is. For example, 300 remains 300.
6. If the word begins with an initial upper case (captial) letter then so should the corresponding 
Pig Latin word. For example, Banana becomes Ananabay. You do not need to handle other capitalization patterns (e.g. all uppercase words).

example output:

```
In Pig Latin 'grape' is 'apegray'.
In Pig Latin 'orange' is 'orangeway'.
In Pig Latin 'Banana' is 'Ananabay'.
In Pig Latin 'Yellow' is 'Ellowyay'.

The file 'fruit.txt' translated into Pig Latin is:

Imetay iesflay ikelay anway arrowway, 
utbay uitfray iesflay ikelay away ananabay!
(Ouchogray Arxmay 1890-1977)

```
