#ifndef ASCNCONFIG_H
#define ASCNCONFIG_H

#include <fstream>
#include <string>
#include <map>
#include "ascnpaths.h"

namespace config {
	class ascnconfig {
	public:
		ascnconfig(std::string appName, bool importFromFile=false);
		ascnconfig(std::string orgName, std::string appName, bool importFromFile=false);
		~ascnconfig();

		/** CONFIG LOAD/SAVE **/
		bool loadConfig();
		bool loadConfig(std::string filename);
		bool saveConfig();
		bool saveConfig(std::string filename);

		/** CONFIG API **/
		std::string getValue(std::string key);
		int getValue(std::string key);
		bool getValue(std::string key);

	private:

	};
}

#endif //ASCNCONFIG_H
