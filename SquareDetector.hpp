#ifndef SQUARES
#define SQUARES

#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

#include <iostream>
#include <cmath>
#include <string>
#include <ctime>
#include <algorithm>
#include <functional> 


class SquareDetector
{
	private:
		int WIDTH;
		int HEIGHT;
		int edge_margin;
		double length_ratio;
		double ang_dif;
		double ang_err;
		double minArea;
		double maxAreaRatio;
		bool special;


		bool intersection(cv::Point & o1, cv::Point & p1, cv::Point & o2, cv::Point & p2, cv::Point &r);
		bool onSegment(cv::Point & p, cv::Point & q, cv::Point & r);
		int orientation(cv::Point p, cv::Point q, cv::Point r);
		bool doIntersect(cv::Point p1, cv::Point q1, cv::Point p2, cv::Point q2);

		int checkSide(const cv::Point & p1, const cv::Point & p2, const cv::Point & p );
		bool insidePolygon(const std::vector<cv::Point> & corners, const cv::Point & p);
		double countOverlap(std::vector<cv::Point> & corners1, std::vector<cv::Point> & corners2);
		
	
		double angle( cv::Point pt1, cv::Point pt2, cv::Point pt0 );
		bool sortCorners( std::vector<cv::Point> & corners);
		double calAngle(const cv::Point & p1,const cv::Point & p2);
		double calAngle2(const cv::Point & p1,const cv::Point & p2);
		double cornerDist(std::vector<cv::Point>& pts1, std::vector<cv::Point>& pts2);
		bool compareRectangles(std::vector<cv::Point>& pts1, std::vector<cv::Point>& pts2);
		bool checkSquare(std::vector<cv::Point> & corners);

		
	
	public:
		SquareDetector();
		void findSquares( const cv::Mat& image, std::vector<std::vector<cv::Point> >& squares );
		void drawSquares( cv::Mat& image, const std::vector<std::vector<cv::Point> >& squares );
		void setMinArea(double val);
		void setMaxArea(double val);
		void setSpecial(bool val);
		bool isOverlap(std::vector<cv::Point> & corners1, std::vector<cv::Point> & corners2);
		bool checkEqual(std::vector<cv::Point>& pts1, std::vector<cv::Point>& pts2);
		double maxDist(std::vector<cv::Point>& pts1, std::vector<cv::Point>& pts2);
};
		

static bool compareContourAreas(std::vector<cv::Point> contour1, std::vector<cv::Point> contour2);

#endif
