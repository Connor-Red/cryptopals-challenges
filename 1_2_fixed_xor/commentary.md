While C does have a native bitwise XOR function, we are working with hexadecimal strings here. I think the way to go here is to decode the hex string to a binary string, then run an
XOR on the binary string itself, then re-encode it back to hex.

This was quite straightforward too, taking around 1 hour to complete.