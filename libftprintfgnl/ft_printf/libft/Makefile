# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: unite <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/26 02:09:26 by unite             #+#    #+#              #
#    Updated: 2020/07/16 12:20:27 by unite            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_NAME = \
ft_abs.c \
ft_atoi.c \
ft_bzero.c \
ft_calloc.c \
ft_isalnum.c \
ft_isalpha.c \
ft_isascii.c \
ft_isdigit.c \
ft_isprint.c \
ft_isspace.c \
ft_itoa.c \
ft_max.c \
ft_memalloc.c \
ft_memccpy.c \
ft_memchr.c \
ft_memcmp.c \
ft_memcpy.c \
ft_memdel.c \
ft_memmove.c \
ft_memset.c \
ft_min.c \
ft_power.c \
ft_putchar.c \
ft_putchar_fd.c \
ft_putendl.c \
ft_putendl_fd.c \
ft_putnbr.c \
ft_putnbr_fd.c \
ft_putnstr.c \
ft_putnstr_fd.c \
ft_puts.c \
ft_putstr.c \
ft_putstr_fd.c \
ft_sqrt.c \
ft_strcapitalize.c \
ft_strcat.c \
ft_strcchr.c \
ft_strchr.c \
ft_strclr.c \
ft_strcmp.c \
ft_strcpy.c \
ft_strdel.c \
ft_strdup.c \
ft_strequ.c \
ft_strintab.c \
ft_striter.c \
ft_striteri.c \
ft_strjoin.c \
ft_strlast.c \
ft_strlcat.c \
ft_strlcpy.c \
ft_strlen.c \
ft_strmap.c \
ft_strmapi.c \
ft_strncat.c \
ft_strncmp.c \
ft_strncpy.c \
ft_strndup.c \
ft_strnequ.c \
ft_strnew.c \
ft_strnstr.c \
ft_strrchr.c \
ft_strrev.c \
ft_strsplit.c \
ft_strstr.c \
ft_strsub.c \
ft_strtrim.c \
ft_tolower.c \
ft_toupper.c \

################################################################################

PATHI = .
PATHS = src
PATHO = obj

################################################################################

COMPILE = gcc -c
LINK = gcc

CFLAGS = -Wall -Wextra -Werror
CFLAGS += -I$(PATHI)

CFLAGS_OPTIMISE = -O3 -std=gnu11 -ffast-math -march=native
CFLAGS_DEPEND = -MMD

################################################################################

ifeq ($(DEBUG), 1)
	COMPILE += -g
endif

################################################################################

SRC = $(patsubst %.c, $(PATHS)/%.c, $(SRC_NAME))
OBJ = $(patsubst %.c, $(PATHO)/%.o, $(SRC_NAME))

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(PATHO)/%.o : $(PATHS)/%.c
	mkdir -p $(@D)
	$(COMPILE) $(CFLAGS) $(CFLAGS_DEPEND) $(CFLAGS_OPTIMISE) $< -o $@

################################################################################

DEP = $(patsubst %.c, $(PATHO)/%.d, $(SRC_NAME))

-include $(DEP)

################################################################################

.PHONY : all clean fclean re docs

all : $(NAME)

fclean : clean
	rm -f $(NAME)

clean :
	rm -rf $(PATHO)

re : fclean all

docs :
	docs/.doxygen/42toDoxygen.sh

################################################################################
