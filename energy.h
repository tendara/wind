#pragma once
#include<opencv2/opencv.hpp>
#include<iostream>
#include<vector>

using namespace cv;
using namespace std;
class wind
{
private:
	
	Mat picb;//Ԥ�����ͼ��
	Mat pica;//Ԥ����ǰͼ��
	Point2f points[4];//���ε��ĸ�����
	Point2f cen;//���ε����ĵ�
public:
	
	
	wind(Mat a);
	void prib();//Ԥ������
	void prir();//Ԥ�����
	Mat& getpica();

	void showwind();

};
