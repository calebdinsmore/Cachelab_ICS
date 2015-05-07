#include "cachelab.h"
#include <getopt.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	char c;
	int v = 0;
	int s;
	int E;
	int b;
	char *t[1];
	
	s = 0;
	E = 0;
	b = 0;
	*t[0] = 'c';
	s = s + E + b + v;
	printf("%s\n", t[0]);
	while ( (c = getopt(argc, argv, ":hvs:E:b:t:")) != -1 ) {
		//printf("%c\n", c);
		switch(c) {
			case 'h':
				break;
			case 'v':
				v = 1;
				break;
			case 's':
				sscanf(optarg, "%d", &s);
				printf("%d\n", s);
				break;
			case 'E':
				sscanf(optarg, "%d", &E);
				printf("%d\n", E);
				break;
			case 'b':
				sscanf(optarg, "%d", &b);
				printf("%d\n", b);
				break;
			case 't':
				*t = optarg;
				printf("%s\n", *t);
				break;
		}
	}
    printSummary(0, 0, 0);
    return 0;
}
