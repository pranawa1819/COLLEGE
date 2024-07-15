clear all;
close all;
clc;
pkg load image;
% Read image for Image Enhancement
I = imread('nature.jpg');
% Display Original Image
subplot(4,2,1);
imshow(I);
title('Original Image');
% Convert to grayscale
g = rgb2gray(I);
% Display Grayscale Image
subplot(4,2,5);
imshow(g);
title('Gray Image');
% Enhance Image
J = imadjust(g, [0.3 0.7],[]);
% Display Enhanced Image
subplot(4,2,3);
imshow(J);
title('Enhanced Image 1');
% Enhance Image 2
D = imadjust(I, [0.2 0.3 0; 0.6 0.7 1],[]);
% Display Enhanced Image 2
subplot(4,2,4);
imshow(D);
title('Enhanced Image 2');
% Histogram and Histogram Equalization
subplot(4,2,7);
 imhist(g);
 title('Histogram of Gray Image');
% Histogram Equalization
m = histeq(g);
% Display Equalized Image
subplot(4,2,6);
imshow(m);
title('Equalized Image');
% Display Histogram of Equalized Image
subplot(4,2,8); imhist(m);
title('Histogram of Equalized Image');
