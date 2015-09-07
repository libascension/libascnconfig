#ifndef ASCNPATHS_H
#define ASCNPATHS_H

#include <string>

#ifdef __unix
	#include <cstdlib>
	#include <sstream>
	#include <unistd.h>
	#include <sys/types.h>
	#include <pwd.h>
#elif _WIN32
	#include <windows.h>
	#include <string>
#endif

namespace paths {
	std::string getConfigPath();
}

#endif //ASCNPATHS_H
