#include <stdio.h>
#include "db.dat"
#include <stdlib.h>

int main(int argc, char *argv[]){
	struct product rec;
	FILE *fp;

	if(argc != 2){
		fprintf(stderr, "How to use: %s FileName\n", argv[0]);
	}

	fp = fopen(argv[1], "wb");

	printf("%-2s %-4s %-8s %-12s %-5s\n", "id", "name", "category", "expired_date", "stock");
	while (scanf("%d %s %s %d %d", &rec.id, rec.name, rec.category,  &rec.expired_data, &rec.stock) == 5)
		fwrite(&rec, sizeof(rec), 1, fp);

	fclose(fp);
	exit(0);
}

