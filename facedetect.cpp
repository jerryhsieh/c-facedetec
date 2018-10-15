#include "opencv2/opencv.hpp"

int main(int argc, char *argv[]) {
  cv::CascadeClassifier cascade;
  std::string imageName, cascadeName;
  cv::Mat image, gray;
  std::vector<cv::Rect> faces;
  cv::Scalar color = cv::Scalar(0, 255, 0);

  cascadeName = "./haarcascade_frontalface_default.xml";
  imageName = argv[1];

  // load image and classifier
  if (!cascade.load(cascadeName)) {
    std::cerr << "Could not load classifier cascade" << std::endl;
  } else if (imageName.empty()) {
    std::cout << "Could not read " << imageName << std::endl;
  } else {
    image = cv::imread(imageName, 1);
    if (image.empty()) {
      std::cout << "Could not imread image " << std::endl;
    }
  }

  // convert to grey
  cv::cvtColor(image, gray, cv::COLOR_BGR2GRAY);

  // run face detector
  cascade.detectMultiScale(image, faces, 1.1, 2, 0, cv::Size(30, 30));

  // output rectangle
  for (size_t i = 0; i < faces.size(); ++i) {
    cv::Rect r = faces[i];
    cv::rectangle(
        image, cv::Point(cvRound(r.x), cvRound(r.y)),
        cv::Point(cvRound(r.x + r.width - 1), cvRound(r.y + r.height - 1)),
        color, 3, 8, 0);
  }

  // show image
  cv::imshow("result", image);
  cv::waitKey(0);
  cv::destroyAllWindows();
  return 0;
}
