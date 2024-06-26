
INC=%%%%

INCLIB=$(INC)/../lib

UNAME := $(shell uname)

CFLAGS= -I$(INC) -O3 -I.. -g

NAME= fractol
SRC = main.c color_utils.c algorithms.c math_utils.c string_utils.c ux_utils.c init_utils.c selection_utils.c events_utils.c graphic_utils.c phoenix_algorithm.c ft_dtoa.c dummy_utils.c 
OBJ = $(SRC:%.c=%.o)

LFLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

ifeq ($(UNAME), Darwin)
	# mac
	CC = clang
else ifeq ($(UNAME), FreeBSD)
	# FreeBSD
	CC = clang
else
	#Linux and others...
	CC	= gcc
	LFLAGS += -lbsd
endif

all: $(NAME)

	
$(NAME): $(OBJ)
	@make -C mlx_linux
	$(CC) -o $(NAME) $(OBJ) $(LFLAGS)

show:
	@printf "UNAME		: $(UNAME)\n"
	@printf "NAME  		: $(NAME)\n"
	@printf "CC		: $(CC)\n"
	@printf "CFLAGS		: $(CFLAGS)\n"
	@printf "LFLAGS		: $(LFLAGS)\n"
	@printf "SRC		:\n	$(SRC)\n"
	@printf "OBJ		:\n	$(OBJ)\n"

clean:
	rm -f $(NAME) $(OBJ) *~ core *.core

re: clean all
