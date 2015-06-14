//

// SaveHandler.hh for Bomberman in
// /home/chambo_e/epitech/cpp_bomberman/includes/
//
// Made by Emmanuel Chambon
// Login   <chambo_e@epitech.eu>
//
// Started on  Wed May 20 15:53:00 2015 Emmanuel Chambon
// Last update Wed May 20 20:57:12 2015 Emmanuel Chambon
//

#pragma once
#ifndef SAVEHANDLER_HH_
#define SAVEHANDLER_HH_

#include "AAsset.hh"
#include "AObj.hh"
#include "rapidjson/rapidjson.h"
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/prettywriter.h"
#include "rapidjson/filereadstream.h"
#include "rapidjson/filewritestream.h"

class SaveHandler : public AAsset
{
public:
    SaveHandler();

public:
    void                                        save() const;
private:
    void                                        preload();
    void                                        loadSave(std::string const &);
};

#endif // SaveHandler_HH_
