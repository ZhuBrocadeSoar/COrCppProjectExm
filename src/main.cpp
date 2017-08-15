/*************************************************************************
	> File Name: main.cpp
	> Author: Zhu Brocadesoar
	> Mail: brocadesoar@gmail.com
	> Created Time: Sun 13 Aug 2017 11:34:03 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

//#include<opencv2/core/core.hpp>
//#include<opencv2/highgui/highgui.hpp>
#include<opencv/cv.hpp>
#include<opencv/highgui.h>
using namespace cv;

#include<gsl/gsl_sf_bessel.h>

int main(int argc, char** argv){
    //check args
    if(argc !=2){
        cout << " Usage : camera <path/for/saving>" << endl;
        double x = 5.0;
        double y = gsl_sf_bessel_J0(x);
        cout << "J0(" << x << ") = " << y << endl;
        return -1;
    }

    //create a capture
    VideoCapture cap(CV_CAP_ANY);
    //create a frame
    Mat frame;
    //create a window for show
    namedWindow("Press Backspace key to capture the image at this monent and save and exit! Enjoy!!", CV_WINDOW_AUTOSIZE);
    //loop for video
    while(1){
        //cap a image
        cap >> frame;
        //show image
        imshow("Press Backspace key to capture the image at this monent and save and exit! Enjoy!!", frame);
        //check a key
        if(waitKey(10) < 10) break;
    }
    return 0;
}
