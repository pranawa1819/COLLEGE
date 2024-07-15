clear all; % clear all variables
close all; % close all figures
clc; % clear command window
% Load image package (for Octave)
pkg load image;
% Read image
I = imread('flower1.jpg');
% Convert image to grayscale
K = rgb2gray(I);
% Add salt and pepper noise to grayscale image
J = imnoise(K,'salt & pepper', 0.05);
% Apply median filters
f = medfilt2(J, [3, 3]); % 3x3 median filter
fl = medfilt2(J, [10, 10]); % 10x10 median filter
% Display images
subplot(3, 2, 1);
imshow(I);
title('Original Image');
subplot(3, 2, 2);
imshow(K);
title('Gray Image');
subplot(3, 2, 3);
imshow(J);
title('Noise added Image');
subplot(3, 2, 4);
imshow(f);
title('3x3 Image');
subplot(3, 2, 5);
imshow(fl);
title('10x10 Image');
