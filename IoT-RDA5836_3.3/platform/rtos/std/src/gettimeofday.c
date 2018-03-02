/* 
 * Copyright (c) 2006-2016 RDA Microelectronics, Inc.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/


#include "time.h"
#include "tm.h"
#include "string.h"

/*  Get the current time of day and timezone information,
 *  putting it into *TV and *TZ.  If TZ is NULL, *TZ is not filled.
 *  Returns 0 on success, -1 on errors.  
 */
int gettimeofday(struct timeval *tv, struct timezone *tz)
{
    TM_SYSTEMTIME systemTime;
	
    memset(&systemTime, 0, sizeof(TM_SYSTEMTIME));
    if (TM_GetSystemTime(&systemTime))
    {
        if (tv)
        {
            tv->tv_sec = systemTime.uSecond; 
			tv->tv_usec = systemTime.uMilliseconds; 
			return 0; 
		}
    }

	return -1; 
    
}


