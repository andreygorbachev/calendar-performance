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

#include "IMM.h"

#include <dateconv.h>
#include <busday.h>

#include <chrono>
#include <string>
#include <iostream>

using namespace std;
using namespace std::chrono;



int main()
{
	auto err = SUCCESS;

	static char holiday_name[] = "NYM";
	static char holiday_file[] = "..\\..\\..\\isda-cds-model-calendar\\NYM.csv";
	err = JpmcdsHolidayLoadFromDisk(holiday_name, holiday_file);
	if (err != SUCCESS)
		return err;

	const auto& imm = make_IMM_dates();

	const auto from_year = 2022l;
	const auto until_year = 2067l;

	const auto start = high_resolution_clock::now();

	auto number_of_business_days = 0;
	for (auto year = from_year; year <= until_year; ++year)
	{
		for (const auto& imm_date : imm)
		{
			const auto date = JpmcdsDate(year, imm_date.month, imm_date.day);

			auto is_business_day = TBoolean{};
			err = JpmcdsIsBusinessDay(date, holiday_name, &is_business_day);
			if (err != SUCCESS)
				return err;

			if (is_business_day == TRUE)
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
