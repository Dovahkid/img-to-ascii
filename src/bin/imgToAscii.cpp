#include "imgToAscii.hpp"
#include <stdint.h>

#include <iostream>
#include <string>

#define STB_IMAGE_IMPLEMENTATION
#include "./../libs/stb_image.h"

AsciiTools::ImageData AsciiTools::loadImage(const char* imageName) {

    int width, height, bpp;
    unsigned char* rgb_image = stbi_load(imageName, &width, &height, &bpp, 3);

    // stbi_image_free(rgb_image);
    return {rgb_image, width, height};
}

void AsciiTools::convertToAscii(AsciiTools::ImageData imageData, std::string fillers) {

    // 3 because it has 3 channels of color, RGB
    int rgbCount = (imageData.height * imageData.width * 3) - 3;
    int aggregateValue = 0;
    int widthCounter = 0;

    for(int i = 0; i < rgbCount; i+=3) {
        // printf(" | %d %d %d", imageData.image[i], imageData.image[i+1], imageData.image[i+2]);
        aggregateValue = (imageData.image[i] + imageData.image[i+1] + imageData.image[i+2]) / 3;

        if(aggregateValue > 128)
            printf("%c", fillers[0]);
        else
            printf("%c", fillers[1]);
        
        widthCounter++;

        if(widthCounter == imageData.width) {
            std::cout << "\n";
            widthCounter = 0;
        }
    }

}