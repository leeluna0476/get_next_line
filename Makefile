.DEFAULT_GOAL = all

NAME=get_next_line
CC=cc
CFLAGS=-Wall -Wextra -Werror -g3 -fsanitize=address -MMD -MP -MF $(DEPS_DIR)/$*.d
SRCS= \
	 main.c \
	 get_next_line.c \
	 get_next_line_utils.c \

RM=rm -fr

OBJS_DIR=.objs
OBJS=$(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

DEPS_DIR=.deps
DEPS=$(addprefix $(DEPS_DIR)/, $(SRCS:.c=.d))
-include $(DEPS)

all: $(NAME)

$(NAME): $(OBJS)
	$(LINK.c) $(OUTPUT_OPTION) $(OBJS)

$(OBJS_DIR)/%.o: %.c | $(OBJS_DIR) $(DEPS_DIR)
	$(COMPILE.c) $(OUTPUT_OPTION) $<

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(DEPS_DIR):
	mkdir -p $(DEPS_DIR)

clean:
	$(RM) $(OBJS) $(DEPS)
	$(RM) $(OBJS_DIR) $(DEPS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE) all

.PHONY: all clean fclean re
