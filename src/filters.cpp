#include "filters.hpp"
#include <opencv2/opencv.hpp>

namespace Filters {

Image toGray(const Image& img) {
    cv::Mat gray;
    cv::cvtColor(img.getMat(), gray, cv::COLOR_BGR2GRAY);
    // Convert back to 3-channel for consistency
    cv::Mat grayBGR;
    cv::cvtColor(gray, grayBGR, cv::COLOR_GRAY2BGR);
    return Image(grayBGR);
}

Image gaussianBlur(const Image& img, int kernelSize) {
    cv::Mat blurred;
    // Ensure kernel size is odd
    if (kernelSize % 2 == 0) kernelSize++;
    cv::GaussianBlur(img.getMat(), blurred, cv::Size(kernelSize, kernelSize), 0);
    return Image(blurred);
}

Image sobelEdge(const Image& img) {
    cv::Mat gray, sobelX, sobelY, edges;
    cv::cvtColor(img.getMat(), gray, cv::COLOR_BGR2GRAY);
    
    cv::Sobel(gray, sobelX, CV_32F, 1, 0, 3);
    cv::Sobel(gray, sobelY, CV_32F, 0, 1, 3);
    
    cv::magnitude(sobelX, sobelY, edges);
    edges.convertTo(edges, CV_8U);
    
    // Convert back to BGR for consistency
    cv::Mat edgesBGR;
    cv::cvtColor(edges, edgesBGR, cv::COLOR_GRAY2BGR);
    return Image(edgesBGR);
}

} // namespace Filters
