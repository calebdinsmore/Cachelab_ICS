#include "cachelab.h"
#include <getopt.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <math.h>


int parseTrace(char operation, char *addr, int size, int verbose, int set, int assoc, int blockBits){
	int S = pow(2,set);
	int B = pow(2,blockBits);
	int *arr[S];

	for ( int i = 0; i < S; i++ ) {
		arr[i] = (int *) malloc((2 + (B)) * assoc);
	}

	arr[0][3] = 4;
	return 0;
}

int main(int argc, char *argv[])
{
	char c;
	int v = 0;
	int s;
	int E;
	int b;
	char *t[10];
	FILE *traceFile;
	
	s = 0;
	E = 0;
	b = 0;
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
	int counter = 0;
	char operation = ' ';
	char *addr;
	int size = 0;
	while ( (nextCh = fgetc(traceFile))  != EOF ) {
		//printf("%c", nextCh);
		while ( !strchr(" ,\n", nextCh) ) {
			value[idx++] = nextCh;
			nextCh = fgetc(traceFile);
		}
		value[idx] = '\0';
		idx = 0;
		if ( strcmp("",value) ) {
			if ( counter == 0 ) operation = value[0];
			else if ( counter == 1 ) sscanf(value, "%s", addr);
			else { 
				sscanf(value, "%d", &size);
				counter = -1;
				parseTrace(operation, addr, size, v, s , E, b);
			}

			counter++;
		}
	}
    printSummary(0, 0, 0);
    return 0;
}
