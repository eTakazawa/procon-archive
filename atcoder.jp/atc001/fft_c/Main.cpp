#include <iostream>
#include <iomanip>
#include <vector>
#include <complex>
#include <cassert>

/**
  参考サイト
    - https://www.creativ.xyz/fast-fourier-transform/
    - http://takashiijiri.com/study/ImgProc/FourierTransform_disc.html
    - http://www.ic.is.tohoku.ac.jp/~swk/lecture/yaruodsp/main.html
 **/

// 離散フーリエ変換
std::vector<std::complex<double>> DiscreteFourierTransform(const std::vector<std::complex<double>>& f) {
  static const double PI = std::acos(-1.0);
  const int N = static_cast<int>(f.size());
  std::vector<std::complex<double>> F(N);
  for (int k = 0; k < N; k++) {
    for (int n = 0; n < N; n++) {
      // \exp(-jt) = \cos(t) - j\sin(t)　(絶対値1, 偏角t の複素数)
      // 元の波形の周期/kの |F[k]| が振幅， ∠F[k] が初期位相
      F[k] = F[k] + f[n] * std::polar(1.0, -2 * PI * k * n / N);
    }
  }
  return F;
}
template<typename T>
std::vector<std::complex<double>> DiscreteFourierTransform(const std::vector<T>& f) {
  std::vector<std::complex<double>> f_complex(f.size());
  for (int i = 0; i < static_cast<int>(f.size()); i++) {
    f_complex[i] = std::complex(f[i]);
  }
  return DiscreteFourierTransform(f_complex);
}

// 逆離散フーリエ変換
std::vector<std::complex<double>> InverseDiscreteFourierTransform(const std::vector<std::complex<double>>& F) {
  static const double PI = std::acos(-1.0);
  const int N = static_cast<int>(F.size());
  std::vector<std::complex<double>> f(N);
  for (int n = 0; n < N; n++) {
    for (int k = 0; k < N; k++) {
      // 虚部は打ち消し合って0になるので本当は計算不要
      // if (k != 0) std::cout << std::fixed << std::setprecision(2) << F[k].imag() << " " << F[N - k].imag() << std::endl;
      f[n] = f[n] + F[k] * std::polar(1.0, 2 * PI * k * n / N);
    }
    f[n] /= N;
  }
  return f;
}
template<typename T>
std::vector<std::complex<double>> InverseDiscreteFourierTransform(const std::vector<T>& F) {
  std::vector<std::complex<double>> F_complex(F.size());
  for (int i = 0; i < static_cast<int>(F.size()); i++) {
    F_complex[i] = std::complex(F[i]);
  }
  return InverseDiscreteFourierTransform(F_complex);
}

// bitの左右フリップ
// 0110011 -> 1100110
int BitSwap(int x, int num_bits) {
  int ret = 0;
  for (int i = 0; i < num_bits; i++) {
    ret |= ((x >> i) & 1) << (num_bits - 1 - i);
  }
  return ret;
}

// 高速フーリエ変換 Cooley-Tukey型FFTアルゴリズム
// 入力サイズは2の累乗であること
//
// DFTのexp(-j*2*PI*k*n/N)部分は共通していてまとめられる
//   参考: https://www.creativ.xyz/fast-fourier-transform/
std::vector<std::complex<double>> FastFourierTransform(const std::vector<std::complex<double>>& f, bool inverse = false) {
  static const double PI = std::acos(-1.0);
  const int N = static_cast<int>(f.size());
  const int logN = static_cast<int>(std::log2(N));
  assert((N & (N - 1)) == 0); // 2の累乗であること
  
  // 並び替え
  std::vector<std::complex<double>> F(N);
  for (int i = 0; i < N; i++) {
    F[i] = f[BitSwap(i, logN)];
  }
  // バタフライ演算
  for (int block_size = 1; block_size < N; block_size <<= 1) {
    // block_size: block_size個飛ばしたものと和を取る
    // バタフライになるのはblock_size*2の範囲
    for (int i = 0; i < block_size; i++) { // ブロック内のi個目
      // W_{2}^{1} == -W_{2}^{0}
      std::complex<double> w = std::polar(1.0, (2 * PI) / (2 * block_size) * i * (inverse ? 1 : -1));
      for (int j = 0; j < N; j += block_size * 2) { // ブロックのイテレーション
        std::complex<double> a = F[i + j];
        std::complex<double> b = F[i + j + block_size] * w;
        F[i + j]              = a + b; // F[l] + F[m] * w;
        F[i + j + block_size] = a - b; // F[l] - F[m] * w;
      }
    }
  }
  if (inverse) {
    for (int i = 0; i < N; i++) {
      F[i] /= N;
    }
  }
  return F;
}
template<typename T>
std::vector<std::complex<double>> FastFourierTransform(const std::vector<T>& f, bool inverse = false) {
  std::vector<std::complex<double>> f_complex(f.size());
  for (int i = 0; i < static_cast<int>(f.size()); i++) {
    f_complex[i] = std::complex<double>(f[i]);
  }
  return FastFourierTransform(f_complex, inverse);
}

