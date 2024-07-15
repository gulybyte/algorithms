NAME = main
ASSEMBLY_SRCS = $(wildcard *.s)
ASSEMBLY_OBJS = $(ASSEMBLY_SRCS:.s=.o)
CXX_SRC = $(NAME).cpp
CXX_OBJ = $(NAME).o

all: run

$(NAME): $(CXX_OBJ) $(ASSEMBLY_OBJS)
	g++ $(CXX_OBJ) $(ASSEMBLY_OBJS) -o $(NAME) -no-pie

$(CXX_OBJ): $(CXX_SRC)
	g++ -c $(CXX_SRC) -o $(CXX_OBJ)

%.o: %.s
	nasm -f elf64 $< -o $@

clean:
	rm -f $(CXX_OBJ) $(ASSEMBLY_OBJS) $(NAME)

run: $(NAME)
	./$(NAME)
	rm -f $(CXX_OBJ) $(ASSEMBLY_OBJS) $(NAME)
