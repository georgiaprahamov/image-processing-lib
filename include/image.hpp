#pragma once

#include <string>
#include <opencv2/opencv.hpp>

class Image {
public:
    explicit Image(const std::string& path);
    explicit Image(const cv::Mat& m);
    
    bool save(const std::string& path) const;
    bool empty() const;
    int width() const;
    int height() const;
    
    // Allow access to underlying mat for filters
    cv::Mat getMat() const { return mat; }
    
private:
    cv::Mat mat;
};
