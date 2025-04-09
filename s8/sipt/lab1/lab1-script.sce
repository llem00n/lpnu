clc;
clear;

//***** INPUT N *****//
n = 0;
try
  nstr = x_dialog("Matrix Size, N", "0");
  n = evstr(nstr)
catch
  messagebox("Invalid value, N must be an integer >= 0!")
  exit;
end

if n <= 0 || floor(n) <> n then
  messagebox("Invalid size, N must be an integer >= 0!");
  exit;
end

//***** INPUT A *****//
is_random_choices = list('', 1, ["Random", "Manual"])
is_random = x_choices("Matrix A mode", list(is_random_choices));

if length(is_random) <> 1 || is_random(1) == 1 then
  A = grand(n, n, "uin", -150, 150);
  x_matrix("<html><body>Generated Matrix <b>A", A);
else
  _A = zeros(n, n);
  A = x_matrix("<html><body>Matrix <b>A", _A);
end

//***** GENERATE B *****//
B = zeros(n, n);
[row, col] = ndgrid(1:n, 1:n);
B = B + (row < col) .* (1 ./ (row + col - 1));
B = B - (row > col) .* (1 ./ (row + col - 1));
x_matrix("<html><body>Matrix <b>B", B);

//***** CALCULATE C *****//
C = A * B;
x_matrix("<html><body>Matrix <b>C = A * B", C);
