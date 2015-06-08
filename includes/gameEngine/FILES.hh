//
// FILES.hh for CPP_BOMBERMAN in /home/Jamais/cpp_bomberman
//
// Made by Jamais
// Login   <Jamais@epitech.net>
//
// Started on  Sun May 24 03:05:21 2015 Jamais
// Last update Wed Jun  3 19:45:04 2015 Jamais
//

#ifndef		___FILES_HH___
# define	___FILES_HH___

# define	S(x)		std::string(x)

# define	ASSET		S("./assets/")

/*######################################*/
#define	MODEL		S(ASSET + S("Models/"))

# define	MAIN_CHARACTER		MODEL + S("marvin.fbx")
# define	BASIC_BOMB		MODEL + S("pumpkinScalled.fbx")

/*######################################*/
#define	TEXTURES		ASSET + S("Textures/")

# define	CRATE1			TEXTURES + S("crate.tga")
# define	CRATE2			TEXTURES + S("DangerousCrate.tga")
# define	LAVA1			TEXTURES + S("lava1.tga")
# define	FLOOR1			TEXTURES + S("paves1.tga")

# define		SKYBOXES TEXTURES + S("SkyBoxTextures/")

# define	STORMSKY		SKYBOXES + S("StormySky/") + S("StormySky")
# define	HELL			SKYBOXES + S("hell/hell")

#endif		/* !___FILES_HH___ */
