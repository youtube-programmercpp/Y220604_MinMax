// C言語(C99)配列・平均値・最大値・最小値サンプル Copyright(C) 2022 https://www.youtube.com/@ProgrammerCpp
#include <stdio.h>  //printf、scanf 用として
#include <stdlib.h> //EXIT_SUCCESS, EXIT_FAILURE 用として

/*【このサンプルのテーマ】
* 入力エラー対策
* C99準拠（scanfの代わりに scanf_s を使用…ただし、このプログラムの内容としては scanf を使っても同じ）
* 関数を用意する
* 先頭の要素だけは特別
* 【説明】
* 入力データを受け付けるための関数として input、
* 出力データを表示するための関数として output を用意した。
* 先頭の要素の読み込みが失敗した場合、平均値、最大値、最小値を求めることはできないため異常終了。
*/

//読み込み関数：読み込み成功の場合は 1、失敗の場合は 0 を返す
static int input(int a[], int i)
{
	printf("Input Data No.%2d : ", i + 1);
	return scanf_s("%d", &a[i]) == 1;
}
//表示関数
static void output(const int a[], int i)
{
	printf("[No.%2d] %d\n", i + 1, a[i]);
}
int main()
{
	int a[10];
	//a[0] の入力データを読み込む
	if (input(a, 0)) {
		double s = a[0];//合計値
		int max_i  = 0; //最大値のインデックス
		int min_i  = 0; //最小値のインデックス
		int n = 1;
		//a[1]～a[9] の入力データを読み込む
		for (;;) {
			if (n == 10/* 10 のところは sizeof a / sizeof *a または _countof(a) 等と書ける*/)
				break;//すべて読み込み完了（n は 10 となり、読み込み済みのデータ個数をあらわす）
			else {
				if (input(a, n)) {
					s += a[n];
					if (a[max_i] < a[n]) max_i = n;
					if (a[min_i] > a[n]) min_i = n;
					++n;
				}
				else
					break;//エラーのため読み込み終了（n は 10 未満の値となり、読み込み済みのデータ個数を表す）
			}
		}
		//読み込んだ整数値の一覧
		printf("Data List:\n");
		output(a, 0);
		for (int i = 1; i < n; ++i)
			output(a, i);
		//平均値，最大値，最小値
		printf("\n");
		printf("average value : %.2f\n", s / n);
		printf("maximum value : %d (no.%d)\n", a[max_i], max_i + 1);
		printf("minimum value : %d (no.%d)\n", a[min_i], min_i + 1);
		return EXIT_SUCCESS;//正常終了
	}
	else
		return EXIT_FAILURE;//読み込みエラー
}
/*
https://detail.chiebukuro.yahoo.co.jp/qa/question_detail/q10271260785
晃一さん

2022/11/19 22:04

2回答

10個の整数値を整数型配列に読み込んで，それらの整数値の一覧，および，平均値，最大値，最小値を求めるプログラムを作成せよという問題がよくわかりもせん。特に最小、最大値を求めるところがわかりません。
実行結果
./a.out
Input Data No. 1 : 10
Input Data No. 2 : 30
Input Data No. 3 : 45
Input Data No. 4 : 70
Input Data No. 5 : -5
Input Data No. 6 : 0
Input Data No. 7 : 28
Input Data No. 8 : 33
Input Data No. 9 : 90
Input Data No.10 : -25

Data List:
[No. 1] 10
[No. 2] 30
[No. 3] 45
[No. 4] 70
[No. 5] -5
[No. 6] 0
[No. 7] 28
[No. 8] 33
[No. 9] 90
[No.10] -25

average value : 27.60
maximum value : 90 (no.9)
minimum value : -25 (no.10)

C言語関連・30閲覧・25
*/
