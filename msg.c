/* 	sigi messaging api
	licensed under the bsd license (LICENSE)
*/
  

#include <stdio.h>

/* very poor way to centralize messages
   but it works */
char *jab_msgs[] = {
	"sigi/Error\nSyntax: sigi [infile]\n",
	"Error, specified file does not exist\n",
	"sigi Live Interpreter\n"
	"Evaluates and executes sigi code\n"
	"Usage: sigi [input]" };
		

char * gmsg(unsigned id) {
	return jab_msgs[id-1];
}
