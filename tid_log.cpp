#include "tid_log.h"
#include <boost/filesystem.hpp>
#include <unordered_map>

#include <boost/log/expressions.hpp>
#include <boost/log/attributes.hpp>
#include <boost/log/sinks.hpp>
#include <boost/log/sinks/text_file_backend.hpp>
#include <boost/log/support/date_time.hpp>
#include <boost/log/sources/channel_feature.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>

namespace keywords = boost::log::keywords;
namespace sinks = boost::log::sinks;
namespace expr = boost::log::expressions;

boost::shared_ptr<boost::log::core> TIDLog::core = nullptr;

// dir-日志保存路径, channel-通道名称, 日志转存大小（字节, 默认1M）
void TIDLog::init(const std::string& dir, const std::string& channel, const int rotation_size)
{
	LoggerModule.channel(channel);
	core = boost::log::core::get();

	if (boost::filesystem::exists(dir) == false)
	{
		boost::filesystem::create_directories(dir);
	}

	boost::shared_ptr<sinks::text_file_backend> backend = boost::make_shared<sinks::text_file_backend>(
		keywords::file_name = dir + "/" + channel + "_%Y-%m-%d_%H-%M-%S_%N.log",
		keywords::rotation_size = rotation_size,
		keywords::time_based_rotation = sinks::file::rotation_at_time_point(0, 0, 0)
		);

	using sink_t = sinks::synchronous_sink<sinks::text_file_backend>;
	boost::shared_ptr<sink_t> sink(new sink_t(backend));
	
	sink->set_formatter(
		expr::stream
		<< "[" << expr::format_date_time<boost::posix_time::ptime>("TimeStamp", "%Y-%m-%d %H:%M:%S.%f") << "] "
		<< "[" << expr::attr<boost::log::aux::thread::id>("ThreadID") << "] "
		<< "[" << boost::log::trivial::severity << "] "
		<< expr::smessage);

	sink->set_filter(expr::attr<std::string>("Channel") == channel);
	core->add_sink(sink);
	boost::log::add_common_attributes();
};
