#include <bits/stdc++.h>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/opencv.hpp"
#include <stdlib.h>
#include <stdio.h>



void stache_file(char* dest,char* mask_desti, int curr);
void stache_cam(char* mask_desti, int curr);

void motionCam_cam();

void motionCam_file(char* dest);

void laplace_cam(); 
void sepia_cam();
void poster_cam();
void negative_cam();
void blurit_cam();
void cannye_cam();
void grayscale_cam();
void bifi_cam();

void laplace_file(char* de);
void sepia_file(char* de);
void poster_file(char* de);
void negative_file(char* de);
void blurit_file(char* de);
void cannye_file(char* de);
void grayscale_file(char* de);
void bifi_file(char* de);