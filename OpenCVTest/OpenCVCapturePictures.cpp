//
// Created by Lenovo on 2023/10/16.
//

#include "OpenCVCapturePictures.h"

OpenCVCapturePictures::OpenCVCapturePictures(const std::string path) {
//    this->maxImageNum = imageNum;
    this->saveImgPath = path;
}

void OpenCVCapturePictures::capturePicturesAndSaveImage() {
    cv::VideoCapture capture(0); //默认摄像头为0
    if (!capture.isOpened()){
        std::cout << "Open camera error!" << std::endl;
        return;
    }
    capture.set(cv::CAP_PROP_FRAME_WIDTH, 720);
    capture.set(cv::CAP_PROP_FRAME_HEIGHT, 720);
    //设置照片分辨率720*720
    capture.set(cv::CAP_PROP_FOURCC, cv::CAP_OPENCV_MJPEG);
    //摄像头帧数
    capture.set(cv::CAP_PROP_FPS, 15);
    cv::Mat frame; //定义摄像头获取到的一帧画面
    int count = 1; //给取帧得到的照片排序
    while (true){
        capture >> frame;
        //镜像获得的图片
        cv::flip(frame, frame, 1);
        if (!frame.empty()){
            std::ostringstream oss;
            //给照片指定顺序并且用顺序来命名
            oss << std::setfill('0') << std::setw(3) << count;
            imwrite(saveImgPath + "\\pic" + oss.str() + ".png", frame);
            cv::imshow("frame", frame);
            char key = cv::waitKey(30);
            if (key == 'q')
                break;
            count++;
        }
    }
    capture.release(); //释放相机捕获对象
    cv::destroyAllWindows(); //关闭所有窗口
}
