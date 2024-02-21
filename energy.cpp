#include"energy.h"
wind::wind(Mat a)
{
	this->picb = a;
 }
void wind::prib()
{
	
	Mat picl[3];
	split(this->picb, picl);
	Mat blue = picl[0] - picl[2];
	Mat wind;
	threshold(blue, wind, 125, 255, 0);
	//开运算
	morphologyEx(wind, wind, 2, getStructuringElement(0, Size(2, 2)));
	Mat mask = Mat::zeros(blue.rows + 2, blue.cols + 2, CV_8UC1);
	floodFill(wind, mask, Point(20, 20), 255);
	threshold(wind, wind, 125, 255, 1);
	morphologyEx(wind, wind, 3, getStructuringElement(0, Size(15, 15)));
	morphologyEx(wind, wind, 2, getStructuringElement(0, Size(6, 6)));
	imshow("pic2", wind);
	
	this->pica = wind;
}
void wind::prir()
{
	Mat picl[3];
	split(this->picb, picl);
	Mat blue = picl[2] - picl[0];
	Mat wind;
	threshold(blue, wind, 125, 255, 0);
	//开运算
	morphologyEx(wind, wind, 2, getStructuringElement(0, Size(2, 2)));
	Mat mask = Mat::zeros(blue.rows + 2, blue.cols + 2, CV_8UC1);
	floodFill(wind, mask, Point(20, 20), 255);
	threshold(wind, wind, 125, 255, 1);
	morphologyEx(wind, wind, 3, getStructuringElement(0, Size(15, 15)));
	morphologyEx(wind, wind, 2, getStructuringElement(0, Size(2, 2)));
	this->pica = wind;
}
void wind::showwind()
{
	vector<vector<Point>> con;
	findContours(this->pica, con, 1, 1);
	double areal = 10000;
	int lon = 0;//序号
	if (con.size() == 0)
	{
		imshow("pic", this->picb);
	
	}
	else
	{
		for (size_t i = 0; i < con.size(); i++)
		{
			if (contourArea(con[i]) < areal)
			{
				lon = i;
				areal = contourArea(con[i]);
			}
		}

		RotatedRect rrect = minAreaRect(con[lon]);
	
		rrect.points(this->points);
		this->cen = rrect.center;
		for (int i = 0; i < 4; i++)
		{
			if (i == 3)
			{
				line(this->picb, points[i], points[0], Scalar(0, 255, 0), 2, 8, 0);
				break;
			}
			line(this->picb, points[i], points[i + 1], Scalar(0, 255, 0), 2, 8, 0);
		}
		circle(this->picb, cen, 2, Scalar(0, 255, 0), 2, 8, 0);

		imshow("pic", this->picb);

		
		vector<vector<Point>>().swap(con);
	}
}
Mat& wind::getpica()
{
	return this->pica;
}