##
## Makefile for CPP_BOMBERMAN in /home/paasch_j/cpp_bomberman
##
## Made by Johan Paasche
## Login   <paasch_j@epitech.net>
##
## Started on  Mon Apr 27 12:03:45 2015 Johan Paasche
## Last update Sun Jun 14 00:46:23 2015 Milox Thomas
##

GRAPHICALGAME	=	yes

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

CFLAGS		=	-W -Wall -Wextra -ansi -std=c++11	\
			-I $(INCLUDE_DIR)			\
			-I $(AI_INC_DIR)			\
			-I $(GRAPHICS_INC_DIR)			\
			-I $(MANAGER_INC_DIR)			\
			-I $(BOMBERMAN_INC_DIR)			\
			-I $(AI_CHAI_DIR)			\

MAKEFLAGS	+=	--warn-undefined-variables		\
			--warn-unused-variables			\
			--no-print-directory

LFLAGS		=	-I$(LIB_INCLUDE_DIR) -L$(LIB_DIR)libs/ $(LIBS) \
			-lgdl_gl -lfmod -lGL -lGLEW -ldl -lrt -lfbxsdk -lSDL2 -lpthread



#########################################################
#			TREE				#
#########################################################

LIBS		=	-lgdl_gl -lGL -lGLEW -ldl -lrt -lfbxsdk -lfmod -lSDL2 -lpthread
LIB_DIR		=	./lib/
LIB_INCLUDE_DIR	=	$(INCLUDE_DIR)lib/
INCLUDE_DIR	=	./includes/
BINARY_DIR	=	./bin/
SRC_DIR		=	./src/
OBJ_DIR		=	./obj/



#########################################################
#	 	ARTIFICIAL INTELLIGENCE			#
#########################################################

AI_SRC_DIR		=	$(addprefix $(SRC_DIR), ai/)
AI_OBJ_DIR		=	$(addprefix $(OBJ_DIR), ai/)
AI_INC_DIR		=	$(addprefix $(INCLUDE_DIR), ai)
AI_SRCS			=	$(addprefix $(AI_SRC_DIR), $(AI_SRC))
AI_OBJS			=	$(addsuffix .o, $(basename $(subst $(AI_SRC_DIR), $(AI_OBJ_DIR), $(AI_SRCS))))
AI_CHAI_DIR	=	./lib/src/

AI_SRC			=	Ia.cpp		\
				Node.cpp	\



#########################################################
#		   GAME ENGINE				#
#########################################################

GRAPHICS_SRC_DIR	=	$(addprefix $(SRC_DIR), graphics/)
GRAPHICS_OBJ_DIR	=	$(addprefix $(OBJ_DIR), graphics/)
GRAPHICS_INC_DIR	=	$(addprefix $(INCLUDE_DIR), gameEngine)
GRAPHICS_SRCS		=	$(addprefix $(GRAPHICS_SRC_DIR), $(GRAPHICS_SRC))
GRAPHICS_OBJS		=	$(addsuffix .o, $(basename $(subst $(GRAPHICS_SRC_DIR), $(GRAPHICS_OBJ_DIR), $(GRAPHICS_SRCS))))

GRAPHICS_SRC		=				\
				ABomb.cpp		\
				AFX.cpp			\
				AGameModel.cpp		\
				AGameObject.cpp		\
				BasicBomb.cpp		\
				Bonus.cpp			\
				Camera.cpp		\
				Character.cpp		\
				Collider.cpp		\
				ComplexObject.cpp	\
				Cube.hpp		\
				GameEngine.cpp		\
				GraphicString.cpp	\
				Geometric.cpp		\
				GeometryFactory.cpp	\
				Particle.cpp			\
				ParticleSystem.cpp	\
				Skybox.cpp		\
				VideoContext.cpp	\
				 # main.cpp

ifeq ($(GRAPHICALGAME),yes)
$(GRAPHICS_SRC) += main.cpp
else
$(BOMBERMAN_SRC) += main.cpp
endif

#########################################################
#		   ASSETMANAGER				#
#########################################################

MANAGER_SRC_DIR		=	$(addprefix $(SRC_DIR), manager/)
MANAGER_OBJ_DIR		=	$(addprefix $(OBJ_DIR), manager/)
MANAGER_INC_DIR		=	$(addprefix $(INCLUDE_DIR), manager)
MANAGER_SRCS		=	$(addprefix $(MANAGER_SRC_DIR), $(MANAGER_SRC))
MANAGER_OBJS		=	$(addsuffix .o, $(basename $(subst $(MANAGER_SRC_DIR), $(MANAGER_OBJ_DIR), $(MANAGER_SRCS))))

MANAGER_SRC		=				\
				Theme.cpp		\
				ThemeHandler.cpp	\
				SoundHandler.cpp	\
				AssetManager.cpp	\
				BoardHandler.cpp	\
				ScoreHandler.cpp	\
				ModelHandler.cpp	\

#########################################################
#		   GAME  CORE				#
#########################################################

BOMBERMAN_SRC_DIR	=	$(addprefix $(SRC_DIR), bomberman/)
BOMBERMAN_OBJ_DIR	=	$(addprefix $(OBJ_DIR), bomberman/)
BOMBERMAN_INC_DIR	=	$(addprefix $(INCLUDE_DIR), engine)
BOMBERMAN_SRCS		=	$(addprefix $(BOMBERMAN_SRC_DIR), $(BOMBERMAN_SRC))
BOMBERMAN_OBJS		=	$(addsuffix .o, $(basename $(subst $(BOMBERMAN_SRC_DIR), $(BOMBERMAN_OBJ_DIR), $(BOMBERMAN_SRCS))))

