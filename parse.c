/*
	sigi language main interpreter 
	copyright (c) david h. kristensen
	2004
	licensed under the bsd license (LICENSE)

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* include the macro set for operators and standardized
   input/output */
#include "include/operator.h"

void jparse(int * lma, char * ips) {
	
	do {
		switch(*(ips++)) {

		/* Arithmetic operators */
			SETUPOP('+', ++*lma);
			SETUPOP('-', --*lma);
			SETUPOP('*', *lma += 10);
			SETUPOP('_', *lma -= 10);
			SETUPOP(':', *lma += 100);
			SETUPOP(';', *lma -= 100);	
			SETUPOP('=', *lma = *lma * *lma);

		/* Output operators */
			SETUPOP('p', putbuf());
			SETUPOP('n', out('\n'));
			SETUPOP('c', putint());

		/* Pointer operators */
			SETUPOP('<', lma--);
			SETUPOP('>', lma++);

		/* Negation operator */
			SETUPOP('0', *lma = 0);

		/* Input operator */
			SETUPOP('.', *lma = getin());
	
		/* ASCII operator */
			SETUPOP('a', *lma = *(ips++));


		/* Looping operator */
			SETUPOP('(',	int a = 0; int b = 0; 
					char * rep = malloc(50); memset(rep, 0, 50);
					do {*(rep++) = *ips; b++;
				     	} while( *(ips++) != ')' );
				     	rep -= b;
				     	for( a = 0; a < *(lma+1); a++ ) {
						jparse( lma, rep );
				    	} free(rep); );
                        
			SETUPOP('{',	int a = 0; int b = 0;
					char * rep = malloc(50); memset(rep, 0, 50);
					do {*(rep++) = *ips; b++;
					} while( *(ips++) != '}' );
					rep -= b;
					int *nlma = (char*)malloc(3*sizeof(int));
					while( (*(nlma) = fgetc(stdin)) != EOF) {
						jparse( nlma, rep );	
					memset((char*)nlma, 3, 0);
					} free(rep); free(nlma); );


		}


	} while( *ips != '\0' );

}
