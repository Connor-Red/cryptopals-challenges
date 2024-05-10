Question is to convert hex (base 16) to base 64. Just from guessing I expect to read the input data bitwise then proceed to parse that to base 64.

From looking at the wikipedia definition, it seems that base 64 is encoded with 6 bits while hex is encoded with 4 (makes sense), so we probably want to read in 12 byte chunks. Data not divisible by 4 should have padding added to the back.

This problem took me 1.5 hours mainly because I was unfamiliar with the finer points of memory management. Conceptually I don't think it was too hard.


Update: moved the hex char to binary, hex to binary and hex to base64 functions out of the file as they are quite useful in future tasks