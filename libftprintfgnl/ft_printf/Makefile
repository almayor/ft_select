# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user <user@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/26 02:09:26 by unite             #+#    #+#              #
#    Updated: 2020/10/23 20:09:42 by user             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

TESTFUNC_NAME = test_functional
TESTPERF_NAME = test_performance

################################################################################

SRC_NAME = \
complete_specifier/complete_specifier.c \
complete_specifier/functions/complete_specifier_b.c \
complete_specifier/functions/complete_specifier_c.c \
complete_specifier/functions/complete_specifier_f.c \
complete_specifier/functions/complete_specifier_i.c \
complete_specifier/functions/complete_specifier_o.c \
complete_specifier/functions/complete_specifier_p.c \
complete_specifier/functions/complete_specifier_s.c \
complete_specifier/functions/complete_specifier_u.c \
complete_specifier/functions/complete_specifier_x.c \
data_specifier/data_specifier.c \
data_specifier/functions/data_specifier_c.c \
data_specifier/functions/data_specifier_f.c \
data_specifier/functions/data_specifier_i.c \
data_specifier/functions/data_specifier_p.c \
data_specifier/functions/data_specifier_pc.c \
data_specifier/functions/data_specifier_s.c \
data_specifier/functions/data_specifier_u.c \
ft_asprintf.c \
ft_dprintf.c \
ft_printf.c \
ft_snprintf.c \
ft_sprintf.c \
ft_vasprintf.c \
ft_vdprintf.c \
ft_vprintf.c \
ft_vsnprintf.c \
ft_vsprintf.c \
parse_specifier/parse_specifier.c \
print_specifier/functions/print_specifier_b.c \
print_specifier/functions/print_specifier_c.c \
print_specifier/functions/print_specifier_f.c \
print_specifier/functions/print_specifier_i.c \
print_specifier/functions/print_specifier_o.c \
print_specifier/functions/print_specifier_p.c \
print_specifier/functions/print_specifier_s.c \
print_specifier/functions/print_specifier_u.c \
print_specifier/functions/print_specifier_x.c \
print_specifier/functions/print_specifier_xx.c \
print_specifier/print_specifier.c \
utils/get_ndigits_int.c \
utils/get_ndigits_uint.c \
utils/min.c \
utils/printing/pf_putchar.c \
utils/printing/pf_putfloat.c \
utils/printing/pf_putint.c \
utils/printing/pf_putnchar.c \
utils/printing/pf_puts.c \
utils/printing/pf_putuint.c \
validate_specifier/functions/validate_specifier_b.c \
validate_specifier/functions/validate_specifier_c.c \
validate_specifier/functions/validate_specifier_f.c \
validate_specifier/functions/validate_specifier_i.c \
validate_specifier/functions/validate_specifier_p.c \
validate_specifier/functions/validate_specifier_s.c \
validate_specifier/functions/validate_specifier_u.c \
validate_specifier/functions/validate_specifier_x.c \
validate_specifier/validate_specifier.c \

TESTFUNCSRC_NAME = \
main.c \
Unity/unity.c \

TESTPERFSRC_NAME = \
main.c \

################################################################################

PATHI = src
PATHS = src
PATHO = obj

PATHFT = libft
PATHFTA = $(PATHFT)/libft.a

PATHTESTFUNC = test/functional
PATHTESTFUNCI = $(PATHTESTFUNC)/src/Unity
PATHTESTFUNCS = $(PATHTESTFUNC)/src
PATHTESTFUNCO = $(PATHTESTFUNC)/obj

PATHTESTPERF = test/performance
PATHTESTPERFI = 
PATHTESTPERFS = $(PATHTESTPERF)/src
PATHTESTPERFO = $(PATHTESTPERF)/obj

################################################################################

COMPILE = gcc -c
LINK = gcc

