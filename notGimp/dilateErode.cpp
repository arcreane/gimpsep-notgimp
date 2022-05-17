#include <opencv2/opencv.hpp>
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>

using namespace cv;
using namespace std;

/// Global variables
Mat src, erosion_dst, dilation_dst;

int erosion_elem = 0;
int erosion_size = 0;
int dilation_elem = 0;
int dilation_size = 0;
int const max_elem = 2;
int const max_kernel_size = 21;





//![erosion]
/**
 * @function Erosion
 */
namespace filter {

    void dilate(cv::Mat& srcfile, int8_t value) {
        int dilation_type = 0;
        if (dilation_elem == 0) { dilation_type = MORPH_RECT; }
        else if (dilation_elem == 1) { dilation_type = MORPH_CROSS; }
        else if (dilation_elem == 2) { dilation_type = MORPH_ELLIPSE; }

        Mat element = getStructuringElement(dilation_type,
            Size(2 * dilation_size + 1, 2 * dilation_size + 1),
            Point(dilation_size, dilation_size));

        /// Apply the dilation operation
        dilate(src, dilation_dst, element);
        imshow("Dilation Demo", dilation_dst);


    }

    void erode(cv::Mat& srcfile, int8_t value) {

        int erosion_type = 0;
        if (erosion_elem == 0) { erosion_type = MORPH_RECT; }
        else if (erosion_elem == 1) { erosion_type = MORPH_CROSS; }
        else if (erosion_elem == 2) { erosion_type = MORPH_ELLIPSE; }

        //![kernel]
        Mat element = getStructuringElement(erosion_type,
            Size(2 * erosion_size + 1, 2 * erosion_size + 1),
            Point(erosion_size, erosion_size));
        //![kernel]

        /// Apply the erosion operation
        erode(src, erosion_dst, element);
        imshow("Erosion Demo", erosion_dst);


    }
}
/**
 * @function Dilation
 */
