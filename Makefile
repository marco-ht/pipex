NAME = pipex

SRC_DIR = ./src
SRCB_DIR = ./bonus
GNL_DIR = ./bonus/gnl

SRC = $(SRC_DIR)/pipex.c \
	$(SRC_DIR)/utils.c \
	$(SRC_DIR)/utils2.c \
	$(SRC_DIR)/ft_split.c \
	$(SRC_DIR)/ft_split_2.c \

SRC_B = $(SRCB_DIR)/pipex_bonus.c \
	$(SRCB_DIR)/utils_bonus.c \
	$(SRCB_DIR)/utils_bonus2.c \
	$(SRC_DIR)/utils.c \
	$(SRC_DIR)/ft_split.c \
	$(SRC_DIR)/ft_split_2.c \
	$(GNL_DIR)/get_next_line.c \
	$(GNL_DIR)/get_next_line_utils.c

OBJS = $(SRC:.c=.o)
OBJS_B = $(SRC_B:.c=.o)

CC = gcc
CFLAGS = -Werror -Wall -Wextra
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus: $(OBJS_B)
	$(CC) $(CFLAGS) $(OBJS_B) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(OBJS_B)

fclean: clean
	$(RM) $(NAME)

re: fclean all
