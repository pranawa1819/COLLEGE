clear all;
close all;
clc;
% Import image package
pkg load image;
% Read image
%Implementation of filterusing Convolution
#figure;
I = imread('frog.jpg');
I = I(:,:,1);
subplot(2,2,1);
imshow(I);
title('Original Image');
a = [0.001 0.001 0.001; 0.001 0.001 0.001; 0.001 0.001 0.001];
R = conv2(a,I);
subplot(2,2,2);
imshow(R);
title('Filtered Image 1');
b = [0.005 0.005 0.005; 0.005 0.005 0.005; 0.005 0.005 0.005];
R1 = conv2(b,I);
subplot(2,2,3);
imshow(R1);
title('Filtered Image 2');
