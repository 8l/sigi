

sigi:	main.o parse.o msg.o
	cc main.o parse.o msg.o -o sigi
	rm -rf *.o

main.o:
	echo Compiling SIGI
	cc -c main.c
parse.o:
	cc -c parse.c
msg.o:
	cc -c msg.c

install:
	install sigi /usr/local/bin
clean:
	rm -rf sigi
