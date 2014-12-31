/*	sigi language parser
	main program file
	copyright (c) david hanefelt kristensen
	licensed under the bsd license (read LICENSE)
*/

#include <stdio.h>
#include <stdlib.h>


#include "include/msg.h"
#include "include/parse.h"
#include "include/params.h"

/* the linear memory array */
int 	* jmarray;

/* healthy amount of space for buffered input */
char	imstrin[1024];
FILE	* fin;

int main( int argc,
	  char ** argv ) {

	/* allocate a huge pool of memory */
	jmarray = (int*)malloc(4096*sizeof(int));

	/* reset the linear memory array
	   to avoid incompatibility */
	memset(&imstrin, 0, 1024);


	/* handle missing input */
	if( argc < 2 ) {
		fprintf(stderr, gmsg(1));
		exit(1);
	}

	/* if we can open the file, then read buffered & parse */
	if( (fin = fopen(argv[1], "r")) != NULL ) {	
		while( fgets(imstrin, 1023, fin) != NULL ) {
			jparse(jmarray, imstrin);
		}
	}

	/* if not, then die */
	else {
		fprintf(stderr, gmsg(2));
	}

	/* make sure we don't leak memory */
	free(jmarray);
	fclose(fin);
	
	/* and exit */
	exit(0);

}
