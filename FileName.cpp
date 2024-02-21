#include "energy.h"
#include<opencv2/opencv.hpp>
#include<iostream>
#include<vector>

using namespace cv;
using namespace std;

int main()
{
	int op = 0;
	cout << "��ѡ��ģʽ��1ѡ����ɫ��2ѡ���ɫ" << endl;
	cin >> op;
	VideoCapture video("C:\\Users\\18640\\Desktop\\wind.mp4");
	if (!video.isOpened())
	{
		cout << "�����ļ�·��" << endl;
		return -1;
	}
	if (op == 1)
	{
		while (1)
		{
			Mat pic;
			video >> pic;
			if (pic.empty())
			{
				break;
			}
			wind a(pic);
			a.prib();
			a.showwind();
			waitKey(100 / video.get(CAP_PROP_FPS));
		
		}
		
	}
	else
	{
		while (1)
		{
			Mat pic;
			video >> pic;
			if (pic.empty())
			{
				break;
			}
			wind a(pic);
			a.prir();
			a.showwind();
			waitKey(1000 / video.get(CAP_PROP_FPS));

		}
	}

	return 0;
	}