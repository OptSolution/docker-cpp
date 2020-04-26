#include <opencv2/opencv.hpp>

int main(int argc, char const *argv[])
{
    cv::Mat img = cv::imread("../paopao.png");
    cv::imshow("paopao", img);
    cv::waitKey(0);
    return 0;
}
