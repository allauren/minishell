
.PHONY: all clean fclean re dclean

NAME = minishell
CC = clang
LIBFT = ft
LIBFT_NAME = $(LIBFT_DIR)libft.a
LIBFT_DIR = libft/
HEADER_PATH = includes
OBJS_PATH = objs
SRCS_PATH = srcs
DPDS_PATH = depend
INCL = -I $(HEADER_PATH) -I $(LIBFT_DIR)
CFLAGS = -g -Wall -Wextra $(INCL)
ifeq ($(FSA), 1)
CFLAGS += -fsanitize=address
endif

SRCS = $(addprefix $(SRCS_PATH)/,  \
	init_env.c main.c error.c display.c minishell.c minishell_utils.c ms_functions.c)
OBJS = $(SRCS:$(SRCS_PATH)/%.c=$(OBJS_PATH)/%.o)
DPDS = $(SRCS:$(SRCS_PATH)/%.c=$(DPDS_PATH)/%.d)
ERASE_LINE = '\r\033[K'
NC = '\033[0m'
RED = '\033[0;31m'
LRED = '\033[1;31m'
LBLUE = '\033[1;34m'
GREEN = '\033[0;32m'
LGREEN = '\033[1;32m'
ORANGE = '\033[0;33m'
YELLOW = '\033[1;33m'

all: $(NAME)

$(NAME): $(LIBFT_NAME) $(OBJS)
	$(CC)  $(CFLAGS) -o $(NAME) $(OBJS) -L./$(LIBFT_DIR) -l$(LIBFT)

$(LIBFT_NAME):
	@make -C $(LIBFT_DIR)

$(OBJS_PATH)/%.o:
	$(CC) $(CFLAGS) -o $@ -c $(@:$(OBJS_PATH)/%.o=$(SRCS_PATH)/%.c)

$(DPDS_PATH)/%.d: $(SRCS_PATH)/%.c
	$(CC) $(CFLAGS) -MM $^ | sed -e '1s/^/$(OBJS_PATH)\//' > $@

clean:
	@make -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

dclean:
	rm -f $(DPDS)

fclean:
	@make -C $(LIBFT_DIR) fclean
	rm -f $(OBJS)
	rm -f $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all

-include $(DPDS)
