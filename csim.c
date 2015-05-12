#include "cachelab.h"
#include <getopt.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char c;
	int v = 0;
	int s;
	int E;
	int b;
	char *t[1];
	FILE *traceFile;
	
	s = 0;
	E = 0;
	b = 0;
	*t[0] = 'c';
	s = s + E + b + v;
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
				break;
			case 'E':
				sscanf(optarg, "%d", &E);
				break;
			case 'b':
				sscanf(optarg, "%d", &b);
				break;
			case 't':
				*t = optarg;
				traceFile = fopen(*t, "r");
				break;
		}
	}
	char nextCh = ' ';

	char value[20] = "aaaaaaaaaaaaaaaaaaaa"; 
	int idx = 0;
	//char operation = ' ';
	//int addr = 0;
	//int size = 0;
	while ( (nextCh = fgetc(traceFile))  != EOF ) {
		printf("%c", nextCh);
		//while ( !strchr(" ,\n", nextCh) ) {
			//value[idx++] = nextCh;
		//	nextCh = fgetc(traceFile);
		//}
		//value[idx] = '\0';
		idx = 0;
		//printf("%s\n", value);
	}
    printSummary(0, 0, 0);
    return 0;
}
