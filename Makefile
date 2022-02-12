# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbouquet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/14 16:30:45 by fbouquet          #+#    #+#              #
#    Updated: 2017/05/16 13:44:41 by fbouquet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

#==========EXECUTABLES==========#

EXE= viewer

#=======COMPILER AND FLAGS======#

CC= g++
FLAGS= -std=c++11

#============HEADERS============#

HEADER= .
VTKHEADERS= /usr/local/opt/vtk/include/vtk-9.1/

#=============LIBS==============#

LIBS= -lvtkCommonExecutionModel-9.1 -lvtkIOCore-9.1 -lvtkCommonColor-9.1 -lvtkCommonCore-9.1 -lvtkFiltersSources-9.1 -lvtkInteractionStyle-9.1 -lvtkRenderingContextOpenGL2-9.1 -lvtkRenderingCore-9.1 -lvtkRenderingFreeType-9.1 -lvtkRenderingGL2PSOpenGL2-9.1 -lvtkRenderingOpenGL2-9.1
VTKLIB= /usr/local/opt/vtk/lib/

#============COLORS=============#

RED=\033[1;31m
GREEN=\033[1;32m
EOC=\033[0m

#=============LEM_IN============#

#SRCIN = $(addprefix ./srcs/, $(SRC))
SRCIN = main.cxx

OBJS= ${SRCIN:.cxx=.o}

#=============RULES=============#

all: $(EXE)

%.o: %.cxx Makefile $(HEADER) $(VTKHEADERS)
	$(CC) $(FLAGS) -c $< -o $@ -I $(HEADER) -I $(VTKHEADERS)
	@printf "$(GREEN)+$(EOC)"


$(EXE): $(OBJS)
	@echo "\t$(EXE)'s objects compiled"
	$(CC) $(FLAGS) -o $(EXE) -L $(VTKLIB) $^ $(LIBS)
	@echo "executable $(GREEN)$(EXE)$(EOC) created"
	@echo "$(GREEN)---------->>>$(EOC)"

clean:
	@rm -f $(OBJS)
	@echo "$(RED)[x]$(EOC) $(EXE)'s objects cleaned"

fclean:
	@rm -f $(OBJS)
	@echo "$(RED)[x]$(EOC) $(EXE)'s objects cleaned"
	@rm -f $(EXE)
	@echo "executable $(RED)$(EXE)$(EOC) removed"
	@echo "$(RED)<<<----------$(EOC)"

re: fclean all