BOMBERMAN_SRC		=				\
				Bomberman.cpp		\
				Bomb.cpp		\
				Player.cpp		\
				Engine.cpp		\
				EThread.cpp		\
				AObj.cpp		\
				Board.cpp		\
				UnbreakableWall.cpp	\
				Crate.cpp		\
				ECondVar.cpp		\
				EThreadPool.cpp		\
				EMutex.cpp		\
				Explosion.cpp		\
				LauncherUI.cpp		\
				UIManager.cpp		\
				PlayUI.cpp		\
				SettingsUI.cpp		\
				AUI.cpp			\
				PauseUI.cpp		\
				Event.cpp		\
				Controller.cpp		\
				Binput.cpp		\
				CreditsUI.cpp		\
				Settings.cpp		\
				main.cpp		\

BOMBERMAN		=	bomberman
PRO			=	$(addprefix $(BINARY_DIR), $(BOMBERMAN))

OBJS			=	$(AI_OBJS)		\
				$(GRAPHICS_OBJS)	\
				$(MANAGER_OBJS)		\
				$(BOMBERMAN_OBJS)

SRCS			=	$(AI_SRCS)		\
				$(GRAPHICS_SRCS)	\
				$(MANAGER_SRCS)		\
				$(BOMBERMAN_SRCS)



#########################################################
#			RULES				#
#########################################################

FIRST		:=	$(shell test -d $(BINARY_DIR)		|| mkdir $(BINARY_DIR))		\
			$(shell test -d $(OBJ_DIR)		|| mkdir $(OBJ_DIR))		\
			$(shell test -d $(AI_OBJ_DIR)		|| mkdir $(AI_OBJ_DIR))		\
			$(shell test -d $(GRAPHICS_OBJ_DIR)	|| mkdir $(GRAPHICS_OBJ_DIR))	\
			$(shell test -d $(MANAGER_OBJ_DIR)	|| mkdir $(MANAGER_OBJ_DIR))	\
			$(shell test -d $(BOMBERMAN_OBJ_DIR)	|| mkdir $(BOMBERMAN_OBJ_DIR))

all		:
			@$(MAKE) $(BOMBERMAN) CC=$(CC) CFLAGS='$(CFLAGS)' MAKEFLAGS='$(MAKEFLAGS) -j4 -l4'


debug		:	$(FIRST) fclean
			@$(MAKE) $(BOMBERMAN) CC=$(CC) CFLAGS='$(CFLAGS) -g3' MAKEFLAGS='$(MAKEFLAGS) -j4 -l4'

$(BOMBERMAN)	:	$(PRO)
ifeq	($(LINKING), yes)
			@$(LINK) $(PRO) $(BOMBERMAN)
endif

$(OBJ_DIR)%.o	:	$(SRC_DIR)%.cpp
			@$(ECHO) $(COLOR_5)
			@$(CC) $(CFLAGS) -c $< -o $@ $(LFLAGS)
			@$(ECHO) $(COLOR_1)"$(CC)" $(COLOR_2) "$(CFLAGS)" $(COLOR_4)"$(LIBS)"$(COLOR_3)" $<"$(COLOR_5)"\n"
			@$(ECHO) $(COLOR_OFF)

$(PRO)		:	$(OBJS)
			@$(ECHO) $(COLOR_3) "\nLinking ...\n"$(COLOR_4)
			@$(CC) $(CFLAGS) $(OBJS) -o $(PRO) $(LFLAGS)
			@$(ECHO) $(COLOR_1)"$(CC)" $(COLOR_2) $(CFLAGS) $(LIBS) "\n"$(COLOR_3)$(OBJS)$(COLOR_5)"\n"
			@$(ECHO)	"	  ________ \n"
			@$(ECHO)	"	 |	  |\n"
			@$(ECHO)	"	 |	  |\n"
			@$(ECHO)	"	 |	  |\n"
			@$(ECHO)	"	 |	  |\n"
			@$(ECHO)	"	 |	  |\n"
			@$(ECHO)	"	 |	  | \n"
			@$(ECHO)	"	 |        | \n"
			@$(ECHO)	"	 |        |\n"
			@$(ECHO)      "       ___        ___\n"
			@$(ECHO)      "       \            / \n"
			@$(ECHO)       "        \          /\n"
			@$(ECHO)        "         \        /\n"
			@$(ECHO)         "          \      /\n"
			@$(ECHO)          "           \    /\n"
			@$(ECHO)           "            \  /\n"
			@$(ECHO)            "             \/\n"
			@$(ECHO) $(COLOR_4) $(PRO)"\n"
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

fclean		:	clean
			@$(ECHO) $(COLOR_3)"Deleting Binary ...\n"
			@$(RM) $(BOMBERMAN)
			@$(RM) $(PRO)
			@$(ECHO) $(COLOR_3)"Done\n"$(COLOR_OFF)

re		:	fclean all

test		:
			export LD_LIBRARY_PATH=./lib/libs/

.PHONY		:	all clean fclean re
