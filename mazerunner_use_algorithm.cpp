//#include <opencv2/opencv.hpp>
//#include <iostream>
//#include <time.h>
//#include <stdlib.h>
//using namespace cv;
//using namespace std;
//
//#define ALLSIZE 41
//#define PERCENT 70
//
//typedef struct MAP {
//	int allmapdata[ALLSIZE][ALLSIZE]; //테두기벽까지
//}Map;
//
//int location_x;
//int location_y;
//int direction;//진행방향 up 1 right 2 down 3 left 4
//int rightside; //진행방향 오른손 벽있으면 1 없으면 0
//int front; //전방 벽있으면1 없으면 0
//int blocksize = 1000 / ALLSIZE;
//Mat mapgraphic(1000, 1000, CV_8UC3, Scalar(255, 255, 255));
//Map mapdata;
//
//void check()
//{
//	if (direction == 1)
//	{
//		if (mapdata.allmapdata[location_x - 1][location_y] == 1)
//			front = 1;
//		else
//			front = 0;
//		if (mapdata.allmapdata[location_x][location_y + 1] == 1)
//			rightside = 1;
//		else
//			rightside = 0;
//	}
//	else if (direction == 2)
//	{
//		if (mapdata.allmapdata[location_x][location_y + 1] == 1)
//			front = 1;
//		else
//			front = 0;
//		if (mapdata.allmapdata[location_x + 1][location_y] == 1)
//			rightside = 1;
//		else
//			rightside = 0;
//	}
//	else if (direction == 3)
//	{
//		if (mapdata.allmapdata[location_x + 1][location_y] == 1)
//			front = 1;
//		else
//			front = 0;
//		if (mapdata.allmapdata[location_x][location_y - 1] == 1)
//			rightside = 1;
//		else
//			rightside = 0;
//	}
//	else if (direction == 4)
//	{
//		if (mapdata.allmapdata[location_x][location_y - 1] == 1)
//			front = 1;
//		else
//			front = 0;
//		if (mapdata.allmapdata[location_x - 1][location_y] == 1)
//			rightside = 1;
//		else
//			rightside = 0;
//	}
//}
//
//void move()
//{
//	if (rightside == 0 && front == 0)
//	{
//		direction += 1; //우회전
//		if (direction >= 5)
//			direction = 1;
//		if (direction == 1)//위로전진
//			location_x -= 1;
//		if (direction == 2)//우로전진
//			location_y += 1;
//		if (direction == 3)//아래로전진
//			location_x += 1;
//		if (direction == 4)//좌로전진
//			location_y -= 1;
//	}
//	else if (rightside == 1 && front == 0)
//	{
//		if (direction == 1)//위로전진
//			location_x -= 1;
//		if (direction == 2)//우로전진
//			location_y += 1;
//		if (direction == 3)//아래로전진
//			location_x += 1;
//		if (direction == 4)//좌로전진
//			location_y -= 1;
//	}
//	else if (rightside == 0 && front == 1)
//	{
//		direction += 1; //우회전
//		if (direction >= 5)
//			direction = 1;
//		if (direction == 1)//위로전진
//			location_x -= 1;
//		if (direction == 2)//우로전진
//			location_y += 1;
//		if (direction == 3)//아래로전진
//			location_x += 1;
//		if (direction == 4)//좌로전진
//			location_y -= 1;
//	}
//	else if (rightside == 1 && front == 1)
//	{
//		direction -= 1; //좌회전
//		if (direction <= 0)
//			direction = 4;
//
//		check();
//
//		if (front == 0)
//		{
//			if (direction >= 5)
//				direction = 1;
//			if (direction == 1)//위로전진
//				location_x -= 1;
//			if (direction == 2)//우로전진
//				location_y += 1;
//			if (direction == 3)//아래로전진
//				location_x += 1;
//			if (direction == 4)//좌로전진
//				location_y -= 1;
//		}
//	}
//}
//
//void graphic()
//{
//	for (int ii = 0; ii < ALLSIZE; ii++)
//	{
//		for (int jj = 0; jj < ALLSIZE; jj++)
//		{
//			if (mapdata.allmapdata[ii][jj] == 1)
//				mapgraphic(Rect(blocksize * ii, blocksize * jj, blocksize, blocksize)) = cv::Scalar(0, 0, 0);
//			else if (mapdata.allmapdata[ii][jj] == 0)
//				mapgraphic(Rect(blocksize * ii, blocksize * jj, blocksize, blocksize)) = cv::Scalar(255, 255, 255);
//			else if (mapdata.allmapdata[ii][jj] == 2)
//				mapgraphic(Rect(blocksize * ii, blocksize * jj, blocksize, blocksize)) = cv::Scalar(0, 255, 0);
//		}
//	}
//	for (int ii = 0; ii < ALLSIZE; ii++)
//	{
//		for (int jj = 0; jj < ALLSIZE; jj++)
//		{
//			if (mapdata.allmapdata[ii][jj] == 0)
//			{
//				int num = 0;
//				if (mapdata.allmapdata[ii + 1][jj] == 2)
//					num++;
//				if (mapdata.allmapdata[ii][jj + 1] == 2)
//					num++;
//				if (mapdata.allmapdata[ii - 1][jj] == 2)
//					num++;
//				if (mapdata.allmapdata[ii][jj - 1] == 2)
//					num++;
//
//				if (num >= 2)
//					mapdata.allmapdata[ii][jj] = 2;
//			}
//		}
//	}
//}
//
//
//int main()
//{
//	Mat up = imread("C:\\JKB\\MOBLEEWORK\\data\\up.png");
//	Mat right = imread("C:\\JKB\\MOBLEEWORK\\data\\right.png");
//	Mat down = imread("C:\\JKB\\MOBLEEWORK\\data\\down.png");
//	Mat left = imread("C:\\JKB\\MOBLEEWORK\\data\\left.png");
//	Mat maploading = imread("C:\\JKB\\MOBLEEWORK\\data\\maploading.png");
//
//	imshow("direction", maploading);
//	waitKey(100);
//
//	while (1) //미로생성 + 완성체크
//	{
//		srand(time(NULL));
//		location_x = 0;
//		location_y = 1;
//		direction = 3;
//
//		fill_n(mapdata.allmapdata[0], ALLSIZE * ALLSIZE, 1);
//
//		for (int ii = 1; ii < ALLSIZE - 1; ii++)
//		{
//			for (int jj = 1; jj < ALLSIZE - 1; jj++)
//			{
//				if (ii % 2 == 1 && jj % 2 == 1)
//				{
//					mapdata.allmapdata[ii][jj] = 0;
//					//////////////////////////////////////////////////////좀더 복잡한 미로
//					/*if (jj > ALLSIZE / 3 && jj <= ALLSIZE / 3 * 2)
//					{
//						if (rand() % 2 == 0)
//							mapdata.allmapdata[ii - 1][jj] = 0;
//						else
//							mapdata.allmapdata[ii][jj + 1] = 0;
//					}
//					else
//					{
//						if (rand() % 2 == 0)
//							mapdata.allmapdata[ii + 1][jj] = 0;
//						else
//							mapdata.allmapdata[ii][jj + 1] = 0;
//					}*/
//					//////////////////////////////////////////////////////기본 미로
//					if (rand() % 2 == 0)
//						mapdata.allmapdata[ii + 1][jj] = 0;
//					else
//						mapdata.allmapdata[ii][jj + 1] = 0;
//				}
//			}
//		}
//		for (int ii = 0; ii < ALLSIZE; ii++)
//		{
//			for (int jj = 0; jj < ALLSIZE; jj++)
//			{
//				if (ii == 0 || ii == ALLSIZE - 1)
//					mapdata.allmapdata[ii][jj] = 1;
//				if (jj == 0 || jj == ALLSIZE - 1)
//					mapdata.allmapdata[ii][jj] = 1;
//			}
//		}
//
//		mapdata.allmapdata[0][1] = 0; //입구
//		mapdata.allmapdata[1][1] = 0;
//		mapdata.allmapdata[ALLSIZE - 1][ALLSIZE - 2] = 0; //출구
//		mapdata.allmapdata[ALLSIZE - 2][ALLSIZE - 2] = 0;
//
//		graphic();
//		imshow("MAZE RUNNER", mapgraphic);
//		waitKey(25);
//		while (1) //완성체크
//		{
//			check();
//
//			move();
//
//			if (location_x == (ALLSIZE - 1) && location_y == (ALLSIZE - 2))
//				break;
//			if (location_x == 0 && location_y == 1)
//				break;
//		}
//		if (location_x == (ALLSIZE - 1) && location_y == (ALLSIZE - 2))
//			break;
//	}
//
//	graphic();
//
//	imshow("MAZE RUNNER", mapgraphic);
//	location_x = 0;
//	location_y = 1;
//	direction = 3;
//
//	while (1) //재생
//	{
//		check();
//
//		if (mapdata.allmapdata[location_x][location_y] == 0)
//			mapdata.allmapdata[location_x][location_y] = 2;
//		else if (mapdata.allmapdata[location_x][location_y] == 2)
//			mapdata.allmapdata[location_x][location_y] = 0;
//
//		move();
//
//		mapgraphic(Rect(blocksize * location_x, blocksize * location_y, blocksize, blocksize)) = cv::Scalar(0, 0, 255);
//
//		if (direction == 1)
//			imshow("direction", left);
//		if (direction == 2)
//			imshow("direction", down);
//		if (direction == 3)
//			imshow("direction", right);
//		if (direction == 4)
//			imshow("direction", up);
//
//		imshow("MAZE RUNNER", mapgraphic);
//		if (location_x == ALLSIZE - 1 && location_y == ALLSIZE - 2)
//		{
//			mapdata.allmapdata[location_x][location_y] = 2;
//			break;
//		}
//		graphic();
//		int key = waitKey(25);
//		if (key == 27)
//			break;
//	}
//	imshow("MAZE RUNNER", mapgraphic);
//
//	waitKey(0);
//	destroyAllWindows();
//}