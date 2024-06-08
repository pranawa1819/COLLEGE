clear all;
close all;

clc;
% Importing image package
pkg load image;
% Reading the image
title("ORIGINAL IMAGE OF LION");
img = imread("lion.jpg");
figure
imshow(img);
% Convert image to grayscale
grayscale_img = rgb2gray(img);
% Show grayscale image
figure
imshow(grayscale_img);
title("GRAYSCALE IMAGE OF LION");
imwrite(grayscale_img, "original.jpg");
% Calculate negative of the image
output = 255 - grayscale_img;
% Show the output image
figure
imshow(uint8(output));
title("NEGATIVE IMAGE OF LION");
imwrite(uint8(output), "negative_transformation.jpg");
