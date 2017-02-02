OBJS = arvoreB.o main.o

#Executa o programa
all : arvoreB

#Compila o programa
arvoreB : ${OBJS}
	gcc -o $@ $^

#Gera os objetos
%.o : %.c
	gcc -o $@ -c $^

#Deleta arquivos
clean :
	rm ${OBJS} arvoreB
