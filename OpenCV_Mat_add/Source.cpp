#include <opencv2\opencv.hpp>
#include <stdio.h>
#include <stdlib.h>
#define pause system("pause")

using namespace cv;

Mat ReadImg(char *, const char *);	//Ū���Ϥ��ɮ�
Mat AddImg(Mat, Mat);	//�Ϥ��ۥ[
Mat Pix_visit(Mat a,int pix_scalar);	// �����M�X
int main()
{
	const char *path1 = "C:\\Users\\bluesky\\Desktop\\green.jpg";
	const char *path2 = "C:\\Users\\bluesky\\Desktop\\blue.jpg";

	Mat a1 = ReadImg("a1", path1);
	Mat a2 = ReadImg("a2", path2);

	Mat result = AddImg(a1, a2);
	// ��ܵ��G�Ϥ�
	result = Pix_visit(result, 20);
	imshow("result", result);
	waitKey(0);
	pause;
	return 0;
}
Mat ReadImg(char* windowsname, const char* path)
{
	Mat a = imread(path);
	// imread Ū������ �|��data == NULL
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
	// output�Binput1�Binput2���������ۦP��rows�Bclos�Btype�~��
	Mat output(input1.rows,input1.cols,input1.type());
	//output = input1 + input2; ���Padd();
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