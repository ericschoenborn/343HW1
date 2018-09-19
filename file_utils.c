#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <stdlib.h>

int read_file(char* filename, char ** buffer){
	FILE *f = fopen(filename,"r");
	if(f != NULL){	
		struct stat st;
		stat(filename, &st);
		int size = st.st_size;
		if(size > 1){
			*buffer = malloc(size * sizeof(char));
	
			fread(*buffer, size, 1, f);
			fclose(f);
			return size;
		}
		fclose(f);
		fprintf( stderr, "file '%s' is empty.\n", filename);
		return 0;
	}
	fprintf( stderr, "file '%s' does not exist.\n", filename);
	return 0;
}

int write_file(char* filename, char *buffer, int size){
	FILE *f = fopen(filename,"w");
	fwrite(buffer, 1, size, f);
	fclose(f);
	return 0;
}
