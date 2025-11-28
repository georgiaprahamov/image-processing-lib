#include <iostream>
#include "image.hpp"
#include "filters.hpp"

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cout << "Usage: demo <input_image> [output_prefix]\n";
        std::cout << "Creates three output files with filters applied.\n";
        return 1;
    }

    std::string inputPath = argv[1];
    std::string outputPrefix = (argc > 2) ? argv[2] : "output";

    try {
        // Load image
        Image img(inputPath);
        std::cout << "Loaded image: " << inputPath
                  << " (" << img.width() << "x" << img.height() << ")\n";

        // Apply filters
        std::cout << "\nApplying filters...\n";
        
        // 1. Grayscale
        std::cout << "  - Converting to grayscale...\n";
        Image gray = Filters::toGray(img);
        std::string grayPath = outputPrefix + "_gray.jpg";
        if (!gray.save(grayPath)) {
            std::cerr << "Failed to save grayscale image\n";
            return 1;
        }
        std::cout << "    Saved: " << grayPath << "\n";
        
        // 2. Gaussian Blur
        std::cout << "  - Applying Gaussian blur...\n";
        Image blurred = Filters::gaussianBlur(img, 15);
        std::string blurPath = outputPrefix + "_blur.jpg";
        if (!blurred.save(blurPath)) {
            std::cerr << "Failed to save blurred image\n";
            return 1;
        }
        std::cout << "    Saved: " << blurPath << "\n";
        
        // 3. Sobel Edge Detection
        std::cout << "  - Detecting edges with Sobel...\n";
        Image edges = Filters::sobelEdge(img);
        std::string edgePath = outputPrefix + "_edges.jpg";
        if (!edges.save(edgePath)) {
            std::cerr << "Failed to save edge detection image\n";
            return 1;
        }
        std::cout << "    Saved: " << edgePath << "\n";
        
        std::cout << "\nAll filters applied successfully!\n";
    }
    catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << "\n";
        return 1;
    }

    return 0;
}