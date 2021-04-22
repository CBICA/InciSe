/**
contact: software@cbica.upenn.edu
Copyright (c) 2018 University of Pennsylvania. All rights reserved.
Use of this source code is governed by license located in license file:
https://github.com/CBICA/InciSe/blob/main/LICENSE
**/
#include "UtilImageToCvMatGTS.h"

void GeodesicTrainingSegmentation::ParserGTS::ScaleSomeOfTheColumns(cv::Mat& mat, int colStart, int colEnd, double ratio)
{
	for (int i_col = colStart; i_col <= colEnd; i_col++)
	{
		mat.col(i_col).convertTo(mat.col(i_col), CV_32F, ratio);
	}
}