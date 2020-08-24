#pragma once

#include <string>
#include <boost/smart_ptr/shared_ptr.hpp>

#include <boost/log/trivial.hpp>
#include <boost/log/sources/severity_channel_logger.hpp>

/*************************************************************************************************/
#define TIDLOG_TRACE(logger)\
    BOOST_LOG_SEV((logger.LoggerModule), (boost::log::trivial::severity_level::trace))

#define TIDLOG_DEBUG(logger)\
    BOOST_LOG_SEV((logger.LoggerModule), (boost::log::trivial::severity_level::debug))

#define TIDLOG_INFO(logger)\
    BOOST_LOG_SEV((logger.LoggerModule), (boost::log::trivial::severity_level::info))

#define TIDLOG_WARN(logger)\
    BOOST_LOG_SEV((logger.LoggerModule), (boost::log::trivial::severity_level::warning))

#define TIDLOG_ERROR(logger)\
    BOOST_LOG_SEV((logger.LoggerModule), (boost::log::trivial::severity_level::error))

#define TIDLOG_FATAL(logger)\
    BOOST_LOG_SEV((logger.LoggerModule), (boost::log::trivial::severity_level::fatal))

/*************************************************************************************************/
class TIDLog
{
	using SeverityLevel = boost::log::trivial::severity_level;
	using ChannelLogger = boost::log::sources::severity_channel_logger<SeverityLevel, std::string>;

public:
	TIDLog() = default;
	void init(const std::string& dir, const std::string& channel, const int rotation_size = 1024*1024);
	~TIDLog(void) {};

	static boost::shared_ptr<boost::log::core> core;
	ChannelLogger LoggerModule;
};