NAME := fractol
CFLAGS := -Ofast -O3
# CFLAGS := -Wall -Wextra -Werror -Wunreachable-code -Ofast
LIBMLX := ./MLX42/

HEADERS := -I ./ -I $(LIBMLX)/include/MLX42
LIBS    := $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm 
# -framework Cocoa -framework OpenGL -framework IOKit # For macos
# LIBS    := $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm # For linux
MANDATORY_SRCS     := main.c
MANDATORY_OBJS_DIR := ./objects/
MANDATORY_SRCS_OBJS:= ${MANDATORY_SRCS:.c=.o}
MANDATORY_OBJS     := $(addprefix $(MANDATORY_OBJS_DIR), $(MANDATORY_SRCS_OBJS))

# Libft
LIBFT_NAME = libft.a
LIBFT_DIR := ./libft/
LIBFT = $(addprefix $(LIBFT_DIR), $(LIBFT_NAME))

all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(MANDATORY_OBJS_DIR)%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"

$(MANDATORY_OBJS_DIR):
	@mkdir -p $(MANDATORY_OBJS_DIR)

$(NAME): $(LIBFT) $(MANDATORY_OBJS_DIR) $(MANDATORY_OBJS)
	@$(CC) $(MANDATORY_OBJS) $(LIBS) $(LIBFT) $(HEADERS) -o $(NAME)

$(LIBFT) : 
	@$(MAKE) -C $(LIBFT_DIR)
	@echo "Created Libft"

clean:
	@rm -rf $(MANDATORY_OBJS_DIR)
	@$(MAKE) clean -C $(LIBFT_DIR)
	@rm -rf $(LIBMLX)/build

fclean: fclean
	@rm -rf $(MANDATORY_OBJS_DIR)
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx, libft

