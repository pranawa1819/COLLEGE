clear all;
close all;
clc;
%import image package
pkg load image;
%read image
l=im2double(imread('tiger.jpg'));
f1=fft(l);
f2=fftshift(f1);
subplot(2,2,1);
imshow(abs(f1));
title('Frequency Spectrum');
subplot(2,2,2);
imshow(abs(f2));
title('Centered Spectrum');
f3=log(1+abs(f2));
subplot(2,2,3);
imshow(abs(f3));
title('log(1+abs(f2))');
l=fft2(f1);
ll=real(l);
subplot(2,2,4);
imshow(ll);
title(' 2-D FFT');

