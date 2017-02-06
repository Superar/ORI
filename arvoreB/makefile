OBJS = arvoreB.o main.o

#Executa o programa
all : arvoreB

#Compila o programa
arvoreB : ${OBJS}
	gcc -std=c99 -o $@ $^

#Gera os objetos
%.o : %.c
	gcc -std=c99 -o $@ -c $^

#Deleta arquivos
clean :
	rm ${OBJS} arvoreB
