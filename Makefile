# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antauber <antauber@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/08 08:19:19 by antauber          #+#    #+#              #
#    Updated: 2025/04/07 14:41:52 by antauber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	cub3D
BONUS	=	cub3B
	
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
INC_B		:=	includes_bonus

SRCS_DIR	:=	srcs
SRCS		:=	cube3D.c\
				graphics/init_mlx.c			graphics/close_mlx.c\
				graphics/ray_caster.c		graphics/dda_algo.c\
				graphics/draw.c				graphics/graphics.c\
				graphics/handle_hooks.c		graphics/minimap.c\
				graphics/move_player.c		graphics/minimap_utils.c\
				parsing/init.c				parsing/create_tab.c\
				parsing/read_fd.c			parsing/read_fd_utils.c\
				parsing/maps.c				parsing/maps_utils.c\
				parsing/texture.c			parsing/texture_utils.c
SRCS		:=	$(SRCS:%=$(SRCS_DIR)/%)

SRCS_B_DIR	:=	srcs_bonus
SRCS_B		:=	cube3D.c\
				graphics/init_mlx.c			graphics/close_mlx.c\
				graphics/ray_caster.c		graphics/dda_algo.c\
				graphics/draw.c				graphics/graphics.c\
				graphics/handle_hooks.c		graphics/minimap.c\
				graphics/move_player.c		graphics/minimap_utils.c\
				graphics/draw_sprites.c\
				parsing/init.c				parsing/create_tab.c\
				parsing/read_fd.c			parsing/read_fd_utils.c\
				parsing/maps.c				parsing/maps_utils.c\
				parsing/texture.c			parsing/texture_utils.c\
				parsing/sprites_utils.c
SRCS_B		:=	$(SRCS_B:%=$(SRCS_B_DIR)/%)

BUILD_DIR	:=	.build
BUILD_DIR_B	:=	.build_bonus
OBJS		:=	$(SRCS:$(SRCS_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS		:=	$(SRCS:$(SRCS_DIR)/%.c=$(BUILD_DIR)/%.d)
OBJS_B        :=    $(SRCS_B:$(SRCS_B_DIR)/%.c=$(BUILD_DIR_B)/%.o)
DEPS_B        :=    $(SRCS_B:$(SRCS_B_DIR)/%.c=$(BUILD_DIR_B)/%.d)

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
CFLAGS		=	-Wall -Wextra -Werror -MMD -MP -g

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
TOTAL_FILES_B	:=	$(words $(OBJS_B))
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

define PROGRESS_BAR_BONUS
    @$(eval CURR_FILE=$(shell echo $$(($(CURR_FILE) + 1))))
    @$(eval PERCENTAGE=$(shell echo $$(($(CURR_FILE) * 100 / $(TOTAL_FILES_B)))))
    @$(eval FILLED=$(shell echo $$(($(CURR_FILE) * $(BAR_LENGTH) / $(TOTAL_FILES_B)))))
    @printf "\rCompiling [%d/%d] %-$(NAME_LENGTH)s" $(CURR_FILE) $(TOTAL_FILES_B) "$(notdir $<)"
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

bonus: $(LIBFT) $(MLX) $(BONUS)

$(NAME): $(OBJS)
	@printf "\n\n${BLUE}Linking objects into debug${RESET}\n"
	@$(CC) $(CFLAGS) $^ -L$(LIB_DIR) -lft -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz -o $@
	@echo "${GREEN}Binary $(NAME) successfully created${RESET}"
	
$(BONUS): $(OBJS_B)
	@printf "\n\n${BLUE}Linking objects into debug${RESET}\n"
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
	@$(CC) $(CFLAGS) -I$(INC) -I$(LIB_DIR) -I$(MLX_DIR) -O3 -Ofast -o $@ -c $<

$(BUILD_DIR_B)/%.o: $(SRCS_B_DIR)/%.c
	@$(DIR_DUP)
	$(PROGRESS_BAR_BONUS)
	@$(CC) $(CFLAGS) -I$(INC_B) -I$(LIB_DIR) -I$(MLX_DIR) -O3 -o $@ -c $<
	
clean:
	@$(MAKE) $(MFLAG) -C $(LIB_DIR) clean
	@$(MAKE) $(MFLAG) -C $(MLX_DIR) clean $(SILENCE)
	@$(RM) $(BUILD_DIR) $(BUILD_DIR_B)
	@echo "${RED}Build directory removed$(RESET)"

fclean: clean
	@$(MAKE) $(MFLAG) -C $(LIB_DIR) fclean $(SILENCE)
	@$(RM) $(MLX)
	@$(RM) $(NAME) $(BONUS) 
	@echo "${RED}Binary $(NAME) removed${RESET}"

re: fclean all

.PHONY: all bonus clean fclean re bonus

-include $(DEPS)