template <typename T>
std::vector<double> Convolution1D(std::vector<T> a, std::vector<T> b) {
  const int N = static_cast<int>(a.size() + b.size() - 1);
  int paddedN = 1;
  while (paddedN < N) paddedN <<= 1;
  
  a.resize(paddedN);
  b.resize(paddedN);
  auto A = FastFourierTransform(a);
  auto B = FastFourierTransform(b);
  for (int i = 0; i < paddedN; i++) A[i] *= B[i];

  auto C = FastFourierTransform(A, true);
  std::vector<double> ret(N);
  for (int i = 0; i < N; i++) {
    ret[i] = C[i].real();
  }
  return ret;
}

bool IsSameComplexRealArray(const std::vector<std::complex<double>>& a, const std::vector<std::complex<double>>& b, double eps = 1e-7) {
  int n = static_cast<int>(a.size());
  int ng_counts = 0;
  for (int i = 0; i < n; i++) {
    if (std::abs(a[i].real() - b[i].real()) > eps) {
      ng_counts++;
      std::cerr << i << ":" << a[i] << " " << b[i] << std::endl;
    }
  }
  return ng_counts == 0;
}
bool IsSameComplexArray(const std::vector<std::complex<double>>& a, const std::vector<std::complex<double>>& b, double eps = 1e-7) {
  int n = static_cast<int>(a.size());
  int ng_counts = 0;
  for (int i = 0; i < n; i++) {
    if (std::abs(a[i].real() - b[i].real()) > eps || std::abs(a[i].imag() - b[i].imag()) > eps) {
      ng_counts++;
      std::cerr << i << ":" << a[i] << " " << b[i] << std::endl;
    }
  }
  return ng_counts == 0;
}

void SimpleDFTTest() {
  std::cerr << "***** SimpleDFTTest *****" << std::endl;

  int n = 1000;
  std::vector<std::complex<double>> f;
  static const double PI = std::acos(-1.0);
  
  // 5 + sin(t) + sin(2t)
  for (int i = 0; i < n; i++) {
    double theta = 2 * PI * static_cast<double>(i) / n;
    f.emplace_back(5.0 + sin(theta) + 3*sin(theta * 2));
  }
  // DFT, IDFTで元に戻す
  auto F = DiscreteFourierTransform(f);
  auto trans_f = InverseDiscreteFourierTransform(F);

  // 結果が一致するか確認
  bool is_match = IsSameComplexRealArray(f, trans_f);
  std::cerr << (is_match ? "OK" : "ERROR") << std::endl;
}
void SimpleFFTTest() {
  std::cerr << "***** SimpleFFTTest *****" << std::endl;

  int n = 2048;
  std::vector<std::complex<double>> f;
  static const double PI = std::acos(-1.0);
  // 5 + sin(t) + sin(2t)
  for (int i = 0; i < n; i++) {
    double theta = 2 * PI * static_cast<double>(i) / n;
    f.emplace_back(5.0 + sin(theta) + 3*sin(theta * 2));
  }
  auto F = FastFourierTransform(f);
  auto trans_f = FastFourierTransform(F, true);

  // 結果が一致するか確認
  bool is_match = IsSameComplexRealArray(f, trans_f);
  std::cerr << (is_match ? "OK" : "ERROR") << std::endl;
}
void RandomFFTTest() {
  std::cerr << "***** RandomFFTTest *****" << std::endl;

  const int n = 65536;
  std::vector<std::complex<double>> f;
  for (int i = 0; i < n; i++) {
    f.emplace_back(rand() % 10000);
  }
  auto trans_f = FastFourierTransform(FastFourierTransform(f), true);
  bool is_match = IsSameComplexRealArray(f, trans_f);
  std::cerr << (is_match ? "OK" : "ERROR") << std::endl;
}
void AtCoderTypicalContest001CTest() {
  // https://atcoder.jp/contests/atc001/tasks/fft_c
  int N;
  std::cin >> N;
  std::vector<int> A(N+1), B(N+1);
  for (int i = 1; i <= N; i++) {
    std::cin >> A[i] >> B[i];
  }
  auto C = Convolution1D(A, B);
  for (int i = 1; i <= 2 * N; i++) {
    std::cout << static_cast<int>(std::round(C[i])) << std::endl;
  }
}

int main(void) {
  // SimpleDFTTest();
  // SimpleFFTTest();
  // RandomFFTTest();
  AtCoderTypicalContest001CTest();
  return 0;
}