// C++配列・平均値・最大値・最小値サンプル Copyright(C) 2022 https://www.youtube.com/@ProgrammerCpp
#include <iostream>
#include <iomanip>
#include <algorithm> //std::max_element, std::min_element
#include <numeric>   //std::accumulate

/*【このサンプルのテーマ】
* 入力処理と平均値、最大値、最小値を求める処理を分離する
* std::accumulate で合計値、
* std::max_element で最小値、
* std::min_element で最大値を得る
* 【説明】
* std::accumulate、std::max_element、std::min_element に対する第１、第２引数は a, a + n と書ける。
* a は &a[0] の意味であり、a + n は &a[n] の意味である。
* &a[0] は範囲の開始ポインタであり、
* &a[n] は範囲の終了ポインタである。
* この場合の（というよりも C++ 標準ライブラリの全体として）終了ポインタは最終要素の次の要素を指すポインタとなる。
*/

//読み込み関数：読み込み成功の場合は true、失敗の場合は false を返す
static bool input(int a[], size_t i)
{
	std::cout << "Input Data No." << std::setw(2) << i + 1 << " : ";
	return (std::cin >> a[i]).good();
}
//表示関数
static void output(const int a[], size_t i)
{
	std::cout << "[No." << std::setw(2) << i + 1 << "] " << a[i] << "\n";
}
int main()
{
	int a[10];
	//a[0] の入力データを読み込む
	if (input(a, 0)) {
		size_t n = 1;
		//a[1]～a[9] の入力データを読み込む
		for (;;) {
			if (n == 10/*10 のところは std::size(a) と書ける*/)
				break;//すべて読み込み完了（n は 10 となり、読み込み済みのデータ個数をあらわす）
			else {
				if (input(a, n))
					++n;
				else
					break;//エラーのため読み込み終了（n は 10 未満の値となり、読み込み済みのデータ個数を表す）
			}
		}
		//読み込んだ整数値の一覧
		std::cout << "Data List:\n";
		output(a, 0);
		for (size_t i = 1; i < n; ++i)
			output(a, i);
		//平均値，最大値，最小値
		const double s   = std::accumulate (a, a + n, 0); //合計値
		const auto max_p = std::max_element(a, a + n   ); //最大値を指すポインタ
		const auto min_p = std::min_element(a, a + n   ); //最小値を指すポインタ
		const auto default_precision = std::cout.precision();
		std::cout
			<< "\n"
			<< "average value : " << std::fixed << std::setprecision(2) << s / n << std::defaultfloat << std::setprecision(default_precision) << "\n"
			<< "maximum value : " << *max_p << " (no." << (max_p - a) + 1 << ")\n"
			<< "minimum value : " << *min_p << " (no." << (min_p - a) + 1 << ")\n"
			;
		return 0;//正常終了
	}
	else
		return 1;//読み込みエラー
}
