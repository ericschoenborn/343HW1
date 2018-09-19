#include "reverse.h"

int main(int argc, char** argv){
	if(argc == 3){
		char *buffer;
		int size = read_file(argv[1],&buffer);
		char *flip = malloc(size * sizeof(char));
		int l = size -1;
		for(int i=0; i<size; i++){
			flip[i] = buffer[l-i];
		}
		write_file(argv[2], flip, size);
		return 0;
	}else{
		fprintf( stderr, "Needs exacly two file arguments.\n");
	}
}
