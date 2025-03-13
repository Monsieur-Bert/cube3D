# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antauber <antauber@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/10 07:40:01 by antauber          #+#    #+#              #
#    Updated: 2025/01/25 15:20:39 by antauber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	libft.a

## ########################################################################## ##
#	INGREDIENTS																  ##
## ########################################################################## ##
# INC			header file locations
#
# SRCS_DIR		source directory
# SRCS			source files
#
# BUILD_DIR		build directory
# OBJS			object files
# DEPS			dependencies files

INC			:=	includes

SRCS_DIR	:=	srcs
SRCS		:=	gnl/get_next_line.c		gnl/get_next_line_utils.c\
				lst/ft_lstadd_back.c	lst/ft_lstclear.c		lst/ft_lstiter.c\
				lst/ft_lstmap.c			lst/ft_lstsize.c		lst/ft_lstadd_front.c\
				lst/ft_lstdelone.c		lst/ft_lstlast.c		lst/ft_lstnew.c\
				maths/ft_abs.c			maths/ft_atoi.c			maths/ft_atol.c\
				maths/ft_itoa.c\
				maths/ft_max.c			maths/ft_min.c\
				maths/ft_pow.c			maths/ft_sqrt.c\
				mem/ft_bzero.c			mem/ft_free_tabstr.c	mem/ft_memcmp.c\
				mem/ft_memmove.c		mem/ft_calloc.c			mem/ft_memchr.c\
				mem/ft_memcpy.c			mem/ft_memset.c			mem/ft_free_mapi.c\
				str/ft_charinset.c		str/ft_isdigit.c		str/ft_strchr.c\
				str/ft_strjoin.c		str/ft_strmapi.c		str/ft_strtrim.c\
				str/ft_isalnum.c		str/ft_isprint.c		str/ft_strcmp.c\
				str/ft_strlcat.c		str/ft_strncmp.c		str/ft_substr.c\
				str/ft_isalpha.c		str/ft_isspace.c		str/ft_strdup.c\
				str/ft_strlcpy.c		str/ft_strnstr.c		str/ft_tolower.c\
				str/ft_isascii.c		str/ft_split.c			str/ft_striteri.c\
				str/ft_strlen.c			str/ft_strrchr.c		str/ft_toupper.c\
				str/ft_setsplit.c		str/ft_count_words.c	str/ft_count_wordset.c\
				str/ft_strjoinvar.c\
				print/ft_putchar_fd.c	print/ft_putnbr_fd.c	print/ft_putendl_fd.c\
				print/ft_putstr_fd.c\
				print/ft_printf.c		print/ft_printf_utils.c	print/ft_printf_utils_nbr.c\
				print/ft_print_tabi.c	print/ft_print_tabstr.c	print/ft_print_mapi.c
SRCS		:=	$(SRCS:%=$(SRCS_DIR)/%)

BUILD_DIR	:=	.build
OBJS		:=	$(SRCS:$(SRCS_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS		:=	$(SRCS:$(SRCS_DIR)/%.c=$(BUILD_DIR)/%.d)

## ########################################################################## ##
#	TOOLS																	  ##
## ########################################################################## ##
# CC			compiler
# CFLAGS		compiler flags
#
# RM			force recusfly remove
# DIR_UP		duplicate directory tree

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g -MMD -MP

RM			:=	rm -rf
DIR_DUP		=	mkdir -p $(@D)

# ########################################################################### ##
#	ANSI_CODES																  ##
## ########################################################################## ##

PREV_LINE	:=	\033[A

GREEN		:=	\033[1;32m
BLUE		:=	\033[1;34m
RED			:=	\033[1;31m
YELLOW		:=	\033[1;33m
RESET		:=	\033[0m

## ########################################################################## ##
#	PROGRESS BAR															  ##
## ########################################################################## ##

TOTAL_FILES	:=	$(words $(OBJS))
CURR_FILE	:=	0
BAR_LENGTH	:=	50
NAME_LENGTH	:=	50

define PROGRESS_BAR
	@$(eval CURR_FILE=$(shell echo $$(($(CURR_FILE) + 1))))
	@$(eval PERCENTAGE=$(shell echo $$(($(CURR_FILE) * 100 / $(TOTAL_FILES)))))
	@$(eval FILLED=$(shell echo $$(($(CURR_FILE) * $(BAR_LENGTH) / $(TOTAL_FILES)))))
	@printf "\rCompiling [%d/%d] %-$(NAME_LENGTH)s" $(CURR_FILE) $(TOTAL_FILES) "$(notdir $<)"
	@printf "\n"
	@printf "\r"
	@for i in `seq 1 $(FILLED)`; do printf "█"; done
	@for i in `seq 1 $$(($(BAR_LENGTH) - $(FILLED)))`; do printf "░"; done
	@printf " %3d%%" $(PERCENTAGE)
	@printf "$(PREV_LINE)\r"
endef

## ########################################################################## ##
#	RECIPES																	  ##
## ########################################################################## ##

all: $(NAME)

$(NAME): $(OBJS)
	@printf "\n\n${BLUE}Linking objects into libft.a${RESET}\n"
	@ar -rcs $@ $^
	@echo "${GREEN}Library $(NAME) successfully created${RESET}"

$(BUILD_DIR)/%.o: $(SRCS_DIR)/%.c
	@$(DIR_DUP)
	$(PROGRESS_BAR)
	@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

clean:
	@$(RM) $(BUILD_DIR)
	@echo "${RED}Build directory removed$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "${RED}Library $(NAME) removed${RESET}"

re: fclean all

.PHONY: all clean fclean re

-include $(DEPS)