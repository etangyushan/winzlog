/*
 * This file is part of the zlog Library.
 *
 * Copyright (C) 2011 by Hardy Simpson <HardySimpson@gmail.com>
 *
 * The zlog Library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * The zlog Library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with the zlog Library. If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include "zlog.h"

//必要的定义
zlog_category_t* ftl_log;
zlog_category_t* err_log;
zlog_category_t* wrn_log;
zlog_category_t* dbg_log;
zlog_category_t* inf_log;
zlog_category_t* ntc_log;
#define LOG4C_CATEGORY_FTL "FTL"
#define LOG4C_CATEGORY_ERR "ERR"
#define LOG4C_CATEGORY_WRN "WRN"
#define LOG4C_CATEGORY_DBG "DBG"
#define LOG4C_CATEGORY_INF "INF"
#define LOG4C_CATEGORY_NTC "NTC"

int init_config_zlog (char *logfile)
{
	//zlog 初始化
	if (zlog_init(logfile)) 
	{
		printf("init program logfile failed: %s\n", logfile);
		return -1;
	}

	ftl_log = zlog_get_category(LOG4C_CATEGORY_FTL);
	err_log = zlog_get_category(LOG4C_CATEGORY_ERR);
	wrn_log = zlog_get_category(LOG4C_CATEGORY_WRN);
	dbg_log = zlog_get_category(LOG4C_CATEGORY_DBG);
	inf_log = zlog_get_category(LOG4C_CATEGORY_INF);
	ntc_log = zlog_get_category(LOG4C_CATEGORY_NTC);

	zlog_debug(dbg_log, "zlog init ok");

	return 0;
}


void free_config_zlog ()
{
   //zlog 释放资源
	zlog_fini();
}

int main(int argc, char** argv)
{
 
	char *zlogfile = "zlog.conf";
    
	//初始化zlog
	if(init_config_zlog (zlogfile))
	{
		printf("init program logfile failed: %s\n", zlogfile);
		return -1;
	}

    //根据配置输出日志
	zlog_debug(dbg_log, "zlog_debug ok");
	zlog_info(inf_log, "zlog_info ok");
	zlog_notice(ntc_log, "zlog_notice ok");
	zlog_warn(wrn_log, "zlog_warn ok");
	zlog_error(err_log, "zlog_error ok");
	zlog_fatal(ftl_log, "zlog_fatal ok");
 

	//释放zlog资源
	free_config_zlog ();
	getchar();
	
	return 0;
}
