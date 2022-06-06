#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/stitching.hpp"
#include <iostream>
#include "filters.h"

void ngp::filters::panorama(vector<Mat> srcfiles){
	Stitcher::Mode mode = Stitcher::PANORAMA;
	Ptr<Stitcher> stitcher = Stitcher::create(mode, false);
	Stitcher::Status status = stitcher->stitch(srcfiles, scrfile);
	 if (status != Stitcher::OK)
    {
        cout << "Can't stitch images\n";
        return -1;
    }
}
