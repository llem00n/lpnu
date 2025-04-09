clc;
clear;

// Основні параметри
m = 10;
N = 2^m; // Кількість відліків
T1 = 3; // Інтервал часу для симуляції
dt1 = T1 / N;

// Створення часу t на інтервалі [-T1, T1]
t1 = linspace(-T1, T1, N);
t2 = linspace(-T1, 0, N);

x = 3 * exp(-abs(t1));
y = 2 * exp(t2);

disp(exp(-0.001));

// Побудова графіків вхідних сигналів
figure(1, 'BackgroundColor', [1,1,1]);
plot2d(t1, x, 5);
plot2d(t2, y, 3);
legend('x(t) = 2e^t', 'y(t) = 3e^{-|t|}');
title('Вхідні сигнали');

// Автокореляційні функції
Bxx = (1/N) * xcorr(x, x);
Byy = (1/N) * xcorr(y, y);
figure(2, 'BackgroundColor', [1,1,1]);
subplot(2,1,1), plot(Bxx, 'color', 5), title('Автокореляційна функція X');
subplot(2,1,2), plot(Byy, 'color', 3), title('Автокореляційна функція Y');

// Взаємокореляційна функція
Bxy = (1/N) * xcorr(x, y);
t_corr = linspace(-2*T1, 2*T1, length(Bxy));
figure(3, 'BackgroundColor', [1,1,1]);
subplot(2,1,1), plot(Bxy), title('Взаємокореляція X та Y (відносно номеру відліку)');
subplot(2,1,2), plot(t_corr, Bxy, 'color', 6), 
title('Взаємокореляція X та Y (відносно часу)');

// Згортка сигналів
Cxy = conv(x, y);
y_inv = y($:-1:1);
Cxy1 = conv(x, y_inv);
t_conv = linspace(-2*T1, 2*T1, length(Cxy));
figure(4, 'BackgroundColor', [1,1,1]);
subplot(2,1,1), plot(t_conv, Cxy./N), title('Згортка X та Y');
subplot(2,1,2), plot(t_conv, Cxy1./N, 'color', 6), title('Згортка X та Y (інверсія)');

// Пікові значення взаємокореляції
[d, d1] = max(Bxy);
disp('Максимальне значення ВКФ: ', d);
disp('Індекс піку: ', d1);
disp('Відповідне значення часу: ', t_corr(d1));
