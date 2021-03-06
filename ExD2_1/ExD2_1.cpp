// ExD2_1.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

#ifdef WIN32
#include <Windows.h>
#include <GL\gl.h>
#include <GL\glu.h>  // glu는 선택사항임
#include <GL\glut.h>
#endif
#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>
#endif

#include <iostream>

void SetupRC();											// OpenGL 렌더링 환경에 대한 기본 설정 부분을 담당하는 함수
void RenderScene();										// 실제 렌더링 부분을 담당하는 함수
void ReshapeScene(int, int);							// 윈도우 크기 변경 설정 담당 함수


int main()
{
	//초기화 함수들

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);		// 디스플레이 모드 설정
	glutInitWindowPosition(100, 100);					// 윈도우의 위치 지정
	glutInitWindowSize(500, 500);						// 윈도우의 크기 지정
	glutCreateWindow("점, 선, 삼각형 그리기");			// 윈도우 생성 (윈도우 이름)

	// 콜백 함수 등록
	glutDisplayFunc(RenderScene);						// 출력 함수의 지정

	SetupRC();
	glutMainLoop();

	return 0;
}


void SetupRC()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);				// 바탕색을 검은색으로
}


void RenderScene()
{
	glClear(GL_COLOR_BUFFER_BIT);						// 설정한 색으로 전체를 칠하기

	glMatrixMode(GL_MODELVIEW);							// 모델 매트릭스모드로 전환
	glLoadIdentity();


	// 점, 선, 삼각형 그리기
	glBegin(GL_TRIANGLES);
		glVertex3f(-1.0f, -1.0f, 0.0f);	//v1
		glVertex3f(1.0f, -1.0f, 0.0f);	//v2
		glVertex3f(0.0f, 1.0f, 0.0f);	//v3
	glEnd();

	glFlush();											// 화면에 출력하기
}
