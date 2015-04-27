##
## Makefile for CPP_BOMBERMAN in /home/paasch_j/cpp_bomberman
## 
## Made by Johan Paasche
## Login   <paasch_j@epitech.net>
## 
## Started on  Mon Apr 27 12:03:45 2015 Johan Paasche
## Last update Mon Apr 27 13:07:08 2015 Johan Paasche
##

#########################################################
#			BASICS				#
#########################################################
CC	=	g++
RM	=	rm -f
RMDIR	=	rm -rf
ECHO	=	echo -ne
LINK	=	ln -fs
CAT	=	cat

COLOR_OFF	=	"\033[0m"
COLOR_1		=	"\033[32m"
COLOR_2		=	"\033[33m"
COLOR_3		=	"\033[34m"
COLOR_4		=	"\033[35m"
COLOR_5		=	"\033[36m"

LINKING		=	yes


#########################################################
#			FLAGS				#
#########################################################
CFLAGS		=	-W -Wall -Wextra -ansi -I$(INCLUDE_DIR)
MAKEFLAGS	+=	--warn-undefined-variables		\
			--warn-unused-variables			\
			--no-print-directory
LFLAGS		=	-I$(LIB_INCLUDE_DIR) -L$(LIB_DIR)/libs/ \
			-lgdl_gl -lGL -lGLEW -ldl -lrt -lfbxsdk -lSDL2 -lpthread



#########################################################
#			TREE				#
#########################################################
LIB_DIR		=	./lib/
LIB_INCLUDE_DIR	=	$(LIB_DIR)/includes/
INCLUDE_DIR	=	./include/
BINARY_DIR	=	./bin/
SRC_DIR		=	./src/
OBJ_DIR		=	./obj/



#########################################################
#	 	ARTIFICIAL INTELLIGENCE			#
#########################################################
AI_SRC_DIR		=	$(addprefix $(SRC_DIR), ai/)
AI_OBJ_DIR		=	$(addprefix $(OBJ_DIR), ai/)
AI_SRCS			=	$(addprefix $(AI_SRC_DIR), $(AI_SRC))
AI_OBJS			=	$(addsuffix .o, $(basename $(subst $(AI_SRC_DIR), $(AI_OBJ_DIR), $(AI_SRCS))))

AI_SRC			=	exemple.cpp		\



#########################################################
#	 	ARTIFICIAL INTELLIGENCE			#
#########################################################
GRAPHICS_SRC_DIR	=	$(addprefix $(SRC_DIR), graphics/)
GRAPHICS_OBJ_DIR	=	$(addprefix $(OBJ_DIR), graphics/)
GRAPHICS_SRCS		=	$(addprefix $(GRAPHICS_SRC_DIR), $(GRAPHICS_SRC))
GRAPHICS_OBJS		=	$(addsuffix .o, $(basename $(subst $(GRAPHICS_SRC_DIR), $(GRAPHICS_OBJ_DIR), $(GRAPHICS_SRCS))))

GRAPHICS_SRC		=	test.cpp		\



#########################################################
#		   GAME  CORE				#
#########################################################
BOMBERMAN_SRC_DIR	=	$(addprefix $(SRC_DIR), bomberman/)
BOMBERMAN_OBJ_DIR	=	$(addprefix $(OBJ_DIR), bomberman/)
BOMBERMAN_SRCS		=	$(addprefix $(BOMBERMAN_SRC_DIR), $(BOMBERMAN_SRC))
BOMBERMAN_OBJS		=	$(addsuffix .o, $(basename $(subst $(BOMBERMAN_SRC_DIR), $(BOMBERMAN_OBJ_DIR), $(BOMBERMAN_SRCS))))

BOMBERMAN_SRC		=	main.cpp		\


BOMBERMAN		=	bomberman
PRO			=	$(addprefix $(BINARY_DIR), $(BOMBERMAN))

OBJS			=	$(AI_OBJS)		\
				$(GRAPHICS_OBJS)	\
				$(BOMBERMAN_OBJS)

SRCS			=	$(AI_SRCS)		\
				$(GRAPHICS_SRCS)	\
				$(BOMBERMAN_SRCS)



#########################################################
#			RULES				#
#########################################################

FIRST		:=	$(shell test -d $(BINARY_DIR)		|| mkdir $(BINARY_DIR))		\
			$(shell test -d $(OBJ_DIR)		|| mkdir $(OBJ_DIR))		\
			$(shell test -d $(AI_OBJ_DIR)		|| mkdir $(AI_OBJ_DIR))		\
			$(shell test -d $(GRAPHICS_OBJ_DIR)	|| mkdir $(GRAPHICS_OBJ_DIR))	\
			$(shell test -d $(BOMBERMAN_OBJ_DIR)	|| mkdir $(BOMBERMAN_OBJ_DIR))

all		:
			@$(MAKE) $(BOMBERMAN) CC=$(CC) CFLAGS='$(CFLAGS)'

debug		:	$(FIRST) fclean
			@$(MAKE) $(BOMBERMAN) CC=$(CC) CFLAGS='$(CFLAGS) -g3'

$(BOMBERMAN)	:	$(PRO)
ifeq	($(LINKING), yes)
			@$(LINK) $(PRO) $(BOMBERMAN)
endif

$(OBJ_DIR)%.o	:	$(SRC_DIR)%.cpp
			@$(ECHO) $(COLOR_2)
			$(CC) $(CFLAGS) -c $< -o $@ $(LFLAGS)
			@$(ECHO) $(COLOR_OFF)

$(PRO)		:	$(OBJS)
			@$(ECHO) $(COLOR_3) "\nLinking ...\n"$(COLOR_4)
			$(CC) $(CFLAGS) $(OBJS) -o $(PRO) $(LFLAGS)
			@$(ECHO) $(COLOR_3) "\nDone.\n"$(COLOR_OFF)

clean		:
			@$(ECHO) $(COLOR_3)"Deleting AI source objects ...\n"
			@$(RM) $(AI_OBJS)
			@$(ECHO) $(COLOR_3)"Deleting Graphic source objects ...\n"
			@$(RM) $(GRAPHICS_OBJS)
			@$(ECHO) $(COLOR_3)"Deleting bomberman source objects ...\n"
			@$(RM) $(BOMBERMAN_OBJS)
			@$(ECHO) $(COLOR_3)"Deleting object directory ...\n"
			@$(RMDIR) $(OBJ_DIR)
			@$(ECHO) $(COLOR_3)"Deleting binary directory ...\n"
			@$(RMDIR) $(BINARY_DIR)
			@$(ECHO) "Done.\n"$(COLOR_OFF)

fclean		:	clean
			@$(ECHO) $(COLOR_3)"Deleting Binary ...\n"
			$(RM) $(BOMBERMAN)
			$(RM) $(PRO)
			@$(ECHO) $(COLOR_3)"Done\n"$(COLOR_OFF)

re		:	fclean all

.PHONY		:	all clean fclean re
