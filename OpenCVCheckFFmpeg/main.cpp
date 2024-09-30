#include <opencv2/opencv.hpp>
#include <iostream>

int main()
{
    // Print OpenCV version
    std::cout << "OpenCV version: " << CV_VERSION << std::endl;

    // Check if OpenCV can use FFmpeg
    bool hasFFmpeg = cv::getBuildInformation().find("FFMPEG") != std::string::npos;

    if (hasFFmpeg)
    {
        std::cout << "OpenCV is built with FFmpeg support." << std::endl;
    }
    else
    {
        std::cout << "OpenCV is NOT built with FFmpeg support." << std::endl;
    }
    return 0;
}
