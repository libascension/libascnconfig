#include "ascnpaths.h"

#ifdef __unix
std::string paths::getConfigPath()
{
	std::string configPath;

	if ((configPath = std::string(getenv("XDG_CONFIG_HOME"))) == NULL)
	{
		struct passwd* user = getpwuid(getuid());
		std::stringstream ss;

		configPath = std::string(user->pw_dir);

		delete user;

		ss << configPath << "/.config/";
		configPath = ss.str();
	}

	return configPath;
}
#elif __WIN32
std::string paths::getConfigPath()
{
	std::string configPath;

	WCHAR path [MAX_PATH];

	if (SUCCEEDED(SHGetFolderPath(NULL, CSIDL_APPDATA, NULL, 0, path)))
	{
		configPath = std::string(path);
	}
	else
		configPath = NULL;
}
#endif
