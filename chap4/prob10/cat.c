#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {

   FILE *fp;
   int c;
   int line_number = 1;
   int show_line_numbers = 0;

   if (argc > 1 && strcmp(argv[1], "-n") == 0) {
	   show_line_numbers = 1;
	   argc--;
	   argv++;
   }

   if(argc < 2) {
	   fprintf(stderr, "Usage: %s [-n] file1 file2 file3...\n", argv[0]);
	   return 1;
   }

   for (int i = 1; i < argc;i++) {
	   fp = fopen(argv[i], "r");

	   if (fp == NULL) {
		   fprintf(stderr, "Cannot open file: %s\n", argv[i]);
		   continue;
	   }

	   if(show_line_numbers) {
		   printf("%d ", line_number);
	   }

	   while ((c = fgetc(fp)) != EOF) {
		   putc(c, stdout);
		   if(c == '\n'){
			   line_number++;
			   if(show_line_numbers){
				   printf("%d", line_number);
			   }
		   }
	   }

	   fclose(fp);
	   line_number = 1;
   }

   return 0;
}
