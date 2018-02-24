# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnugroho <rnugroho@students.42.fr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/01 20:07:00 by rnugroho          #+#    #+#              #
#    Updated: 2018/02/24 02:14:33 by rnugroho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME:=libftprintf.a
FILES:=ft_printf ft_vprintf ft_vasprintf ft_convert \
		ft_convert_numeric_1 ft_convert_numeric_2 ft_convert_numeric_3 \
		ft_convert_char \
		ft_convert_double_1 ft_convert_double_2 ft_convert_double_3 \
		ft_convert_color \
		ft_convert_date \
		ft_convert_data

# ----- Libft ------
LFTDIR:=./libft
# ==================

# ------------------
COMPILER:=clang
LINKER:=ar rc
SRCPATH:=src/
HDRPATH:=include/
CCHPATH:=obj/
IFLAGS:=-I $(HDRPATH) -I $(LFTDIR)/include
LFLAGS:=-L $(LFTDIR) -lft
CFLAGS:=-Wall -Wextra $(IFLAGS)
# ==================

# ----- Colors -----
BLACK:="\033[1;30m"
RED:="\033[1;31m"
GREEN:="\033[1;32m"
CYAN:="\033[1;35m"
PURPLE:="\033[1;36m"
WHITE:="\033[1;37m"
EOC:="\033[0;0m"
# ==================

# ------ Auto ------
SRC:=$(addprefix $(SRCPATH),$(addsuffix .c,$(FILES)))
OBJ:=$(addprefix $(CCHPATH),$(addsuffix .o,$(FILES)))
# ==================
CCHF:=.cache_exists

all: $(NAME)

$(NAME): $(OBJ)
	@cd $(LFTDIR) && $(MAKE)
	@echo $(CYAN) " - Compiling $@" $(RED)
	@$(LINKER) $(NAME) $(OBJ) $(LFTDIR)/$(CCHPATH)*.o $(LFTDIR)/$(CCHPATH)*/*.o
	@ranlib $(NAME)
	@echo $(GREEN) " - OK" $(EOC)

$(CCHPATH)%.o: $(SRCPATH)%.c | $(CCHF)
	@echo $(PURPLE) " - Compiling $< into $@" $(EOC)
	@$(COMPILER) $(CFLAGS) -c $< -o $@

%.c:
	@echo $(RED)"Missing file : $@" $(EOC)

$(CCHF):
	@mkdir $(CCHPATH)
	@touch $(CCHF)

clean:
	@rm -rf $(CCHPATH)
	@rm -f $(CCHF)
	@cd $(LFTDIR) && $(MAKE) clean

fclean: clean
	@rm -f $(NAME)
	@rm -f test_me
	@rm -rf test_me.dSYM/
	@rm -rf a.out.dSYM/
	@cd $(LFTDIR) && $(MAKE) fclean

re: fclean
	@$(MAKE) all

test: $(NAME)
	@echo "Files :" $(FILES)
	@$(COMPILER) -g -w $(CFLAGS) src/main.c $(SRC) $(LFLAGS) -o test_me

debug: $(NAME)
	@echo "Files :" $(FILES)
	@$(COMPILER) -g $(IFLAGS) src/main.c $(SRC) $(LFLAGS)

norm:
	@echo $(RED)
	@norminette $(SRC) $(HDRPATH) | grep -v	Norme -B1 || true
	@echo $(END)
	@cd $(LFTDIR) && $(MAKE) norm

.PHONY: all clean fclean re test norme
