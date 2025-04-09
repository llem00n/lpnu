clc;
clear;

T = 15;
m = 8;
N = 2^m;

p = N/4;
k1 = N/2 - p;
k2 = N/2 + p;

dt = T/N;
t1 = 0:dt:5-dt;
t2 = 5:dt:15;
t = [t1, t2];


x1 = 36 + 0*t1;
x2 = (1.3)*t2 - 19.5;
x = [x1, x2];

dw = 2*%pi/T;
w = 1:1:N;

Sx = fft(x) / N;

figure(1, 'BackgroundColor', [1, 1, 1]);
subplot(3,1,1), plot(t, x), title('Вхідний сигнал - x(n)', 'position', [T/2, max(x)/2]);
subplot(3,1,2), plot(w, real(Sx)), title('Дійсна частина ШПФ', 'position', [N/2, max(real(Sx))/2]);
subplot(3,1,3), plot(w, imag(Sx)), title('Уявна частина ШПФ', 'position', [N/2, max(imag(Sx))/2]);

Sx1 = [Sx(1:k1), zeros(1, k2 - k1), Sx(k2 + 1:N)];
Sx2 = [zeros(1, p), Sx(p+1:N-p), zeros(1, p)];
Sx3 = [Sx(1 : N/4 - p/2), zeros(1, p), Sx((N/4 + p/2) + 1 : 3*N/4 - p/2), zeros(1, p), Sx(3*N/4 + p/2 + 1:N)];
Sx4 = [zeros(1, N/4 - p/2), Sx((N/4 - p/2) + 1 : N/4 + p/2), zeros(1, N/2 - p), Sx(3*N/4 - p/2 + 1 : 3*N/4 + p/2), zeros(1, N/4 - p/2)];

figure(2, 'BackgroundColor', [1, 1, 1]);
subplot(5,2,1), plot(w, abs(Sx)), title('Амплітудний спектр X(k)', 'position', [N/4, max(abs(Sx))/2]);
subplot(5,2,3), plot(w, abs(Sx1)), title('Модифікований амплітудний спектр Xm1(k)', 'position', [N/20, max(abs(Sx1))/2]);
subplot(5,2,5), plot(w, abs(Sx2)), title('Модифікований амплітудний спектр Xm2(k)', 'position', [N/20, max(abs(Sx2))/2]);
subplot(5,2,7), plot(w, abs(Sx3)), title('Модифікований амплітудний спектр Xm3(k)', 'position', [N/20, max(abs(Sx3))/2]);
subplot(5,2,9), plot(w, abs(Sx4)), title('Модифікований амплітудний спектр Xm4(k)', 'position', [N/20, max(abs(Sx4))/2]);

x1 = N * ifft(Sx);
xm1 = N * ifft(Sx1);
xm2 = N * ifft(Sx2);
xm3 = N * ifft(Sx3);
xm4 = N * ifft(Sx4);

subplot(5,2,2), plot(t, x1), title('Відновлений сигнал x1(n)', 'position', [T/4, max(abs(x1))/2]);
subplot(5,2,4), plot(t, real(xm1)), title('Відновлений сигнал xm1(n)', 'position', [T/4, max(abs(xm1))/2]);
subplot(5,2,6), plot(t, real(xm2)), title('Відновлений сигнал xm2(n)', 'position', [T/4, max(abs(xm2))/2]);
subplot(5,2,8), plot(t, real(xm3)), title('Відновлений сигнал xm3(n)', 'position', [T/4, max(abs(xm3))/2]);
subplot(5,2,10), plot(t, real(xm4)), title('Відновлений сигнал xm4(n)', 'position', [T/4, max(abs(xm4))/2]);

onePr = 100 / (N * max(abs(26), abs(-13)));

bm1 = onePr * sum(abs(x - xm1));
bm2 = onePr * sum(abs(x - xm2));
bm3 = onePr * sum(abs(x - xm3));
bm4 = onePr * sum(abs(x - xm4));

disp("N=", N);
disp("p=", p);

bm = [bm1, bm2, bm3, bm4];
disp("bm", bm);

E_time  = sum(abs(x).^2) / N;
E_spektr = sum(abs(Sx).^2);

E_time1 = sum(abs(xm1).^2) / N; E_spektr1 = sum(abs(Sx1).^2);
E_time2 = sum(abs(xm2).^2) / N; E_spektr2 = sum(abs(Sx2).^2);
E_time3 = sum(abs(xm3).^2) / N; E_spektr3 = sum(abs(Sx3).^2);
E_time4 = sum(abs(xm4).^2) / N; E_spektr4 = sum(abs(Sx4).^2);

E_t = [E_time, E_time1, E_time2, E_time3, E_time4];
E_s = [E_spektr, E_spektr1, E_spektr2, E_spektr3, E_spektr4];

E = [E_t, E_s];
disp("E=", E');
