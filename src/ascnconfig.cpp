#include "ascnconfig.h"
using namespace config;

/** SINGLE CONFIGURATION ITEM **/

ConfigItem::ConfigItem()
{

}

ConfigItem::ConfigItem(std::string contents)
{
	m_content.s = contents;
}

ConfigItem::ConfigItem(int contents)
{
	m_content.i = contents;
}

ConfigItem::ConfigItem(double contents)
{
	m_content.r = contents;
}

ConfigItem::ConfigItem(bool contents)
{
	m_content.b = contents;
}

std::string ConfigItem::getString()
{
	return m_content.s;
}

int ConfigItem::getInt()
{
	return m_content.i;
}

double ConfigItem::getReal()
{
	return m_content.r;
}

bool ConfigItem::getBool()
{
	return m_content.b;
}

/** CONFIG OBJECT **/
ascnconfig::ascnconfig (std::string appName, bool importFromFile)
{
	m_app = appName;
	m_error = kNone;

	if (importFromFile)
		loadConfig();
}

ascnconfig::ascnconfig (std::string orgName, std::string appName, bool importFromFile)
{
	m_org = orgName;
	m_app = appName;
	m_error = kNone;

	if (importFromFile)
		loadConfig();
}
