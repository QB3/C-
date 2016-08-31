#include "opencv/cxcore.h"
#include "opencv/cv.h"
#include "opencv/highgui.h"

int _tmain(int argc, _TCHAR* argv[])
{
    cv::Mat image(480, 640, CV_8UC3);
    cv::putText(image, "Hello world", cvPoint(320, 200), 
        CV_FONT_HERSHEY_SIMPLEX, 1, cvScalar(255, 0, 0));
    cv::imwrite("output.tif", image);
    return 0;
}
