clear all;
close all;
clc;
% Import image package
pkg load image;
% Read image
i = imread("car.jpg");
% Extract bit planes
b0 = double(bitget(i,1));
b1 = double(bitget(i,2));
b2 = double(bitget(i,3));
b3 = double(bitget(i,4));
b4 = double(bitget(i,5));
b5 = double(bitget(i,6));
b6 = double(bitget(i,7));
b7 = double(bitget(i,8));
% Display original image and bit planes
subplot(3,3,1);
imshow(i);
title('Original Image');
subplot(3,3,2);
imshow(b0);
title('BIT PLANE 0');

subplot(3,3,3);
imshow(b1);
title('BIT PLANE 1');
subplot(3,3,4);
imshow(b2);
title('BIT PLANE 2');
subplot(3,3,5);
imshow(b3);
title('BIT PLANE 3');
subplot(3,3,6);
imshow(b4);
title('BIT PLANE 4');
subplot(3,3,7);
imshow(b5);
title('BIT PLANE 5');
subplot(3,3,8);
imshow(b6);
title('BIT PLANE 6');
subplot(3,3,9);
imshow(b7);
title('BIT PLANE 7');
