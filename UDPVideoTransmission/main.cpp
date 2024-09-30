#include <QCoreApplication>
#include <QUdpSocket>
#include <opencv2/opencv.hpp>

#define PORT 3333
#define MAX_BUFFER_SIZE 65507 // Maximum size for UDP packet

void reduceImageSize(cv::Mat &frame, int newWidth, int newHeight)
{
    // Create a destination matrix for the resized image
    cv::Mat resizedFrame;

    // Resize the frame to new dimensions (newWidth x newHeight)
    cv::resize(frame, resizedFrame, cv::Size(newWidth, newHeight), 0, 0, cv::INTER_LINEAR);

    // The resized frame is now stored in resizedFrame
    frame = resizedFrame;  // Optionally overwrite the original frame
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Open the default camera
    cv::VideoCapture cap(0);
    if (!cap.isOpened())
    {
        qDebug() << "Error: Could not open the camera.";
        return -1;
    }

    // Create a UDP socket
    QUdpSocket udpSocket;

    qDebug() << "Server ready to send video...";

    cv::Mat frame;
    while (true)
    {
        // Capture a frame
        cap >> frame;
        if (frame.empty())
        {
            qDebug() << "Error: Captured empty frame.";
            break;
        }

        // Reduce the frame size to half (or set custom width/height)
        reduceImageSize(frame, frame.cols / 2, frame.rows / 2);

        // Encode the frame to JPEG format
        std::vector<uchar> buffer;
        cv::imencode(".jpg", frame, buffer);

        // Send the frame to the client
        qDebug() << "buffer size:" << buffer.size();
        udpSocket.writeDatagram(reinterpret_cast<const char*>(buffer.data()), buffer.size(),
                                QHostAddress::Broadcast, PORT);

        qDebug() << "Frame sent to client.";

        // Display the frame (optional)
        cv::imshow("Webcam Stream", frame);
        if (cv::waitKey(30) >= 0)
        {
            break; // Exit on key press
        }
    }

    // Clean up
    cap.release();
    cv::destroyAllWindows();
    return a.exec();
}
