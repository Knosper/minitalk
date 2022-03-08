
all: client server clean

client server: client.o server.o utils.o
		gcc -o client client.o utils.o
		gcc -o server server.o utils.o

server.o client.o: server.c client.c utils.c
		gcc -Wall -Wextra -Werror -c server.c utils.c
		gcc -Wall -Wextra -Werror -c client.c utils.c

clean:
		rm -f *.o

fclean: clean
		rm -f client server
