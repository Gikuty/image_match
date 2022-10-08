/*  Copyright (c) 2013, Robert Wang, email: robertwgh (at) gmail.com
    All rights reserved. https://github.com/robertwgh/ezSIFT
    Description:Detect keypoints and extract descriptors from two input images.
                Then, match features from two images using brute-force method.
    Revision history:
        September 15th, 2013: initial version.
        July 2nd, 2018: code refactor.
*/

#include "ezsift.h"

#include <iostream>
#include <list>

#define USE_FIX_FILENAME 0
int main(int argc, char *argv[])
{
#if USE_FIX_FILENAME
    char *file1 = "img1.pgm";
    char *file2 = "img2.pgm";
#else
    if (argc != 3) {
        printf("Please input two image filenames.\n");
        printf("usage: image_match img1 img2\n");
        return -1;
    }
    char file1[255];
    char file2[255];
    memcpy(file1, argv[1], sizeof(char) * strlen(argv[1]));
    file1[strlen(argv[1])] = 0;
    memcpy(file2, argv[2], sizeof(char) * strlen(argv[2]));
    file2[strlen(argv[2])] = 0;
#endif
    // Match keypoints.
    std::list<ezsift::MatchPair> match_list;
    ezsift::match_keypoints(kpt_list1, kpt_list2, match_list);

   

    if (image2.read_pgm(file2) != 0) {
        printf("Failed to open input image2!\n");
        return -1;
    }
    std::cout << "Image 1 loaded, image size: " << image1.w << " x " << image1.h
              << std::endl;
    std::cout << "Image 2 loaded, image size: " << image2.w << " x " << image2.h
              << std::endl;

   
 // Read two input images
    ezsift::Image<unsigned char> image1, image2;
    if (image1.read_pgm(file1) != 0) {
        std::cerr << "Failed to open input image1!" << std::endl;
        return -1;
    }
    

    // Draw result image.
    ezsift::draw_match_lines_to_ppm_file("sift_matching_a_b.ppm", image1,
                                         image2, match_list);
    std::cout << "# of matched keypoints: "
              << static_cast<unsigned int>(match_list.size()) << std::endl;

    return 0;
}
