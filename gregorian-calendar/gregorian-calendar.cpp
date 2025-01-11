// The MIT License (MIT)
//
// Copyright (c) 2025 Andrey Gorbachev
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
#include "IMM.h"

#include <calendar.h>

#include <chrono>
#include <string>
#include <iostream>

using namespace std;
using namespace std::chrono;

using namespace gregorian;



int main()
{
	const auto& nym = make_NYM_calendar();

	const auto& imm = make_IMM_dates();

	const auto& from_until = nym.get_schedule().get_from_until();
	const auto& from_year = from_until.get_from().year();
	const auto& until_year = from_until.get_until().year();

	const auto start = high_resolution_clock::now();

	auto number_of_business_days = 0;
	for (auto year = from_year; year <= until_year; ++year)
	{
		for (const auto& imm_date : imm)
		{
			const auto date = year / imm_date;
			if (nym.is_business_day(date))
				++number_of_business_days;
		}
	}

	const auto stop = high_resolution_clock::now();

	cout << "Number of business days: "s << number_of_business_days << endl;

	const auto duration = duration_cast<microseconds>(stop - start);
	cout
		<< " Duration: "s
		<< duration.count()
		<< " microseconds."s
		<< endl;

	return 0;
}
