#ifndef TRACKER
#define TRACKER

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <fstream>
#include <visp/vpImageIo.h>
#include <visp/vpDisplayGDI.h>
#include <visp/vpDisplayX.h>
#include <visp/vpDisplayOpenCV.h>
#include <visp/vpTemplateTrackerSSDInverseCompositional.h>
#include <visp/vpTemplateTrackerZNCCInverseCompositional.h>
#include <visp/vpTemplateTrackerWarpHomography.h>
#include <unistd.h>
#include <sstream>
#include <cmath>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#define HEIGHT 1200
#define WIDTH 1600

class Tracker{
	private:
		vpTemplateTrackerWarpHomography * warp;
		vpTemplateTrackerSSDInverseCompositional * tracker;
		vpTemplateTrackerZone * zone_ref;
		vpTemplateTrackerZone * zone_warped;
		int id;
	public:
		vpImagePoint rec_corners[4];
		Tracker(vpImage<unsigned char> & I, std::vector<vpImagePoint> & points, int initID);
		~Tracker();
		bool start(vpImage<unsigned char> & I);
		bool check_pts(std::vector<std::vector<cv::Point> >  & cvpts);
		void write_pts(std::ofstream & ptsfile , std::string & number);
		int getID();
};

void pad( std::vector<cv::Point>& con, int N, cv::Size sz = cv::Size(WIDTH, HEIGHT));

void getImageList( std::string filename,  std::vector<std::string>* il );

void showResult(const char * name, const std::vector<std::vector<cv::Point> > & cvpts);

bool checkEqual(std::vector<cv::Point> & square1, std::vector<cv::Point> & square2);

#endif
