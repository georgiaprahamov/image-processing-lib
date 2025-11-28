#include "image.hpp"
#include <stdexcept>
#include <opencv2/opencv.hpp>

Image::Image(const std::string& path) {
    mat = cv::imread(path, cv::IMREAD_COLOR);
    if (mat.empty()) {
        throw std::runtime_error("Failed to load image from: " + path);
    }
}

Image::Image(const cv::Mat& m) {
    if (m.empty()) {
        throw std::runtime_error("Cannot construct Image from empty cv::Mat");
    }
    mat = m.clone();
}

bool Image::save(const std::string& path) const {
    if (mat.empty()) return false;
    return cv::imwrite(path, mat);
}

bool Image::empty() const {
    return mat.empty();
}

int Image::width() const {
    return mat.cols;
}

int Image::height() const {
    return mat.rows;
}
