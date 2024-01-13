#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

unsigned char* resizeImage(unsigned char* input, int width, int height, int channels, int new_width, int* new_height) {
    float scale = (float)new_width / width;
    *new_height = (int)(height * scale);

    unsigned char* output = malloc(new_width * (*new_height) * channels);
    if (!output) {
        return NULL;
    }

    for (int y = 0; y < *new_height; ++y) {
        for (int x = 0; x < new_width; ++x) {
            int srcX = (int)(x / scale);
            int srcY = (int)(y / scale);
            memcpy(output + (y * new_width + x) * channels, 
                   input + (srcY * width + srcX) * channels, 
                   channels);
        }
    }

    return output;
}


void imageToAscii(unsigned char* img, int new_width, int new_height, int channels) {
    const char ascii_chars[] = " .:-=+*#%% ";
    for (int i = 0; i < new_width * new_height * channels; i += channels) {
        unsigned char pixel = img[i];
        int ascii_index = pixel / 25;
        printf("%c", ascii_chars[ascii_index]);

        // 检查是否到达了缩放后图像的行尾
        if ((i / channels + 1) % new_width == 0) {
            printf("\n");
        }
    }
}

void processImage(const char* filePath) {
    int width, height, channels;
    unsigned char *img = stbi_load(filePath, &width, &height, &channels, 0);
    if (img == NULL) {
        printf("Error in loading the image %s\n", filePath);
        return;
    }

    int new_width = 15;
    int new_height;
    unsigned char* resized_img = resizeImage(img, width, height, channels, new_width, &new_height);

    if (resized_img != NULL) {
        imageToAscii(resized_img, new_width, new_height, channels);
        free(resized_img);
    }

    stbi_image_free(img);
}

int main() {
    DIR *d;
    struct dirent *dir;
    d = opendir("image");
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            if (dir->d_type == DT_REG) {
                char filePath[1024];
                snprintf(filePath, sizeof(filePath), "image/%s", dir->d_name);
                processImage(filePath);
                printf("\n\n"); // 分隔不同图片
            }
        }
        closedir(d);
    } else {
        printf("Error opening directory 'image'\n");
    }
    return 0;
}
