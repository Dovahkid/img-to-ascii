#include "./bin/imgToAscii.cpp"
#include <string>

int main(int argc, char* argv[]) {
    std::string imageFile = "";
    std::string outputFile = "";
    std::string fillers = " _-*oOQA";

    switch(argc) {
        case 4:
            fillers = argv[3];

        case 3:
            imageFile = argv[1];
            outputFile = argv[2];
        break;

        default:
            while(imageFile == "" || outputFile == "") {
                std::cout << "Please enter the image to be processed then the output text file" << std::endl;
                std::cin >> imageFile >> outputFile;
            }
    }

    AsciiTools::ImageData imageData = AsciiTools::loadImage(imageFile.c_str());
    AsciiTools::convertToAscii(imageData, outputFile, fillers);
    
    return 0;
}