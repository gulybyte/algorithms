NAME = main

all: $(NAME).o
	ld -s -o $(NAME) $(NAME).o
	./$(NAME)
	rm *.o $(NAME)

%.o: %.s
	nasm -f elf64 $<
