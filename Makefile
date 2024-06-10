# PROGAM NAME
NAME = push_swap

# COMPILATON FLAGS
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = /bin/rm -rf

# INCLUDE
INCLUDE = push_swap.h

# FILES TO COMPILE
SRCS =	srcs/main.c \
		srcs/algorithm/rythm.c \
		srcs/algorithm/special_cases.c \
		srcs/moves/lists.c \
		srcs/moves/moves_for_a.c \
		srcs/moves/moves_for_b.c \
		srcs/parser/parser.c \
		srcs/checks.c \
		srcs/utils.c


#OBJECTS (*.o)
OBJS = $(SRCS:.c=.o)

# ASCII COLORS #
BLACK=\033[0;30m
RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[0;33m
BLUE=\033[0;34m
MAG=\033[0;35m
CYAN=\033[0;36m
WHITE=\033[0;37m
PAPYRUS=\033[38;5;223m
END=\033[0m

# MAKEFILE ART #
define PUSH_SWAP
$(YELLOW)


█ ▄▄   ▄      ▄▄▄▄▄    ▄  █    ▄▄▄▄▄    ▄ ▄   ██   █ ▄▄  
█   █   █    █     ▀▄ █   █   █     ▀▄ █   █  █ █  █   █ 
█▀▀▀ █   █ ▄  ▀▀▀▀▄   ██▀▀█ ▄  ▀▀▀▀▄  █ ▄   █ █▄▄█ █▀▀▀  
█    █   █  ▀▄▄▄▄▀    █   █  ▀▄▄▄▄▀   █  █  █ █  █ █     
 █   █▄ ▄█               █             █ █ █     █  █    
  ▀   ▀▀▀               ▀               ▀ ▀     █    ▀   
                                               ▀         

$(END)
endef
export PUSH_SWAP

#RULES
# .SILENT:

.c.o: $(SRCS)
	$(CC) -I includes $(CFLAGS) -c $< -o $@ 

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C srcs/libft
	mv srcs/libft/libft.a .
	$(CC) $(CFLAGS) $(OBJS) libft.a -o $(NAME)
	echo "$$PUSH_SWAP"

sanitize:
	$(eval CFLAGS+=-fsanitize=address -g3)

sani: sanitize all

sunny_delight: sani

clean:
	$(RM) $(OBJS)
	$(RM) libft.a
	echo "objects removed"

fclean: clean
	$(RM) $(NAME)
	echo "executable removed"

re: fclean all

.PHONY: all clean fclean re sani sanitize sunny_delight

