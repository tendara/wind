#pragma once
#include<opencv2/opencv.hpp>
#include<iostream>
#include<vector>

using namespace cv;
using namespace std;
class wind
{
private:
	
	Mat picb;//预处理后图像
	Mat pica;//预处理前图像
	Point2f points[4];//矩形的四个顶点
	Point2f cen;//矩形的中心点
public:
	
	
	wind(Mat a);
	void prib();//预处理蓝
	void prir();//预处理红
	Mat& getpica();

	void showwind();

};
