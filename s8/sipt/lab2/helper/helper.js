function calculateQuantizationErrors(coef, M) {
  // Constants
  const A1 = -3, A2 = 6, A3 = 15, A4 = -0.12;
  const w1 = 6, w2 = 1 / 5, w3 = 3, w4 = 8;
  const phi1 = Math.PI / 5, phi2 = Math.PI / 6, phi3 = 0, phi4 = Math.PI / 7;

  const w_max = Math.max(w1, w2, w3, w4);
  const f_max = w_max / (2 * Math.PI);
  const dt = 1 / (2 * f_max * coef);
  const T = 10 * Math.PI;

  // Time vector
  const t = [];
  for (let i = 0; i < T; i += dt) {
    t.push(i);
  }

  // Signal x(t)
  const x = t.map(ti =>
    A1 * Math.cos(w1 * ti + phi1) -
    A2 * Math.sin(w2 * ti + phi2) +
    A3 * Math.sin(w3 * ti + phi3) -
    A4 * Math.cos(w4 * ti + phi4)
  );

  const maxA = Math.max(...x.map(Math.abs));
  const minA = -maxA;
  const N = x.length;
  const k = (maxA - minA) / (M - 1);

  // Quantization levels
  const K = Array.from({ length: M }, (_, i) => minA + i * k);

  // Quantized signal y(t)
  let y = x.map(xi => Math.floor(xi / k) * k);

  // If M is even, offset quantization levels
  if (M % 2 === 0) {
    y = y.map(yi => yi + k / 2);
  }

  // Error metrics
  const a = Math.max(...y.map((yi, i) => Math.abs(yi - x[i])));
  const b = (y.reduce((sum, yi) => sum + yi, 0) - x.reduce((sum, xi) => sum + xi, 0)) / N;
  const d = y.reduce((sum, yi, i) => sum + Math.pow(yi - x[i], 2), 0) / N;

  return { a, b, d };
}

function padWithSpaces(value, length) {
  const str = String(value); // convert number to string
  const padded = str.padStart(length, ' ');
  return padded;
}


const coefValues = [1, 2, 4, 8];
const MValues = [8, 32, 256];

for (const coef of coefValues) {
  console.log(`\n=== coef = ${coef} ===`);
  for (const M of MValues) {
    const { a, b, d } = calculateQuantizationErrors(coef, M);
    console.log(`M = ${padWithSpaces(M, 3)} => A: ${padWithSpaces(a.toFixed(5), 8)}, B: ${padWithSpaces(b.toFixed(5), 8)}, D: ${padWithSpaces(d.toFixed(5), 8)}`);
  }
}
