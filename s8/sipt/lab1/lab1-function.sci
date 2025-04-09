// Main function to coordinate matrix operations
function main()
  n = get_matrix_size();
  if n <= 0 then
      disp("Invalid size, N must be an integer >= 0!");
      return;
  end

  A = generate_matrix_a(n);
  disp("Matrix A:");
  disp(A);
  disp("");

  B = generate_matrix_b(n);
  disp("Matrix B:");
  disp(B);
  disp("")

  C = A * B;
  disp("Matrix C = A * B:");
  disp(C);
endfunction


// Function to get matrix size from user
function n = get_matrix_size()
  nstr = input("Enter matrix size N (positive integer): ", "string");
  try n = evstr(nstr);
  catch n = 0;
  end
  
  if n <= 0 | floor(n) <> n then
      disp("Invalid value! N must be a positive integer.");
      n = 0;
  end
endfunction


// Function to generate matrix A (random or manual)
function A = generate_matrix_a(n)
  disp("Choose how to generate matrix A:");
  disp("1. Random");
  disp("2. Manual");
  choice = input("Enter your choice (1 or 2): ");
  if choice == 1 then
      A = grand(n, n, "uin", -150, 150);
  elseif choice == 2 then
      A = input("Enter matrix A (NxN): ");
  else
      disp("Invalid choice! Generating random matrix by default.");
      A = grand(n, n, "uin", -150, 150);
  end
endfunction


// Function to generate matrix B based on conditions
function B = generate_matrix_b(n)
  [row, col] = ndgrid(1:n, 1:n);
  B = zeros(n, n);
  B = B + (row < col) .* (1 ./ (row + col - 1));
  B = B - (row > col) .* (1 ./ (row + col - 1));
endfunction
