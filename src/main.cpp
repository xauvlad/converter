#include <opencv2/opencv.hpp>
#include <iostream>
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

void processImage(const fs::path& imagePath, const fs::path& outputFilePath) {
    cv::Mat image = cv::imread(imagePath.string(), cv::IMREAD_GRAYSCALE);
    if (image.empty()) {
        std::cerr << "Error: Unable to open image " << imagePath << std::endl;
        return;
    }

    cv::Mat resizedImage;
    cv::resize(image, resizedImage, cv::Size(640, 480));

    resizedImage.convertTo(resizedImage, CV_32F, 1.0 / 255.0);

    std::ofstream outputFile(outputFilePath);
    if (!outputFile.is_open()) {
        std::cerr << "Error: Unable to open file " << outputFilePath << std::endl;
        return;
    }

    for (int i = 0; i < resizedImage.rows; ++i) {
        for (int j = 0; j < resizedImage.cols; ++j) {
            outputFile << resizedImage.at<float>(i, j);
            if (!(i == resizedImage.rows - 1 && j == resizedImage.cols - 1)) {
                outputFile << " ";
            }
        }
    }
    outputFile << std::endl;

    std::cout << "Processed " << imagePath.filename() << " -> " << outputFilePath << std::endl;
}

int main(int argc, char** argv) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <input_folder> <output_folder>" << std::endl;
        return -1;
    }

    fs::path inputFolder = argv[1];
    fs::path outputFile = argv[2];

    if (!fs::exists(inputFolder) || !fs::is_directory(inputFolder)) {
        std::cerr << "Error: Input folder does not exist or is not a directory." << std::endl;
        return -1;
    }


    for (const auto& entry : fs::directory_iterator(inputFolder)) {
        if (entry.is_regular_file() && entry.path().extension() == ".jpg") {
            processImage(entry.path(), outputFile);
        }
    }

    std::cout << "Processing complete. Transformed images saved as text files in " << outputFile << std::endl;
    return 0;
}
