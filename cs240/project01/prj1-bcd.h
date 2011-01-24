#ifndef prj1_bcd_h
#define prj1_bcd_h

// Encode integer i into buffer s of size n. Returns 0 on
// success or -1 in case of an overflow (encoding i requires
// a buffer larger than n).

int bcd_encode(int i, int n, char *s);

// Decode BCD number s to an integer. The decoded integer is
// the return value.

int bcd_decode(char *s);

// Returns 1 if BCD number s is greater than BCD number t and 0 otherwise.

int bcd_gt(char *s, char *t);

// Returns 1 if the two BCD numbers s and t are equal and 0 otherwise.

int bcd_eq(char *s, char *t);

// Add two BCD numbers s and t and put the result in buffer u of
// size n allocated by the caller.  Returns -1 if a larger
// buffer is required or 0 on success.

int bcd_add(char *s, char *t, int n, char *u);

// Subtract BCD number t from BCD number s and put the result in buffer
// u of size n allocated by the caller.  If BCD number t is
// greater than BCD number s, the function returns -1 and no
// subtraction is carried out.  The function also returns -1
// if a larger buffer is required. On success it returns 0.

int bcd_sub(char *s, char *t, int n, char *u);

// Multiply two BCD numbers s and t and put the result in buffer u
// of size n allocated by the caller.  Returns -1 if a larger
// buffer is required or 0 on success.

int bcd_mul(char *s, char *t, int n, char *u);

// Divide BCD number s by BCD number t and put the
// quotient (i.e. the result) in buffer u of size n allocated
// by the caller. The remainder is stored in buffer v of
// size m also allocated by the caller.  Returns -1 if a
// larger buffer is required for storing either the quotient
// or the remainder.  Also returns -1 in case of division by
// zero (BCD number t is 0). Returns 0 on success.

int bcd_div(char *s, char *t, int n, char *u, int m, char *v);

#endif
