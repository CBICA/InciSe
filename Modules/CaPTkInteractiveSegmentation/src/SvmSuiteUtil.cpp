/**
contact: software@cbica.upenn.edu
Copyright (c) 2018 University of Pennsylvania. All rights reserved.
Use of this source code is governed by license located in license file:
https://github.com/CBICA/InciSe/blob/main/LICENSE
**/
#include "SvmSuiteUtil.h"

SvmSuiteUtil::Timer::Timer() {
	Reset();
}

void SvmSuiteUtil::Timer::Reset() {
	m_timestamp = std::chrono::high_resolution_clock::now();
}

float SvmSuiteUtil::Timer::Diff() {
	std::chrono::duration<float> fs = std::chrono::high_resolution_clock::now() - m_timestamp;
	return fs.count();
}