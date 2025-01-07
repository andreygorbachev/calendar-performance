// The MIT License (MIT)
//
// Copyright (c) 2024 Andrey Gorbachev
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include "NYM.h"

#include <schedule.h>
#include <annual_holidays.h>
#include <weekend.h>
#include <business_day_conventions.h>

#include <chrono>


using namespace std;
using namespace std::chrono;

using namespace gregorian;



auto _make_NYM_schedule() -> schedule
{
	auto holidays = schedule::dates{
		year{ 2022 } / June / day{ 20u },
		year{ 2033 } / June / day{ 20u },
		year{ 2039 } / June / day{ 20u },
		year{ 2044 } / June / day{ 20u },
		year{ 2050 } / June / day{ 20u },
		year{ 2061 } / June / day{ 20u },
		year{ 2067 } / June / day{ 20u },
	};

	return schedule{
		days_period{ year{ 2022 } / FirstDayOfJanuary, year{ 2067 } / LastDayOfDecember },
		move(holidays)
	};
}

auto _make_NYM_calendar() -> calendar
{
	return calendar{
		SaturdaySundayWeekend,
		_make_NYM_schedule()
	};
}


auto make_NYM_calendar() -> const calendar&
{
	static const auto s = _make_NYM_calendar();
	return s;
}
