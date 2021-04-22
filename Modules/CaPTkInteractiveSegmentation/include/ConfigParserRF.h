/**
contact: software@cbica.upenn.edu
Copyright (c) 2018 University of Pennsylvania. All rights reserved.
Use of this source code is governed by license located in license file:
https://github.com/CBICA/InciSe/blob/main/LICENSE
**/
#include <opencv2/ml.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <fstream>

namespace ConfigParserRF
{
	void Parse(std::string filePath, double &trainingSamplePercentage, int &maxDepth, double &minSampleCountPercentage,
               int &maxCategories, int &activeVarCount, int &numberOfTrees, cv::Mat &priors);

	void PrintParseResult(double trainingSamplePercentage, int maxDepth, double minSampleCountPercentage,
                          int maxCategories, int activeVarCount, int numberOfTrees, cv::Mat &priors);

	void PrintParseResultToFile(std::string filePath, double trainingSamplePercentage, int maxDepth, double minSampleCountPercentage,
	                            int maxCategories, int activeVarCount, int numberOfTrees, cv::Mat &priors);
}