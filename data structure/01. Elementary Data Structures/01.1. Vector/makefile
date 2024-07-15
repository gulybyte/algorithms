NAME = static_imul_vector

all: $(NAME).o
	ld -s -o $(NAME) $(NAME).o
	./$(NAME)
	rm *.o $(NAME)

%.o: %.s
	nasm -f elf64 $<
