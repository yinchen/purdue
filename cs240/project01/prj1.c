#include <assert.h>
#include <stdio.h>

#include "prj1-bcd.h"


int main()
{
	int i, j, k, a, b;
	char s[128], t[128], u[128], v[128];

	for (i = 0; i < 1000; i++){
		j = rand()%10;
		a = rand()%100000000 >> j;
		j = rand()%25;
		b = rand()%10000000 >> j;
		if (rand()%20 == 11){
			a = b;
			printf(">>>>>>>>>>>> %d\n", a);
		}
		else
			printf("%d %d\n", a, b);
		assert(bcd_encode(a, 128, s) == 0);
		assert(bcd_encode(b, 128, t) == 0);
		if (a > b){
			assert(bcd_gt(s, t) && !bcd_eq(s, t));
		}
		if (a == b)
			assert(bcd_eq(s, t));
		assert(bcd_add(s, t, 128, u) == 0 && a+b == bcd_decode(u));
		if (a >= b)
			assert(bcd_sub(s, t, 128, u) == 0 && a-b == bcd_decode(u));
		else
			assert(bcd_sub(s, t, 128, u) == -1);
		assert(bcd_mul(s, t, 128, u) == 0 && a*b == bcd_decode(u));
		if (b == 0)
			assert(bcd_div(s, t, 128, u, 128, v) == -1);
		else
			assert(bcd_div(s, t, 128, u, 128, v) == 0 && a/b == bcd_decode(u) && a%b == bcd_decode(v));
	}
	assert(bcd_encode(5676765, 128, s) == 0);
	assert(bcd_encode(0, 128, t) == 0);
	assert(bcd_mul(s, t, 128, u) == 0 && u[0] == 1 && u[1] == 0);
	return 0;
}
