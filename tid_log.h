#pragma once

#include <string>
#include <boost/smart_ptr/shared_ptr.hpp>

#include <boost/log/trivial.hpp>
#include <boost/log/sources/severity_channel_logger.hpp>

/*************************************************************************************************/
#define LOGDEBUG(logger)\
    BOOST_LOG_SEV((logger.LoggerModule), (boost::log::trivial::severity_level::debug))

#define LOGINFO(logger)\
    BOOST_LOG_SEV((logger.LoggerModule), (boost::log::trivial::severity_level::info))

#define LOGWARNING(logger)\
    BOOST_LOG_SEV((logger.LoggerModule), (boost::log::trivial::severity_level::warning))

#define LOGERROR(logger)\
    BOOST_LOG_SEV((logger.LoggerModule), (boost::log::trivial::severity_level::error))

/*************************************************************************************************/
class TIDLog
{
	using SeverityLevel = boost::log::trivial::severity_level;
	using ChannelLogger = boost::log::sources::severity_channel_logger<SeverityLevel, std::string>;

public:
	TIDLog(const std::string& dir, const std::string& channel);
	~TIDLog(void) {};

	static boost::shared_ptr<boost::log::core> core;
	ChannelLogger LoggerModule;
};