#ifndef ASCNCONFIG_H
#define ASCNCONFIG_H

#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include "ascnpaths.h"

namespace config {

	enum configError_t {
		kNone,
		kKeyNotFound,
		kInvalidKey,
		kUnknownKeyError,
		kFileNotFound
	};

	union configItem_u {
		std::string s;
		int i;
		double r;
		bool b;
	};

	class ConfigItem {
	public:
		ConfigItem();
		ConfigItem(std::string contents);
		ConfigItem(int contents);
		ConfigItem(double contents);
		ConfigItem(bool contents);

		~ConfigItem();

		std::string getString();
		int getInt();
		double getReal();
		bool getBool();
	private:
		configItem_u m_content;
	};

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
		ConfigItem getValue(std::string key);

		bool setValue(std::string key, std::string value);
		bool setValue(std::string key, int value);
		bool setValue(std::string key, bool value);

		/** CONFIGURE CONFIGURATION OBJECT (hehe) **/
		void setAppName(std::string appName);
		void setOrgName(std::string orgName);
		void setAppQualified(std::string orgName, std::string appName);

	private:
		bool importSettings(std::string fname);
		bool exportSettings(std::string fname);
		std::map<std::string,ConfigItem*> m_settings;

		std::string m_org, m_app;

		configError_t m_error;
	};
}

#endif //ASCNCONFIG_H
