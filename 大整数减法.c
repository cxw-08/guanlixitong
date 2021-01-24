#include<stdio.h>
#include<string.h>
int main() 
{
	const int MAXLEN = 210;
	int a[MAXLEN], b[MAXLEN], c[MAXLEN];
	char s1[MAXLEN], s2[MAXLEN];
	int l1, l2, na, nb, nc, i;
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	memset(c, 0, sizeof(c));
	scanf("%s%s",s1,s2);
	l1 = strlen(s1);
	l2 = strlen(s2);
	for (i = 0; i < l1; i++) {
		a[i] = s1[l1 - i - 1] - '0';
	}
	na = l1;
	for (i = 0; i < l2; i++) {
		b[i] = s2[l2 - i - 1] - '0';
	}
	nb = l2;
	if (na > nb) nc = na;
	else nc = nb;
	for (i = 0; i < nc; i++) {
		if(a[i]>=b[i]){
			c[i]=a[i]-b[i];
		}
		else{
			c[i]=a[i]+10-b[i];
			a[i+1]=a[i+1]-1;
		}
	}
	while (c[nc - 1] == 0) {
		if (nc == 1)break;
		nc--;
	}
	for (i = nc - 1; i >= 0; i--) printf("%d", c[i]);
	printf("\n");

	return 0;
}

