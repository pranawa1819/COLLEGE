clear all;
close all;
clc;

% Importing image package
pkg load image;
% Read image
a = imread('fish.jpg');
subplot(2,2,1);
imshow(a);
title('Original Image');
b = im2double(a);
% Input values for image transformation
a1 = input('Enter value a for Image 1: ');
ga1 = input('Enter value gamma for Image 1: ');
s = (a1*(b.^ga1))*256;
s1 = uint8(s);
subplot(2,2,2);
imshow(s1);
title('Image 1');

a2 = input('Enter value a for Image 2: ');
ga2 = input('Enter value gamma for Image 2: ');
sp = (a2*(b.^ga2))*256;
s2 = uint8(sp);
subplot(2,2,3);
imshow(s2);
title('Image 2');

a3 = input('Enter value a for Image 3: ');
ga3 = input('Enter value gamma for Image 3: ');
sp3 = (a3*(b.^ga3))*256;
s3 = uint8(sp3);
subplot(2,2,4);
imshow(s3);
title('Image 3');


