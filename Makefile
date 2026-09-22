var:=$(patsubst %.c, %.o, $(wildcard *.c))
cal.exe:$(var)
	gcc -o cal.exe $(var)
clean:
	rm *.exe *.o	