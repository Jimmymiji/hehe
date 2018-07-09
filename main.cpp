 #include "opencv2/opencv.hpp"
#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>
#include <thread>
using namespace std;
using namespace cv;


// Get current date/time, format is YYYY-MM-DD.HH:mm:ss
const std::string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    return buf;
}


int main()
{
  VideoCapture vcap("/dev/v4l/by-id/usb-DETNR019I9RK3F_HP_HD_Camera_200901010001-video-index0");
      if(!vcap.isOpened()){
             cout << "Error opening video stream or file" << endl;
             return 1;
      }
  VideoCapture vcap1("/dev/v4l/by-id/usb-HD_Camera_Manufacturer_Stereo_Vision_1_Stereo_Vision_1-video-index0");
      if(!vcap.isOpened()){
              cout << "Error opening video stream or file" << endl;
              return 1;
          }
  int frame_width=   640;
  int frame_height=   480;
  string filename = currentDateTime() + to_string(0)+".avi";
  string filename1 = currentDateTime() + to_string(1)+".avi";
  VideoWriter video(filename,CV_FOURCC('M','J','P','G'),30, Size(frame_width,frame_height),true);
  VideoWriter video1(filename1,CV_FOURCC('M','J','P','G'),30, Size(frame_width,frame_height),true);
  for(;;){

      Mat frame;
      vcap >> frame;
      video.write(frame);
      vcap1 >> frame;
      video1.write(frame);
      //imshow( "Frame", frame );
      //char c = (char)waitKey(33);
      //if( c == 27 ) break;
   }
  return 0;
}
