#include <stdio.h>
#include "db.dat"

int main(int argc, char*argv[]) {
	struct product rec;
	FILE *fp;
	if(argc != 2) {
		fprintf(stderr, "How to duse: %s FileName\n", argv[0]);
		return 1;
	}
	if((fp = fopen(argv[1], "rb")) == NULL) {
		fprintf(stderr, "Error Open File\n");
		return 2;
	}
	printf("0: list of all goods, 1: list of available goods")

		if 

