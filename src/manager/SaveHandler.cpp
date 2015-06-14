//
// SaveHandler.cpp for Bomberman in
// /home/chambo_e/epitech/cpp_bomberman/src/bomberman/
//
// Made by Emmanuel Chambon
// Login   <chambo_e@epitech.eu>
//
// Started on  Wed May 20 15:53:08 2015 Emmanuel Chambon
// Last update Sat Jun 13 14:16:39 2015 Emmanuel Chambon
//

#include "SaveHandler.hh"

SaveHandler::SaveHandler()
{
	// preload();
	// save();
}

void SaveHandler::save() const
{
	rapidjson::Document doc;
	rapidjson::Document::AllocatorType& allocator = doc.GetAllocator();
	doc.SetObject();

	doc.AddMember("id", rapidjson::Value(static_cast<int>(time(0))), allocator);

	rapidjson::Value pls(rapidjson::kArrayType);

	//for (auto i : players) {
	rapidjson::Document player;
	player.SetObject();

	player.AddMember("name", "toto", allocator);
	player.AddMember("score", 150, allocator);
	player.AddMember("color", "blue", allocator);
	player.AddMember("ia", false, allocator);

	rapidjson::Value pos(rapidjson::kArrayType);
	pos.PushBack(15, allocator);
	pos.PushBack(16, allocator);
	player.AddMember("position", pos, allocator);

	pls.PushBack(player, allocator);
	//}

	doc.AddMember("players", pls, allocator);

	rapidjson::Value map(rapidjson::kArrayType);

	// for (size_t i = 0; i < board->size(); i++) {
	//      if ((*board)[i].size() == 0) {
	//              map.PushBack(::NONE, allocator);
	//              continue;
	//      }
	//      for (auto cas : (*board)[i]) {
	//              if (cas->getType() == CRATE || cas->getType() == UNBREAKABLE_WALL)
	//                      map.PushBack(cas->getType(), allocator);
	//      }
	// }

	doc.AddMember("map", map, allocator);

	std::stringstream tmp;

	tmp << doc["id"].GetInt();

	std::string outputPath("./assets/saves/" + tmp.str( ) + ".json");
	FILE* fp = fopen(outputPath.c_str(), "w");
	if (fp) {
		char buff[65536] = {0};
		rapidjson::FileWriteStream os(fp, buff, sizeof(buff));
		rapidjson::Writer<rapidjson::FileWriteStream> writer(os);
		doc.Accept(writer);
		fclose(fp);
	}
}

void SaveHandler::loadSave(std::string const &file)
{
	size_t pos;

	if ((pos = file.find_last_of(".")) != std::string::npos && file.substr(pos) == ".json") {
		FILE* fp = fopen(std::string(file).c_str(), "r");
		if (fp) {
			char buff[65536] = {0};
			rapidjson::FileReadStream is(fp, buff, sizeof(buff));
			rapidjson::Document d;

			std::cout << file << std::endl;

			try {
				if (d.ParseStream(is).HasParseError())
					throw std::invalid_argument(file + ": Invalid JSON file. Will not be loaded.");
			} catch (std::exception &e) {
				fclose(fp);
				throw;
			}
			// {
			// 	rapidjson::StringBuffer strbuf;
			// 	rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(strbuf);
			// 	d.Accept(writer);
			// 	std::cout << strbuf.GetString() << std::endl;
			// 	fclose(fp);
			// }
		}
	}

}

void SaveHandler::preload()
{
	DIR *dir;
	struct dirent *ent;
	// Container for async calls
	std::vector<std::future<void>>  f;

	if ((dir = opendir ("./assets/saves")) != NULL) {
		auto func = std::bind(&SaveHandler::loadSave, this, std::placeholders::_1);
		while ((ent = readdir (dir)) != NULL) {
			if (std::string(ent->d_name)[0] != '.')
				f.push_back(std::async (std::launch::async, func,
				                        "assets/saves/" + std::string(ent->d_name)));
		}
		try {
			for (auto i = f.begin(); i != f.end(); i++)
				i->get();
		} catch (std::invalid_argument &e) {
			std::cerr << e.what() << std::endl;
		}
		closedir (dir);
	} else {
		std::cerr << "Cannot open saves folder. They will not be available" << std::endl;
	}

}
