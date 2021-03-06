#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char** argv) {
    bool capturing = true;

    VideoCapture cap(0);

    if (!cap.isOpened()) {
        cerr << "error opening frames source" << endl;
        return -1;
    }
    cout << "Video size: " << cap.get(CAP_PROP_FRAME_WIDTH) << "x" << cap.get(CAP_PROP_FRAME_HEIGHT) << endl;

    do {
        Mat frame;
        Mat dst = frame;

        if (cap.read(frame)) {
            flip(frame, dst, 1);
            imshow("Not-yet smart window", dst);
        }

        else {
            //stream finished
            capturing = false;
        }
        //wait for key, check if it is 'esc'
        if ((waitKey(1000.0 / 60.0) & 0x0ff) == 27) {
            capturing = false;
        }

    } while (capturing);

    return 0;
}
