/* 	Operator creation & implementation macro
   	& a macro to put the current buffer on screen 

	copyright (c) david h. kristensen
	2004
	licensed under the bsd license (LICENSE)

*/

#define out(a) fputc(a, stdout);
#define putbuf() out(*lma);
#define getin() fgetc(stdin);
#define putint() printf("%d", *lma);
#define SETUPOP(a, b) case a: { \
b; }\
break;


