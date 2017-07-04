#include <opencv2\opencv.hpp>
#include <stdio.h>
#include <stdlib.h>
#define pause system("pause")

using namespace cv;

Mat ReadImg(char *, const char *);	//讀取圖片檔案
Mat AddImg(Mat, Mat);	//圖片相加
Mat Pix_visit(Mat a,int pix_scalar);	// 像素尋訪
int main()
{
	const char *path1 = "C:\\Users\\bluesky\\Desktop\\green.jpg";
	const char *path2 = "C:\\Users\\bluesky\\Desktop\\blue.jpg";

	Mat a1 = ReadImg("a1", path1);
	Mat a2 = ReadImg("a2", path2);

	Mat result = AddImg(a1, a2);
	// 顯示結果圖片
	result = Pix_visit(result, 20);
	imshow("result", result);
	waitKey(0);
	pause;
	return 0;
}
Mat ReadImg(char* windowsname, const char* path)
{
	Mat a = imread(path);
	// imread 讀取失敗 會使data == NULL
	if (a.data != NULL)
	{
		imshow(windowsname, a);
	}
	else
	{
		printf("%s can't be read, maybe it's not exist\n", path);
		pause;
	}
	return a;
}
Mat AddImg(Mat input1, Mat input2)
{
	//Mat output;
	// output、input1、input2都必須為相同的rows、clos、type才行
	Mat output(input1.rows,input1.cols,input1.type());
	//output = input1 + input2; 等同add();
	add(input1, input2, output);
	return output;
}
Mat Pix_visit(Mat a, int pix)
{
	for (int row = 0; row < a.rows; row++)
	{
		for (int col = 0; col < a.cols; col++)
		{
			a.at<uchar>(row, col) += pix;
		}
	}
	return a;
}