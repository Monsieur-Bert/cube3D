# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antauber <antauber@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/08 08:19:19 by antauber          #+#    #+#              #
#    Updated: 2025/03/24 13:24:50 by antauber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	cube3D

## ########################################################################## ##
#   INGREDIENTS																  ##
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
SRCS		:=	cube3D.c\
				graphics/ray_caster.c	graphics/dda_algo.c\
				graphics/draw.c			graphics/graphics.c\
				graphics/hooks.c\
				parsing/init.c			parsing/create_tab.c\
				parsing/read_fd.c		parsing/read_fd_utils.c\
				parsing/maps.c			parsing/maps_utils.c\
				parsing/texture.c		parsing/texture_utils.c
SRCS		:=	$(SRCS:%=$(SRCS_DIR)/%)

BUILD_DIR	:=	.build
OBJS		:=	$(SRCS:$(SRCS_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS		:=	$(SRCS:$(SRCS_DIR)/%.c=$(BUILD_DIR)/%.d)

LIB_DIR		=	libft
LIBFT		=	libft/libft.a
MLX_DIR		=	minilibx-linux
MLX 		=	minilibx-linux/libmlx_Linux.a

## ########################################################################## ##
#   TOOLS																	  ##
## ########################################################################## ##
# CC			compiler
# CFLAGS		compiler flags
#
# RM			force recusfly remove
# DIR_UP		duplicate directory tree

MFLAG		=	--no-print-directory
SILENCE		=	--silent >/dev/null
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g -MMD -MP -pg

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

TOTAL_FILES		:=	$(words $(OBJS))
CURR_FILE		:=	0
BAR_LENGTH		:=	50
NAME_LENGTH		:=	50

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
#   RECIPES																	  ##
## ########################################################################## ##
# all			default goal
# $(NAME)		link .o -> archive file
# %.o			compilation .c -> .o
# clean			remove .o && directory tree
# fclean		remove .o && libft.a
# re			fclean && default goal


all: $(LIBFT) $(MLX) $(NAME)

$(NAME): $(OBJS)
	@printf "\n\n${BLUE}Linking objects into $(NAME)${RESET}\n"
	@$(CC) $(CFLAGS) $^ -L$(LIB_DIR) -lft -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz -o $@
	@echo "${GREEN}Binary $(NAME) successfully created${RESET}"

$(MLX):
	@printf "\n\n${BLUE}Linking objects into mlx.a${RESET}\n"
	@$(MAKE) $(MFLAG) -C $(MLX_DIR) $(SILENCE)
	@echo "${GREEN}Mlx.a successfully created${RESET}"

$(LIBFT):
	@$(MAKE) $(MFLAG) -C $(LIB_DIR)

$(BUILD_DIR)/%.o: $(SRCS_DIR)/%.c
	@$(DIR_DUP)
	$(PROGRESS_BAR)
	@$(CC) $(CFLAGS) -I$(INC) -I$(LIB_DIR) -I$(MLX_DIR) -O3 -o $@ -c $<

clean:
	@$(MAKE) $(MFLAG) -C $(LIB_DIR) clean
	@$(MAKE) $(MFLAG) -C $(MLX_DIR) clean $(SILENCE)
	@$(RM) $(BUILD_DIR)
	@echo "${RED}Build directory removed$(RESET)"

fclean: clean
	@$(MAKE) $(MFLAG) -C $(LIB_DIR) fclean $(SILENCE)
	@$(RM) $(MLX)
	@$(RM) $(NAME)
	@echo "${RED}Binary $(NAME) removed${RESET}"


re: fclean all

.PHONY: all bonus clean fclean re bonus

-include $(DEPS)
