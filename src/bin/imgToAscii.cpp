#include "imgToAscii.hpp"
#include <stdint.h>

#include <iostream>
#include <fstream>
#include <string>

#define STB_IMAGE_IMPLEMENTATION
#include "./../libs/stb_image.h"

AsciiTools::ImageData AsciiTools::loadImage(const char* imageName) {

    int width, height, bpp;
    unsigned char* rgb_image = stbi_load(imageName, &width, &height, &bpp, 3);

    // stbi_image_free(rgb_image);
    return {rgb_image, width, height};
}

void AsciiTools::convertToAscii(AsciiTools::ImageData imageData, std::string outputFile, std::string fillers) {

    // 3 because it has 3 channels of color, RGB
    int rgbCount = (imageData.height * imageData.width * 3);
    int aggregateValue = 0;
    int widthCounter = 0;
    std::fstream outFile;
    
    outFile.open(outputFile, std::ios::out);

    for(int i = 0; i < rgbCount; i+=3) {
        // printf(" | %d %d %d", imageData.image[i], imageData.image[i+1], imageData.image[i+2]);
        aggregateValue = (imageData.image[i] + imageData.image[i+1] + imageData.image[i+2]) / 3;

        /*
            I would prefer if this wasnt hard coded but idc to find a better solution rn
        */

		if(aggregateValue > 224)
            outFile << fillers[0] << fillers[0];
            
		else if(aggregateValue > 192)
            outFile << fillers[1] << fillers[1];

		else if(aggregateValue > 160)
            outFile << fillers[2] << fillers[2];
		
		else if(aggregateValue > 128)
            outFile << fillers[3] << fillers[3];

		else if(aggregateValue > 96)
            outFile << fillers[4] << fillers[4];

		else if(aggregateValue > 64)
            outFile << fillers[5] << fillers[5];
        
		else if(aggregateValue > 32)
            outFile << fillers[6] << fillers[6];

		else if(aggregateValue > 0)
            outFile << fillers[7] << fillers[7];

/*
		if(aggregateValue > 224)
            printf("%c%c", fillers[0], fillers[0]);
        
		else if(aggregateValue > 192)
            printf("%c%c", fillers[1], fillers[1]);

		else if(aggregateValue > 160)
            printf("%c%c", fillers[2], fillers[2]);
		
		else if(aggregateValue > 128)
            printf("%c%c", fillers[3], fillers[3]);

		else if(aggregateValue > 96)
            printf("%c%c", fillers[4], fillers[4]);

		else if(aggregateValue > 64)
            printf("%c%c", fillers[5], fillers[5]);
        
		else if(aggregateValue > 32)
            printf("%c%c", fillers[6], fillers[6]);

		else if(aggregateValue > 0)
            printf("%c%c", fillers[7], fillers[7]);

		printf("%c", );
*/
        
        widthCounter++;

        if(widthCounter == imageData.width) {
            outFile << "\n";
            widthCounter = 0;
        }
    }

	delete[] imageData.image;
}