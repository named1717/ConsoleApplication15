#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <windows.h>

int main() {
	int score[3][30] = {0};
	float avascore[30] = { 0.f };
	int max[3] = { 0 }, min[3] = { 100,100,100 };
	float avamax = 0, avamin = 100;
	float avaava=0;
	float subava[3] = { 0.f };
	for (int i = 0;i < 30;i++) {
		char buff[50];
		sprintf(buff, "학생 %d의 국어, 영어, 수학 점수를 입력해 주세요\n", i+1);
		printf(buff);
		scanf("%d %d %d", &score[0][i], &score[1][i], &score[2][i]);
	}
	for (int i = 0;i < 30;i++) { //각 학생의 평균값
		avascore[i] = (score[0][i] + score[1][i] + score[2][i]) / 3;
	}
	for (int i = 0;i < 30;i++) { //각 학생의 평균값의 최대 최소
		if (avascore[i] > avamax) avamax = avascore[i];
		if (avascore[i] < avamin) avamin = avascore[i];
	}
	for (int i = 0; i < 30; i++) {//각 학생 평균의 평균
		avaava += avascore[i];
	}
	avaava = avaava / 30;
	printf("학생평균의 최소값은 %.2f입니다\n", avamin);
	printf("학생평균의 최대값은 %.2f입니다\n", avamax);
	printf("학생평균의 평균값은 %.2f입니다\n", avaava);
	for (int j = 0; j < 3;j++) {
		for (int i = 0; i < 30; i++) { //각 과목의 최대 최소 평균
			if (score[j][i] > max[j]) max[j] = score[j][i];
			if (score[j][i] < min[j]) min[j] = score[j][i];
			subava[j] += score[j][i];
		}
		subava[j] = subava[j] / 30;
		if (j == 0) {
			printf("국어과목의 평균값은 %.2f입니다\n", subava[j]);
			printf("국어과목의 최소값은 %d입니다\n", min[j]);
			printf("국어과목의 최대값은 %d입니다\n", max[j]);
		}
		else if (j == 1) {
			printf("영어과목의 평균값은 %.2f입니다\n", subava[j]);
			printf("영어과목의 최소값은 %d입니다\n", min[j]);
			printf("영어과목의 최대값은 %d입니다\n", max[j]);
		}
		else if (j == 2) {
			printf("수학과목의 평균값은 %.2f입니다\n", subava[j]);
			printf("수학과목의 최소값은 %d입니다\n", min[j]);
			printf("수학과목의 최대값은 %d입니다\n", max[j]);
		}
	}
}