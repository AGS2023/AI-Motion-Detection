#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
    VideoCapture video("https://192.168.79.123:8080/video");
    Mat first_frame, gray, delta_frame, threshold_frame;

    while (true)
    {
        Mat frame;
        bool check = video.read(frame);
        cvtColor(frame, gray, COLOR_BGR2GRAY);
        GaussianBlur(gray, gray, Size(21, 21), 0);

        if (first_frame.empty())
        {
            first_frame = gray;
            continue;
        }

        absdiff(first_frame, gray, delta_frame);
        threshold(delta_frame, threshold_frame, 50, 255, THRESH_BINARY);
        dilate(threshold_frame, threshold_frame, Mat(), Point(-1, -1), 2);
        threshold_frame.convertTo(threshold_frame, CV_8U);

        vector<vector<Point> > contours;
        findContours(threshold_frame, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

        for (int i = 0; i < contours.size(); i++)
        {
            if (contourArea(contours[i]) < 1000)
                continue;
            Rect rect = boundingRect(contours[i]);
            rectangle(frame, rect, Scalar(0, 255, 0), 3);
            imshow("AI motion", frame);
        }

        int key = waitKey(1);
        if (key == 'q')
            break;
    }

    video.release();
    destroyAllWindows();
    return 0;
}