CFLAGS = -Wall -Wextra -Werror -Wno-unused-result
CFLAGS += -I$(PATHI) -I$(PATHFT)
CFLAGS_OPTIMISE = -O3 -std=gnu11 -ffast-math -march=native
CFLAGS_DEPEND = -MMD

CFLAGS_TESTFUNC = -I$(PATHTESTFUNCI)
CFLAGS_TESTPERF = -I$(PATHTESTPERFI)

################################################################################

ifeq ($(DEBUG), 1)
	COMPILE += -g
endif

################################################################################

SRC = $(patsubst %.c, $(PATHS)/%.c, $(SRC_NAME))
OBJ = $(patsubst %.c, $(PATHO)/%.o, $(SRC_NAME))

$(NAME) : $(OBJ) $(PATHFT)/libft.a
	cp $(PATHFTA) $(NAME)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(PATHO)/%.o : $(PATHS)/%.c
	mkdir -p $(@D)
	$(COMPILE) $(CFLAGS) $(CFLAGS_DEPEND) $(CFLAGS_OPTIMISE) $< -o $@

################################################################################

TESTFUNCSRC = $(patsubst %.c, $(PATHTESTFUNCS)/%.c, $(TESTFUNCSRC_NAME))
TESTFUNCOBJ = $(patsubst %.c, $(PATHTESTFUNCO)/%.o, $(TESTFUNCSRC_NAME))

$(PATHTESTFUNC)/$(TESTFUNC_NAME) : $(NAME) $(TESTFUNCOBJ)
	$(LINK) $^ -o $@

$(PATHTESTFUNCO)/%.o : $(PATHTESTFUNCS)/%.c
	mkdir -p $(@D)
	$(COMPILE) $< -o $@ -I . -I $(PATHTESTFUNCI) $(CFLAGS_TESTFUNC)

################################################################################

TESTPERFSRC = $(patsubst %.c, $(PATHTESTPERFS)/%.c, $(TESTPERFSRC_NAME))
TESTPERFOBJ = $(patsubst %.c, $(PATHTESTPERFO)/%.o, $(TESTPERFSRC_NAME))

$(PATHTESTPERF)/$(TESTPERF_NAME) : $(NAME) $(TESTPERFOBJ)
	$(LINK) $^ -o $@

$(PATHTESTPERFO)/%.o : $(PATHTESTPERFS)/%.c
	mkdir -p $(@D)
	$(COMPILE) $< -o $@ -I . $(CFLAGS_TESTPERF)

################################################################################

.DEFAULT_GOAL = all

.PHONY : all clean fclean re test-functional test-performance test docs libft

all : libft $(NAME)

fclean : clean
	rm -f $(NAME)
	$(MAKE) -C $(PATHFT) fclean

clean :
	rm -rf $(PATHO)
	rm -rf $(PATHTESTFUNCO) $(PATHTESTFUNC)/$(TESTFUNC_NAME)
	rm -rf $(PATHTESTPERFO) $(PATHTESTPERF)/$(TESTPERF_NAME)
	$(MAKE) -C $(PATHFT) clean

re : fclean all

test : test-functional test-performance

test-functional : $(NAME) $(PATHTESTFUNC)/$(TESTFUNC_NAME)
	@echo "\n========= FUNCTIONAL TESTS =========\n"
	$(PATHTESTFUNC)/$(TESTFUNC_NAME) 2>/dev/null

test-performance : $(NAME) $(PATHTESTPERF)/$(TESTPERF_NAME)
	@echo "\n========= PERFORMANCE TESTS =========\n"
	$(PATHTESTPERF)/$(TESTPERF_NAME) 2>/dev/null

libft $(PATHFT)/libft.a :
	$(MAKE) -C $(PATHFT)

docs :
	docs/.doxygen/42toDoxygen.sh

################################################################################

DEP = $(patsubst %.c, $(PATHO)/%.d, $(SRC_NAME))

-include $(DEP)

################################################################################
