#pragma once

#include "image.hpp"

namespace Filters {

    // Засега само декларации – ще ги имплементираме в следващия модул

    Image toGray(const Image& img);
    Image gaussianBlur(const Image& img, int kernelSize = 5);
    Image sobelEdge(const Image& img);

} // namespace Filters
